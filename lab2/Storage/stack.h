// stack.h - ����� Stack
#pragma once
#include "container.h"

class Stack :public Container {
public:
    // ������������
    Stack() {};
    Stack(int x) :Container(x) {};

    // ��������� ����� push ��� �����
    void push(int x) override {
        if (_count < _size) {
            _ptr[_count] = x;
            _count++;
        }
        else throw std::out_of_range("����� �� ������� �����!");
    };

    // ��������� ����� pop ��� �����
    void pop() override {
        if (_count > 0) {
            _count--;
        }
        else throw std::out_of_range("����� �� ������� �����!");
    };

    // ��������� ����� isEmpty ��� �����
    bool isEmpty() override {
        if (_count) {
            return false;
        }
        else {
            return true;
        }
    };

    // ��������� ����� front ��� �����
    int front() override {
        if (_count > 0) {
            return _ptr[_count - 1];
        }
        else {
            return -1;
        };
    };
};
