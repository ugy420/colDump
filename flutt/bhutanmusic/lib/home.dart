import 'package:flutter/material.dart';

class HomeScreen extends StatefulWidget {
  @override
  _HomeScreenState createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  final List<Map<String, dynamic>> genres = [
    {
      'name': 'Pop',
      
    },
    {
      'name': 'Rock',
      
    },
    {
      'name': 'Hip-Hop',
      
    },
    {
      'name': 'Other',
    },
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Music Library'),
      ),
      body: GridView.builder(
        gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(
          crossAxisCount: 2, // Number of columns
        ),
        itemCount: genres.length,
        itemBuilder: (context, index) {
          return GenreCard(
            genreName: genres[index]['name'],
            genreImage: genres[index]['image'],
          );
        },
      ),
    );
  }
}

class GenreCard extends StatelessWidget {
  final String genreName;
  final String genreImage;

  GenreCard({required this.genreName, required this.genreImage});

  @override
  Widget build(BuildContext context) {
    return Card(
      margin: EdgeInsets.all(16),
      child: InkWell(
        onTap: () {
          // Navigate to the list of songs for this genre
          Navigator.push(
            context,
            MaterialPageRoute(
              builder: (context) => GenreSongsScreen(genreName: genreName),
            ),
          );
        },
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Image.asset(
              genreImage,
              width: 120,
              height: 120,
            ),
            Text(
              genreName,
              style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
            ),
          ],
        ),
      ),
    );
  }
}

class GenreSongsScreen extends StatelessWidget {
  final String genreName;

  GenreSongsScreen({required this.genreName});

  @override
  Widget build(BuildContext context) {
    // You can implement the songs list for a specific genre here
    return Scaffold(
      appBar: AppBar(
        title: Text(genreName + ' Songs'),
      ),
      body: Center(
        child: Text('List of Songs for $genreName'),
      ),
    );
  }
}

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: HomeScreen(),
    );
  }
}
