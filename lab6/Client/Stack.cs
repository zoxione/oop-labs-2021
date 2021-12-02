// Stack.cs - класс Stack
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client {
    class Stack : Container {
        // Конструктор по умолчанию.
        public Stack() { }

        // Конструктор с заданным размером.
        public Stack(int x) : base(x) { }

        // Публичный метод для добавления элемента в стек.
        // Входной параметр: новый элемент x.
        // Возвращаемых значений нет.
        public override void Push(int x) {
            if (_count < _size) {
                _ptr[_count] = x;
                _count++;
            }
            else throw new IndexOutOfRangeException("Out of the stack!");
        }

        // Публичный метод для удаления элемента из стека.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        public override void Pop() {
            if (_count > 0) {
                _count--;
            }
            else throw new IndexOutOfRangeException("Out of the stack!");
        }

        // Публичный метод для проверки стека на пустоту.
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

        // Публичный метод для просмотра верхушки стека.
        // Входных параметров нет.
        // Возвращаемое значение: последний элемент.
        public override int Front() {
            if (_count > 0) {
                return _ptr[_count - 1];
            }
            else {
                return -1;
            };
        }
    }
}
