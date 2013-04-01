using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ColSortCSh
{
    class Program
    {
        private static void ArrayPrint(int[,] array, int cols, int rows)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                    Console.Write(array[i, j] + " ");
                Console.WriteLine();
            }
        }

        private static void ColSwap(int[,] array, int col1, int col2, int rowNum)
        {
            for (int i = 0; i < rowNum; i++)
            {
                int tmp = array[i, col1];
                array[i, col1] = array[i, col2];
                array[i, col2] = tmp;
            }
        }

        private static void ColSort(int[,] array, int cols, int rows)
        {
            for (int i = 0; i < cols - 1; i++)
            {
                for (int j = 0; j < cols - 1; j++)
                    if (array[0, j] > array[0, j + 1])
                        ColSwap(array, j, j + 1, rows);
            }
        }

        static void Main(string[] args)
        {
            int[,] numbers = new int[3, 3] { { 2, 3, 2 }, { 1, 2, 6 }, { 6, 4, 5 } };
            int matrixCols = 3;
            int matrixRows = 3;
            Console.WriteLine("Исходная матрица:");
            ArrayPrint(numbers, matrixCols, matrixRows);
            ColSort(numbers, matrixCols, matrixRows);
            Console.WriteLine("Отсортированная матрица:");
            ArrayPrint(numbers, matrixCols, matrixRows);
            Console.ReadKey();
        }
    }
}
