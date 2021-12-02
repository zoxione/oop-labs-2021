// consoleInterface.h - ����� ConsoleInterface
#pragma once
#include "STLInterface.h"
#include "userVector.h"
#include "userMultimap.h"

class ConsoleInterface {
private:
	static const int INSERTCINEMAFROMFILE = 1;                 // �������� 1
	static const int INSERTCOMPUTINGCENTERFROMFILE = 2;        // �������� 2
	static const int SEARCHCINEMA = 3;                         // �������� 3
	static const int SEARCHCOMPUTINGCENTER = 4;                // �������� 4
	static const int RATEFILLCINEMA = 5;                       // �������� 5
	static const int PREVIOUSLYYEARCOMPUTINGCENTER = 6;        // �������� 6
	static const int PRINTCINEMA = 7;                          // �������� 7
	static const int PRINTCOMPUTINGCENTER = 8;                 // �������� 8
	static const int EXIT = 0;                                 // �������� 0
	int _action = 0;                                           // ������� ��������

	// ��������� ����� ��� ��������� ����������� ���������.
	// ������� ���������� ���.
	// ������������ �������� ���.
	void Welcome() {
		cout << "Hello, wordl!" << endl << endl;
	};

	// ��������� ����� ��� ����������� ���� ���������.
	// ������� ���������� ���.
	// ������������ �������� ���.
	void ShowMenu() {
		cout << "Choose action:" << endl;
		cout << "(" << INSERTCINEMAFROMFILE << ") Import cinema from file." << endl;
		cout << "(" << INSERTCOMPUTINGCENTERFROMFILE << ") Import computing center from file." << endl;
		cout << "(" << SEARCHCINEMA << ") Find cinema." << endl;
		cout << "(" << SEARCHCOMPUTINGCENTER << ") Find computing center." << endl;
		cout << "(" << RATEFILLCINEMA << ") Print rate fill." << endl;
		cout << "(" << PREVIOUSLYYEARCOMPUTINGCENTER << ") Print previously year." << endl;
		cout << "(" << PRINTCINEMA << ") Print cinema." << endl;
		cout << "(" << PRINTCOMPUTINGCENTER << ") Print computing center." << endl;
		cout << "(" << EXIT << ") Exit." << endl;
	};

	// ��������� ����� ��� ��������� ���������� ���������.
	// ������� ���������� ���.
	// ������������ �������� ���.
	void Exit() {
		cout << "Goodbye, world!" << endl;
	};

	// ��������� ����� ��� ��������� ��������� ��������.
	// ������� ���������� ���.
	// ������������ �������� ���.
	void InvalidAction() {
		cout << "Invalid entered action!" << endl;
	};

public:
	// ��������� ����� ��� ������� ����������� ����������.
	// ������� ���������� ���.
	// ������������ �������� ���.
	void Run() {
		try {
			Welcome();
			shared_ptr <STLInterface> cinemaVector, computingCenterMultimap;
			cinemaVector.reset(new UserVector);
			computingCenterMultimap.reset(new UserMultimap);

			do {
				ShowMenu();

				cin >> _action;
				cout << endl;

				switch (_action) {
					case (INSERTCINEMAFROMFILE): cinemaVector->Insert(); break;
					case (INSERTCOMPUTINGCENTERFROMFILE): computingCenterMultimap->Insert(); break;
					case (SEARCHCINEMA): cinemaVector->Search(); break;
					case (SEARCHCOMPUTINGCENTER): computingCenterMultimap->Search(); break;
					case (RATEFILLCINEMA): cinemaVector->Optional(); break;
					case (PREVIOUSLYYEARCOMPUTINGCENTER): computingCenterMultimap->Optional(); break;
					case (PRINTCINEMA): cinemaVector->Print(); break;
					case (PRINTCOMPUTINGCENTER): computingCenterMultimap->Print(); break;
					case (EXIT): Exit(); break;
					default: InvalidAction(); break;
				}

				cout << endl;
			} while (_action != 0);
		}
		catch (const exception& e) {
			cerr << e.what() << endl;
			exit(1);
		}
		catch (...) {
			cerr << "Unknown error!" << endl;
			exit(1);
		}
	};
};