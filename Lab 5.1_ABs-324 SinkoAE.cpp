﻿// Lab 5.1_ABs-324 SinkoAE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <Windows.h>

using namespace std;    // используем пространство имен std

// Функция для подсчета количества товара в заданном адресе
int examination(map<string, vector<string>> product, string number, string s) {
// подсчет количества товара определенного типа (s) в заданном адресе (number) на складе (product)
// product - словарь, где ключ - адрес, значение - вектор товаров в этом адресе,
// number - адрес, в котором нужно посчитать товар,
// s - тип товара, который нужно посчитать.
	int k = 0;	// инициализация переменной k - подсчет количества товара

	for (pair<string, vector<string>> i : product) {	// цикл, который проходит по каждому элементу словаря product
	// каждый элемент представляет собой пару ключ-значение, где ключ - адрес, значение - вектор товаров в этом адресе
		if (i.first == number) {	// проверка, соответствует ли адрес текущего элемента искомому адресу number
			for (string j : i.second) {	// если адрес совпадает, то происходит цикл по вектору товаров в этом адресе
				if (j == s) {	// проверка, является ли текущий товар искомым типом s
					k++;	// если товар является искомым типом, то k увеличивается на 1
				}
			}
		}
	}
	// после того, как все товары проверены
	return k;	// возвращает количество товара s в адресе number
}

// Функция для вывода информации о товаре в заданном адресе
void out(map<string, vector<string>> product, string number) {
// вывод информации о товаре в заданном адресе (number) на складе (product)
// product - словарь, где ключ - адрес, а значение - вектор товаров в этом адресе,
// number - адрес, информацию о котором нужно вывести.

	for (pair<string, vector<string>> i : product) {	// цикл, который проходит по каждому элементу словаря product
	// каждый элемент представляет собой пару ключ-значение, где ключ - адрес, значение - вектор товаров в этом адресе
		if (i.first == number) {	// проверка, соответствует ли адрес текущего элемента искомому адресу number
			cout << i.first << " : ";	// если адрес совпадает, то он выводится на экран
			for (string j : i.second) {	// если адрес совпадает, то происходит цикл по вектору товаров в этом адресе
				cout << j << " ";	// для каждого товара в адресе выводится его название
			}
			cout << endl;	// после вывода всех товаров в адресе происходит переход на новую строку
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<string, vector<string>> product;	// объявление переменной, которая является ассоциативным массивом (словарём), ключ - строка, значение - вектор строк
	for (int i = 0; i < 1; i++) {	// одна зона хранения
		string zone;
		if (i == 0) {
			zone = "A";
		}

		// Инициализация склада
		for (int j = 0; j < 10; j++) {	// количество стеллажей в зоне хранения 10
		// цикл создает номера стеллажей (rack) от "01" до "10"
			string rack = to_string(j + 1);
			if (j < 9) {
				rack = '0' + rack;
			}

			for (int z = 0; z < 7; z++) {	// количество вертикальных секций стеллажа 7
			// цикл создает номера вертикальных секций (sections) от "01" до "07" для каждого стеллажа
				string sections = to_string(z + 1);

				for (int y = 0; y < 4; y++) {	// количество полок в вертикальной секции 4
				// цикл создает номера полок (shelves) от "01" до "04" для каждой вертикальной секции
					string shelves = to_string(y + 1);

					// строка all, которая является уникальным идентификатором адреса на складе, состоящим из зоны, стеллажа, секции и полок
					string all = zone + rack + sections + shelves;
					for (int w = 0; w < 10; w++) {
					// цикл добавляет в вектор товаров товары в количестве до 10 штук
						product[all].push_back("0");
					}
				}
			}
		}
	}
	string command;	// строка объявляет переменную command, которая будет использоваться для хранения команд, введенных пользователем
	while (true) {	// бесконечный цикл, который продолжает работу, пока программа не будет завершена внешней силой (нажатие клавиши "CTRL+C")
		cout << "Введите команду (ADD/REMOVE/INFO): ";	// приглашение ввести команду
		cin >> command;	// сохранение введенной команды в соответствующую переменную
		string merchandise, number;	// переменные для хранения названия товара, адреса товара 
		int kol;
		// Код для добавления товара на склад
		if (command == "ADD") {	// если пользователь ввел команду "ADD"
			cout << "Введите товар: ";	// запрос названия товара
			cin >> merchandise;	// ввод названия товара
			cout << "Введите кол-во: ";	// запрос количества товара
			cin >> kol;	// ввод количества товара
			cout << "Введите адрес: ";	// запрос адреса товара, куда должен быть добавлен товар
			cin >> number;	// ввод адреса

			// Проверка, есть ли место на складе для добавления товара с помощью функции examination
			int there = examination(product, number, "0");
			
			// Если есть место, товар добавляется в первые пустые ячейки в указанном адресе
			if (kol <= 10 && kol <= there) {
				int k = 0;
				//Заполняем первые пустые ячейки
				for (int w = 0; w < 10; w++) {
					if (product[number][w] == "0" && k < kol) {
						product[number][w] = merchandise;
						k++;
					}
				}
			}
			// Если недостаточно места
			else {
				cout << "Недостаточно места" << endl;
			}
		}
		// Код для удаления товара со склада
		else if (command == "REMOVE") {	// если пользователь ввел команду "REMOVE"
			cout << "Введите товар: ";	// запрос названия товара
			cin >> merchandise;	// ввод названия товара
			cout << "Введите кол-во: ";	// запрос количества товара
			cin >> kol;	// ввод количества товара
			cout << "Введите адрес: ";	// запрос адреса товара, куда должен быть добавлен товар
			cin >> number;	// ввод адреса
			// Процесс аналогичен, но вместо добавления товара, программа удаляет товар из указанного адреса
			// Проверка, есть ли столько товара
			int there = examination(product, number, merchandise);
			if (kol <= 10 && kol <= there) {
				int k = 0;
				// Удаление с конца
				for (int w = 9; w >= 0; w--) {
					if (product[number][w] == merchandise && k < kol) {
						product[number][w] = "0";
						k++;
					}
				}
			}
			// Если товара недостаточно для удаления
			else {
				cout << "Недостаточно товара" << endl;
			}
		}
		// Код для вывода информации о складе
		else if (command == "INFO") {	// если пользователь ввел команду "INFO"
			vector<string> noEmpty;
			vector<string> empty;
			int kolNull = 0;
			int nullA = 0;
			// Прохождение по всем адресам склада и сбор информации о заполненности каждого адреса
			for (pair<string, vector<string>> i : product) {
				int there = examination(product, i.first, "0");
				kolNull += there;
				if (!i.first.find('A')) {
					nullA += there;
				}
				if (there < 10) {	// если адрес заполнен менее чем на 10 единиц товара
					noEmpty.push_back(i.first);	// то он добавляется в вектор noEmpty
				}
				else {	// в противном случае
					empty.push_back(i.first);	// он добавляется в вектор empty
				}
			}
			// Вывод содержимого каждого адреса
			cout << " Cодержание каждой ячейки: " << endl;
			for (int i = 0; i < noEmpty.size(); i++) {
				out(product, noEmpty[i]);
			}
			// Вычисление степени загруженности склада и вывод в процентах
			cout << " Склад загружен на " << float(float(2800 - kolNull) / 2800) * 100 << " %" << endl;
			// Вывод списка пустых адресов
			cout << " Пустые ячейки: " << endl;
			for (string i : empty) {
				cout << i << " ";
			}
			cout << endl;
		}
	}
}