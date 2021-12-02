// Queue.cs - класс Queue
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client {
    class Queue : Container {
        // Конструктор по умолчанию.
        public Queue() { }

        // Конструктор с заданным размером.
        public Queue(int x) : base(x) { }

        // Публичный метод для добавления элемента в очередь.
        // Входной параметр: новый элемент x.
        // Возвращаемых значений нет.
        public override void Push(int x) {
            if (_count < _size) {
                _ptr[(_head + _count) % _size] = x;
                _count++;
            }
            else throw new IndexOutOfRangeException("Out of the queue!");
        }

        // Публичный метод для удаления элемента из очереди.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        public override void Pop() {
            if (_count > 0) {
                _head = ++_head % _size;
                _count--;
            }
            else throw new IndexOutOfRangeException("Out of the queue!");
        }

        // Публичный метод для проверки очереди на пустоту.
        // Входных параметров нет.
        // Возвращаемое значение: булевская константа.
        public override bool IsEmpty() {
            if (_count > 0) {
                return false;
            }
            else {
                return true;
            }
        }

        // Публичный метод для просмотра головки очереди.
        // Входных параметров нет.
        // Возвращаемое значение: первый элемент.
        public override int Front() {
            if (_count > 0) {
                return _ptr[_head];
            }
            else {
                return -1;
            };
        }
    }
}
