import 'package:flutter/material.dart';
import 'home.dart';
import 'favorites.dart';
import 'search.dart';
import 'profile.dart';


void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  int _selectedIndex = 0;

  void _onItemTapped(int index) {
    setState(() {
      _selectedIndex = index;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: _buildScreen(_selectedIndex),
        bottomNavigationBar: _buildBottomNavigationBar(_selectedIndex, _onItemTapped),
      ),
    );
  }

  Widget _buildScreen(int index) {
    switch (index) {
      case 0:
        return HomeScreen();
      case 1:
        return SearchScreen();
      case 2:
        return FavoritesScreen();
      case 3:
        return ProfileScreen();
      default:
        return HomeScreen();
    }
  }

  BottomNavigationBar _buildBottomNavigationBar(int selectedIndex, void Function(int) onItemTapped) {
    return BottomNavigationBar(
      currentIndex: selectedIndex,
      onTap: onItemTapped,
      items: [
        BottomNavigationBarItem(
          icon: Icon(Icons.home),
          label: 'Home',
        ),
        BottomNavigationBarItem(
          icon: Icon(Icons.search),
          label: 'Search',
        ),
        BottomNavigationBarItem(
          icon: Icon(Icons.star),
          label: 'Favorites',
        ),
        BottomNavigationBarItem(
          icon: Icon(Icons.person),
          label: 'Profile',
        ),
      ],
      backgroundColor: Colors.blue, // Background color
      unselectedItemColor: const Color.fromARGB(255, 143, 143, 143), // Color for unselected items
      selectedItemColor: Colors.black, // Color for selected item
    );
  }
}
