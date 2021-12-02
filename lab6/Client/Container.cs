// Container.cs - абстрактный класс Container
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
        protected int _head = 0;         // Головка очереди

        // Конструктор по умолчанию.
        public Container() { }

        // Конструктор с заданным размером.
        public Container(int x) {
            _ptr = new int[x];
            _size = x;
        }

        // Публичный метод для получения размера контейнера.
        // Входных параметров нет.
        // Возвращаемое значение: _size.
        public int GetSize() {
            return _size;
        }

        // Публичный метод для получения количества элементов.
        // Входных параметров нет.
        // Возвращаемое значение: _count.
        public int GetCount() {
            return _count;
        }

        // Публичный метод для получения головки контейнера.
        // Входных параметров нет.
        // Возвращаемое значение: _head.
        public int GetHead() {
            return _head;
        }

        // Публичный метод для получения массива контейнера.
        // Входных параметров нет.
        // Возвращаемое значение: _ptr.
        public int[] GetContainer() {
            return _ptr;
        }

        // Виртуальная функция для добавления элемента в контейнер.
        // Входной параметр: новый элемент x.
        // Возвращаемых значений нет.
        abstract public void Push(int x);

        // Виртуальная функция для удаления элемента из контейнера.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        abstract public void Pop();

        // Виртуальная функция для проверки контейнера на пустоту.
        // Входных параметров нет.
        // Возвращаемое значение: булевская константа.
        abstract public bool IsEmpty();

        // Виртуальная функция для просмотра головки очереди или верхушки стека.
        // Входных параметров нет.
        // Возвращаемое значение: первый или последний элемент.
        abstract public int Front();
    }
}
