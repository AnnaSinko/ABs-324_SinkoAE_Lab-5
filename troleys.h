#pragma once	// гарантирантия, что заголовочный файл будет включен только один раз в каждом исходном файле (предотвращение множественного определения)
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;	// позволяет использовать стандартные идентификаторы без уточнения пространства имен

enum class Type {	// перечисление Type, которое определяет четыре константы
	CREATE_TRL,
	TRL_IN_STOP,
	STOPS_IN_TRL,
	TRLS
};

// определения функций, которые принимают map, где ключ - string, значение - set из string
void CreateTrl(map <string, set<string>>& Trolleybus);	// принимает map по ссылке (&), что позволяет изменять ее содержимое внутри функции
void TrlInStop(map <string, set<string>> Trolleybus);	// map передается по значению, что означает, что функция получает копию map, но не может изменить ее содержимое
void StopsInTrl(map <string, set<string>> Trolleybus);	// map передается по значению, что означает, что функция получает копию map, но не может изменить ее содержимое
void Trls(map <string, set<string>> Trolleybus);	// map передается по значению, что означает, что функция получает копию map, но не может изменить ее содержимое