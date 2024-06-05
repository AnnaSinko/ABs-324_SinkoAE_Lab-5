#include "troleys.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map <string, set<string>> Trolleybus;	// map ��� �������� ���������� � ������������ � �� ����������
	// ���� - �������� �����������, �������� - set ���������� �������� ���������

	while (true) {	// ����������� ����, ������� ����� ����������� �� ��� ���, ���� ��������� �� ����� ��������� ������� �������
		cout << "������� �������: ";
		string tral1 = "";	// ������ ��������� ���������� tral1 ��� �������� ��������� �������
		cin >> tral1;	// ���������� ��������� �������
		// ����� ������� ���� �������
		int i = -1;	// ��������������� ���������� i � ��������������� �������� ��� Type
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
		Type com = Type(i);	// ������ ������� ���������� com ���� Type � �������������� �� ��������� i
		switch (com) {	// ����� �������� � ����������� �� ��������� �������
		// ��������� ������� � ����������� �� ��������� �������
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
		// ��������� ���������� ������� �������� �����
		default:
			break;
		}

	}

}