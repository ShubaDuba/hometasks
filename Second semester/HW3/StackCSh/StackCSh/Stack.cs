using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StackCSh
{
    public class Stack
    {
        public StackElement head { get; set; }

        /// <summary>
        /// Конструктор класса.
        /// </summary>
        public Stack()
        {
            this.head = null;
        }

        public class StackElement
        {
            public int data { get; set; }
            public StackElement next { get; set; }

            /// <summary>
            /// Конструктор класса.
            /// </summary>
            public StackElement(int value, StackElement nxt)
            {
                this.data = value;
                this.next = nxt;
            }
        }

        /// <summary>
        /// Добавление элемента в стэк.
        /// </summary>
        /// <param name="n">Значение элемента.</param>
        public void Push(int n)
        {
            StackElement element = new StackElement(n, head);
            head = element;
        }

        /// <summary>
        /// Взять значение из стэка.
        /// </summary>
        /// <returns>Значение "верхнего элемента".</returns>
        public int Pop()
        {
            if (head == null)
            {
                throw new Exception("Stack is empty!");
            }
            else
            {
                int result = head.data;
                head = head.next;
                return result;
            }
        }

        /// <summary>
        /// Обнуление стэка.
        /// </summary>
        public void Delete()
        {
            head = null;
        }


        static void Main(string[] args)
        {
        }
    }
}
