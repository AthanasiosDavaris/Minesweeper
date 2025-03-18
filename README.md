# Minesweeper in C

## Overview

This project is a C implementation of the classic Minesweeper game. The game allows players to select the size of the board and the difficulty level. Players can open cells, mark cells as potential mines, and even cheat to reveal the contents of a cell. The game ends when the player either uncovers all non-mine cells or triggers a mine.

## Features

- **Customizable Board Size**: Players can choose the number of rows and columns for the game board (minimum 8x8, maximum 16x16).
- **Difficulty Levels**: Four difficulty levels are available:
  - **Easy**, **Medium**,**Hard**,**Impossible**
- **Game Commands**:
  - **`open(x,y)`**: Opens the cell at position (x,y).
  - **`mark(x,y)`**: Marks the cell at position (x,y) as a potential mine.
  - **`cheat(x,y)`**: Reveals the contents of the cell at position (x,y) without opening it.
  - **`exit`**: Exits the game.
- **Dynamic Board Generation**: Mines are randomly placed on the board, and the numbers in the cells indicate the number of adjacent mines.
- **Recursive Cell Opening**: When a cell with no adjacent mines is opened, all adjacent cells are automatically opened.

## Authors

- **Athanasios Davaris**
- **Theodoros Triados**
