// container.cs - абстрактный класс Container
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client {
    abstract class Container {
        protected int[] _ptr;            // Массив элементов
        protected int _size = 0;         // Размер массива
        protected int _count = 0;        // Кол-во элементов

        // Конструктор по умолчанию
        public Container() { }

        // Конструктор с заданным размером
        public Container(int x) {
            _ptr = new int[x];
            _size = x;
        }

        // Получить размер контейнера
        public int GetSize() {
            return _size;
        }

        // Получить кол-во элементов контейнера
        public int GetCount() {
            return _count;
        }

        // Виртуальные функции
        abstract public void Push(int x);
        abstract public void Pop();
        abstract public bool IsEmpty();
        abstract public int Front();
    }
}
