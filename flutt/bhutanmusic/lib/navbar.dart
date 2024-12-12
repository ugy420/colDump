import 'package:flutter/material.dart';
class CustomTabBar extends StatelessWidget {
  final TabController tabController;

  CustomTabBar({required this.tabController});

  @override
  Widget build(BuildContext context) {
    return TabBar(
      controller: tabController,
      indicatorColor: Colors.white,
      tabs: <Widget>[
        Tab(
          icon: Icon(Icons.home),
          text: 'Menu',
        ),
        Tab(
          icon: Icon(Icons.search),
          text: 'Hostel',
        ),
        Tab(
          icon: Icon(Icons.star),
          text: 'Maintenance',
        ),
        Tab(
          icon: Icon(Icons.add),
          text: 'Add Hostel',
        ),
      ],
    );
  }
}
