// STLInterface.h - ����� STLInterface
#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
//#include <vld>
using namespace std;
#include "cinema.h"
#include "computingCenter.h";

class STLInterface {
public:
	// ����������� ������� ��� ����� � ����� ��������.
	// ������� ���������� ���.
	// ������������ �������� ���.
	virtual void Insert() = 0;

	// ����������� ������� ��� ������ ��������.
	// ������� ���������� ���.
	// ������������ �������� ���.
	virtual void Search() = 0;

	// ����������� ������� ��� ������ ��������.
	// ������� ���������� ���.
	// ������������ �������� ���.
	virtual void Print() = 0;

	// ����������� ������� ��� �������������� ������.
	// ������� ���������� ���.
	// ������������ �������� ���.
	virtual void Optional() = 0;
};