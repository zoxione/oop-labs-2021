// operations.cpp - реализация класса Operations
#include "operations.h"

bool Operations::isValid(int i) {
    if ((i - 1) >= 0 && (i - 1) < _countShapes) {
        return true;
    }
    else {
        cout << "Неверно указано значение номера!" << endl;
        return false;
    }
};

Operations::Operations(int count) {
    _countShapes = count;
    _shapesList = new Shape * [count];
    string typeShape; int i = 0;

    while (count) {
        cout << endl << "Тип фигуры " << i + 1 << ": ";
        cin >> typeShape;

        if (typeShape == "Square" || typeShape == "Rectangle") {
            _shapesList[i] = Shape::createShape(typeShape);
            count--;
            i++;
        }
        else throw invalid_argument("Неверный тип фигуры!");
    }
};

Operations::~Operations() {
    for (int i = 0; i < _countShapes; i++) {
        delete _shapesList[i];
    }
    delete[] _shapesList;
};

void Operations::Compare(int x1, int x2) {
    if (isValid(x1) && isValid(x2)) {
        double s1 = _shapesList[x1 - 1]->getArea(),
            s2 = _shapesList[x2 - 1]->getArea();

        cout << "Площадь " << x1 << "-й фигуры: " << fixed << setprecision(2) << s1 << endl;
        cout << "Площадь " << x2 << "-й фигуры: " << fixed << setprecision(2) << s2 << endl;

        if (s1 > s2) {
            cout << "Соответственно, площадь " << x1 << "-й фигуры больше." << endl;
        }
        else if (s1 < s2) {
            cout << "Соответственно, площадь " << x2 << "-й фигуры больше." << endl;
        }
        else {
            cout << "Площади двух фигур равны." << endl;
        }
    }
};

void Operations::IsIntersect(int x1, int x2) {
    if (isValid(x1) && isValid(x2)) {
        Point centerPoint1 = _shapesList[x1 - 1]->getCenterPoint(),
            centerPoint2 = _shapesList[x2 - 1]->getCenterPoint();

        if ((abs(centerPoint2.x - centerPoint1.x) <= (_shapesList[x1 - 1]->getLengh() / 2 + _shapesList[x2 - 1]->getLengh() / 2)) && 
        (abs(centerPoint2.y - centerPoint1.y) <= (_shapesList[x1 - 1]->getWidth() / 2 + _shapesList[x2 - 1]->getWidth() / 2))) {
            cout << "Фигуры пересекаются." << endl;
        }
        else {
            cout << "Фигуры не пересекаются." << endl;
        }
    }
};

void Operations::IsInclude(int x1, int x2) {
    if (isValid(x1) && isValid(x2)) {
        Point* points1 = _shapesList[x1 - 1]->getPoints(),
            * points2 = _shapesList[x2 - 1]->getPoints();

        int countPoints1 = _shapesList[x1 - 1]->getCountPoints(),
            countPoints2 = _shapesList[x2 - 1]->getCountPoints();

        bool* checkPoints = new bool[countPoints1] {false};

        bool isIntersect = true;

        for (int i = 0; i < countPoints1; i++) {
            for (int j = 0; j < countPoints2; j++) {
                if (points1[i].x >= points2[j].x && points1[i].x <= points2[(j + 2) % countPoints2].x) {
                    if (points1[i].y >= points2[j].y && points1[i].y <= points2[(j + 2) % countPoints2].y) {
                        checkPoints[i] = true;
                    }
                }
            }
        }

        for (int i = 0; i < countPoints1; i++) {
            if (checkPoints[i] == false) {
                isIntersect = false;
                break;
            }
        }

        if (isIntersect == true) {
            cout << "Фигура " << x1 << " включается в фигуру " << x2 << "." << endl;
        }
        else {
            cout << "Фигура " << x1 << " не включается в фигуру " << x2 << "." << endl;
        }
    }
};

void Operations::Rotate(int i, int x) {
    if (isValid(i)) {
        _shapesList[i - 1]->rotate(x);
        cout << "Готово." << endl;
    }
};

void Operations::Move(int i, double x, double y) {
    if (isValid(i)) {
        _shapesList[i - 1]->move(x, y);
        cout << "Готово." << endl;
    }
};

void Operations::printShapes() {
    if (_countShapes == 0) {
        cout << "Фигуры не заданы." << endl;
    }
    else {
        for (int i = 0; i < _countShapes; i++) {
            Point* points = _shapesList[i]->getPoints();

            cout << i + 1 << ". ";
            if (_shapesList[i]->getType() == "Square") {
                cout << "Тип: Квадрат. ";
                cout << "Центр: " << fixed << setprecision(1) << _shapesList[i]->getCenterPoint().x << " " << _shapesList[i]->getCenterPoint().y;
                cout << ". Длина стороны: " << _shapesList[i]->getLengh() << "." << endl;
            }
            else {
                cout << "Тип: Прямоугольник. ";
                cout << "Центр: " << fixed << setprecision(1) << _shapesList[i]->getCenterPoint().x << " " << _shapesList[i]->getCenterPoint().y;
                cout << ". Длина: " << _shapesList[i]->getLengh() << ". Ширина: " << _shapesList[i]->getWidth() << "." << endl;
            }

            cout << "Точки: ";
            for (int j = 0; j < _shapesList[i]->getCountPoints(); j++) {
                cout << points[j].x << " " << points[j].y << "; ";
            }
            cout << endl;
        }
    }
};
