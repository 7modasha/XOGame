#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void show(const char xo[][3]){

	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			cout << "   " << xo[row][col] << " || ";
		}
		cout << "\n=========================\n";
	}
}

void reFill(char xo[][3]){

	char c = '1';

	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++) xo[row][col] = c++;
}

void input(char xo[][3], int numOfSquare, bool isX, bool &isWrong){

	char in; isWrong = false;
	if (isX) in = 'X'; else in = 'O';

	switch (numOfSquare){

	case 1:
		if (xo[0][0] == '1') xo[0][0] = in; else isWrong = true; break;
	case 2:
		if (xo[0][1] == '2') xo[0][1] = in; else isWrong = true; break;
	case 3:
		if (xo[0][2] == '3') xo[0][2] = in; else isWrong = true; break;
	case 4:
		if (xo[1][0] == '4') xo[1][0] = in; else isWrong = true; break;
	case 5:
		if (xo[1][1] == '5') xo[1][1] = in; else isWrong = true; break;
	case 6:
		if (xo[1][2] == '6') xo[1][2] = in; else isWrong = true; break;
	case 7:
		if (xo[2][0] == '7') xo[2][0] = in; else isWrong = true; break;
	case 8:
		if (xo[2][1] == '8') xo[2][1] = in; else isWrong = true; break;
	case 9:
		if (xo[2][2] == '9') xo[2][2] = in; else isWrong = true; break;
	}

	

}

bool isHeWon(char xo[][3]){

	//ver
	     if (xo[0][0] == xo[1][0] && xo[0][0] == xo[2][0]) return true;

	else if (xo[0][1] == xo[1][1] && xo[0][1] == xo[2][1]) return true;

	else if (xo[0][2] == xo[1][2] && xo[0][2] == xo[2][2]) return true;

	//hor
	else if (xo[0][0] == xo[0][1] && xo[0][0] == xo[0][2]) return true;

	else if (xo[1][0] == xo[1][1] && xo[1][0] == xo[1][2]) return true;

	else if (xo[2][0] == xo[2][1] && xo[2][0] == xo[2][2]) return true;

	//CROSS

	else if (xo[0][0] == xo[1][1] && xo[0][0] == xo[2][2]) return true;

	else if (xo[0][2] == xo[1][1] && xo[0][2] == xo[2][0]) return true;

	return false;

}

void pronTheWinner(bool isX){

	if (isX) cout << "The winner is the X player\n";
	else cout << "The winner is the O player\n";

}

void main() {

	char xo[3][3], anotherGames;
	int numOfSquare, c = 0;
	bool isX, isWrong, noWinner = true;

	reFill(xo);
	show(xo);

	do{

		while (true){

			do{

				cout << "Player X, enter the number of the square: "; cin >> numOfSquare; isX = true;

				if (numOfSquare > 9 || numOfSquare < 1) isWrong = true; else input(xo, numOfSquare, isX, isWrong);  

				system("CLS"); show(xo);
				
				if (isHeWon(xo)){ pronTheWinner(isX); noWinner = false; }

				if (isWrong) cout << "The square is used try another one.\n\n";

			} while (isWrong);

			if (!noWinner) break; 

			c++;
			if (c == 9) { cout << "No winner sorry\n"; break; }

			do{

				srand(time(NULL)); numOfSquare = rand() % (9 + 1); isX = false; input(xo, numOfSquare, isX, isWrong); system("CLS"); show(xo);

				if (isHeWon(xo)){ pronTheWinner(isX); noWinner = false; }

			} while (isWrong);

			if (!noWinner) break; 

			c++;
			if (c == 9) { cout << "No winner sorry\n"; break; }

			system("CLS");
			show(xo);
		}

		cout << "Another game? (y/n): "; cin >> anotherGames; system("CLS"); reFill(xo); show(xo); noWinner = true; c = 0;

	} while (anotherGames != 'n');

	system("pause");
}