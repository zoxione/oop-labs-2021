// computingCenter.h - ����� ComputingCenter
#pragma once
#include <string>
using std::string;

class ComputingCenter {
private:
	int _number = 0;             // ����� �����������
	string _cpu = "";            // ��� ����������
	int _ram = 0;                // �������� ���
	int _disk = 0;               // ������� �����
	string _monitor = "";        // ��� ��������
	int _year = 0;               // ��� �������
public:
	// ����������� �� ���������
	ComputingCenter() = default;

	// ����������� � ��������� �����������
	ComputingCenter(const int& number, const string& cpu, const int& ram, const int& disk, const string& monitor, const int& year)
		:_number(number), _cpu(cpu), _ram(ram), _disk(disk), _monitor(monitor), _year(year) {

	};

	// ��������� ����� ��� ��������� ������ �����������.
	// ������� ���������� ���.
	// ������������ ��������: _number �������.
	const int& GetNumber() const {
		return _number;
	};

	// ��������� ����� ��� ��������� ���� ����������.
	// ������� ���������� ���.
	// ������������ ��������: _cpu �������.
	const string& GetCpu() const {
		return _cpu;
	};

	// ��������� ����� ��� ��������� �������� ���.
	// ������� ���������� ���.
	// ������������ ��������: _ram �������.
	const int& GetRam() const {
		return _ram;
	};

	// ��������� ����� ��� ��������� ������� �����.
	// ������� ���������� ���.
	// ������������ ��������: _disk �������.
	const int& GetDisk() const {
		return _disk;
	};

	// ��������� ����� ��� ��������� ���� ��������.
	// ������� ���������� ���.
	// ������������ ��������: _monitor �������.
	const string& GetMonitor() const {
		return _monitor;
	};

	// ��������� ����� ��� ��������� ���� �������.
	// ������� ���������� ���.
	// ������������ ��������: _year �������.
	const int& GetYear() const {
		return _year;
	};
};