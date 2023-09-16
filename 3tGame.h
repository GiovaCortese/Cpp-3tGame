#pragma once
#include <iostream>

class Game {
public:
	Game();
	void setChoice(int);
	int getChoice();
	void setTurn(char);
	char getTurn();
	void setTie(bool);
	bool getTie();
	void drawBoard();
	void playerTurn();
	bool gameOver();
	void GameOverMessage();
	~Game();

private:
	char* boardPtr;
	int choice;
	char turn;
	bool tie;
};