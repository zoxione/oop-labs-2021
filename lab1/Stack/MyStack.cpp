// ЮФУ, ИКТИБ, МОП ЭВМ
// Лабораторная работа № 1. Классы и объекты в С++
// Задание 9
// Отхонов Баир КТбо2-8; Бакухин Александр КТбо2-8
// 05.09.2021г.

#include "stack.h"
#include <iostream>
#include <string>
#include <vld.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int size = 0, exit = 0;
    cout << "Введите размер стека: ";
    cin >> size;
    // Проверка ввода
    if (cin.fail() || size < 0) {
        cout << "Неверный размер стека!" << endl;
        return 1;
    }
    Stack userStack(size);

    cout << endl << "В программе есть 4 операции: " << endl;
    cout << "1.push [значение]" << endl;
    cout << "2.pop" << endl;
    cout << "3.isEmpty" << endl;
    cout << "4.back" << endl;
    cout << "Для выхода введите 'exit'." << endl;

    try {
        // Основной цикл программы
        while (exit == 0) {
            cout << endl << "Введите операцию: ";
            string oper; int value = 0;
            cin >> oper;

            if (oper == "push") {
                cin >> value;
                if (cin.fail()) {
                    cout << "Ошибка ввода!" << endl;
                    cin.clear();
                    // Игнорирование строки ввода до конца
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    userStack.push(value);
                    cout << "Готово" << endl;
                }
            }
            else if (oper == "pop") {
                userStack.pop();
                cout << "Готово" << endl;
            }
            else if (oper == "isEmpty") {
                if (userStack.isEmpty()) {
                    cout << "Стек пустой" << endl;
                }
                else {
                    cout << "Стек не пустой" << endl;
                }
            }
            else if (oper == "back") {
                if (userStack.getCount() != 0) {
                    cout << userStack.back() << endl;
                }
                else {
                    cout << "Стек пустой" << endl;
                }
            }
            else if (oper == "exit") {
                cout << endl << "Программа завершена." << endl;
                exit = 1;
            }
            else {
                cout << "Неверная операция!" << endl;
            }
        }
    }
    catch (int) {
        // Обработка ошибки
        cout << "Выход за пределы стека!" << endl;
        return 1;
    }

    return 0;
}