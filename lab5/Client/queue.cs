// queue.cs - класс Queue
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client {
    class Queue : Container {
        private int _head = 0;    // Указатель на головку очереди

        // Конструкторы
        public Queue() { }
        public Queue(int x) : base(x) { }

        // Публичный метод push для очереди
        public override void Push(int x) {
            if (_count<_size) {
                _ptr[(_head + _count) % _size] = x;
                _count++;
            }
            else throw new IndexOutOfRangeException("Out of the queue!");
        }

        // Публичный метод pop для очереди
        public override void Pop() {
            if (_count > 0) {
                _head = ++_head % _size;
                _count--;
            }
            else throw new IndexOutOfRangeException("Out of the queue!");
        }

        // Публичный метод isEmpty для очереди
        public override bool IsEmpty() {
            if (_count > 0) {
                return false;
            }
            else {
                return true;
            }
        }

        // Публичный метод front для очереди
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
