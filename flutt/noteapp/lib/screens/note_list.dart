import 'package:flutter/material.dart';
import 'dart:async';
import 'package:noteapp/models/note.dart';
import 'package:noteapp/utils/database_helper.dart';
import 'package:noteapp/screens/note_detail.dart';
import 'package:sqflite/sqflite.dart';


class NoteList extends StatefulWidget{
  const NoteList({super.key});

  @override
  State<StatefulWidget> createState(){
    return NoteListState();
  }
}

class NoteListState extends State<NoteList>{
  
  DatabaseHelper databaseHelper = DatabaseHelper();
  late List<Note> noteList;
  int count = 0;

  @override
  Widget build(BuildContext context){


    if(noteList == null){
      noteList = [];
      updateListView();
    }

    return Scaffold(
      appBar: AppBar(
        title: const Text('Notes'),
      ),
      body: getNoteListView(),

      floatingActionButton: FloatingActionButton(
        onPressed: () {
          debugPrint('FAB clicked');
          navigateToDetail(Note ('','',2), 'Add Note');
        },
        tooltip: 'Add Note',
        child: const Icon(Icons.add),
      )
    );
  }

  ListView getNoteListView(){
    TextStyle? titleStyle = Theme.of(context).textTheme.titleMedium;
    return ListView.builder(
      itemCount: count,
      itemBuilder: (BuildContext context, int position){
        return Card(
          color: Colors.white,
          elevation:2.0,
          child:ListTile(
            leading: CircleAvatar(
							backgroundColor: getPriorityColor(this.noteList[position].priority),

							child: getPriorityIcon(this.noteList[position].priority),
              
            ),

            title: Text('Dummt Title', style: titleStyle,),

            subtitle: const Text('Dummy Date'),

            trailing: GestureDetector(
              child: const Icon(Icons.delete, color: Colors.grey),
              onTap: () {
                _delete(context, noteList[position]);
              }
            ),
            onTap: (){
              navigateToDetail(noteList[position], 'Edit Note');
            },
          ),
        );
      }
    );
  }

  Color getPriorityColor(int priority){
    switch (priority){
      case 1:
        return Colors.red;
        break;
      case 2:
        return Colors.yellow;
        break;
      default:
        return Colors.yellow;
    }
  }

  Icon getPriorityIcon(int priority){
    switch(priority){
      case 1:
        return const Icon(Icons.play_arrow);
        break;
      case 2:
        return const Icon(Icons.keyboard_arrow_right);
        break;

      default:
        return const Icon(Icons.keyboard_arrow_right);
    }
  }

  void _delete(BuildContext context, Note note) async{
    int result = await databaseHelper.deleteNote(note.id);
      _showSnackBar(context, 'Note Deleted Succesfully');
      updateListView();
  }

  void _showSnackBar(BuildContext context, String message){
    final snackBar = SnackBar(content: Text(message));
  }

  void navigateToDetail(Note note, String title) async{
    bool result = await Navigator.push(context, MaterialPageRoute(builder: (context){
      return NoteDetail(note, title);
    }));
    if(result == true){
      updateListView();
    }
  }

  void updateListView(){
    final Future<Database> dbFuture = databaseHelper.initializeDatabase();
    dbFuture.then((database){
      Future<List<Note>> noteListFuture = databaseHelper.getNoteList();
      noteListFuture.then((noteList){
        setState((){
          this.noteList = noteList;
          count = noteList.length;
      });
    });
  });
  }
}