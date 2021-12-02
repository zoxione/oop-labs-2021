// Client.cpp
// ЮФУ, ИКТИБ, МОП ЭВМ
// Лабораторная работа № 3. Динамический выбор типа объектов
// Задание 7
// Отхонов Баир КТбо2-8; Бакухин Александр КТбо2-8
// 20.09.2021г.

#include <iostream>
//#include <vld>
#include "operations.h"
using namespace std;

// Фабричный метод для создания объектов классов
Shape* Shape::createShape(string typeShape) {
    Shape* shape = 0;

    if (typeShape == "Square") {
        shape = new Square();
    }
    else if (typeShape == "Rectangle") {
        shape = new Rectangle();
    }

    return shape;
};

int main() {
    setlocale(LC_ALL, "Russian");
    
    int count = 0, exit = 0;
    cout << "Количество фигур: ";
    cin >> count;

    cout << endl << "Введите тип фигуры:" << endl;
    cout << " - Square" << endl;
    cout << " - Rectangle" << endl;

    try {
        // Работа только с userOperations
        Operations userOperations = Operations(count);
        cout << endl << "Фигуры:" << endl;
        userOperations.printShapes();

        cout << endl << "В программе есть 6 операций: " << endl;
        cout << "1. Compare [номер 1] [номер 2]" << endl;
        cout << "2. IsIntersect [номер 1] [номер 2]" << endl;
        cout << "3. IsInclude [номер 1] [номер 2]" << endl;
        cout << "4. Rotate [номер] [угол]" << endl;
        cout << "5. Move [номер] [x] [y]" << endl;
        cout << "6. Shapes" << endl;
        cout << "Для выхода введите 'exit'." << endl;

        while (exit == 0) {
            cout << endl << "Введите операцию: ";
            string oper; int number1 = 0, number2 = 0;
            cin >> oper;

            if (oper == "Compare") {
                cin >> number1 >> number2;
                userOperations.Compare(number1, number2);
            }
            else if (oper == "IsIntersect") {
                cin >> number1 >> number2;
                userOperations.IsIntersect(number1, number2);
            }
            else if (oper == "IsInclude") {
                cin >> number1 >> number2;
                userOperations.IsInclude(number1, number2);
            }
            else if (oper == "Rotate") {
                cin >> number1 >> number2;
                userOperations.Rotate(number1, number2);
            }
            else if (oper == "Move") {
                double x1, x2; cin >> number1 >> x1 >> x2;
                userOperations.Move(number1, x1, x2);
            }
            else if (oper == "Shapes") {
                userOperations.printShapes();
            }
            else if (oper == "exit") {
                cout << "Программа завершена." << endl;
                exit = 1;
            }
            else {
                cout << "Неверная операция!" << endl;
            }
        }
    }
    catch (invalid_argument &e) {
        // Обработка ошибок
        cerr << e.what();
        return 1;
    }

    return 0;
}
