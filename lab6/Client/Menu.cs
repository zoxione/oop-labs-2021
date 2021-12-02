// Menu.cs - главная форма
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Client {
    public partial class Menu : Form {
        public Storage _userStorage;                    // Фасад Storage
        private int _sizeStack = 0;                     // Размер стека
        private int _sizeQueue = 0;                     // Размер очереди
        private int _countStack = 0;                    // Кол-во элементов стека
        private int _countQueue = 0;                    // Кол-во элементов очереди
        private int _headQueue = 0;                     // Головка очереди
        private int[] _tempStack;                       // Массив стека
        private int[] _tempQueue;                       // Массив очереди

        // Конструктор по умолчанию.
        public Menu() {
            InitializeComponent();
        }

        // Публичный метод для создания объекта Storage.
        public void SetStorage(int n, int m) {
            _userStorage = new Storage(n, m);
            _sizeStack = _userStorage.GetSizeStack();
            _sizeQueue = _userStorage.GetSizeQueue();

            ClearTrees();

            labelSizeStack.Text = Convert.ToString(_sizeStack);
            labelSizeQueue.Text = Convert.ToString(_sizeQueue);
        }

        // Приватный метод для обновления текстовых полей.
        private void UpdateLabels() {
            // ISEMPTY and FRONT
            if (_userStorage.IsEmpty(1)) {
                labelIsEmptyStack.Text = "true";
                labelFrontStack.Text = "";
            }
            else {
                labelIsEmptyStack.Text = "false";
                labelFrontStack.Text = Convert.ToString(_userStorage.Front(1));
            }

            if (_userStorage.IsEmpty(2)) {
                labelIsEmptyQueue.Text = "true";
                labelFrontQueue.Text = "";
            }
            else {
                labelIsEmptyQueue.Text = "false";
                labelFrontQueue.Text = Convert.ToString(_userStorage.Front(2));
            }

            // COUNT
            labelCountStack.Text = Convert.ToString(_countStack);
            labelCountQueue.Text = Convert.ToString(_countQueue);
        }

        // Приватный метод для очищения деревьев.
        private void ClearTrees() {
            treeStack.BeginUpdate();
            treeStack.Nodes.Clear();
            for (int i = 0; i < _sizeStack; i++) {
                treeStack.Nodes.Add("");
            }
            treeStack.EndUpdate();

            treeQueue.BeginUpdate();
            treeQueue.Nodes.Clear();
            for (int i = 0; i < _sizeQueue; i++) {
                treeQueue.Nodes.Add("");
            }
            treeQueue.EndUpdate();
        }

        // Приватный метод для обновления деревьев.
        private void UpdateTrees() {
            ClearTrees();

            _countStack = _userStorage.GetCountStack();
            _countQueue = _userStorage.GetCountQueue();
            _headQueue = _userStorage.GetHeadQueue();
            _tempStack = _userStorage.GetStack();
            _tempQueue = _userStorage.GetQueue();

            treeStack.BeginUpdate();
            for (int i = 0; i < _countStack; i++) {
                treeStack.Nodes.RemoveAt(i);
                treeStack.Nodes.Insert(i, Convert.ToString(_tempStack[i]));
            }
            treeStack.EndUpdate();

            treeQueue.BeginUpdate();
            for (int i = _headQueue; i < _countQueue + _headQueue; i++) {
                treeQueue.Nodes.RemoveAt(i % _sizeQueue);
                treeQueue.Nodes.Insert(i % _sizeQueue, Convert.ToString(_tempQueue[i % _sizeQueue]));
            }
            treeQueue.EndUpdate();

            UpdateLabels();
        }

        // Приватный метод для обработки нажания на кнопку "+" стека.
        private void buttonPushStack_Click(object sender, EventArgs e) {
            int value = Storage.ReadInt(textBoxStack.Text);
            if (_userStorage.Push(1, value)) {
                UpdateTrees();
            }
        }

        // Приватный метод для обработки нажания на кнопку "+" очереди.
        private void buttonPushQueue_Click(object sender, EventArgs e) {
            int value = Storage.ReadInt(textBoxQueue.Text);
            if (_userStorage.Push(2, value)) {
                UpdateTrees();
            }
        }

        // Приватный метод для обработки нажания на кнопку "-" стека.
        private void buttonPopStack_Click(object sender, EventArgs e) {
            if (_userStorage.Pop(1)) {
                UpdateTrees();
            }
        }

        // Приватный метод для обработки нажания на кнопку "-" очереди.
        private void buttonPopQueue_Click(object sender, EventArgs e) {
            if (_userStorage.Pop(2)) {
                UpdateTrees();
            }
        }

        // Приватный метод для обработки закрытия формы Menu.
        private void Menu_FormClosing(object sender, FormClosingEventArgs e) {
            Application.Exit();
        }
    }
}
