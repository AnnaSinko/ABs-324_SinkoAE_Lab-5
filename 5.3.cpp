#include "troleys.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map <string, set<string>> Trolleybus;	// map для хранения информации о троллейбусах и их остановках
	// клюя - название троллейбуса, значение - set уникальных названий остановок

	while (true) {	// бесконечный цикл, который будет выполняться до тех пор, пока программа не будет завершена внешним образом
		cout << "Введите команду: ";
		string tral1 = "";	// строка объявляет переменную tral1 для хранения введенной команды
		cin >> tral1;	// считывание введенной команды
		// Какая команда была введена
		int i = -1;	// устанавливается переменная i в соответствующее значение для Type
		if (tral1 == "CREATE_TRL") {
			i = 0;
		}
		else if (tral1 == "TRL_IN_STOP") {
			i = 1;
		}
		else if (tral1 == "STOPS_IN_TRL") {
			i = 2;
		}
		else if (tral1 == "TRLS") {
			i = 3;
		}
		Type com = Type(i);	// строка создает переменную com типа Type и инициализирует ее значением i
		switch (com) {	// выбор действия в зависимости от введенной команды
		// Различные функции в зависимости от введенной команды
		case Type::CREATE_TRL:
			CreateTrl(Trolleybus);
			break;
		case Type::TRL_IN_STOP:
			TrlInStop(Trolleybus);
			break;
		case Type::STOPS_IN_TRL:
			StopsInTrl(Trolleybus);
			break;
		case Type::TRLS:
			Trls(Trolleybus);
			break;
		// завершает выполнение текущей итерации цикла
		default:
			break;
		}

	}

}