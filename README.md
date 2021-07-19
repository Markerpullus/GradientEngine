# Gradient
![C++](https://img.shields.io/badge/language-C%2B%2B-%23f34b7d.svg?style=plastic)
![x86](https://img.shields.io/badge/arch-x64-red.svg?style=plastic)

A 2D and 3D game engine built from scratch with c++ and opengl by ya boy Markerpullus  
The project is designed to be cross-platform with premake, yet it is at its early stage and primarily targeted towards Win64 (my workstation).

## To generate visual studio files
```powershell
PS> cd GradientEngine
PS> .\vendor\Premake\premake5.exe vs2019
```

## Directory Structure
```
.
├── Gradient
│   ├── src
│   │   └── Gradient
│   │       ├── Core
│   │       ├── EventSystem
│   │       ├── Math
│   │       ├── Rendering
│   │       │   ├── Camera
│   │       │   └── Model
│   │       ├── Scopes
│   │       └── Shaders
│   └── vendor 				# Third Party Depedencies
└── TestGame
    └── src
```