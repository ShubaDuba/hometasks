using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArraySpiralBypassCSh
{
    class Program
    {
        private static void SpiralBypass(int[,] tmp, int N)
        {
            Console.WriteLine("Исходный массив:");
            for (int i = 0; i < 5; ++i)
            {
                for (int j = 0; j < 5; ++j)
                {
                    Console.Write(tmp[i, j] + " ");
                }
                Console.WriteLine();
            }

            Console.WriteLine("Обход массива:");
            for(int level = N/2; level >= 0; level--)
            {
                if (level == N / 2)
                {
                    Console.Write(tmp[level, level] + " ");
                }
                else
                {
                    for (int cols1 = level + 1; cols1 < N - level; cols1++)
                        Console.Write(tmp[level, cols1] + " ");
                    for (int rows1 = level + 1; rows1 < N - level; rows1++)
                        Console.Write(tmp[rows1, N - level - 1] + " ");
                    for (int cols2 = N - level - 2; cols2 >= level; cols2--)
                        Console.Write(tmp[N - level - 1, cols2] + " ");
                    for (int rows2 = N - level - 2; rows2 >= level; rows2--)
                        Console.Write(tmp[rows2, level] + " ");
                }
            }
        }

        static void Main(string[] args)
        {
            int[,] array = new int[5, 5] { { 2, 3, 2, 4, 1 }, { 1, 2, 6, 5, 2 }, { 2, 4, 5, 6, 3 }, { 1, 2, 3, 4, 5 }, { 2, 3, 5, 3, 1 } };
            int size = 5;
            SpiralBypass(array, size);
            Console.ReadKey();
        }
    }
}
