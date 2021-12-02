// consoleInterface.h - класс ConsoleInterface
#pragma once
#include "STLInterface.h"
#include "userVector.h"
#include "userMultimap.h"

class ConsoleInterface {
private:
	static const int INSERTCINEMAFROMFILE = 1;                 // Действие 1
	static const int INSERTCOMPUTINGCENTERFROMFILE = 2;        // Действие 2
	static const int SEARCHCINEMA = 3;                         // Действие 3
	static const int SEARCHCOMPUTINGCENTER = 4;                // Действие 4
	static const int RATEFILLCINEMA = 5;                       // Действие 5
	static const int PREVIOUSLYYEARCOMPUTINGCENTER = 6;        // Действие 6
	static const int PRINTCINEMA = 7;                          // Действие 7
	static const int PRINTCOMPUTINGCENTER = 8;                 // Действие 8
	static const int EXIT = 0;                                 // Действие 0
	int _action = 0;                                           // Текущее действие

	// Приватный метод для обработки приветствия программы.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void Welcome() {
		cout << "Hello, wordl!" << endl << endl;
	};

	// Приватный метод для отображения меню программы.
	// Входных параметров нет.
	// Возвращаемых значений нет.
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

	// Приватный метод для обработки завершения программы.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void Exit() {
		cout << "Goodbye, world!" << endl;
	};

	// Приватный метод для обработки неверного действия.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void InvalidAction() {
		cout << "Invalid entered action!" << endl;
	};

public:
	// Публичный метод для запуска консольного интерфейса.
	// Входных параметров нет.
	// Возвращаемых значений нет.
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