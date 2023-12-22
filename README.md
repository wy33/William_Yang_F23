# Coconut Falls on Seal Game

William Yang

Professor Pavel Shostak

CSCI 39541

## Game Rules:

- Coconuts will fall from the sky, if you get hit, the game ends
- You control the seal and can move left or right using the `<` and `>` keyboard buttons
- Keep dodging the coconuts to increase your score

## Controls:

- `<` button:	move left
- `>` button:	move right

## Features:

- Coconut spawning position is random
- Coconut spawning is random (determined by a rate)
- Type of coconut (brown or green) get chosen at random when spawning
- Speed of a coconut is random (determined by difficulty)
- A timer exists and will determine difficulty (increases every 20 seconds), increasing the spawn rate of coconuts and the speed range of the coconuts
- A counter on the top right corner exists to keep track of score, successfully dodging coconuts increments the score (coconuts go off screen)
- The counter's position and length is dynamic, being able to contain as many digits as an integer can hold and should be able to adjust to a change in screen size
- If a collision is detected, a "GAME OVER" screen appears and the game stops (you can still see the game and score, but everything stops and you can only close the window)
- The seal (you) cannot go off screen

## Cloning:

`git clone --recursive https://github.com/wy33/William_Yang_F23.git`

**CMake required to build**

**(My settings)**

Configure Settings:
- Visual Studio 17 2022
- Use default native compilers

Generate Settings:
- GLFW_BUILD_WIN32
- GLFW_INSTALL
- USE_MSVC_RUNTIME_LIBRARY_DLL
