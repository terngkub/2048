# ft_contrast
École 42 assignment in C - "2048" game

### About this project
* This is a Rushes project at [École 42](https://42.fr)
* Rushes project is a 2 days group project on weekend incremented to a normal school curriculum.
* My teammate is [Strix0x2A](https://github.com/Strix0x2A)
* The objective of this project is to create a "2048" game in C language with ncurses GUI library.
* I work on ncurses and my teammate work on the game algorithm.

[!2048](/screenshot/screenshot1.png?raw=true)

### How to run the program
* Run make command, this will create an executable file.
	```
	make
	```
* To start the game
	```
	./game_2048
	```

### About the game
* The objective of the game is to combine the numbers until you get 2048.
* Press ARROW key to move every pieces in the direction that you press all the way to the border.
* If the same numbers crash together, they will combine into one bigger number.
* Each turn, the program will randomly create a new piece of the value 2 or 4.
* The game will end when there is no move left.
* The game records high score. You can play again or restart the game to create a new record. However, if you close the program, your highscore will be gone.
* There are 2 levels. 5x5 for an easy one and 4x4 for a harder one.

[!2048](/screenshot/screenshot2.png?raw=true)
