# Kandinsky

## About

**Kandinsky** is a wrapper library around the OpenGL graphics API, intended for use in 2D rendering applications. 
Kandinsky provides a simple, abstracted interface to the OpenGL API written in C++, combined with a lightweight wrapper around GLFW, to provide methods for window management and event listening.
It also takes full advantage of the unique features C++ has to offer, including a true object oriented model that better represents the structure of an OpenGL application as well as a proper error handling system and more intuitive, modernized design.

## Using Kandinsky

**It is highly recommended to use [CMake](https://cmake.org) to build your Kandinsky project.**
If you would like to use another method, you can download the precompiled library from the [Releases](https://github.com/ElizaDoesStuff/Kandinsky/releases) page.

### Getting started

You can start by adding Kandinsky to your project directory either by downloading and extracting an archive from the [Releases](https://github.com/ElizaDoesStuff/Kandinsky/releases) page or using `git submodule add --recursive https://github.com/ElizaDoesStuff/Kandinsky`
If you are using a precompiled library file, simply download it from the [Releases](https://github.com/ElizaDoesStuff/Kandinsky/releases) page and place it somewhere in your project directory.

#### Using CMake **(Recommended)**

Kandinsky comes with ready-made CMake build scripts, designed for ease of use. To build the library with CMake and link with your executable or library, add the following lines to your `CMakeLists.txt`:

```CMake
add_subdirectory( /path/to/Kandinsky )
target_link_libraries( your_target_name Kandinsky.library )
```

Kandinsky header files can be included with the following line:

```cpp
#include <Kandinsky/Header.h>
```