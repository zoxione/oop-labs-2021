// computingCenter.h - класс ComputingCenter
#pragma once
#include <string>
using std::string;

class ComputingCenter {
private:
	int _number = 0;             // Номер лаборатории
	string _cpu = "";            // Тип процессора
	int _ram = 0;                // Величина ОЗУ
	int _disk = 0;               // Емкость диска
	string _monitor = "";        // Тип монитора
	int _year = 0;               // Год выпуска
public:
	// Конструктор по умолчанию
	ComputingCenter() = default;

	// Конструктор с заданными параметрами
	ComputingCenter(const int& number, const string& cpu, const int& ram, const int& disk, const string& monitor, const int& year)
		:_number(number), _cpu(cpu), _ram(ram), _disk(disk), _monitor(monitor), _year(year) {

	};

	// Публичный метод для получения номера лаборатории.
	// Входных параметров нет.
	// Возвращаемое значение: _number объекта.
	const int& GetNumber() const {
		return _number;
	};

	// Публичный метод для получения типа процессора.
	// Входных параметров нет.
	// Возвращаемое значение: _cpu объекта.
	const string& GetCpu() const {
		return _cpu;
	};

	// Публичный метод для получения величины ОЗУ.
	// Входных параметров нет.
	// Возвращаемое значение: _ram объекта.
	const int& GetRam() const {
		return _ram;
	};

	// Публичный метод для получения емкости диска.
	// Входных параметров нет.
	// Возвращаемое значение: _disk объекта.
	const int& GetDisk() const {
		return _disk;
	};

	// Публичный метод для получения типа монитора.
	// Входных параметров нет.
	// Возвращаемое значение: _monitor объекта.
	const string& GetMonitor() const {
		return _monitor;
	};

	// Публичный метод для получения года выпуска.
	// Входных параметров нет.
	// Возвращаемое значение: _year объекта.
	const int& GetYear() const {
		return _year;
	};
};