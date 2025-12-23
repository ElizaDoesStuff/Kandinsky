# Kandinsky

## About

**Kandinsky** is a wrapper library for the OpenGL graphics API, intended for use in 2D rendering applications. 
Kandinsky provides a simple, abstracted interface to the OpenGL API written in C++, combined with a lightweight wrapper around GLFW, to provide methods for window management and event listening.
It also takes full advantage of the unique features C++ has to offer, including a true object oriented model that better represents the structure of an OpenGL application as well as a proper error handling system and a more intuitive, modernized design.

## Using Kandinsky

Kandinsky uses [CMake](https://cmake.org) to generate build files. **This is the easiest way to use Kandinsky in your project.**
If, for whatever reason, you would not like to use CMake, you can also download the precompiled binaries from the 
[Releases](https://github.com/ElizaDoesStuff/Kandinsky/releases) page use the appropriate methods to link it with your project.

### Steps for linking with CMake

#### 1. Download the Kandinsky source files

##### Using `git submodule add`

If your project is a git repository (which it really should be), you can use `git submodule add https://github.com/ElizaDoesStuff/Kandinsky` to add Kandinsky as a submodule in your project repo.

##### Using GitHub releases

Alternatively, you can download the source code as an archive from the Releases page. You can then extract the archive and place it somewhere in your project directory.

#### 2. Edit CMakeLists.txt

To actually link your project with Kandinsky, you will have to edit the **CMakeLists.txt** for your project. Thanks to the CMake scripts included with the library, you can perform the linking with just two lines:

```cmake
add_subdirectory( /path/to/Kandinsky )
target_link_libraries( your_project_target Kandinsky.library )
```

#### 3. Build your project!