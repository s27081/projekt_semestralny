#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

//stworzenie planszy do gry

bool mazeLoop = true;
char boardChar = ' ';
bool finish = false;

string gameBoard[10][20] = {{"#", "#", "#", "#", "#", "#", "#", "#", "@", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
							{"#", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", " ", " ", " ", " ", "#", " ", " ", " ", "#"},
							{"#", " ", "#", "#", "#", "#", " ", "#", "#", " ", "#", "#", "#", "#", " ", " ", " ", "#", " ", "#"},
							{"#", " ", " ", " ", " ", "#", " ", "#", " ", " ", "#", "#", "#", " ", "#", "#", "#", "#", " ", "#"},
							{"#", "#", "#", "#", " ", "#", "#", "#", "#", "#", "#", "#", "#", " ", "#", "#", " ", " ", " ", "#"},
							{"#", "#", "#", "#", " ", "#", "#", " ", " ", " ", " ", " ", " ", " ", "#", "#", " ", "#", "#", "#"},
							{"#", " ", " ", " ", " ", "#", "#", " ", "#", "#", "#", "#", "#", " ", "#", "#", " ", "#", "#", "#"},
							{"#", " ", "#", "#", "#", "#", "#", " ", "#", "#", "#", "#", "#", " ", " ", " ", " ", "#", "#", "#"},
							{"#", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "#", "#", " ", "#", "#", "#"},
							{"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "$", "#", "#", "#", "#", "#", "#", "#", "#"},

};

//początkowa pozycja gracza (y,x) ustawiona na znak $

int playerPosition[2] = { 9,11 };
char playerChar = '*';


//mechanika gracza

void playerMovement(string gameBoard[10][20], int playerPosition[2]) {

	//sterowanie + spradzanie dotarcia do mety
	char ch = _getch();
	
	switch (ch) {
	case 'l':
		if (gameBoard[playerPosition[0]][playerPosition[1] - 1] != "#") {

			//sprawdzanie mety
			if (gameBoard[playerPosition[0]][playerPosition[1] - 1] == "@") {
				finish = true;
			}
			gameBoard[playerPosition[0]][playerPosition[1]] = boardChar;
			playerPosition[1] -= 1;
		}
		break;
	case 'p':
		if (gameBoard[playerPosition[0]][playerPosition[1] + 1] != "#") {
			if (gameBoard[playerPosition[0]][playerPosition[1] + 1] == "@") {
				finish = true;
			}
			gameBoard[playerPosition[0]][playerPosition[1]] = boardChar;
			playerPosition[1] += 1;
		}
		break;
	case 'g':
		if (gameBoard[playerPosition[0] - 1][playerPosition[1]] != "#") {
			if (gameBoard[playerPosition[0]- 1][playerPosition[1]] == "@") {
				finish = true;
			}
			gameBoard[playerPosition[0]][playerPosition[1]] = boardChar;
			playerPosition[0] -= 1;

		}
		break;
	case 'd':
		if (gameBoard[playerPosition[0] + 1][playerPosition[1]] != "#") {
			if (gameBoard[playerPosition[0] + 1][playerPosition[1]] == "@") {
				finish = true;
			}
			gameBoard[playerPosition[0]][playerPosition[1]] = boardChar;
			playerPosition[0] += 1;
		}
		break;
	}
}

//generowanie programu do konsoli
void gameStart(string gameBoard[10][20], int playerPosition[2], char playerChar, bool finish) {


	//ustawiene pozycji gracza
	gameBoard[playerPosition[0]][playerPosition[1]] = playerChar;
	

	//ustawienie miejsca startu
	if (gameBoard[9][11] == " ") {
		gameBoard[9][11] = "$";
	}


	//wyświetlenie planszy na ekranie

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j++) {
			cout << gameBoard[i][j];
		}
		cout << endl;
	}

	if (finish) {
		cout << "Gratulacje wyszedles z labiryntu!";
		cout << endl;
		exit(0);
	}

	playerMovement(gameBoard, playerPosition);

}

//sprawdzenie dotarcia do końca labiryntu


int main()
{
	while (mazeLoop) {
		gameStart(gameBoard, playerPosition, playerChar, finish);
		system("CLS");
	}
	
}