using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArraySpiralBypassCSh
{
    public class ArraySpiralBypass
    {
        /// <summary>
        /// Обход квадратной матрицы по спирали.
        /// </summary>
        /// <param name="tmp">Квадратная матрица.</param>
        /// <param name="N">Кол-во строк/столбцов.</param>
        /// <returns> Возвращает одномерный массив обхода по спирали.</returns>
        public static int[] SpiralBypass(int[,] tmp, int N)
        {
            int[] result = new int[N * N];
            if (N > 0)
            {
                int currentElement = 0;
                for (int level = N / 2; level >= 0; level--)
                {
                    if (level == N / 2)
                    {
                        result[currentElement++] = tmp[level, level];
                    }
                    else
                    {
                        for (int cols1 = level + 1; cols1 < N - level; cols1++)
                            result[currentElement++] = tmp[level, cols1];

                        for (int rows1 = level + 1; rows1 < N - level; rows1++)
                            result[currentElement++] = tmp[rows1, N - level - 1];

                        for (int cols2 = N - level - 2; cols2 >= level; cols2--)
                            result[currentElement++] = tmp[N - level - 1, cols2];

                        for (int rows2 = N - level - 2; rows2 >= level; rows2--)
                            result[currentElement++] = tmp[rows2, level];
                    }
                }
                return result;
            }
            else
                return result;    
        }
        /// <summary>
        /// Вывод в консоль одномерного массива.
        /// </summary>
        /// <param name="tmp">Одномерный массив.</param>
        /// <param name="size">Размер массива.</param>
        public static void PrintOneDimArray(int[] tmp, int size)
        {
            if (size > 0)
            {
                for (int i = 0; i < size; ++i)
                {
                    Console.Write(tmp[i] + " ");
                }
            }
            else
                Console.WriteLine("Массив отсутствует");
        }

        /// <summary>
        /// Вывод на экран двумерного массива.
        /// </summary>
        /// <param name="tmp">Двумерный массив</param>
        /// <param name="size">Кол-во строк/столбцов</param>
        public static void PrintTwoDimSquareArray(int[,] tmp, int size)
        {
            if (size > 0)
            {
                for (int i = 0; i < size; ++i)
                {
                    for (int j = 0; j < size; ++j)
                    {
                        Console.Write(tmp[i, j] + " ");
                    }
                    Console.WriteLine();
                }
            }
            else
                Console.WriteLine("Массив отсутствует");
        }

        static void Main(string[] args)
        {
            int[,] array = new int[5, 5] { { 2, 3, 2, 4, 1 }, { 1, 2, 6, 5, 2 }, { 2, 4, 5, 6, 3 }, { 1, 2, 3, 4, 5 }, { 2, 3, 5, 3, 1 } };
            int size = 5;
            Console.WriteLine("Изначальный массив:");
            PrintTwoDimSquareArray(array, size);
            Console.WriteLine("Обход по спирали:");
            PrintOneDimArray(SpiralBypass(array, size), size * size);
            Console.ReadKey();
        }
    }
}
