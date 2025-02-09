﻿
// Lab 5.4_ABs-324 SinkoAE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>

using namespace std;	// используем пространство имен std

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<string> student{ "Синько","Красина","Савицкий","Аснин","Шумский" };	// объявление вектора строк student, который инициализируется фамилиями студентов
	
	string command;	// объявление строковой переменной command для хранения введенных команд
	
	vector<string> deduction;	// вектор строк для хранения данных о студентах, которые будут отчислены
	
	vector<string> inviolable;	// вектор строк для хранения данных о студентах, которые будут неприкасаемы

	while (true) {	// бесконечный цикл, который будет выполняться до тех пор, пока программа не будет завершена
		cout << "Введите команду (NEW_STUDENTS/SUSPICIOUS/IMMORTAL/TOP-LIST/SCOUNT): ";
		cin >> command;	// чтение введенной команды
		int number, numberStudent;
		// Команда для добавления или удаленния студентов
		if (command == "NEW_STUDENTS") {
			cin >> number;	// ввод целого числа для определения количества студентов, которых нужно добавить или удалить
			if (number > 0) {	// если введенное число number больше нуля
				// то выполняется блок кода для добавления студентов
				for (int i = 0; i < number; i++) {	// выполняется указанное количество итераций, равное введенному числу number
				// в каждой итерации выполняется добавление нового студента в вектор student
					string s;	// переменная для хранения фамилии нового студента
					cout << "Введите фамилию: ";
					cin >> s;
					student.push_back(s);	// введенная фамилия добавляется в конец вектора student
				}
				cout << "Welcome " << number << " clever students!" << endl;	// сообщение о количестве добавленных студентов
			}
			else if (number < 0) {	// если введенное число number меньше нуля
				// то выполняется блок кода для удаления студентов
				if (abs(number) > student.size()) {	// если число по модулю больше, чем количество студентов в векторе student
				// abs() возвращает абсолютное значение числа (число без знака)
					cout << "Incorrect" << endl;
				}
				else {
					for (int i = 0; i > number; i--) {	// количество итераций, равное введенному числу number по модулю
						student.pop_back();	// в каждой итерации выполняется удаление студента из конца вектора student
					}
					cout << "GoodBye " << abs(number) << " clever students!" << endl;	// сообщение о количестве удаленных студентов
				}
			}
		}
		// Команда для добавления студента в список на отчисление, если он не находится в списке неприкасаемых студентов
		else if (command == "SUSPICIOUS") {
			cin >> numberStudent;	// ввод номера студента, которого нужно добавить в список на отчисление
			// Проверка, что введенный номер студента положительный и не превышает общее количество студентов в векторе student
			if (numberStudent > 0 && numberStudent <= student.size()) {
				int k = 0;	// переменная для отслеживания наличия студента в списке неприкасаемых
				// Проверка, есть ли в списке неприкасаемых студентов
				if (inviolable.size() > 0) {
					// Цикл для проверки, есть ли студент с введенным номером в списке неприкасаемых
					for (int i = 0; i < inviolable.size(); i++) {
						// Если студент найден в списке неприкасаемых
						if (inviolable[i] == student[numberStudent - 1]) {
							k++;	// то k увеличивается на 1
							break;	// и цикл прерывается
						}
					}
				}
				// Если k равно 0 (студент не найден в списке неприкасаемых и его можно добавить в список на отчисление)
				if (k == 0) {
					deduction.push_back(student[numberStudent - 1]);	// студент с введенным номером добавляется в вектор deduction
					cout << "The suspected student " << numberStudent << endl;	// вывод сообщения о номере студента, который был добавлен в список на отчисление
				}
				// Если k не равно 0 (студент найден в списке неприкасаемых и его нельзя добавить в список на отчисление)
				else {
					cout << "Неприкасаемый " << endl;	// вывод сообщения о том, что студент неприкасаемый
				}

			}
		}
		// Команда для удаления студента из списка на отчисление и добавление его в список неприкасаемых студентов
		else if (command == "IMMORTAL") {
			cin >> numberStudent;	// ввод номера студента, которого нужно сделать неприкасаемым
			// Проверка, что введенный номер студента положительный и не превышает общее количество студентов в векторе student
			if (numberStudent > 0 && numberStudent <= student.size()) {
				// Проверка, есть ли в списке студентов на отчисление
				if (deduction.size() > 0) {
					// Цикл для проверки, есть ли студент с введенным номером в списке студентов на отчисление
					for (int i = 0; i < deduction.size(); i++) {
						// Если студент найден в списке на отчисление
						if (deduction[i] == student[numberStudent - 1]) {
							deduction.erase(deduction.begin() + i);	// студент удаляется из вектора deduction
							break;	// цикл прерывается
						}
					}
				}
				inviolable.push_back(student[numberStudent - 1]);	// студент с введенным номером добавляется в вектор inviolable
				cout << "Student " << numberStudent << " is immortal!" << endl;	// вывод сообщения о том, что студент стал неприкасаемым
			}
		}
		// Команда для вывода списка на отчисление
		else if (command == "TOP-LIST") {
			cout << "List of students for expulsion: " << endl;	// вывод заголовка списка студентов, которые должны быть отчислены
			sort(begin(deduction), end(deduction));	// сортировка вектора deduction по возрастанию
			int k = 1;	// переменная для нумерации студентов в отсортированном списке
			// Цикл, который проходится по каждому студенту в отсортированном векторе deduction
			for (string i : deduction) {
				// Цикл, который проходится по каждому студенту в векторе student
				for (int j = 0; j < student.size(); j++) {
					// Если текущий студент в deduction совпадает с текущим студентом в student
					if (i == student[j]) {
						// Вывод информации о студенте, включая его порядковый номер в списке, фамилию и номер в общем списке студентов
						cout << "Student " << k << " : " << i << " " << j + 1 << endl;
						k++;	// увеличивается на 1, чтобы следующий студент получил следующий порядковый номер
						break;	// цикл прерывается
					}
				}

			}
		}
		// Команда для вывода количества студентов в списке на отчисление
		else if (command == "SCOUNT") {
			cout << "List of students for expulsion consists of " << deduction.size() << " students" << endl;
		}
	}
}