# Competitive Pong

A competitive pong game.

### Controls
- Use `Z` to move the paddle up and `S` to move it down.
- Press `space` to restart

---

# Building and Development

## Informations
- The game is currently under development. 
- Game developed using the [Raylib](https://www.raylib.com/) library.

## Prerequisites
- Ensure you have a compiler installed on your computer.
- There's no need to install Raylib separately. It is already precompiled and stored in the 'lib' folder.

## Compilation instructions

1. Open a PowerShell/cmd terminal and navigate to the project's directory.

2. Navigate to the build directory : 
```
cd build 
```

3. Generate the makefiles:
```
cmake -G "MinGW Makefiles" ..
```

4. Compile the project : (assuming that you use the minGW compiler)   
``` 
mingw32-make 
```

4. Run the game :   
```
.\debug.exe
```
