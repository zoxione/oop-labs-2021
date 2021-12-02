// stack.h - класс Stack
#pragma once
#include "container.h"

class Stack :public Container {
public:
    // Конструкторы
    Stack() {};
    Stack(int x) :Container(x) {};

    // Публичный метод push для стека
    void push(int x) override {
        if (_count < _size) {
            _ptr[_count] = x;
            _count++;
        }
        else throw std::out_of_range("Выход за пределы стека!");
    };

    // Публичный метод pop для стека
    void pop() override {
        if (_count > 0) {
            _count--;
        }
        else throw std::out_of_range("Выход за пределы стека!");
    };

    // Публичный метод isEmpty для стека
    bool isEmpty() override {
        if (_count) {
            return false;
        }
        else {
            return true;
        }
    };

    // Публичный метод front для стека
    int front() override {
        if (_count > 0) {
            return _ptr[_count - 1];
        }
        else {
            return -1;
        };
    };
};
