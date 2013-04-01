using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BubleSortCSh
{
    class Program
    {
        private static void BubbleSort(int[] tmp)
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

        static void Main(string[] args)
        {
            Console.WriteLine("Введите размер массива");
            var inputString = Console.ReadLine();
            int arraySize = int.Parse(inputString);
            Console.WriteLine("Элементы массива:");
            int[] array = new int[arraySize];
            for (var i = 0; i < array.Length; ++i)
            {
                array[i] = -i;
                Console.Write(array[i]);
                Console.Write(" ");
            }

            Console.WriteLine();
            BubbleSort(array);
            Console.WriteLine("Отсортированный массив:");
            for (var i = 0; i < array.Length; ++i)
            {
                Console.Write(array[i]);
                Console.Write(" ");
            }

            Console.WriteLine();
            Console.ReadKey();
        }
    }
}
