# filler
an algorithmic game

the algorithm is written using [taxicab geometry](https://en.wikipedia.org/wiki/Taxicab_geometry)

## short description
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

## installation
>	works for linux and mac.

run the following commands:
* download
  - clone with `--recursive` flag (there is submodule)
* compile
  - `make`
* remove objects:
  - `make clean`
* remove objects and library
  - `make fclean`
* re-compile:
  - `make re`
## usage

run the following commands:
  - `cd resources`
  - ./filler_vm `-f` path/to/map `-p1` ./path/to/player_1 -`p2` ./path/to/player_2 > don't forget give executable files permissions
