using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BubbleSortCSh
{
    public class Program
    {
        /// <summary>
        /// Сортировка одномерного массива пузырьком.
        /// </summary>
        /// <param name="tmp">Исходный одномерный массив.</param>
        public static void BubbleSort(int[] tmp)
        {
            for (int i = 0; i < tmp.Length; ++i)
                for (int j = tmp.Length - 1; j > i; --j)
                {
                    if (tmp[j - 1] > tmp[j])
                    {
                        int a = tmp[j - 1];
                        tmp[j - 1] = tmp[j];
                        tmp[j] = a;
                    }
                }
        }

        /// <summary>
        /// Вывод в консоль одномерного массива.
        /// </summary>
        /// <param name="tmp">Одномерный массив.</param>
        public static void PrintArray(int[] tmp)
        {
            for (var i = 0; i < tmp.Length; ++i)
            {
                Console.Write(tmp[i]);
                Console.Write(" ");
            }
            Console.WriteLine();
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Элементы массива:");
            int[] array = new int[15] {1,2,4,124,124,124,124,14,14,12412,13512,53,23,23,34234};
            PrintArray(array);
            Console.WriteLine("Исходный массив:");
            BubbleSort(array);
            Console.WriteLine("Отсортированный массив:");
            PrintArray(array);
            Console.WriteLine();
            Console.ReadKey();
        }
    }
}
