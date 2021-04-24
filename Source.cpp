#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>

using namespace std;


const int width = 20;
const int height = 20;

const int N = width * height;
int Arr[N];


int headX;
int headY;
int knopka = 1;
int snake = 3;
int score = 0;


bool game;

int Uroven;


void Logic();
void Draw();
void Build();
void Dvig(int x, int y);
void update();
void eda();
char Proverka(int d);
void menu();


int main()
{
	menu();
}

void menu() {
	setlocale(0, "");

	cout << "Введите уровень сложности: " << endl << endl;
	cout << "1 - Легко" << endl;
	cout << "2 - Средне" << endl;
	cout << "3 - Сложно" << endl;
	cin >> Uroven;
	cout << endl;
	int c = 0;
	if (Uroven == 1 || Uroven == 2 || Uroven == 3) {



		Logic();
	}



	else {

		while (true)
		{
			c++;

			if (c == 3) {
				Uroven = 1;
				Logic();
				break;
			}
			else {

				cout << "Введите уровень сложности: " << endl << endl;
				cout << "1 - Легко" << endl;
				cout << "2 - Средне" << endl;
				cout << "3 - Сложно" << endl;
				cout << endl;

				cin >> Uroven;

				if (Uroven == 1 || Uroven == 2 || Uroven == 3) {



					Logic();
					break;
				}
			}
		}
	}

	return;
}


void Logic()
{

	Build();
	game = true;
	while (game)
	{

		if (_kbhit())
		{
			char key = _getch();
			switch (key) {
			case 'w':
				if (knopka != 3) knopka = 1;
				break;
			case 'd':
				if (knopka != 4) knopka = 2;
				break;
			case 's':
				if (knopka != 1) knopka = 3;
				break;
			case 'a':
				if (knopka != 2) knopka = 4;
				break;




			}


		}

		update();
		system("cls");

		Draw();
		switch (Uroven)
		{
		case 1: Sleep(500);
			break;
		case 2: Sleep(400);
			break;
		case 3: Sleep(200);
			break;
		}
	}


	cout << "Game Over                Score: " << score;

	cout << endl;

	cin.ignore();
}


void eda() {
	int x = 0;
	int y = 0;
	do
	{

		srand(time(NULL));
		x = rand() % (width - 2) + 1;
		y = rand() % (height - 2) + 1;


	} while (Arr[x + y * width] != 0);


	Arr[x + y * width] = -2;
}


void update()
{

	switch (knopka) {
	case 1:Dvig(-1, 0);
		break;
	case 2: Dvig(0, 1);
		break;
	case 3: Dvig(1, 0);
		break;
	case 4: Dvig(0, -1);
		break;
	}

	for (int i = 0; i < N; i++)
	{
		if (Arr[i] > 0) Arr[i]--;
	}

}





void Dvig(int x, int y) {
	int x1 = headX + x;
	int y1 = headY + y;


	if (Arr[x1 + y1 * width] == -2) {



		snake = snake + 1;
		score = score + 1;
		eda();
	}





	else if (Arr[x1 + y1 * width] != 0) {
		game = false;
	}

	headX = x1;
	headY = y1;
	Arr[headX + headY * width] = snake + 1;


}





void Build()
{

	headX = width / 2;
	headY = height / 2;
	Arr[headX + headY * height] = 1;


	for (int x = 0; x < width; x++)
	{
		Arr[x] = -1;
		Arr[x + (height - 1) * width] = -1;
	}

	//
	for (int y = 0; y < height; y++)
	{
		Arr[0 + y * height] = -1;
		Arr[(width - 1) + y * width] = -1;
	}


	eda();
}


void Draw()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{

			cout << Proverka(Arr[x + y * width]);
		}

		cout << endl;

	}
}

char Proverka(int d)
{

	if ( d == -1) {
		return '#';
	}
	else if (d > 1) return 'o';
	else if (d == -2) return 'X';
	else return' ';
}