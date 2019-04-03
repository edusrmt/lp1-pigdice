# Introduction

This programming project implements a simple clone of the popular game **Pass the Pig**&copy; and **PigMania**&copy;.

The main objective with this assignemnt is to introduce separate compiling, progressive programming (small versions towards the final full-fledged program), as well as to provide an oportunity to develop a project using the tools already taught such as git, gdb, and doxygen.

Another objective is to demonstrate the importante of modular programming.
For that, I'm planning a Pig's tournment where each programming team's IA plays against other teams.
For that to happen, the programming teams should write code that strictly complies with the project specifications.


# The Gameplay

Pig is a folk jeopardy dice game described by John Scarne in 1945, in which two players compete to reach **100 points** first.

<!-- Each turn one of the players rolls the dice until one of these two conditions happen: -->
<!-- The game is organized in turns. Each turn, one of the players rolls the dice and (temporarily) accumulates the face points until one of these two conditions happen: -->

<!--The game is organized in turns. Each turn, one of the players rolls the dice and the face points are accumulated into a __turn total__. The same player continues to roll the dice until one of these two conditions happen:
Each turn, the same player keeps rolling the dice and the face points are accumulated into a __turn total__.-->
The game is organized in turns. Each turn, the same player keeps rolling the dice, while the face points are accmulated into a __turn total__, until one of these two conditions happen:

<!-- accumulated sum of the rolls for that turn; this is called **the turn total**. -->
1. The current player decides to _hold_, in which case s/he scores the **turn total**; or,
2. The face  &#9856;, (the pig) is rolled, in which case the current player scores nothing.

In both cases, the **turn total** is set to zero and it becomes the opponent's turn.
    
<!-- In short, any time during a player's turn, s/he is faced with two decisions or *actions*: -->
In summary, any time during a player's turn, s/he must take one of these two *actions*:

* **Roll** the dice, which may produce:
    - Face &#9856;: the player scores nothing and it becomes the opponent's turn;
    - Faces &#9857;, &#9858;, &#9859;, &#9860;, or &#9861;: the face point is added to the **turn total** and the player's turn continues.
* **Hold**
    - The _turn total_ is added to the player's overall score and it becomes the opponent's turn.

The player who scores **100** or more points at the end of a turn is the winner.

<!-- The game ends if, at the end of a turn, one of the player scores **100** or more points. -->

# TODO

- [X] Write a basic simulation.
- [ ] Create the game loop.

# Authorship

Program developed by Carlos Eduardo Alves Sarmento  (< *edusrmt@gmail.com* >) and Victor Raphaell Vieira Rodrigues  (< *victor@agenciaatwork.com* >), 2019.1

&copy; IMD/UFRN 2019.

