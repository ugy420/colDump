import 'package:flutter/material.dart';
import 'package:noteapp/screens/note_list.dart';

void main(){
  runApp(const MyApp());
}

class MyApp extends StatelessWidget{
  const MyApp({super.key});

  @override
  Widget build(BuildContext context){

    return MaterialApp(
      title:'Notekeeper',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        primarySwatch: Colors.pink
      ),
      home: const NoteList(),
    );
  }
}