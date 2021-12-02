// userVector.h - класс UserVector
#pragma once
#include "STLInterface.h"

class UserVector : public STLInterface {
private:
	vector <shared_ptr<Cinema>> _cinemaVector;   // Контейнер vector для указателей класса Cinema
public:
	// Публичный метод для ввода с файла объектов
	// класса Cinema в контейнер vector.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void Insert() override {
		if (_cinemaVector.size() > 0) {
			cout << "Already input." << endl;
			return;
		}
		
		string file;
		cout << "Enter file name: ";
		cin >> file;
		ifstream fin(file);
		//ifstream fin("cinema.txt");

		if (!fin) { throw logic_error("File not found!"); }

		string name = "";
		int seats = 0, viewers = 0;
		double price = 0;
		Time start;

		string str; int countCinema = 0, param = 0;
		while (getline(fin, str, '"')) {
			if (str == "" || str == " ") { continue; };

			if (str == "\n") {
				countCinema++;
				param = 0;
				shared_ptr <Cinema> newCinema(new Cinema(countCinema, name, seats, viewers, price, start));
				_cinemaVector.push_back(newCinema);
			}
			else {
				switch (param) {
					case (0): name = str; break;
					case (1): seats = stoi(str); break;
					case (2): viewers = stoi(str); break;
					case (3): price = stod(str); break;
					case (4): start.hours = stoi(str.substr(0, 2)); start.minutes = stoi(str.substr(3, 2)); break;
				default: break;
				}

				param++;
			}
		}

		// Сортировка по имени
		sort(_cinemaVector.begin(), _cinemaVector.end(), 
			[](shared_ptr<Cinema> one, shared_ptr<Cinema> next) -> bool {
				return one->GetName() < next->GetName();
			}
		);
		

		cout << "Done!" << endl;
		fin.close();
	};

	// Публичный метод для поиска объектов класса Cinema
	// в контейнере vector по названию фильма и вывод их.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void Search() override {
		string find;
		cout << "Enter name cinema: ";
		cin.ignore();
		getline(cin, find);
		bool isFind = false;

		for (auto elem : _cinemaVector) {
			if (elem->GetName() == find) {
				if (isFind != true) {
					cout << setfill(' ') << left << setw(5) << "Id" << setw(44) << "Name" << setw(8) << "Seats" << setw(10) << "Viewers" << setw(9) << "Price" << setw(13) << "Start time" << endl;
				}
				isFind = true;
				Time start = elem->GetStart();
				cout << setfill(' ') << left << setw(5) << elem->GetId() << setw(44) << elem->GetName() << setw(8);
				cout << elem->GetSeats() << setw(10) << elem->GetViewers() << setw(9);
				cout << fixed << setprecision(2) << elem->GetPrice() << setw(13);
				cout << setfill('0') << setw(2) << start.hours << ":" << setw(2) << start.minutes << endl;
			}
		}

		if (isFind == false) {
			cout << "Not found." << endl;
		}
	};

	// Публичный метод для вывода объектов 
	// класса Cinema в контейнере vector.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void Print() override {
		if (_cinemaVector.size() == 0) {
			cout << "Cinema is empty." << endl;
		}
		else {
			cout << setfill(' ') << left << setw(5) << "Id" << setw(44) << "Name" << setw(8) << "Seats" << setw(10) << "Viewers" << setw(9) << "Price" << setw(13) << "Start time" << endl;
			for (auto elem : _cinemaVector) {
				Time start = elem->GetStart();
				cout << setfill(' ') << left << setw(5) << elem->GetId() << setw(44) << elem->GetName() << setw(8);
				cout << elem->GetSeats() << setw(10) << elem->GetViewers() << setw(9);
				cout << fixed << setprecision(2) << elem->GetPrice() << setw(13);
				cout << right << setfill('0') << setw(2) << start.hours << ":" << setfill('0') << setw(2) << start.minutes << endl;
			}
		}
	};

	// Публичный метод для вывода процента 
	// заполнения зала для введенного фильма.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void Optional() override {
		int number;
		cout << "Enter number cinema: ";
		cin >> number;
		bool isFind = false;

		for (auto elem : _cinemaVector) {
			if (elem->GetId() == number) {
				isFind = true;
				cout << elem->GetName() << ": ";
				cout << fixed << setprecision(2) << elem->RateFill() << "%" << endl;
			}
		}

		if (isFind == false) {
			cout << "Not found." << endl;
		}
	};
};