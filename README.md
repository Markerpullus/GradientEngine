# Gradient
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