// cinema.h - класс Cinema
#pragma once
#include <string>
using std::string;

// Структура времени
struct Time {
	int hours;
	int minutes;
};

class Cinema {
private:
	int _id = 0;             // Идентификатор фильма
	string _name = "";       // Название фильма
	int _seats = 0;          // Количество мест
	int _viewers = 0;        // Количество зрителей
	double _price = 0;       // Цена билета
	Time _start;             // Начало сеанса
public:
	// Конструктор по умолчанию
	Cinema() = default;

	// Конструктор с заданными параметрами
	Cinema(const int& id, const string& name, const int& seats, const int& viewers, const double& price, const Time& start)
		:_id(id), _name(name), _seats(seats), _viewers(viewers), _price(price), _start(start) {

	};

	// Публичный метод для получения идентификатора.
	// Входных параметров нет.
	// Возвращаемое значение: _id объекта.
	const int& GetId() const {
		return _id;
	};

	// Публичный метод для получения названия фильма.
	// Входных параметров нет.
	// Возвращаемое значение: _name объекта.
	const string& GetName() const {
		return _name;
	};

	// Публичный метод для получения количества мест.
	// Входных параметров нет.
	// Возвращаемое значение: _seats объекта.
	const int& GetSeats() const {
		return _seats;
	};

	// Публичный метод для получения количества зрителей.
	// Входных параметров нет.
	// Возвращаемое значение: _viewers объекта.
	const int& GetViewers() const {
		return _viewers;
	};

	// Публичный метод для получения стоимости билета.
	// Входных параметров нет.
	// Возвращаемое значение: _price объекта.
	const double& GetPrice() const {
		return _price;
	};

	// Публичный метод для получения начала сеанса.
	// Входных параметров нет.
	// Возвращаемое значение: _start объекта.
	const Time& GetStart() const {
		return _start;
	};

	// Публичный метод для получения процента заполнения зала.
	// Входных параметров нет.
	// Возвращаемое значение: rate в процентах.
	const double RateFill() const {
		double rate = (_viewers * 1.0) / (_seats * 1.0) * 100;
		return rate;
	};
};