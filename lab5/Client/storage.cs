// storage.cs - класс Storage
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client {
    class Storage {
        private int _countStack = 0;          // Кол-во стеков
        private int _countQueue = 0;          // Кол-во очередей
        private Container[] _containerList;   // Массив контейнеров

        // Конструктор по умолчанию
        public Storage() { }

        // Конструктор с заданным количеством
        public Storage(int n, int m) {
            _countStack = n;
            _countQueue = m;
            _containerList = new Container[_countStack + _countQueue];

            int size;
            for (int i = 0; i < _countStack; i++) {
                Console.Write("\nEnter size stack " + (i + 1) + ": ");
                size = ConsoleInterface.ReadInt();
                _containerList[i] = new Stack(size);
            }
            for (int i = 0; i < _countQueue; i++) {
                Console.Write("Enter size queue " + (i + 1) + ": ");
                size = ConsoleInterface.ReadInt();
                _containerList[i + _countStack] = new Queue(size);
            }
        }

        // Приватный метод для проверки номера контейнера.
        // Входной параметр: номер контейнера i.
        // Возвращаемое значение: булева константа.
        private bool IsValid(int i)
        {
            if ((i - 1) >= 0 && (i - 1) < _countStack + _countQueue)
            {
                return true;
            }
            else
            {
                Console.Write("The number is wrong!");
                return false;
            }
        }

        // Публичный метод для получения кол-ва контейнеров.
        // Входных параметров нет.
        // Возвращаемое значение: кол-во контейнеров.
        public int GetAllCount() {
            return (_countStack + _countQueue);
        }

        // Публичный метод для вывода хранилища.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        public void PrintStorage() {
            if (_countStack + _countQueue == 0) {
                Console.Write("\nStorage is empty.");
            }
            else {
                Console.Write("\nStorage:");
                for (int i = 0; i < _countStack + _countQueue; i++) {
                    Console.Write("\n" + (i + 1) + ". ");
                    Console.Write("Type: " + ((i < _countStack) ? "Stack. " : "Queue. "));
                    Console.Write("Size: " + _containerList[i].GetSize() + ". ");
                    Console.Write("Amount of elements: " + _containerList[i].GetCount());
                }
            }
        }

        // Публичный метод для добавления элемента в заданный контейнер.
        // Входные параметры: номер контейнера i, новый элемент x.
        // Возвращаемых значений нет.
        public void Push(int i, int x) {
            if (IsValid(i)) {
                _containerList[i - 1].Push(x);
                Console.Write("Element " + x + " is added.");
            }
        }

        // Публичный метод для удаления элемента из заданного контейнера.
        // Входной параметр: номер контейнера i.
        // Возвращаемых значений нет.
        public void Pop(int i) {
            if (IsValid(i)) {
                _containerList[i - 1].Pop();
                Console.Write("Element is deleted.");
            }
        }

        // Публичный метод для вывода наполненности заданного контейнера.
        // Входной параметр: номер контейнера i.
        // Возвращаемых значений нет.
        public void PrintEmpty(int i) {
            if (IsValid(i)) {
                if (!_containerList[i - 1].IsEmpty()) {
                    if ((i - 1) < _countStack) {
                        Console.Write("Stack isn't empty.");
                    }
                    else {
                        Console.Write("Queue isn't empty.");
                    }
                }
                else {
                    Console.Write("Container is empty.");
                }
            }
        }

        // Публичный метод для вывода головки очереди или верхушки стека.
        // Входной параметр: номер контейнера i.
        // Возвращаемых значений нет.
        public void PrintFront(int i) {
            if (IsValid(i)) {
                if ((i - 1) < _countStack) {
                    if (_containerList[i - 1].GetCount() != 0) {
                        Console.Write("Last element: " + _containerList[i - 1].Front());
                    }
                    else {
                        Console.Write("Stack is empty.");
                    }
                }
                else {
                    if (_containerList[i - 1].GetCount() != 0) {
                        Console.Write("First element: " + _containerList[i - 1].Front());
                    }
                    else {
                        Console.Write("Queue is empty.");
                    }
                }
            }
        }
    }
}
