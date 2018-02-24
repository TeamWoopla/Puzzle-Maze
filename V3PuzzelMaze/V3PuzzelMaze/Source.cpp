#include <stdio.h>
#include "conio.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;
int playerX, playerY, lvl, timer, bon, fuck = 1000;
bool gameOver, reTry = true, sRoom, finish;
string dif;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

char lvlOn[15][15];
char lvl1[15][15] = {
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', 'E', '|', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '-', '-', '-', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', '-', '-', ' ', '|', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', '-', '-', '-', '-', '-', ' ', '|', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ' },
	{ ' ', ' ', ' ', '-', '-', '-', '-', ' ', '-', '-', '-', '-', '-', ' ', ' ' },
	{ ' ', ' ', ' ', '|', 'B', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', '-', '-', '-', '-', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', '|', 'P', '|', ' ', ' ', ' ', ' ', ' ', ' ' },
};
char lvl2[15][15] = {
	{ '|', 'E', ' ', ' ', 'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', 'M', ' ', ' ', 'M', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', 'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', 'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', 'M', ' ', 'M', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', 'M', 'M', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', 'M', ' ', 'M', ' ', ' ', ' ', ' ', 'M', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', '|' },
	{ '-', '-', '-', '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', ' ', 'M', ' ', ' ', '|' },
	{ '|', ' ', '-', '-', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', '|' },
	{ '|', 'P', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', '|' },
};
char lvl3[15][15] = {
	{ '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '|' },
	{ '|', ' ', ' ', ' ', ' ', 'E', 'M', ' ', ' ', ' ', '|', ' ', '|', 'P', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '-', ' ', '-', '-', '|', ' ', '_' },
	{ '|', ' ', ' ', '-', 'M', 'M', '|', ' ', 'M', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', 'M', ' ', '|', ' ', ' ', '|', ' ', 'M', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '-', '-', '-', '-', '-', 'M', '|' },
	{ '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', '|', ' ', ' ', '|', ' ', ' ', ' ', 'M', ' ', ' ', ' ', '|' },
	{ '|', ' ', 'M', '|', ' ', ' ', '-', '-', '-', '-', '-', '-', ' ', ' ', '|' },
	{ '|', ' ', ' ', '|', ' ', ' ', ' ', 'M', ' ', ' ', 'B', '|', ' ', ' ', '|' },
	{ '|', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', 'M', ' ', '|', ' ', '-', '|' },
	{ '|', 'M', ' ', '|', ' ', '-', '-', '-', '-', '-', '-', '|', ' ', 'M', '|' },
	{ '|', ' ', ' ', '|', ' ', ' ', 'M', ' ', ' ', ' ', ' ', ' ', ' ', '-', '|' },
	{ '|', 'B', ' ', '|', ' ', ' ', ' ', ' ', ' ', 'M', ' ', ' ', ' ', ' ', '|' },
	{ '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '|' },
};
char lvl4[15][15] = {
	{ '|', ' ', 'S', 'e', 'c', 'r', 'e', 't', ' ', 'R', 'o', 'o', 'm', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', 'G', 'o', 'o', 'd', ' ', 'J', 'o', 'B', ' ', 'M', 'a', 't', 'e', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '-', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '|', ' ', ' ', ' ', ' ', ' ', ' ', 'P', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
	{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', '-' },
};

void StartTalk() {
	char def;
	cout << "HELLOOOOOOOO! HELLOOOOOOOO!" << endl;
	Sleep(fuck);
	cout << "Welcome to my little game!" << endl;
	Sleep(fuck);
	cout << "It's very simple! go to the E - End and avoid the M - Monsters!" << endl;
	Sleep(fuck);
	cout << "Look for the B - Bonuses thir are 5 of them!" << endl;
	Sleep(fuck);
	cout << "On what difficulty you want to play? E - easy / N - normal / H - hard?" << endl;
	cin >> def;
	switch (def) {
	case 'E':
		timer = 100;
		dif = "Easy";
		break;
	case 'e':
		timer = 100;
		dif = "Easy";
		break;
	case 'N':
		timer = 70;
		dif = "Normal";
		break;
	case 'n':
		timer = 70;
		dif = "Normal";
		break;
	case 'H':
		timer = 50;
		dif = "Hard";
		break;
	case 'h':
		timer = 50;
		dif = "Hard";
		break;
	default:
		timer = 70;
		dif = "Na";
		break;
	}
	cout << "Good Luck & Have Fun" << endl;
	system("pause");
}

void Setup() {
	int i, i1;
	for (i = 0; i < 15; i++) {
		for (i1 = 0; i1 < 15; i1++) {
			lvlOn[i][i1] = lvl1[i][i1];
		}
	}
	lvl3[14][13] = '_'; // seceret room lvl 3
	playerX = 7;
	playerY = 14;
	lvl = 1;
	bon = 0;
	gameOver = false;
	finish = false;
	sRoom = false;
	dir = STOP;
}

void Again(int a5) {
	string a;
	cout << "Do you want to try again?" << endl;
	cin >> a;
	if ((a == "No") || (a == "Nop") || (a == "no") || (a == "nop") || (a == "FUCK THIS STUPIED GAME")) {
		cout << "oh realy?" << endl;
		Sleep(1500);
		cout << "ok then, thank you and not thank you ya bolgari mashriahch!" << endl;
		Sleep(2500);
		reTry = false;
	}
	else {
		cout << "Ok then LET'S GOOOOOO!" << endl;
		if (a5 == 1) {
			if (lvl3[14][13] == '_') {
				cout << "Whana_hit_for_one_of_the_bonuses?_Find_a_secret_room_" << endl;
			}
		}
	}
}

void Finito() {
	system("cls");
	cout << "Woow dude!" << endl;
	Sleep(fuck);
	cout << "You compeleted the game! I'm proud of you!" << endl;
	Sleep(fuck);
	if (bon >= 5) {
		cout << "Woooooooowwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww" << endl;
		Sleep(fuck);
		cout << "you got all the bonuses" << endl;
		Sleep(fuck);
		Again(0);
		system("pause");
	}
	else {
		cout << "Woow and with " << bon << " bonuses!! just " << 5 - bon << " more!" << endl;
		Sleep(fuck);
		cout << "I dont blame you... it's very hard to get the bonuses... ";
		if (dif == "Hard") { cout << "especially on hard!"; }
		Sleep(fuck);
		cout << endl << "You can always try again!" << endl;
		Sleep(fuck);
		Again(1);
		system("pause");

	}

}

void nextlvl() {
	int i1, i2, i3, i4;
	if (!sRoom) {
		lvl++;
	}
	else { sRoom = false; }
	switch (lvl) {
	case 2:
		for (i1 = 0; i1 < 15; i1++) {
			for (i2 = 0; i2 < 15; i2++) {
				lvlOn[i1][i2] = lvl2[i1][i2];
			}
		}
		playerX = 1;
		playerY = 14;
		break;
	case 3:
		for (i3 = 0; i3 < 15; i3++) {
			for (i4 = 0; i4 < 15; i4++) {
				lvlOn[i3][i4] = lvl3[i3][i4];
			}
		}
		playerX = 13;
		playerY = 1;
		break;
	case 4:
		finish = true;
		gameOver = true;
		break;
	default:
		break;
	}
}

void Draw() {
	system("cls");
	int i, i1;
	cout << "\n\n\n";
	for (i = 0; i < 15; i++) {
		cout << "\t\t\t";
		for (i1 = 0; i1 < 15; i1++) {
			cout << lvlOn[i][i1] << " ";
		}
		cout << endl;
	}
	cout << "lvl - " << lvl << endl;
	cout << "Difficulty - " << dif << endl;
	cout << "Bonuses - " << bon << endl;
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void secretRoom() {
	sRoom = true;
	int i, i1;
	for (i = 0; i < 15; i++) {
		for (i1 = 0; i1 < 15; i1++) {
			lvlOn[i][i1] = lvl4[i][i1];
		}
	}
	playerX = 7;
	playerY = 13;
	lvl3[14][13] = '-';

}

int spCheck() {
	if (lvlOn[playerY][playerX] == 'E') {
		nextlvl();
		return false;
	}
	else if (lvlOn[playerY][playerX] == 'M') {
		gameOver = true;
		return false;
	}
	else if (lvlOn[playerY][playerX] == 'B') {
		bon++;
		lvlOn[playerY][playerX] = ' ';
	}
	else if (lvlOn[playerY][playerX] == '_') {
		secretRoom();
		return false;
	}
	return true;
}

void Logic() {
	switch (dir) {
	case LEFT:
		playerX--;
		if (spCheck()) {
			if (lvlOn[playerY][playerX] == ' ') {
				playerX++;
				lvlOn[playerY][playerX] = ' ';
				playerX--;
				lvlOn[playerY][playerX] = 'P';
			}
			else { playerX++; }
		}
		break;

	case RIGHT:
		playerX++;
		if (spCheck()) {
			if (lvlOn[playerY][playerX] == ' ') {
				playerX--;
				lvlOn[playerY][playerX] = ' ';
				playerX++;
				lvlOn[playerY][playerX] = 'P';
			}
			else { playerX--; }
		}
		break;

	case UP:
		playerY--;
		if (spCheck()) {
			if (lvlOn[playerY][playerX] == ' ') {
				playerY++;
				lvlOn[playerY][playerX] = ' ';
				playerY--;
				lvlOn[playerY][playerX] = 'P';
			}
			else { playerY++; }
		}
		break;

	case DOWN:
		playerY++;
		if (spCheck()) {
			if (lvlOn[playerY][playerX] == ' ') {
				playerY--;
				lvlOn[playerY][playerX] = ' ';
				playerY++;
				lvlOn[playerY][playerX] = 'P';
			}
			else { playerY--; }
		}
		break;
	default:
		break;
	}
}

void Setdown() {
	string a;
	system("cls");
	cout << "ohhh" << endl;
	Sleep(fuck);
	cout << "You lost :(" << endl;
	Sleep(fuck);
	Again(0);
	system("pause");
}

int main() {
	StartTalk();
	while (reTry) {
		Setup();
		while (!gameOver) {
			Input();
			Logic();
			Draw();
			Sleep(timer);
		}
		if (!finish) {
			Setdown();
		}
		else {
			Finito();
		}
	}
	return 0;
}