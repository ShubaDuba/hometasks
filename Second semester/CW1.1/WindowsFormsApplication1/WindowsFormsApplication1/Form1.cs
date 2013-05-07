using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        /// <summary>
        /// Событие нажатия кнопки мышкой. Закрывает окно формы.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

        /// <summary>
        /// Событие ввода мыши в область кнопки и нахождения кнопки внутри мыши. Перемещает кнопку в случайную зону внутри формы.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_MouseEnter(object sender, EventArgs e)
        {
            Random xRandom = new Random();
            if (Size.Width < 2 * button1.Size.Width || Size.Height < 2 * button1.Size.Height)
            {
                button1.Location = new Point(xRandom.Next(0, Size.Width - button1.Size.Width), xRandom.Next(0, Size.Height - button1.Size.Height));
            }
            else
            {
                button1.Location = new Point(xRandom.Next(0, Size.Width - 2 * button1.Size.Width), xRandom.Next(0, Size.Height - 2 * button1.Size.Height));
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
