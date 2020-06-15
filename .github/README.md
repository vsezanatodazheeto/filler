# Filler
An algorithmic game.

The algorithm is written using [taxicab geometry](https://en.wikipedia.org/wiki/Taxicab_geometry).

## Short description
"Filler is an algorithmic game which consists in filling a grid of a known size in advance
with pieces of random size and shapes, without the pieces being stacked more than one
square above each other and without them exceeding the grid. If one of these conditions
is not met, the game stops."
- everything happens using a virtual machine through which players will interact
- two players take part (it can be one player on two sides of the barricade)
- each successfully placed piece yields a number of points, and has only one player
- the goal of the game could be to get the best score possible
- each player has for the purpose of placing as many pieces as possible while attempting to prevent his opponent from doing the same
- at the end of the game, the one with the most points wins the match

![](https://github.com/vsezanatodazheeto/img/blob/master/filler/ex_1.png)

## Bonuses
There is a visualization written using with [SDL2](https://www.libsdl.org/index.php).

![](https://github.com/vsezanatodazheeto/img/blob/a26005a1755ff43f31a7e8c9aeed635ad745ab9f/filler/ex_2.png)

## Installation
>	Works for Linux and Mac OS.

Run the following commands:
* download
  - clone with `--recursive` flag (there is submodule)
* compile
  - `make`
* compile visualization
  - `make vis`
  
## Usage
Run the following commands:
  > Don't forget to give executable files permissions.
  
  > When you compile files will be automatically copied to resources directory (yshawn.filler, vis).
  ```
  cd resources/
  ```
  ```
  ./filler_vm -f path/to/map -p1 ./path/to/player_1 -p2 ./path/to/player_2
  ```
  For example:
  
  `./filler_vm -p1 ./players_linux/superjeannot.filler -p2 ./yshawn.filler -f maps/map00`
## How to run visualization
  If you are using Linux, you have to install sdl2 packages.
  
  For debian 10: `libsdl2-dev libsdl2-image-2.0-0 libsdl2-mixer-2.0-0 libsdl2-ttf-2.0-0`
  
  For ubuntu 20.04: `libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev`
 
  ```
  cd resources/
  ```
  ```
  ./filler_vm -f path/to/map -p1 ./path/to/player_1 -p2 ./path/to/player_2 | ./vis
  ```
  ```
  control:
  ESC                 exit
  SPACE               resume/pause
  R                   replay
  left/right button   back/forward (works only from pause)
  top/bottom button   change speed
  N                   mute music 
  ```
  For example: 
  
  Linux:
  
  `./filler_vm -f maps/map01 -p1 ./players_linux/superjeannot.filler -p2 ./yshawn.filler | ./vis`
  
  Mac OS:
  
  `./filler_vm -f maps/map01 -p1 ./players_mac/superjeannot.filler -p2 ./yshawn.filler | ./vis`
