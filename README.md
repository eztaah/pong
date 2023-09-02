<div align="center">

Pong
=========
"A classic Pong game where your goal is to score as high as possible against an unbeatable bot."

Use `Z`, `S` and `Space` keys to move inside the menu.



## Download the game

<a href="ttps://github.com/EzTaah/pong/releases/download/v1.1/pong-for-windows.zip"> <img src="https://github.com/EzTaah/pong/blob/main/datasrc/assets/logo/logo.png?raw=true" height=70 hspace=1> </a>
<br undefined>
<br undefined>
<br undefined>
<br undefined>
</div>

---

# Building on Windows with MinGW & CMake

Open a PowerShell terminal and navigate to the project's directory.
Next, run these commands

```
mkdir build
cd build 
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
mingw32-make 
```
 