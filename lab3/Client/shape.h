// shape.h - класс Shape
#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <math.h>
using namespace std;

// Структура точки
struct Point { double x, y; }; 

class Shape {
protected:
    Point* _points = nullptr;      // Точки фигуры
    Point _centerPoint;            // Центр тяжести фигуры
    int _countPoints = 0;          // Количество точек фигуры
    string _type = "";             // Тип фигуры
    double _area = 0;              // Площадь фигуры 
    double _lengh = 0;             // Длина фигуры 
    double _width = 0;             // Ширина фигуры 
    double _angle = 0;             // Угол фигуры 
    void destroy() { if (_points) { delete[] _points; } }; // Приватный метод очищения дин. памяти.
public:
    // Конструктор по умолчанию
    Shape() = default;

    // Констуктор копирования
    Shape(const Shape& s) {
        destroy();
        _centerPoint = s._centerPoint;
        _countPoints = s._countPoints;
        _type = s._type;
        _area = s._area;
        _lengh = s._lengh;
        _width = s._width;
        _angle = s._angle;
        _points = new Point[_countPoints];
        memcpy(_points, s._points, _countPoints);
    }

    // Виртуальный деструктор
    virtual ~Shape() { delete[] _points; };

    // Операция присваивания
    Shape& operator=(const Shape& s) {
        //предотвращение самокопирования
        if (this == &s) {
            // возврат вызвавшего объекта
            return *this;
        }
        destroy();
        _centerPoint = s._centerPoint;
        _countPoints = s._countPoints;
        _type = s._type;
        _area = s._area;
        _lengh = s._lengh;
        _width = s._width;
        _angle = s._angle;
        _points = new Point[_countPoints];
        memcpy(_points, s._points, _countPoints);
        return *this;
    }

    // Статический метод для создания фигуры
    static Shape* createShape(string typeShape);

    // Публичный метод для получения центра тяжести
    Point getCenterPoint() {
        return _centerPoint;
    };

    // Публичный метод для получения точек фигуры
    Point* getPoints() {
        return _points;
    };

    // Публичный метод для получения количества точек
    int getCountPoints() {
        return _countPoints;
    };

    // Публичный метод для получения типа фигуры
    string getType() {
        return _type;
    };

    // Публичный метод для получения площади фигуры
    double getArea() {
        return _area;
    };

    // Публичный метод для получения длины фигуры
    double getLengh() {
        return _lengh;
    };

    // Публичный метод для получения ширины фигуры
    double getWidth() {
        return _width;
    };

    // Публичный метод для получения угла фигуры
    double getAngle() {
        return _angle;
    };

    // Виртуальные функции
    virtual void calculateArea() = 0;
    virtual void calculateCenterPoint() = 0;
    virtual void rotate(double angle) = 0;
    virtual void move(double x, double y) = 0;
};
