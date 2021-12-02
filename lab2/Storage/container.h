// container.h - класс Container
#pragma once
#include <cstring>
#include <stdexcept>

class Container {
protected:
    int *_ptr = nullptr;   // Динам. массив
    int _size = 0;         // Размер массива
    int _count = 0;        // Кол-во элементов
    void destroy() { if (_ptr) { delete[] _ptr; } }; // Приватный метод очищения дин. памяти.
public:
    // Конструктор по умолчанию
    Container() = default;
    
    // Конструктор с заданным размером
    Container(int x) {
        _ptr = new int[x];
        _size = x;
    };
    
    // Конструктор копирования
    Container(const Container& c) {
        destroy();
        _size = c._size;
        _count = c._count;
        _ptr = new int[_size];
        memcpy(_ptr, c._ptr, _size);
    }

    // Виртуальный деструктор
    virtual ~Container() { delete[] _ptr; };

    // Операция присваивания
    Container &operator=(const Container& c) {
        //предотвращение самокопирования
        if (this == &c) {
            // возврат вызвавшего объекта
            return *this;
        }
        destroy();
        _size = c._size;
        _count = c._count;
        _ptr = new int[_size];
        memcpy(_ptr, c._ptr, _size);
        return *this;
    }

    // Получить размер контейнера
    int getSize() {
        return _size;
    };
    // Получить кол-во элементов контейнера
    int getCount() {
        return _count;
    };

    // Виртуальные функции
    virtual void push(int x) = 0;
    virtual void pop() = 0;
    virtual bool isEmpty() = 0;
    virtual int front() = 0;
};
