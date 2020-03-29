// Snake(C++).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
//#include <iostream>
//Функции для ввода кодов клавиш и статуса клавиатуры.
//Изучение функций для ввода кодов нажатых клавиш и статуса клавиатуры.


//#include "stdafx.h"
#include "iostream"
#include <windows.h>
#include <conio.h>
#include <string>
#include <time.h>
using namespace std;

#define x3 60//Задаем размер окна
#define y3 34
#define x2 (x3/2)//Находим центр
#define y2 ((y3-4)/2)

class snake {
private:
	unsigned short int x[500], y[500], xb, yb;
	int  l = 2;
public:
	snake(unsigned short int x1, unsigned short int y1, int *t) {
		golova(&x1, &y1);
		hvost();
		xb = rand() % 27;
		yb = rand() % 27;
		int i = 0;
		while (i != 1) {
			xb = rand() % 27;
			yb = rand() % 27;
			for (int j = 0; j < l; j++) {
				if ((xb != x[j]) || (yb != y[j])) {
					i = 1;
				}
			}
		}
		COORD crd = { (xb + 2) * 2,yb + 5 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		cout << char(206);
		crd.X = 8;
		crd.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		cout << (l * 100) / (*t);
		crd.X = 12;
		crd.Y = 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		//cout << "xb = " << (xb + 2) * 2 << "  ";
		crd.Y++;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		//cout << "yb = " << yb + 5 << "  ";
		x[1] = x2 - 1;
		y[1] = y2;
	}
	void start1(unsigned short int x1, unsigned short int y1) {

	}
	void golova(unsigned short int *x1, unsigned short int *y1) {
		COORD crd;
		for (int i = l; i >= 0; i--) {
			x[i + 1] = x[i];
			y[i + 1] = y[i];
			if (i == 0) {
				x[0] = *x1;
				y[0] = *y1;
			}
		}
		crd.X = x[0];
		crd.Y = y[0];
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		cout << char(254);
		//test();
	}
	void hvost() {
		COORD crd;
		crd.X = x[l - 1];
		crd.Y = y[l - 1];
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		cout << " ";
	}
	void test() {
		COORD crd;
		crd.X = 0;
		crd.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		for (int i = 0; i <= l; i++) {
			cout << "                           " << endl;
		}
		crd.X = 0;
		crd.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		for (int i = 0; i <= l; i++) {
			cout << "x[" << i << "] = " << x[i] << " y[" << i << "] = " << y[i] << endl;
		}
	}
	void crash(unsigned short int *x1, unsigned short int *y1, int *p) {
		for (int i = 1; i < l; i++) {
			if ((*x1 == x[i]) && (*y1 == y[i])) {
				*p = 27;
				l = 1;
				x[0] = 0;
				y[0] = 0;
			}
		}
		if ((*x1 == 0) || (*x1 == x3) || (*y1 == 4) || (*y1 == y3)) {
			*p = 27;
			l = 1;
			x[0] = 0;
			y[0] = 0;
		}
	}
	void bounce(unsigned short int *x1, unsigned short int *y1, int *t, unsigned short int *Us) {
		if (((*x1 == (xb + 2) * 2) && (*y1 == yb + 5)) || (*Us == 0)) {
			unsigned short int i = 0;
			while (i != 1) {
				xb = rand() % 27;
				yb = rand() % 27;
				for (int j = 0; j < l; j++) {
					if ((xb != x[j]) || (yb != y[j])) {
						i = 1;
					}
				}
			}
			*Us = 1;
			COORD crd = { (xb + 2) * 2,yb + 5 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			cout << char(206);
			crd.X = 8;
			crd.Y = 0;
			l++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			cout << (l * 100) / (*t);
			//crd.X = 12;
			//crd.Y = 1;
			//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			//cout << "xb = " << (xb + 2) * 2 << "  ";
			//crd.Y++;
			//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			//cout << "yb = " << yb + 5 << "  ";
		}
	}
};

void wall() {
	COORD crd = { 0,4 };
	for (int i = 0; i < x3; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		cout << char(219);
		crd.X++;
	}
	for (int i = 0; i < y3 - 4; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		cout << char(219);
		crd.Y++;
	}
	for (int i = 0; i < x3; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		cout << char(219);
		crd.X--;
	}
	for (int i = 0; i < y3 - 4; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		cout << char(219);
		crd.Y--;
	}
}
//меню
void cursor() {
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}
void menu(int *t, int *p) {
	system("cls");
	cursor();
	unsigned short int x = 1, k = 0;
	COORD crd = { x2 - 2,y2 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
	cout << "S N A K E";
	crd.Y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
	cout << "Play";
	crd.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
	cout << "Speed: " << (210 - (*t)) << "  ";
	crd.Y++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
	cout << "Exit";
	crd.X--;
	while (k != 1) {
		switch (x) {
		case 1:
			crd.Y = y2 + 3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			cout << " ";
			crd.Y--;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			cout << char(178);
			break;
		case 2:
			crd.Y = y2 + 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			cout << " ";
			crd.Y += 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			cout << " ";
			crd.Y--;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			cout << char(178) << "Speed: " << (210 - (*t)) << "  ";
			break;
		case 3:
			crd.Y = y2 + 3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			cout << " ";
			crd.Y++;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
			cout << char(178);
			break;
		}
		k = _getch();
		switch (k)
		{
		case 119://w
			if (x > 1) {
				x--;
			}
			break;
		case 115://s 
			if (x < 3) {
				x++;
			}
			break;
		case 100://d
			if ((x == 2) && (*t > 10)) {
				*t -= 10;
			}
			break;
		case 97://a 
			if ((x == 2) && (*t < 200)) {
				*t += 10;
			}
			break;
		case 13://enter
			switch (x) {
			case 1:
				k = 1;
				system("cls");

				break;
			case 3:
				k = 1;
				*p = 0;
				break;
			}
		}
	}
}

void start() {
	cursor();
	cout << "  Score: ";
	wall();
}

int main() {
	int t = 110;
	unsigned short int x1 = x2;
	unsigned short int y1 = y2;
	unsigned short int Us = 1;
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x3, y3 };    //Задаем размеры ком. строки
	srand(time((time_t)NULL));
	SMALL_RECT src = { 0, 0, crd.X, crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	int p = 100;
	int tes = 100;
	menu(&t, &p);
	start();
	snake Go(x2, y2, &t);
	while (p != 0) {
		Sleep(t);
		if (_kbhit()) {
			p = _getch();
		}

		//проверка
		switch (p) {
		case 119://w
			if (tes == 115) {
				p = tes;
			};
			tes = p;
			break;
		case 100://d
			if (tes == 97) {
				p = tes;
			};
			tes = p;
			break;
		case 115://s 
			if (tes == 119) {
				p = tes;
			};
			tes = p;
			break;
		case 97://a 
			if (tes == 100) {
				p = tes;
			};
			tes = p;
			break;
		}
		//поворот
		switch (p)
		{
		case 119://w
			y1--;
			break;
		case 100://d
			x1 += 2;
			break;
		case 115://s 
			y1++;
			break;
		case 97://a 
			x1 -= 2;
			break;
		}
		crd.Y = 1;
		crd.X = 0;
		//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crd);
		//cout << "x1 = " << x1 << "\ny1 = " << y1;
		Go.hvost();
		Go.bounce(&x1, &y1, &t, &Us); 
		Go.golova(&x1, &y1);
		Go.crash(&x1, &y1, &p);
		if (p == 27) {
			menu(&t, &p);
			if (p != 0) {
				start();
				p = 100;
				tes = 100;
				x1 = x2;
				y1 = y2;
				Us = 0;
			}
		}
	}
	return 0;
}