# Unreal Infinite Runner Assignment

### Improvements since part one
- Added support for two characters using a modified character controller [commit](https://github.com/RainCatalyst/InfiniteRunner/tree/450bae1a98d420a846f4534f541585404ef628bd)
- Added extra logic for dodging obstacles using a tag system for hitboxes
[commit](https://github.com/RainCatalyst/InfiniteRunner/tree/8ae527f012fa5d4642252bf1106867f0571deb3a)
- Added health tracking logic, a simple healthbar and a game over screen
[commit](https://github.com/RainCatalyst/InfiniteRunner/tree/8ae527f012fa5d4642252bf1106867f0571deb3a)
- Fixed incorrectly assigned input bindings for keyboard and antialiasing issues
[commit](https://github.com/RainCatalyst/InfiniteRunner/tree/cb8a85ed4753b6cd3e6920f742414cfa9a300f1d)

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