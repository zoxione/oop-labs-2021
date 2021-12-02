// rectangle.h - класс Rectangle
#pragma once
#include "shape.h"

class Rectangle :public Shape {
private:
    // Приватный метод для вычисления точек прямоугольника
    void calculatePoints() {
        _points[1].x = _points[0].x + _lengh;
        _points[1].y = _points[0].y;

        _points[2].x = _points[0].x + _lengh;
        _points[2].y = _points[0].y + _width;

        _points[3].x = _points[0].x;
        _points[3].y = _points[0].y + _width;
    };
public:
    // Конструктор по умолчанию
    Rectangle() {
        _type = "Rectangle";
        _countPoints = 4;
        _points = new Point[_countPoints];

        cout << "Введите левую нижнюю точку прямоугольника (x y): ";
        cin >> _points[0].x >> _points[0].y;

        cout << "Длина прямоугольника: ";
        cin >> _lengh;
        cout << "Ширина прямоугольника: ";
        cin >> _width;

        calculateCenterPoint();
        calculatePoints();
        calculateArea();
    };

    // Декстркутор с очищением дин.памяти
    ~Rectangle() {
        delete[] _points;
    };

    // Публичный метод для вычисления площади прямоугольника
    void calculateArea() override {
        if (_area == 0) {
            _area = _lengh * _width;
        }
    };

    // Публичный метод для вычисления центра тяжести
    void calculateCenterPoint() override {
        _centerPoint.x = _points[0].x + _lengh / 2;
        _centerPoint.y = _points[0].y + _width / 2;
    };

    // Публичный метод для вращения прямоугольника
    void rotate(double angle) override {
        int a = ((angle - int(angle)) < 0.5) ? int(angle) : int(angle) + 1;
        angle *= M_PI / 180.;

        for (int i = 0; i < _countPoints; i++) {
            double x_shifted = _points[i].x - _centerPoint.x;
            double y_shifted = _points[i].y - _centerPoint.y;
            _points[i].x = _centerPoint.x + (x_shifted * cos(angle) - y_shifted * sin(angle));
            _points[i].y = _centerPoint.y + (x_shifted * sin(angle) + y_shifted * cos(angle));
        }

        if ((a % 90) != 0) {
            (_points[0].x > _points[2].x) ? _lengh = _points[0].x - _points[2].x : _lengh = _points[2].x - _points[0].x;
            (_points[0].y > _points[2].y) ? _width = _points[0].y - _points[2].y : _width = _points[2].y - _points[0].y;
        }
    };

    // Публичный метод для перемещения прямоугольника
    void move(double x, double y) override {
        _points[0].x += x;
        _points[0].y += y;

        calculateCenterPoint();
        calculatePoints();
    };
};
