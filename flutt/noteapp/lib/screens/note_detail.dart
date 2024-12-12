import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:noteapp/models/note.dart';
import 'package:noteapp/utils/database_helper.dart';

class NoteDetail extends StatefulWidget{

  final String appBarTitle;
  final Note note;

  const NoteDetail(this.note, this.appBarTitle, {super.key});

  @override
  State<StatefulWidget> createState(){
    return NoteDetailState(note, appBarTitle);
  }
}

class NoteDetailState extends State<NoteDetail>{
  static final _priorities = ['High','Low']; 
  
  DatabaseHelper helper = DatabaseHelper();

  String appBarTitl;
  Note note;

  TextEditingController titleController = TextEditingController();
  TextEditingController descriptionController = TextEditingController();

  NoteDetailState(this.note, this.appBarTitl);
  @override
  Widget build(BuildContext context){

    TextStyle? textStyle = Theme.of(context).textTheme.titleSmall;

    titleController.text = note.title;
    descriptionController.text = note.description;
    
    return WillPopScope(
      onWillPop: () async{
        moveToLastScreen();
        return true;
      },
      child: Scaffold(
      appBar: AppBar(
        title: Text(appBarTitl),
        leading: IconButton(icon:const Icon(
          Icons.arrow_back),
          onPressed: () {
            moveToLastScreen();
          },
        ),
      ),

      body: Padding(
        padding: const EdgeInsets.only(top: 15.0, left: 10.0, right: 10.0),
        child: ListView(
          children: <Widget>[
            ListTile(
              title: DropdownButton(
                items: _priorities.map((String dropDownStringItem){
                  return DropdownMenuItem<String>(
                    value: dropDownStringItem,
                    child: Text(dropDownStringItem),
                  );
                }).toList(),

                style: textStyle,

                value: getPriorityAsString(note.priority),

                onChanged: (valueSelectedByUser){
                  setState((){
                    debugPrint('User selected $valueSelectedByUser');
                    updatePriorityAsInt(valueSelectedByUser!);
                  });
                },
              ),
            ),

            // Second Element
            Padding(
              padding: const EdgeInsets.only(top:15.0, bottom: 15.0),
              child: TextField(
                controller: titleController,
                style: textStyle,
                onChanged: (value) {
                  debugPrint('Something changed in Title Text Field');
                  updateTitle();
                },
                decoration: InputDecoration(
                  labelText: 'Title',
                  labelStyle: textStyle,
                  border: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(5.0)
                  ),
                ),
              ),
            ),
            // Third Element
            Padding(
              padding: const EdgeInsets.only(top:15.0, bottom: 15.0),
              child: TextField(
                controller: descriptionController,
                style: textStyle,
                onChanged: (value) {
                  debugPrint('Something changed in Description Text Field');
                  updateDescription();
                },
                decoration: InputDecoration(
                  labelText: 'Description',
                  labelStyle: textStyle,
                  border: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(5.0)
                  ),
                ),
              ),
            ),
            // Fourth Element
            Padding(
              padding: const EdgeInsets.only(top:15.0, bottom: 15.0),
              child: Row(
                children: <Widget>[
                  Expanded(
                    child: ElevatedButton(
                      child: const Text(
                        'Save',
                        textScaleFactor: 1.5,
                      ),
                      onPressed: (){
                        setState((){
                          debugPrint("Save button clicked");
                          _save();
                        });
                      },
                    ),
                  ),

                  Container(width: 5.0,),

                  Expanded(
                    child: ElevatedButton(
                      child: const Text(
                        'Delete',
                        textScaleFactor: 1.5,
                      ),
                      onPressed: (){
                        setState((){
                          debugPrint("Delte button clicked");
                          _delete();
                        });
                      },
                    )
                  )
                ],
              ),
            ),
          ],
        ),
      ),
    ));
  }

  void moveToLastScreen() {
    Navigator.pop(context, true);
  }

  void updatePriorityAsInt(String value){
    switch(value){
      case 'High':
        note.priority = 1;
        break;
      case 'Low':
        note.priority = 2;
        break;
    }
  }

  String getPriorityAsString(int value){
    String priority = _priorities[1];
    switch(value){
      case 1:
        priority = _priorities[0];
        break;
      case 2:
        priority = _priorities[1];
        break;
    }
    return priority;
  }

  void updateTitle(){
    note.title = titleController.text;
  }

  void updateDescription(){
    note.description = descriptionController.text;
  }

  void _save() async{

    moveToLastScreen();

    note.date = DateFormat.yMMMd().format(DateTime.now());
    int result;
    if(note.id != null){
      result = await helper.updateNote(note);
    }else{
      result = await helper.insertNote(note);
    }

    if(result!=0){
      _showAlterDialog('Status', 'Note Saved Successfully');
    }
    else{
      _showAlterDialog('Status', 'Problem Saving Note');
    }
  }
  
  void _showAlterDialog(String title, String message) {
    AlertDialog alertDialog = AlertDialog(
      title:Text(title),
      content: Text(message),
    );
    showDialog(
      context: context,
      builder: (_) => alertDialog,
    );
  }

  void _delete() async{

    moveToLastScreen();

    if(note.id==null){
      _showAlterDialog('Status', 'No Note was deleted');
      return;
    }

    int result = await helper.deleteNote(note.id);
    if(result!=0){
      _showAlterDialog('Status', 'Note Deleted Successfully');
    }
    else{
      _showAlterDialog('Status', 'Error Occured while deleting note');
    }
  }
}
