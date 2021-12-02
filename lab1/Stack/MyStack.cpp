// ���, �����, ��� ���
// ������������ ������ � 1. ������ � ������� � �++
// ������� 9
// ������� ���� ����2-8; ������� ��������� ����2-8
// 05.09.2021�.

#include "stack.h"
#include <iostream>
#include <string>
#include <vld.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int size = 0, exit = 0;
    cout << "������� ������ �����: ";
    cin >> size;
    // �������� �����
    if (cin.fail() || size < 0) {
        cout << "�������� ������ �����!" << endl;
        return 1;
    }
    Stack userStack(size);

    cout << endl << "� ��������� ���� 4 ��������: " << endl;
    cout << "1.push [��������]" << endl;
    cout << "2.pop" << endl;
    cout << "3.isEmpty" << endl;
    cout << "4.back" << endl;
    cout << "��� ������ ������� 'exit'." << endl;

    try {
        // �������� ���� ���������
        while (exit == 0) {
            cout << endl << "������� ��������: ";
            string oper; int value = 0;
            cin >> oper;

            if (oper == "push") {
                cin >> value;
                if (cin.fail()) {
                    cout << "������ �����!" << endl;
                    cin.clear();
                    // ������������� ������ ����� �� �����
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else {
                    userStack.push(value);
                    cout << "������" << endl;
                }
            }
            else if (oper == "pop") {
                userStack.pop();
                cout << "������" << endl;
            }
            else if (oper == "isEmpty") {
                if (userStack.isEmpty()) {
                    cout << "���� ������" << endl;
                }
                else {
                    cout << "���� �� ������" << endl;
                }
            }
            else if (oper == "back") {
                if (userStack.getCount() != 0) {
                    cout << userStack.back() << endl;
                }
                else {
                    cout << "���� ������" << endl;
                }
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
    catch (int) {
        // ��������� ������
        cout << "����� �� ������� �����!" << endl;
        return 1;
    }

    return 0;
}