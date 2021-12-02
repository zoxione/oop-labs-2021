// queue.h - ����� Queue
#pragma once
#include "container.h"

class Queue :public Container {
private:
    int _head = 0;  // ��������� �� ������� �������
public:
    // ������������
    Queue() {};
    Queue(int x) :Container(x) {};

    // ��������� ����� push ��� �������
    void push(int x) override {
        if (_count < _size) {
            _ptr[(_head + _count) % _size] = x;
            _count++;
        }
        else throw std::out_of_range("����� �� ������� �������!");
    };

    // ��������� ����� pop ��� �������
    void pop() override {
        if (_count > 0) {
            _head = ++_head % _size;
            _count--;
        }
        else throw std::out_of_range("����� �� ������� �������!");
    };

    // ��������� ����� isEmpty ��� �������
    bool isEmpty() override {
        if (_count) {
            return false;
        }
        else {
            return true;
        }
    };

    // ��������� ����� front ��� �������
    int front() override {
        if (_count > 0) {
            return _ptr[_head];
        }
        else {
            return -1;
        };
    };
};
