#include "stack.h"
#include <iostream>
using namespace std;
// Определения конструкторов и методов

// Конструктор по умолчанию
Stack::Stack() {};

// Конструктор с заданным размером
Stack::Stack(int x) { _size = x; _ptr = new int[x]; };

// Констуктор копирования
Stack::Stack(const Stack& s) {
    destroy();
    _size = s._size;
    _count = s._count;
    _ptr = new int[_size];
    memcpy(_ptr, s._ptr, _size);
}

// Деструктор с очищением динамической памяти
Stack::~Stack() { delete[] _ptr; };

// Операция присваивания
Stack& Stack::operator=(const Stack& s) {
    //предотвращение самокопирования
    if (this == &s) {
        // возврат вызвавшего объекта
        return *this;
    }
    destroy();
    _size = s._size;
    _count = s._count;
    _ptr = new int[_size];
    memcpy(_ptr, s._ptr, _size);
    return *this;
}

// Функция для получения размера стека.
// Входных параметров нет.
// Возвращаемое значение : _size.
int Stack::getSize() {
    return _size;
}

// Функция для получения количества элементов в стеке.
// Входных параметров нет.
// Возвращаемое значение : _count.
int Stack::getCount() {
    return _count;
}

// Получить элемент стека по индексу
// На вход подается нужный индекс
// Возвращает значение _ptr[i]
int Stack::getValue(int i) {
    return _ptr[i];
}

// Функция для добавления элемента в стек.
// Входной параметр : новый элемент x.
// Возвращаемых значений нет.
void Stack::push(int x) {
    if (_count < _size) {
        _ptr[_count] = x;
        _count++;
    }
    else throw 1;
};

// Функция для удаления элемента из стека.
// Входных параметров нет.
// Возвращаемых значений нет.
void Stack::pop() {
    if (_count > 0) {
        _count--;
    }
    else throw 1;
}

// Функция для проверки стека на пустоту.
// Входных параметров нет.
// Возвращаемое значение : булевская константа.
bool Stack::isEmpty() {
    if (_count) {
        return false;
    }
    else {
        return true;
    }
}

// Функция для просмотра верхушки стека.
// Входных параметров нет.
// Возвращаемое значение : последний элемент.
int Stack::back() {
    if (_count > 0) {
        return _ptr[_count - 1];
    }
    else {
        return -1;
    }
}
