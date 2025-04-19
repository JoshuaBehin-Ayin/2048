# 2048 (C++ OOP Edition)

This is a command-line version of the classic **2048 puzzle game**, written in **C++** using **Object-Oriented Programming principles**. The game is structured to demonstrate **inheritance**, **composition**, and **polymorphism**, and includes core mechanics like score tracking, high score saving, and win/loss detection.

## 🎮 Game Features
- Play 2048 using your keyboard's arrow keys (detected via ASCII escape sequences)
- Automatically checks for valid moves and ends when no moves are possible
- Win the game by reaching the 2048 tile
- Score, high score, and move counter display

## 🧱 OOP Design
- **Inheritance**: Movement logic is separated into derived classes (`Up`, `Down`, `Left`, `Right`) inheriting from a base `Movement` class.
- **Composition**: The `Grid` class manages a 2D array of tile values and composes the main game state.
- **Polymorphism**: Movement classes override a `moveTiles()` function, enabling runtime behavior depending on the user's input.
