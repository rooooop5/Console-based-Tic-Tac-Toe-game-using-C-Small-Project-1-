# Author: rooooop5(github name)


# Tic-Tac-Toe (Console Game)

This is a console-based Tic-Tac-Toe game written in C.

## Features
- 2-player local gameplay
- Input validation
- Score tracking for best of N rounds
- Clear board display with position guide

## How to Compile and Run
1. Compile the game:gcc game.c -o game
2. Run: ./game

## 🧩 Overview

Two players take turns marking positions (`1–9`) on a 3x3 grid.

* Player 1 → `X`
* Player 2 → `O`

The game continues until one player wins (three in a row horizontally, vertically, or diagonally) or all boxes are filled (draw).

The game can be played for **multiple rounds**, and the final winner is decided based on the number of wins.

---

## 🧠 Functions Breakdown

### 1. `int main()`

**Purpose:**
Entry point of the program. Calls the `run()` function.

---

### 2. `int run()`

**Purpose:**
Handles the overall game loop.

* Asks the user if they want to play.
* Prompts for number of rounds (`best of N`).
* Calls `best_of_N(N)` to start.
* Repeats if the player chooses to play again.

**Returns:**
`0` after exiting.

---

### 3. `int round_inputter()`

**Purpose:**
Prompts the user to enter the number of rounds (N) for a "best of N" series.
**Returns:** the number of rounds entered.

---

### 4. `void best_of_N(int N)`

**Purpose:**
Runs the game for `N` rounds and keeps score of wins for each player.

**Parameters:**

* `N` → Number of rounds.

**Behavior:**

* Calls `game()` each round.
* Tracks wins for both players.
* Displays the overall series winner or declares a draw.

---

### 5. `char game()`

**Purpose:**
Runs one full round of Tic-Tac-Toe.

**Behavior:**

* Initializes a 3x3 board.
* Alternates turns between players.
* Displays the board after each move.
* Calls `decider()` to check for game-over conditions.
* Returns the winning symbol (`'X'`, `'O'`, or `' '` for draw).

---

### 6. `void format_printer()`

**Purpose:**
Prints a reference layout of positions (1–9) corresponding to board cells.
Used to help players know where to place their mark.

---

### 7. `void board_printer(char board[][3])`

**Purpose:**
Prints the current Tic-Tac-Toe board in a formatted grid style.

**Parameters:**

* `board` → 3x3 character array representing the board state.

---

### 8. `void write_in_posn(char board[3][3], int* boxes_filled, char entry)`

**Purpose:**
Handles user input for position selection and updates the board.

**Parameters:**

* `board` → Game board.
* `boxes_filled` → Pointer to number of filled cells.
* `entry` → `'X'` or `'O'` (the symbol to be placed).

**Behavior:**

* Takes numeric input (1–9).
* Validates it (rejects invalid or already occupied cells).
* Updates the board if valid.

---

### 9. `void get_index(int posn, int* row, int* col)`

**Purpose:**
Converts a position number (1–9) to board indices `[row][col]`.

**Parameters:**

* `posn` → Position number (1–9).
* `row`, `col` → Pointers to store computed row and column indices.

**Example:**
`posn = 5` → `row = 1`, `col = 1`

---

### 10. `char decider(char board[3][3], int* boxes_filled, int* game_over)`

**Purpose:**
Determines whether the game should continue, end, or declare a draw.

**Parameters:**

* `board` → Current board state.
* `boxes_filled` → Number of filled cells.
* `game_over` → Pointer to flag that indicates if the round is finished.

**Returns:**

* `'X'` → Player 1 wins.
* `'O'` → Player 2 wins.
* `' '` → Draw.
* `'N'` → No winner yet.

---

### 11. `char who_won(char board[3][3], int* game_over)`

**Purpose:**
Checks if any player has won after a move.

**Parameters:**

* `board` → Game board.
* `game_over` → Pointer to flag marking the end of the game.

**Returns:**
Winning symbol (`'X'` or `'O'`) if any, otherwise `' '`.

---

### 12. `char win_checker(char board[][3])`

**Purpose:**
Evaluates all 8 possible win conditions.

**Parameters:**

* `board` → 3x3 array representing the game board.

**Checks:**

* 3 rows
* 3 columns
* 2 diagonals

**Returns:**
Winning symbol (`'X'` or `'O'`) if found, otherwise `' '`.

---

## 🕹️ Example Run

```
This program is a game of tic-tac-toe. Do you wanna play?(y/n): y
You wanna play this game as best of how many rounds?: 3
This is round 1.

Refer to this table to know what number corresponds to what posn in the tic tac toe table.

 1 | 2 | 3 
---+---+---
 4 | 5 | 6 
---+---+---
 7 | 8 | 9 

Player One's turn to enter :5
Player Two's turn to enter :1
...
Player one wins
Player one wins 2 - 1.
Do you wanna play again?(y/n): n
Exiting program.
```

---

## ⚙️ Notes

* Handles invalid and non-numeric input safely.
* Prevents overwriting already occupied positions.
* Displays the board and position guide clearly.
* Allows multiple rounds for extended play.

---

## 🧑‍💻 Author

**Saswata Mondal**

A simple yet solid implementation of Tic-Tac-Toe using pure C — modular, readable, and fun to play!
