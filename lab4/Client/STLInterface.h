// STLInterface.h - класс STLInterface
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
	// Виртуальная функция для ввода с файла объектов.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	virtual void Insert() = 0;

	// Виртуальная функция для поиска объектов.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	virtual void Search() = 0;

	// Виртуальная функция для вывода объектов.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	virtual void Print() = 0;

	// Виртуальная функция для дополнительной задачи.
	// Входных параметров нет.
	// Возвращаемых значений нет.
	virtual void Optional() = 0;
};