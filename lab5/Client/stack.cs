// stack.cs - класс Stack
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client {
    class Stack : Container {
        // Конструкторы
        public Stack() { }
        public Stack(int x) :base(x) { }

        // Публичный метод push для стека
        public override void Push(int x) {
            if (_count < _size) {
                _ptr[_count] = x;
                _count++;
            }
            else throw new IndexOutOfRangeException("Out of the stack!");
        }

        // Публичный метод pop для стека
        public override void Pop() {
            if (_count > 0) {
                _count--;
            }
            else throw new IndexOutOfRangeException("Out of the stack!");
        }

        // Публичный метод isEmpty для стека
        public override bool IsEmpty() {
            if (_count > 0) {
                return false;
            }
            else {
                return true;
            }
        }

        // Публичный метод front для стека
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
