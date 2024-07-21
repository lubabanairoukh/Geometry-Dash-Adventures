================================================================================

OOP, Final project

by: lubaba nairoukh , id:211559901
    jehan karaki , id:212500102
    hadeel ghazawi, id:207535212
================================================================================

Description
===========
we built the game Geometry Dash Adventures with C++ using "SFML"and "BOX2D". 

instructions
============

joystick:


use "Space" button to jump.
use "P" for  PauseMode.


kill/ die:

in collision between player and any static object expect rectangle shapes and square shapes 


Complete level:
In order to complete a level the player needs to reach the end of the level, the level is divided to two parts, one of the part the player be square and he change 
to be a plane in the end of part two the level finish.


================================================================================
We used: Singleton(Music,Texture),  Multimethod

================================================================================
List of files
Main classes:
1) MenuGame.cpp – the purpose of this class is to have a menu in which the player can choose if he wants to play, get help or quit.
   it runs in the GameController function.

2) GameController.cpp - runs the game after the play option and player character is chosen, runs all controls, buttons and all the game objects and to activate other game classes as well.

3) Board.cpp– the purpose of this class is to have a game board in which all Static objects will appear and interact with each other.
4) Texture.cpp  – it's purpose is to load the images and sound files.

5) CollisionHandlling.cpp - the multi methods map class, stores all collision functions in a map and instanciates them only once when used like in singelton.
6) Oncollision.cpp -  class of collision of Box2D that take all the collision of the game and declay which two object had been collide and acctivate the    CollisionHandlling class.
7) GameObject - the abstract base class to store gameobjects and their functions for polymorphism.
8) Levels.cpp- class That declay which level the player will choose to play, there are three levels in the game, and each level harder than others;
9) StaticObject - a derived class from the abstract base class "gameObject " to store the static game objects such as "Rectangle, Triangle,Floor, etc.." and their functions for polymorphism.
10) Player.cpp - a derived class from GameObject class, it defines the specific Player and sets it's functions acordingly.

11)Texture.cpp- This class is a singleton responsible for loading the textures, and font. The decision to make this class a singleton was so it can be easily accessed from every class in the project. 
12) Music.cpp - This class is a singleton responsible for loading the music for the levels, foe each level there is a specific music, and for the main menu there is a different music.

14) Floor.cpp - a derived class from StaticObject class, it defines the specific StaticObject as Floor and it's functions acordingly.
15) Rectangle.cpp - a derived class from StaticObject class, it defines the specific StaticObject as Rectangles shapes and it's functions acordingly.
16) Triangle.cpp - a derived class from StaticObject class, it defines the specific StaticObject as Convexshapes shapes and it's functions acordingly.
17) Portal.cpp - a derived class from StaticObject class, it defines the specific StaticObject as Portal and it's func tions acordingly.(if the player collide with it the part two of the game start).

18)Thorns.cpp - a derived class from StaticObject class, it defines the specific StaticObject as Thorns and it's functions acordingly, if the player touch it, it will lose.

19)Doublejump.cpp - a derived class from StaticObject class, it defines the specific StaticObject as a circle shape and it's functions acordingly, if the player touch it, it will jump double jump.

20)utils.cpp - a class that converts sfml coordinates  to box2d coordinates.

21)WinTheGame.cpp - the purpos of this class is to open a new window to the user when he win the level so he chose to exit the game or return to the main menu;

22)Define.h - represents all the constant declarations and enum classes declared in the project.


=====================================================
Files in the game: (All located in Resource folder)

Font
all game object images.
level1.txt ,level2.txt ,level3.txt
songs for the music.
=====================================================

Data bases:

we used different data bases for different uses, like array, vector, map, pair

Main data bases:
 
m_board- vector of all static objects, located in Board.

=====================================================

Known bugs:
sometimes the player stuck when he is on the stairs (rectangle shape - static object) so you can out from this , you should jump.
=====================================================
Comment:
hard to play the game, have fun ^_^