import 'package:flutter/material.dart';

void main() {
  runApp(QuizApp());
}

class QuizApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Quiz App',
      theme: ThemeData(primarySwatch: Colors.blue),
      home: QuizPage(),
    );
  }
}

class QuizPage extends StatefulWidget {
  @override
  _QuizPageState createState() => _QuizPageState();
}

class _QuizPageState extends State<QuizPage> {
  int _questionIndex = 0;
  int _score = 0;

  List<MCQQuestion> _questions = [
    MCQQuestion(
      '1. What is Flutter?',
      ['A mobile app development framework', 'A programming language', 'A database system', 'A game engine'],
      0, // Index of the correct option (A mobile app development framework)
    ),
    MCQQuestion(
      '2. Which programming language is used in Flutter?',
      ['JavaScript', 'Kotlin', 'Swift', 'Dart'],
      3, // Index of the correct option (Dart)
    ),
    MCQQuestion(
      '3. What is a widget in Flutter?',
      ['A furry creature', 'A building block for the user interface', 'A piece of code', 'A hardware component'],
      1, // Index of the correct option (A building block for the user interface)
    ),
    MCQQuestion(
      '4. What is the Flutter layout system called?',
      ['Grid', 'Flexbox', 'RelativeLayout', 'Widget Tree'],
      3, // Index of the correct option (Widget Tree)
    ),
    MCQQuestion(
      '5. Which command is used to create a new Flutter project?',
      ['create', 'init', 'start', 'new'],
      1, // Index of the correct option (init)
    ),
    // Add more MCQ questions related to Flutter here
  ];

  int selectedOptionIndex = -1; // Initialize with -1 to represent no selection

  void _checkAnswer() {
    int correctOptionIndex = _questions[_questionIndex].correctOptionIndex;
    bool isCorrect = selectedOptionIndex == correctOptionIndex;

    if (isCorrect) {
      _score++;
    }

    setState(() {
      if (_questionIndex < _questions.length - 1) {
        _questionIndex++;
        selectedOptionIndex = -1; // Reset selected option
      } else {
        showResultDialog();
      }
    });
  }

  void showResultDialog() {
    String grade;
    double percentage = (_score / _questions.length) * 100;
    if (percentage >= 90) {
      grade = 'Excellent';
    } else if (percentage >= 80) {
      grade = 'Very Good';
    } else if (percentage >= 70) {
      grade = 'Good';
    } else if (percentage >= 60) {
      grade = 'Fair';
    } else if (percentage >= 50) {
      grade = 'Pass';
    } else {
      grade = 'Poor';
    }

    showDialog(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          title: Text('Quiz Result'),
          content: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              Text('Your score is $_score/${_questions.length}'),
              Text('Percentage: $percentage%'),
              Text('Grade: $grade'),
            ],
          ),
          actions: [
            TextButton(
              onPressed: () {
                setState(() {
                  _questionIndex = 0;
                  _score = 0;
                  selectedOptionIndex = -1; // Reset selected option
                });
                Navigator.of(context).pop();
              },
              child: Text('Restart Quiz'),
            ),
          ],
        );
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Quiz App'),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              _questions[_questionIndex].question,
              style: TextStyle(fontSize: 24),
            ),
            SizedBox(height: 20),
            Column(
              children: _questions[_questionIndex].options.asMap().entries.map((entry) {
                final index = entry.key;
                final option = entry.value;
                return RadioListTile(
                  title: Text(option),
                  value: index,
                  groupValue: selectedOptionIndex,
                  onChanged: (int? value) {
                    setState(() {
                      selectedOptionIndex = value!;
                    });
                  },
                );
              }).toList(),
            ),
            ElevatedButton(
              onPressed: _checkAnswer,
              child: Text('Submit Answer'),
            ),
          ],
        ),
      ),
    );
  }
}

class MCQQuestion {
  final String question;
  final List<String> options;
  final int correctOptionIndex;

  MCQQuestion(this.question, this.options, this.correctOptionIndex);
}
