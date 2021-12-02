// Welcome.cs - начальная форма
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
    public partial class Welcome : Form {
        // Конструктор по умолчанию.
        public Welcome() {
            InitializeComponent();
        }

        // Приватный метод для обработки нажания на кнопку.
        private void buttonStart_Click(object sender, EventArgs e) {
            int sizeStack = Storage.ReadInt(textBox1.Text);
            int sizeQueue = Storage.ReadInt(textBox2.Text);

            Menu menu = new Menu();
            menu.SetStorage(sizeStack, sizeQueue);
            this.Hide();
            menu.ShowDialog();
        }
    }
}
