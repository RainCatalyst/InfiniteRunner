# Unreal Infinite Runner Assignment

### Project Structure
The game is composed out of 3 main systems:
- Player controller and pawn - responsible for receiving input, moving the character and reacting to collision events
- Game mode - responsible for global game parameters, acceleration logic and health tracking
- Spawners - responsible for spawning various objects (including floor, decorations and obstacles) within the level based on the distance passed

### Features implemented in C++:
- Player controller and player pawn with basic lane movement
- A custom game mode containing global parameters and functions (such as the number of lanes, lane width and speed)
- A custom component (ScrollComponent) responsible for moving the owner with the level
- A base Obstacle class responsible for handling obstacle interactions
- A base ObjectSpawner class responsible for spawning objects within the level

Features extended in blueprints:
- ObjectSpawner can be further inherited to allow custom spawning logic
- Character and GameMode are customizable in blueprints
- Obstacle class can be inherited to add various obstacle logic