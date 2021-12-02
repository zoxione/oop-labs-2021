// Client.cpp
// ���, �����, ��� ���
// ������������ ������ � 2. ������������ � �++
// ������� 11
// ������� ���� ����2-8; ������� ��������� ����2-8
// 12.09.2021�.

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
    cout << "������� ���������� ������: ";
    cin >> countStack;
    cout << "������� ���������� ��������: ";
    cin >> countQueue;

    try {
        // ������ ������ � userStorage
        Storage userStorage(countStack, countQueue);
        cout << endl;
        cout << "���������:" << endl;
        userStorage.printStorage();

        cout << endl << "� ��������� ���� 5 ��������: " << endl;
        cout << "1. push [�����] [��������]" << endl;
        cout << "2. pop [�����]" << endl;
        cout << "3. isEmpty [�����]" << endl;
        cout << "4. front [�����]" << endl;
        cout << "5. storage" << endl;
        cout << "��� ������ ������� 'exit'." << endl;

        int exit = 0;
        while (exit == 0) {
            cout << endl << "������� ��������: ";
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
                cout << endl << "��������� ���������." << endl;
                exit = 1;
            }
            else {
                cout << "�������� ��������!" << endl;
            }
        }
    }
    catch (std::out_of_range &e) {
        // ��������� ������
        std::cerr << e.what();
        return 1;
    }

    return 0;
}