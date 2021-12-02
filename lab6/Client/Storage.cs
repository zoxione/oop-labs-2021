// Storage.cs - класс Storage
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client {
    public class Storage {
        private int _countStack = 0;          // Кол-во стеков
        private int _countQueue = 0;          // Кол-во очередей
        private Container[] _containerList;   // Массив контейнеров

        // Конструктор с заданным размером.
        public Storage(int n, int m) {
            _countStack = 1;
            _countQueue = 1;
            _containerList = new Container[_countStack + _countQueue];
            _containerList[0] = new Stack(n);
            _containerList[1] = new Queue(m);
        }

        // Публичный метод для чтения целого числа int.
        // Входных параметров нет.
        // Возвращаемое значение: целое число int.
        static public int ReadInt(string str) {
            if (int.TryParse(str, out _) == false) {
                return 0;
            }
            else {
                return Convert.ToInt32(str);
            }
        }

        // Приватный метод для проверки номера контейнера.
        // Входной параметр: номер контейнера i.
        // Возвращаемое значение: булева константа.
        private bool IsValid(int i) {
            if ((i - 1) >= 0 && (i - 1) < _countStack + _countQueue) {
                return true;
            }
            else throw new Exception("The number is wrong!");
        }

        // Публичный метод для получения стека.
        // Входных параметров нет.
        // Возвращаемое значение: _ptr стека.
        public int[] GetStack() {
            return _containerList[0].GetContainer();
        }

        // Публичный метод для получения очереди.
        // Входных параметров нет.
        // Возвращаемое значение: _ptr очереди.
        public int[] GetQueue() {
            return _containerList[1].GetContainer();
        }

        // Публичный метод для получения размера стека.
        // Входных параметров нет.
        // Возвращаемое значение: _size стека.
        public int GetSizeStack() {
            return _containerList[0].GetSize();
        }

        // Публичный метод для получения размера очереди.
        // Входных параметров нет.
        // Возвращаемое значение: _size очереди.
        public int GetSizeQueue() {
            return _containerList[1].GetSize();
        }

        // Публичный метод для получения кол-ва элементов стека.
        // Входных параметров нет.
        // Возвращаемое значение: _count стека.
        public int GetCountStack() {
            return _containerList[0].GetCount();
        }

        // Публичный метод для получения кол-ва элементов очереди.
        // Входных параметров нет.
        // Возвращаемое значение: _count очереди.
        public int GetCountQueue() {
            return _containerList[1].GetCount();
        }

        // Публичный метод для получения головки очереди.
        // Входных параметров нет.
        // Возвращаемое значение: _head очереди.
        public int GetHeadQueue() {
            return _containerList[1].GetHead();
        }

        // Публичный метод для добавления элемента в заданный контейнер.
        // Входные параметры: номер контейнера i, новый элемент x.
        // Возвращаемое значение: булева константа.
        public bool Push(int i, int x) {
            if (IsValid(i)) {
                _containerList[i - 1].Push(x);
                return true;
            }
            else {
                return false;
            }
        }

        // Публичный метод для удаления элемента из заданного контейнера.
        // Входной параметр: номер контейнера i.
        // Возвращаемое значение: булева константа.
        public bool Pop(int i) {
            if (IsValid(i)) {
                _containerList[i - 1].Pop();
                return true;
            }
            else {
                return false;
            }
        }

        // Публичный метод для проверки наполненности заданного контейнера.
        // Входной параметр: номер контейнера i.
        // Возвращаемое значение: булева константа.
        public bool IsEmpty(int i) {
            if (IsValid(i)) {
                if (_containerList[i - 1].IsEmpty()) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }

        // Публичный метод для получения головки очереди или верхушки стека.
        // Входной параметр: номер контейнера i.
        // Возвращаемое значение: головка очереди или верхушка стека.
        public int Front(int i) {
            if (IsValid(i)) {
                return _containerList[i - 1].Front();
            }
            else {
                return -1;
            }
        }
    }
}
