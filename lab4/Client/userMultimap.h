// userMultimap.h - класс UserMultimap
#pragma once
#include "STLInterface.h"

class UserMultimap : public STLInterface {
private:
	multimap <int, shared_ptr<ComputingCenter>> _computingCenterMultimap;  // Контейнер multimap для указателей класса ComputingCenter
public:
	// Публичный метод для ввода с файла объектов
	// класса ComputingCenter в контейнер multimap.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void Insert() override {
		if (_computingCenterMultimap.size() > 0) {
			cout << "Already input." << endl;
			return;
		}

		string file;
		cout << "Input file name: ";
		cin >> file;
		ifstream fin(file);
		//ifstream fin("ComputingCenter.txt");

		if (!fin) { throw logic_error("File not found!"); }

		int number = 0;
		string cpu = "";
		int ram = 0, disk = 0;
		string monitor = "";
		int year = 0;

		string str; int count = 0;
		while (getline(fin, str, '"')) {
			if (str == "" || str == " ") { continue; };

			if (str == "\n") {
				count = 0;
				shared_ptr<ComputingCenter> newComputingCenter(new ComputingCenter(number, cpu, ram, disk, monitor, year));
				_computingCenterMultimap.emplace(number, newComputingCenter);

			}
			else {
				switch (count) {
					case (0): number = stoi(str); break;
					case (1): cpu = str; break;
					case (2): ram = stoi(str); break;
					case (3): disk = stoi(str); break;
					case (4): monitor = str; break;
					case (5): year = stoi(str); break;
				default: break;
				}

				count++;
			}
		}

		cout << "Done!" << endl;
		fin.close();
	};

	// Публичный метод для поиска объектов класса ComputingCenter
	// в контейнере multimap по номеру лаборатории и вывод их.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void Search() override {
		int find;
		cout << "Enter laboratory number: ";
		cin >> find;
		bool isFind = false;

		for (auto elem : _computingCenterMultimap) {
			if (elem.second->GetNumber() == find) {
				isFind = true;
				cout << setfill(' ') << left << setw(6) << elem.second->GetNumber() << setw(8);
				cout << elem.second->GetCpu() << setw(6) << elem.second->GetRam() << setw(7);
				cout << elem.second->GetDisk() << setw(10) << elem.second->GetMonitor() << setw(7);
				cout << elem.second->GetYear() << endl;
			}
		}

		if (isFind == false) {
			cout << "Not found." << endl;
		}
	};

	// Публичный метод для вывода объектов 
	// класса ComputingCenter в контейнере multimap.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void Print() override {
		if (_computingCenterMultimap.size() == 0) {
			cout << "Computing center is empty." << endl;
		}
		else {
			cout << setfill(' ') << left << setw(6) << "Lab" << setw(8) << "CPU" << setw(6) << "RAM" << setw(7) << "Disk" << setw(10) << "Monitor" << setw(7) << "Year" << endl;
			for (auto elem : _computingCenterMultimap) {
				cout << left << setw(6) << elem.second->GetNumber() << setw(8);
				cout << elem.second->GetCpu() << setw(6) << elem.second->GetRam() << setw(7);
				cout << elem.second->GetDisk() << setw(10) << elem.second->GetMonitor() << setw(7);
				cout << elem.second->GetYear() << endl;
			}
		}
	};

	// Публичный метод для вывода объектов класса ComputingCenter, 
	// которые выпущены ранее вводимого года.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	void Optional() override {
		int year;
		cout << "Enter year: ";
		cin >> year;
		bool isFind = false;

		for (auto elem : _computingCenterMultimap) {
			if (elem.second->GetYear() < year) {
				isFind = true;
				cout << setfill(' ') << left << setw(6) << elem.first << setw(8);
				cout << elem.second->GetCpu() << setw(6) << elem.second->GetRam() << setw(7);
				cout << elem.second->GetDisk() << setw(10) << elem.second->GetMonitor() << setw(7);
				cout << elem.second->GetYear() << endl;
			}
		}

		if (isFind == false) {
			cout << "Not found." << endl;
		}
	};
};