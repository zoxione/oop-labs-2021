// cinema.h - ����� Cinema
#pragma once
#include <string>
using std::string;

// ��������� �������
struct Time {
	int hours;
	int minutes;
};

class Cinema {
private:
	int _id = 0;             // ������������� ������
	string _name = "";       // �������� ������
	int _seats = 0;          // ���������� ����
	int _viewers = 0;        // ���������� ��������
	double _price = 0;       // ���� ������
	Time _start;             // ������ ������
public:
	// ����������� �� ���������
	Cinema() = default;

	// ����������� � ��������� �����������
	Cinema(const int& id, const string& name, const int& seats, const int& viewers, const double& price, const Time& start)
		:_id(id), _name(name), _seats(seats), _viewers(viewers), _price(price), _start(start) {

	};

	// ��������� ����� ��� ��������� ��������������.
	// ������� ���������� ���.
	// ������������ ��������: _id �������.
	const int& GetId() const {
		return _id;
	};

	// ��������� ����� ��� ��������� �������� ������.
	// ������� ���������� ���.
	// ������������ ��������: _name �������.
	const string& GetName() const {
		return _name;
	};

	// ��������� ����� ��� ��������� ���������� ����.
	// ������� ���������� ���.
	// ������������ ��������: _seats �������.
	const int& GetSeats() const {
		return _seats;
	};

	// ��������� ����� ��� ��������� ���������� ��������.
	// ������� ���������� ���.
	// ������������ ��������: _viewers �������.
	const int& GetViewers() const {
		return _viewers;
	};

	// ��������� ����� ��� ��������� ��������� ������.
	// ������� ���������� ���.
	// ������������ ��������: _price �������.
	const double& GetPrice() const {
		return _price;
	};

	// ��������� ����� ��� ��������� ������ ������.
	// ������� ���������� ���.
	// ������������ ��������: _start �������.
	const Time& GetStart() const {
		return _start;
	};

	// ��������� ����� ��� ��������� �������� ���������� ����.
	// ������� ���������� ���.
	// ������������ ��������: rate � ���������.
	const double RateFill() const {
		double rate = (_viewers * 1.0) / (_seats * 1.0) * 100;
		return rate;
	};
};