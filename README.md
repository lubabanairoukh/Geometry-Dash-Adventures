# Geometry Dash Adventures

## Project Description
This project is an implementation of the game "Geometry Dash Adventures" developed using C++, SFML, and BOX2D. The game involves navigating a player character through various levels filled with obstacles and challenges.

## Team Members
- Lubaba Nairoukh
- Jehan Karaki 
- Hadeel Ghazawi 

## Game Description
**Geometry Dash Adventures** is a challenging and engaging game where the player controls a character that can switch between a square and a plane. The objective is to navigate through levels by jumping over obstacles and reaching the end.

## Game Mechanics
- **Jumping:** Use the "Space" button to jump.
- **Pause Mode:** Use the "P" button to pause the game.
- **Death:** The player dies upon collision with any static object except rectangle and square shapes.
- **Level Completion:** To complete a level, the player must reach the end, transitioning from a square to a plane in the second part of the level.

## Features
- **Multiple Levels:** Three levels of increasing difficulty.
- **Menu:** A main menu to start the game, get help, or quit.
- **Collision Handling:** Implemented using multi-methods and Box2D for realistic physics interactions.
- **Singleton Pattern:** Used for managing music and textures efficiently.


## Usage
- Use the "Space" button to jump.
- Use the "P" button to pause the game.
- Navigate through the levels and avoid obstacles to reach the end.

## Resources
### Files in the Game (Located in the Resource Folder)
- Fonts and images for game objects.
- Level data files: `level1.txt`, `level2.txt`, `level3.txt`.
- Music files for background and level-specific music.


## Watch the Game
You can watch a gameplay video of "Save the King" here: https://www.youtube.com/watch?v=BUthIWcyPpI


## Known Bugs
- Occasionally, the player may get stuck on stairs (rectangle shape). To resolve this, the player should jump.

## Additional Comments
The game can be challenging to play. Have fun and good luck!



## Conclusion
This project was developed using C++, SFML, and Box2D, employing object-oriented programming principles and design patterns like Singleton and Multi-methods.
