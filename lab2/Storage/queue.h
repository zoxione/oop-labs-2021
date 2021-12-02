// queue.h - класс Queue
#pragma once
#include "container.h"

class Queue :public Container {
private:
    int _head = 0;  // Указатель на головку очереди
public:
    // Конструкторы
    Queue() {};
    Queue(int x) :Container(x) {};

    // Публичный метод push для очереди
    void push(int x) override {
        if (_count < _size) {
            _ptr[(_head + _count) % _size] = x;
            _count++;
        }
        else throw std::out_of_range("Выход за пределы очереди!");
    };

    // Публичный метод pop для очереди
    void pop() override {
        if (_count > 0) {
            _head = ++_head % _size;
            _count--;
        }
        else throw std::out_of_range("Выход за пределы очереди!");
    };

    // Публичный метод isEmpty для очереди
    bool isEmpty() override {
        if (_count) {
            return false;
        }
        else {
            return true;
        }
    };

    // Публичный метод front для очереди
    int front() override {
        if (_count > 0) {
            return _ptr[_head];
        }
        else {
            return -1;
        };
    };
};
