// Giovanni Cortese 
// Tic - Tac - Toe Game

#include <iostream>	
#include <iomanip> 
#include "3tGame.h"

using namespace std;

int main() {
	Game g1;
	cout << "\t\tTIC - TAC - TOE GAME\n";
	cout << "\t\t  For two players.\t\t\n\n";
	cout << "\nPLAYER - 1 [X]\t\t\t\tPLAYER - 2 [O]\n\n\n";
	while (g1.gameOver() != true) {
		g1.drawBoard();
		g1.playerTurn();
		system("cls");
		g1.gameOver();
	}
	g1.drawBoard();
	g1.GameOverMessage();
	return 0;
}