// square.h - ����� Square
#pragma once
#include "shape.h"

class Square :public Shape {
private:
    // ��������� ����� ��� ���������� ����� ��������
    void calculatePoints() {
        _points[1].x = _points[0].x + _lengh;
        _points[1].y = _points[0].y;

        _points[2].x = _points[0].x + _lengh;
        _points[2].y = _points[0].y + _width;

        _points[3].x = _points[0].x;
        _points[3].y = _points[0].y + _width;
    };
public:
    // ����������� �� ���������
    Square() {
        _type = "Square";
        _countPoints = 4;
        _points = new Point[_countPoints];

        cout << "������� ����� ������ ����� �������� (x y): ";
        cin >> _points[0].x >> _points[0].y;

        cout << "����� ������� ��������: ";
        cin >> _lengh;
        _width = _lengh;

        calculateCenterPoint();
        calculatePoints();
        calculateArea();
    };

    // ����������� � ��������� ���.������
    ~Square() {
        delete[] _points;
    };

    // ��������� ����� ��� ���������� ������� ��������
    void calculateArea() override {
        if (_area == 0) {
            _area = _lengh * _lengh;
        }
    };

    // ��������� ����� ��� ���������� ������ �������
    void calculateCenterPoint() override {
        _centerPoint.x = _points[0].x + _lengh / 2;
        _centerPoint.y = _points[0].y + _width / 2;
    };

    // ��������� ����� ��� �������� ��������
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

    // ��������� ����� ��� ����������� ��������
    void move(double x, double y) override {
        _points[0].x += x;
        _points[0].y += y;

        calculateCenterPoint();
        calculatePoints();
    };
};
