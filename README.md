
# ♟️ Chess Game in C++

This is a fully object-oriented chess game implemented in C++.  
It uses modular classes to represent different chess pieces, the board, and the game logic, with basic graphical support via a custom `chessGraphics` library.

---

## 🎯 Features
- OOP structure: Base `Piece` class + derived classes (`King`, `Queen`, `Bishop`, etc.)
- Valid move logic for each piece
- Turn-based play
- Board state management
- Custom lightweight graphics interface (`chessGraphics`)

---_

## 🧠 Skills Demonstrated
- C++ object-oriented programming and polymorphism
- Clean modular file structure with `.h` and `.cpp` separation
- Use of external graphics library
- Visual Studio project management (`.vcxproj`)

---

## 📁 Project Structure

```
├── Bishop.cpp / Bishop.h
├── Board.cpp / Board.h
├── King.cpp / King.h
├── Knight.cpp / Knight.h
├── Queen.cpp / Queen.h
├── Rook.cpp / Rook.h
├── Pawn.cpp / Pawn.h
├── Piece.cpp / Piece.h
├── NullPiece.cpp / NullPiece.h
├── ChessException.cpp / ChessException.h
├── chessGraphics/          # Graphics rendering interface
├── Debug/                  # Output folder (ignored in GitHub)
├── Source.cpp              # Main game loop
├── stdafx.cpp / stdafx.h   # Precompiled headers
├── Chess.vcxproj files     # Visual Studio project settings
```

---

## 🚀 How to Run

1. Open the solution in **Visual Studio**
2. Build the project (Debug or Release)
3. Run the executable

> Not using Visual Studio? You can set up a `Makefile` or use `g++` to compile manually.

Example:
```bash
g++ Source.cpp *.cpp -o chessGame
```

---

## 📌 Notes
This project was developed as a personal challenge to build a working chess game from scratch using C++.

### Potential Improvements:
- Full rules (check, checkmate, stalemate)
- Save/load game functionality
- Online multiplayer
- Better graphics interface

---

## 👤 Author

Developed by a second-year Software Engineering student at Braude College,  
, with high motivation, strong self-learning ability, and love for challenges and building things from scratch.
