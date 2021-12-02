// Client.cpp
// ЮФУ, ИКТИБ, МОП ЭВМ
// Лабораторная работа № 2. Наследование в С++
// Задание 11
// Отхонов Баир КТбо2-8; Бакухин Александр КТбо2-8
// 12.09.2021г.

#include <iostream>
#include <string>
//#include <vld.h>
#include "storage.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    setlocale(LC_ALL, "Russian");

    int countStack, countQueue;
    cout << "Введите количество стеков: ";
    cin >> countStack;
    cout << "Введите количество очередей: ";
    cin >> countQueue;

    try {
        // Работа только с userStorage
        Storage userStorage(countStack, countQueue);
        cout << endl;
        cout << "Хранилище:" << endl;
        userStorage.printStorage();

        cout << endl << "В программе есть 5 операций: " << endl;
        cout << "1. push [номер] [значение]" << endl;
        cout << "2. pop [номер]" << endl;
        cout << "3. isEmpty [номер]" << endl;
        cout << "4. front [номер]" << endl;
        cout << "5. storage" << endl;
        cout << "Для выхода введите 'exit'." << endl;

        int exit = 0;
        while (exit == 0) {
            cout << endl << "Введите операцию: ";
            string oper; int number = 0, value = 0;
            cin >> oper;

            if (oper == "push") {
                cin >> number >> value;
                userStorage.push(number, value);
            }
            else if (oper == "pop") {
                cin >> number;
                userStorage.pop(number);
            }
            else if (oper == "isEmpty") {
                cin >> number;
                userStorage.printEmpty(number);
            }
            else if (oper == "front") {
                cin >> number;
                userStorage.printFront(number);
            }
            else if (oper == "storage") {
                userStorage.printStorage();
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
    catch (std::out_of_range &e) {
        // Обработка ошибок
        std::cerr << e.what();
        return 1;
    }

    return 0;
}