#include <iostream>	
#include <iomanip> 
#include "3tGame.h"

using namespace std;

Game::Game() {
	boardPtr = new char[9];

	for (int i = 0; i < 9; i++) {
		boardPtr[i] = i + 49;
	}
	choice = 0;
	turn = 'X';
	tie = false;
}

void Game::setChoice(int choice1) {
	choice = choice1;
}
int Game::getChoice() {
	return choice;
}

void Game::setTurn(char turn1) {
	turn = turn1;
}
char Game::getTurn() {
	return turn;
}

void Game::setTie(bool tie1) {
	tie = tie1;
}
bool Game::getTie() {
	return tie;
}

void Game::drawBoard() {

	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << boardPtr[0] << "  |" << "\t" << boardPtr[1] << "  |  " << boardPtr[2] << " \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << boardPtr[3] << "  |" << "\t" << boardPtr[4] << "  |  " << boardPtr[5] << " \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << boardPtr[6] << "  |" << "\t" << boardPtr[7] << "  |  " << boardPtr[8] << " \n";
	cout << "\t\t     |     |     \n";
}

void Game::playerTurn() {
	if (getTurn() == 'X') {

		cout << "\nPlayer One [X] - choose a location (1-9): ";
		cin >> choice;

		while (boardPtr[choice - 1] == 'X' || boardPtr[choice - 1] == 'O') {
			cout << "\nLocation taken.";
			cout << "\nPlayer One [X] - choose another location (1-9): ";
			cin >> choice;
		}

	LOOP1:switch (getChoice()) {
	case 1:
		boardPtr[0] = 'X';
		break;
	case 2:
		boardPtr[1] = 'X';
		break;
	case 3:
		boardPtr[2] = 'X';
		break;
	case 4:
		boardPtr[3] = 'X';
		break;
	case 5:
		boardPtr[4] = 'X';
		break;
	case 6:
		boardPtr[5] = 'X';
		break;
	case 7:
		boardPtr[6] = 'X';
		break;
	case 8:
		boardPtr[7] = 'X';
		break;
	case 9:
		boardPtr[8] = 'X';
		break;
	default:
		cout << "\nNot a valid location. Choose location from 1 - 9: ";
		cin >> choice;
		goto LOOP1;
	}
	setTurn('O');
	}

	else if (getTurn() == 'O') {

		cout << "\nPlayer Two [O] - choose a location (1-9): ";
		cin >> choice;

		while (boardPtr[choice - 1] == 'X' || boardPtr[choice - 1] == 'O') {
			cout << "\nLocation taken.";
			cout << "\nPlayer Two [O] - choose another location (1-9): ";
			cin >> choice;
		}

	LOOP2:switch (getChoice()) {
	case 1:
		boardPtr[0] = 'O';
		break;
	case 2:
		boardPtr[1] = 'O';
		break;
	case 3:
		boardPtr[2] = 'O';
		break;
	case 4:
		boardPtr[3] = 'O';
		break;
	case 5:
		boardPtr[4] = 'O';
		break;
	case 6:
		boardPtr[5] = 'O';
		break;
	case 7:
		boardPtr[6] = 'O';
		break;
	case 8:
		boardPtr[7] = 'O';
		break;
	case 9:
		boardPtr[8] = 'O';
		break;
	default:
		cout << "\nNot a valid location. Choose location from 1 - 9: ";
		cin >> choice;
		goto LOOP2;
	}
	setTurn('X');
	}
}

bool Game::gameOver() {

	// Checking Rows
	if (boardPtr[0] == boardPtr[1] && boardPtr[1] == boardPtr[2]) {
		return true;
	}
	else if (boardPtr[3] == boardPtr[4] && boardPtr[4] == boardPtr[5]) {
		return true;
	}
	else if (boardPtr[6] == boardPtr[7] && boardPtr[7] == boardPtr[8]) {
		return true;
	}

	// Checking Columns
	else if (boardPtr[0] == boardPtr[3] && boardPtr[3] == boardPtr[6]) {
		return true;
	}
	else if (boardPtr[1] == boardPtr[4] && boardPtr[4] == boardPtr[7]) {
		return true;
	}
	else if (boardPtr[2] == boardPtr[5] && boardPtr[5] == boardPtr[8]) {
		return true;
	}

	// Checking Diagonals
	else if (boardPtr[0] == boardPtr[4] && boardPtr[4] == boardPtr[8]) {
		return true;
	}
	else if (boardPtr[2] == boardPtr[4] && boardPtr[4] == boardPtr[6]) {
		return true;
	}

	// Chgecking for Tie Game						
	if ((boardPtr[0] == 'X' || boardPtr[0] == 'O') && (boardPtr[1] == 'X' || boardPtr[1] == 'O') &&
		(boardPtr[2] == 'X' || boardPtr[2] == 'O') && (boardPtr[3] == 'X' || boardPtr[3] == 'O') &&
		(boardPtr[4] == 'X' || boardPtr[4] == 'O') && (boardPtr[5] == 'X' || boardPtr[5] == 'O') &&
		(boardPtr[6] == 'X' || boardPtr[6] == 'O') && (boardPtr[7] == 'X' || boardPtr[7] == 'O') &&
		(boardPtr[8] == 'X' || boardPtr[8] == 'O'))
	{
		setTie(true);
		return true;
	}
}

void Game::GameOverMessage() {
	if (getTie() == true) {
		cout << "\nTie Game.\n\n";
	}
	else {
		if (getTurn() == 'O')
			cout << "\nGame Over.\nPlayer 1 wins.\n\n";
		else
			cout << "\nGame Over.\nPlayer 2 wins.\n\n";
	}
}

Game::~Game() {
	delete[] boardPtr;
	cout << "\n\nboardPtr destroyed.";
	cout << "\nProgram Ended.\n\n";
}
