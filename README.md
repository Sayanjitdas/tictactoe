# tictactoe
This is a simple tictactoe game build with pure c++

Tic Tac Toe
------------

Write the game of Tic Tac Toe. It's a game with a 3 by 3 grid played by 2 players. 
One player places O markers and the other player places X markers. Each player takes 
turns placing his/her marker in order to get 3 of their markers to line up on the board. 
A player wins when 3 or their markers line up either horizontally, vertically or diagonally. 
If no player has their markers line up in that fashion, and the board is full, then the 
game is called a "Cat Game". Your program should output the winner of the game or "Cat Game" 
if there was no winner. The user should be prompted if they would like to play again when the 
game is over. If they choose to play again, the player who started second last game should go first.

steps of approaching the problem..

Step - 1
--------

do {
	
	SelectPlayer();
	PlayTheGame();

}while(WantToPlayAgain())

Step - 2
--------

PlayTheGame(){
	boardgrid[BOARD_GRID_SIZE] = {'0','1','2','3','4','5','7','8','9'};
	activePlayer; 
	activePlayerID;
	chances;
	playerInput;
	DrawTheBoard();
	
	do{
		GetPlayerInput();
		UpdateBoard();
		DrawBoard();
	}while(GameIsNotOver())

	DisplayWinner();

}

Step - 3
--------

SelectPlayer(){
	
	if playerOne == 'X'
		playerOne = 'O'
		playerTwo = 'X'
	else if playerOne == 'O'
		playerOne = 'X'
		playerTwo = 'O'
	else:
		playerOne = 'X'
		playerTwo = 'O'
}

Step - 4
--------

DrawTheBoard(){
	
	print out the board onscreen with valid positions and values
	 0 | 1 | 2
	---+---+---
	 3 | 4 | 5
	---+---+---
	 6 | 7 | 8

}

Step - 5
--------
GetPlayerInput(){
	
	will get the input of the active player in the mentioned grid number
	return the grid number and player 
}


Step - 6
--------

UpdateBoard(){
	update the grid 
}

Step - 7
--------

GameIsNotOver(){
	
	CheckCombinations()
	return True while no combinations is satisfied else false

}

Step - 8
--------
	 0 | 1 | 2
	---+---+---
	 3 | 4 | 5
	---+---+---
	 6 | 7 | 8

	 Combinations (grid numbers)
	 --------------
	 1. 0 == 1 == 2
	 2. 3 == 4 == 5
	 3. 6 == 7 == 8
	 4. 0 == 3 == 6
	 5. 1 == 4 == 7
	 6. 2 == 5 == 8
	 7. 0 == 4 == 8
	 8. 2 == 4 == 6

