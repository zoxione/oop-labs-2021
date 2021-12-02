// container.h - ����� Container
#pragma once
#include <cstring>
#include <stdexcept>

class Container {
protected:
    int *_ptr = nullptr;   // �����. ������
    int _size = 0;         // ������ �������
    int _count = 0;        // ���-�� ���������
    void destroy() { if (_ptr) { delete[] _ptr; } }; // ��������� ����� �������� ���. ������.
public:
    // ����������� �� ���������
    Container() = default;
    
    // ����������� � �������� ��������
    Container(int x) {
        _ptr = new int[x];
        _size = x;
    };
    
    // ����������� �����������
    Container(const Container& c) {
        destroy();
        _size = c._size;
        _count = c._count;
        _ptr = new int[_size];
        memcpy(_ptr, c._ptr, _size);
    }

    // ����������� ����������
    virtual ~Container() { delete[] _ptr; };

    // �������� ������������
    Container &operator=(const Container& c) {
        //�������������� ���������������
        if (this == &c) {
            // ������� ���������� �������
            return *this;
        }
        destroy();
        _size = c._size;
        _count = c._count;
        _ptr = new int[_size];
        memcpy(_ptr, c._ptr, _size);
        return *this;
    }

    // �������� ������ ����������
    int getSize() {
        return _size;
    };
    // �������� ���-�� ��������� ����������
    int getCount() {
        return _count;
    };

    // ����������� �������
    virtual void push(int x) = 0;
    virtual void pop() = 0;
    virtual bool isEmpty() = 0;
    virtual int front() = 0;
};
