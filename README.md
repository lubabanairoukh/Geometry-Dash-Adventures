
# Circle the Cat Game

## Project Description
This project is an implementation of the "Circle the Cat" game. The game is a puzzle genre where the player is presented with a board of tiles (circles) containing "blocked tiles" (dark circles) and "empty tiles" (light circles). The cat can only move on empty tiles, and the player must surround the cat on all sides by "filling in the tiles" to prevent it from escaping.

You can find a demonstration of the game here: [Circle the Cat](https://www.crazygames.com/game/circle-the-cat).

## Game Objective
The objective of the game is to surround the cat completely so that it cannot move, thereby preventing it from escaping the board.

## Game Rules
- The game is a turn-based game between the player and the computer.
- The player selects a tile to block by clicking on the desired circle.
- The computer moves the cat to try to escape the board.
- If the cat reaches the edge of the board, it escapes and wins the game.
- If the player successfully surrounds the cat, the player wins.
- The player must completely surround the cat; merely blocking it in a certain area is insufficient.

## Implementation Details
- **Smooth Gameplay:** The game must be smooth and responsive, with no lag or freezing.
- **Multiple Levels:** The game includes at least three levels of increasing difficulty, each with an 11x11 tile board.
- **Win/Lose Messages:** Display messages for winning or losing and move to the next level or retry the same level accordingly.
- **Click Counter:** Display the number of clicks made by the player.
- **Randomized Levels:** Levels are generated automatically with blocked tiles, ranging from 14 blocked tiles (easy) to 4 blocked tiles (hard).
- **Undo Button (Bonus):** An undo button that undoes the last move, allowing multiple undos back to the start of the game.

## Data Structures and Algorithms
- **Graph Representation:** The board is represented as a graph, with tiles as nodes and edges between adjacent tiles.
- **Pathfinding Algorithms:** Algorithms like BFS or DFS are used to determine the cat's movements, aiming to find the shortest path to the board edge or escape the blocked area.

## Technologies Used
- **C++:** Core programming language.
- **SFML:** Graphics and sound library.
- **Object-Oriented Programming:** Inheritance, polymorphism.
