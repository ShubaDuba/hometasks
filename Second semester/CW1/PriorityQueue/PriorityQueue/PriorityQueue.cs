using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PriorityQueue
{
    public class Queue
    {
        public PriorityQueueElement Head { get; private set; }

        /// <summary>
        /// Конструктор класса.
        /// </summary>
        public Queue()
        {
            this.Head = null;
        }

        public class PriorityQueueElement
        {
            public int Value { get; set; }
            public PriorityQueueElement Next { get; set; }
            public int Priority { get; set; }
        }

        /// <summary>
        /// Добавление элемента в очереди.
        /// </summary>
        /// <param name="value">Значение элемента.</param>
        /// <param name="priority">Приоритет элемента.</param>
        public void Enqueue(int value, int priority)
        {
            PriorityQueueElement element = null;
            element.Value = value;
            element.Priority = priority;

            if (Head == null)
            {
                element.Next = null;
                Head = element;
            }
            else
            {
                if (element.Priority > Head.Priority)
                {
                    element.Next = Head;
                    Head = element;
                }
                else
                {
                    PriorityQueueElement tmp = new PriorityQueueElement();
                    tmp.Next = Head;

                    while (tmp.Next.Priority < priority && tmp.Next != null)
                        tmp = tmp.Next;

                    element.Next = tmp.Next;
                    tmp.Next = element;
                }
            }
        }

        /// <summary>
        /// Функция, удаляющая элемент очереди с наивысшим приоритетом.
        /// </summary>
        /// <returns>Значение удаленного элемента.</returns>
        public int Dequeue()
        {
            if (Head == null)
            {
                throw new Exception("List is empty!");
            }
            else
            {
                int result = Head.Value;
                Head = Head.Next;
                return result;
            }
        }

        static void Main(string[] args)
        {
        }
    }
}
