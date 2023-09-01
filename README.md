# Competitive Pong

A competitive pong game.

### Controls
- Use `Z` to move up and `S` to move down.
- Press `space` to confirm

---

# Building and Development

## Informations
- Game developed using the [Raylib](https://www.raylib.com/) library.

## Prerequisites
- Ensure you have a compiler installed on your computer.
- There's no need to install Raylib separately. It is already precompiled and stored in the 'lib' folder.

## Compilation instructions

1. Open a PowerShell/cmd terminal and navigate to the project's directory.

2. Create a build directory : 
```
mkdir build
```

3. Navigate to the build directory : 
```
cd build 
```

4. Generate the makefiles:
```
cmake -G "MinGW Makefiles" ..
```

5. Compile the project : (assuming that you use the minGW compiler)   
``` 
mingw32-make 
```

5. Run the game :   
```
.\debug.exe
```
