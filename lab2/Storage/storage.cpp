// storage.cpp - реализация класса Storage
#include "storage.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool Storage::isValid(int i) {
    if ((i - 1) >= 0 && (i - 1) < _countStack + _countQueue) {
        return true;
    }
    else {
        cout << "Неверно указано значение номера!" << endl;
        return false;
    }
};

Storage::Storage(int n, int m) {
    _countStack = n;
    _countQueue = m;
    _containerList = new Container * [_countStack + _countQueue];

    int size;
    for (int i = 0; i < _countStack; i++) {
        cout << "Введите размер стека " << i + 1 << ": ";
        cin >> size;
        _containerList[i] = new Stack(size);
    }
    for (int i = 0; i < _countQueue; i++) {
        cout << "Введите размер очереди " << i + 1 << ": ";
        cin >> size;
        _containerList[i + _countStack] = new Queue(size);
    }
};

Storage::~Storage() {
    for (int i = 0; i < _countStack + _countQueue; i++) {
        delete _containerList[i];
    }
    delete[] _containerList;
}

void Storage::printStorage() {
    if (_countStack + _countQueue == 0) {
        cout << "Хранилище пустое." << endl;
    }
    else {
        for (int i = 0; i < _countStack + _countQueue; i++) {
            cout << i + 1 << ". ";
            cout << "Тип: " << ((i < _countStack) ? "Стек. " : "Очередь. ");
            cout << "Размер: " << _containerList[i]->getSize() << ". ";
            cout << "Количество элементов: " << _containerList[i]->getCount() << endl;
        }
    }
}

void Storage::push(int i, int x) {
    if (isValid(i)) {
        _containerList[i - 1]->push(x);
        cout << "Элемент " << x << " добавлен." << endl;
    }
}

void Storage::pop(int i) {
    if (isValid(i)) {
        _containerList[i - 1]->pop();
        cout << "Элемент удален." << endl;
    }
}

void Storage::printEmpty(int i) {
    if (isValid(i)) {
        if (!_containerList[i - 1]->isEmpty()) {
            if ((i - 1) < _countStack) {
                cout << "Стек не пустой." << endl;
            }
            else {
                cout << "Очередь не пустая." << endl;
            }
        }
        else {
            cout << "Контейнер пустой." << endl;
        }
    }
}

void Storage::printFront(int i) {
    if (isValid(i)) {
        if ((i - 1) < _countStack) {
            if (_containerList[i - 1]->getCount() != 0) {
                cout << _containerList[i - 1]->front() << endl;
            }
            else {
                cout << "Стек пуст." << endl;
            }
        }
        else {
            if (_containerList[i - 1]->getCount() != 0) {
                cout << _containerList[i - 1]->front() << endl;
            }
            else {
                cout << "Очередь пуста." << endl;
            }
        }
    }
}
