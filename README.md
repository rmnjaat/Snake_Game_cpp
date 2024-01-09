# Snake Game in C++ 🐍

Welcome to the Snake Game project! This simple console-based Snake Game is implemented in C++ using OOP principles and additional libraries like `conio.h` and `windows.h`.

## How to Play 🎮

1. Run the program.
2. Enter your player name when prompted.
3. Press any key to start the game.
4. Use the following keys to control the snake:
   - **W:** Move Up
   - **S:** Move Down
   - **A:** Move Left
   - **D:** Move Right

5. Eat the food (`o`) to grow and increase your score!
6. Avoid colliding with the snake's own body.

## Features 🌟

- Responsive and dynamic console display.
- Randomized food placement for each game.
- Score tracking for each player.

## Code Structure 🧱

The project is structured using Object-Oriented Programming (OOP) principles:

- **Snake Class:** Represents the snake in the game. Handles movement, direction, and collision detection.
- **Board Class:** Manages the game board, including the snake, food, and score. Handles user input and game updates.
- **Point Struct:** Represents a 2D point in the console.

## Requirements 🛠️

- C++ Compiler
- Windows Operating System (for `windows.h`)

## Compilation and Execution 🚀

```bash
g++ snake_game.cpp -o SnakeGame
./SnakeGame
```

## Enjoy the Game! 🕹️

Feel free to explore and modify the code to enhance the game further. Have fun playing and improving the Snake Game in C++! 🚀
