// shape.h - ����� Shape
#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <math.h>
using namespace std;

// ��������� �����
struct Point { double x, y; }; 

class Shape {
protected:
    Point* _points = nullptr;      // ����� ������
    Point _centerPoint;            // ����� ������� ������
    int _countPoints = 0;          // ���������� ����� ������
    string _type = "";             // ��� ������
    double _area = 0;              // ������� ������ 
    double _lengh = 0;             // ����� ������ 
    double _width = 0;             // ������ ������ 
    double _angle = 0;             // ���� ������ 
    void destroy() { if (_points) { delete[] _points; } }; // ��������� ����� �������� ���. ������.
public:
    // ����������� �� ���������
    Shape() = default;

    // ���������� �����������
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

    // ����������� ����������
    virtual ~Shape() { delete[] _points; };

    // �������� ������������
    Shape& operator=(const Shape& s) {
        //�������������� ���������������
        if (this == &s) {
            // ������� ���������� �������
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

    // ����������� ����� ��� �������� ������
    static Shape* createShape(string typeShape);

    // ��������� ����� ��� ��������� ������ �������
    Point getCenterPoint() {
        return _centerPoint;
    };

    // ��������� ����� ��� ��������� ����� ������
    Point* getPoints() {
        return _points;
    };

    // ��������� ����� ��� ��������� ���������� �����
    int getCountPoints() {
        return _countPoints;
    };

    // ��������� ����� ��� ��������� ���� ������
    string getType() {
        return _type;
    };

    // ��������� ����� ��� ��������� ������� ������
    double getArea() {
        return _area;
    };

    // ��������� ����� ��� ��������� ����� ������
    double getLengh() {
        return _lengh;
    };

    // ��������� ����� ��� ��������� ������ ������
    double getWidth() {
        return _width;
    };

    // ��������� ����� ��� ��������� ���� ������
    double getAngle() {
        return _angle;
    };

    // ����������� �������
    virtual void calculateArea() = 0;
    virtual void calculateCenterPoint() = 0;
    virtual void rotate(double angle) = 0;
    virtual void move(double x, double y) = 0;
};
