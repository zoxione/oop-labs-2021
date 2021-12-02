// consoleInterface.cs - интерфейс
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client {
    class ConsoleInterface {
        private const int INPUT = 1;                    // Действие 1
        private const int PUSH = 2;                     // Действие 2
        private const int POP = 3;                      // Действие 3
        private const int ISEMPTY = 4;                  // Действие 4
        private const int FRONT = 5;                    // Действие 5
        private const int STORAGE = 6;                  // Действие 6
        private const int EXIT = 0;                     // Действие 0
        private int _countStack = 0;                    // Кол-во стеков
        private int _countQueue = 0;                    // Кол-во очередей
        private int _number = 0;                        // Номер контейнера
        private int _value = 0;                         // Значение элемента
        private int _action = 0;                        // Текущее действие
        private Storage _userStorage = new Storage();   // Объект хранилища

        // Конструктор по умолчанию
        public ConsoleInterface() { }

        // Публичный метод для чтения целого числа int.
        // Входных параметров нет.
        // Возвращаемое значение: целое число int.
        static public int ReadInt() {
            string str;
            do {
                str = Console.ReadLine();
                if (int.TryParse(str, out _) == false) {
                    Console.WriteLine("Wrong input format!");
                }
            } while (int.TryParse(str, out _) == false);
            return Convert.ToInt32(str);
        }
        
        // Публичный метод для запуска консольного интерфейса.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        public void Run() {
            try {
                Welcome();

                do {
                    ShowMenu();

                    _action = ReadInt();

                    switch (_action) {
                        case INPUT: Input(); break;
                        case PUSH: Push(); break;
                        case POP: Pop(); break;
                        case ISEMPTY: IsEmpty(); break;
                        case FRONT: Front(); break;
                        case STORAGE: Storage(); break;
                        case EXIT: Exit(); break;
                        default: InvalidAction(); break;
                    }

                    Console.WriteLine("\n");
                } while (_action != 0);
            }
            catch (Exception e) {
                // Обработка ошибок
                Console.WriteLine("\n" + e.Message);
            }
        }

        // Приватный метод для обработки приветствия программы.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        private void Welcome() {
            Console.WriteLine("Hello, world!\n");
        }

        // Приватный метод для отображения меню программы.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        private void ShowMenu() {
            Console.WriteLine("Choose action:");
            Console.WriteLine("(" + INPUT + ") Input amount stack and queue.");
            Console.WriteLine("(" + PUSH + ") Push [number] [value].");
            Console.WriteLine("(" + POP + ") Pop [number].");
            Console.WriteLine("(" + ISEMPTY + ") IsEmpty [number].");
            Console.WriteLine("(" + FRONT + ") Front [number].");
            Console.WriteLine("(" + STORAGE + ") Print storage.");
            Console.WriteLine("(" + EXIT + ") Exit.");
            Console.Write("Action: ");
        }

        // Приватный метод для обработки завершения программы.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        private void Exit() {
            Console.Write("\nGoodbye, world!");
        }

        // Приватный метод для обработки действия 1.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        private void Input() {
            if (_userStorage.GetAllCount() > 0) {
                Console.Write("\nAlready input.");
            }
            else {
                Console.Write("\nAmount stack: ");
                _countStack = ReadInt();
                Console.Write("Amount queue: ");
                _countQueue = ReadInt();

                _userStorage = new Storage(_countStack, _countQueue);
                _userStorage.PrintStorage();
            }
        }

        // Приватный метод для обработки действия 2.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        private void Push() {
            Console.Write("\nNumber: ");
            _number = ReadInt();
            Console.Write("Value: ");
            _value = ReadInt();
            _userStorage.Push(_number, _value);
        }

        // Приватный метод для обработки действия 3.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        private void Pop() {
            Console.Write("\nNumber: ");
            _number = ReadInt();
            _userStorage.Pop(_number);
        }

        // Приватный метод для обработки действия 4.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        private void IsEmpty() {
            Console.Write("\nNumber: ");
            _number = ReadInt();
            _userStorage.PrintEmpty(_number);
        }

        // Приватный метод для обработки действия 5.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        private void Front() {
            Console.Write("\nNumber: ");
            _number = ReadInt();
            _userStorage.PrintFront(_number);
        }

        // Приватный метод для обработки действия 6.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        private void Storage() {
            _userStorage.PrintStorage();
        }

        // Приватный метод для обработки неверного действия.
        // Входных параметров нет.
        // Возвращаемых значений нет.
        private void InvalidAction() {
            Console.Write("Invalid entered action!");
        }
    }
}
