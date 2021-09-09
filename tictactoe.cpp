// tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
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

*/

#include <iostream>
#include "utils.h"
using namespace std;

//Function declaration
void SelectPlayer(char& playerOne, char& playerTwo);
bool GameIsNotOver(const char* boardgrid,int& chances);
bool WantToPlayAgain();
void PlayTheGame(const char& playerOne, const char& playerTwo);
void DrawBoard(const char* boardgrid);
int GetPlayerInput(char playerOne,int player,const char* boardgrid);
void UpdateBoard(const int playerInput, const int activePlayer, char* boardgrid);
bool CheckCombination(const char* boardgrid);
void DisplayWinner(const int activePlayer, const int& chances);

char PLAYER_ONE = ' ';
char PLAYER_TWO = ' ';
const int BOARD_GRID_SIZE = 9;

int main(void)
{
	char& playerOne = PLAYER_ONE;
	char& playerTwo = PLAYER_TWO;
	do {
		SelectPlayer(playerOne, playerTwo);
		cout << "Player 1: " << playerOne << endl;
		cout << "Player 2: " << playerTwo << endl << endl;

		PlayTheGame(playerOne,playerTwo);

	} while (WantToPlayAgain());
}

void SelectPlayer(char& playerOne, char& playerTwo) {

	if (playerOne == 'X') {
		playerOne = 'O';
		playerTwo = 'X';
	}
	else if (playerOne == 'O') {
		playerOne = 'X';
		playerTwo = 'O';
	}
	else {
		playerOne = 'X';
		playerTwo = 'O';
	}
}

void PlayTheGame(const char& playerOne, const char& playerTwo) {

	char boardgrid[BOARD_GRID_SIZE] = {'0','1','2','3','4','5','6','7','8'};
	char activePlayer = playerTwo; //so that first player is selected..
	int activePlayerID = 2;
	int chances= BOARD_GRID_SIZE;
	int& chancesRef = chances;
	int playerInput;
	DrawBoard(boardgrid);
	
	do {

		//swapping players
		if (activePlayer == playerOne) {
			activePlayer = playerTwo;
			activePlayerID = 2;
			playerInput = GetPlayerInput(activePlayer, activePlayerID, boardgrid);
		}
		else {
			activePlayer = playerOne;
			activePlayerID = 1;
			playerInput = GetPlayerInput(activePlayer, activePlayerID, boardgrid);
		}
		
		UpdateBoard(playerInput, activePlayer, boardgrid);
		DrawBoard(boardgrid);

	} while (GameIsNotOver(boardgrid,chancesRef));

	DisplayWinner(activePlayerID,chancesRef);
}


void DrawBoard(const char* boardgrid) {
	
	clearScreen();
	cout << " " << boardgrid[0] << " | " << boardgrid[1] << " | " << boardgrid[2] << endl;
	cout << "---+---+---" << endl;
	cout << " " << boardgrid[3] << " | " << boardgrid[4] << " | " << boardgrid[5] << endl;
	cout << "---+---+---" << endl;
	cout << " " << boardgrid[6] << " | " << boardgrid[7] << " | " << boardgrid[8] << endl;
	cout << endl;
}

int GetPlayerInput(char activePlayer,int player,const char* boardgrid) {

	bool failure;
	int playerInput;
	cout << "PLAYER " << player << ": (" << activePlayer << ")" << endl;
	do {
		failure = false;
		playerInput = GetIntInput("Enter an available grid number", "Input Error!! Enter an integer (grid number)");
		
		if (playerInput >= BOARD_GRID_SIZE) {
			cout << "Wrong grid!! please enter an available grid shown on board." << endl;
			failure = true;
		}
		else if (boardgrid[playerInput] == 'X' || boardgrid[playerInput] == 'O') {
			cout << "Wrong grid!! please enter on available grid which has no 'X'/'O' in it.." << endl;
			failure = true;
		}

	} while (failure);
	
	return playerInput;
}

void UpdateBoard(const int playerInput,const int activePlayer, char* boardgrid){

	boardgrid[playerInput] = activePlayer;

}

bool CheckCombination(const char* boardgrid) {
	//Combinations(grid numbers)
	//	--------------
	//	1. 0 == 1 == 2
	//	2. 3 == 4 == 5
	//	3. 6 == 7 == 8
	//	4. 0 == 3 == 6
	//	5. 1 == 4 == 7
	//	6. 2 == 5 == 8
	//	7. 0 == 4 == 8
	//	8. 2 == 4 == 6
	//-------------------

	bool gameNotOver = true;

	if (boardgrid[0] == boardgrid[1] && boardgrid[1] == boardgrid[2]) {
		gameNotOver = false;
	}
	else if (boardgrid[3] == boardgrid[4] && boardgrid[4] == boardgrid[5]) {
		gameNotOver = false;
	}
	else if (boardgrid[6] == boardgrid[7] && boardgrid[7] == boardgrid[8]) {
		gameNotOver = false;
	}
	else if (boardgrid[0] == boardgrid[3] && boardgrid[3] == boardgrid[6]) {
		gameNotOver = false;
	}
	else if (boardgrid[1] == boardgrid[4] && boardgrid[4] == boardgrid[7]) {
		gameNotOver = false;
	}
	else if (boardgrid[2] == boardgrid[5] && boardgrid[5] == boardgrid[8]) {
		gameNotOver = false;
	}
	else if (boardgrid[0] == boardgrid[4] && boardgrid[4] == boardgrid[8]) {
		gameNotOver = false;
	}
	else if (boardgrid[2] == boardgrid[4] && boardgrid[4] == boardgrid[6]) {
		gameNotOver = false;
	}

	return gameNotOver;
}

void DisplayWinner(const int activePlayer,const int& chances) {

	if (chances > 0) {
		cout << "Player " << activePlayer << " is the winner!!!" << endl;
	}
	else {
		cout << "Game is a tie!!!" << endl;
	}
	
}


bool GameIsNotOver(const char* boardgrid,int& chances) {
	
	bool check;

	check = CheckCombination(boardgrid);
	chances -= 1;
	if (check && chances > 0) {
		return true;
	}
	else {
		return false;
	}
}

bool WantToPlayAgain() {
	
	bool failure;
	char input;

	do {
		failure = false;
		input = GetCharInput("Do you want to play again? (y/n)", "Error Input!! should be (y/n)");
		input = tolower(input);
		if (input != 'y' && input != 'n') {
			cout << "should be (y/n)" << endl;
			failure = true;
		}
	} while (failure);

	return input == 'y';

}