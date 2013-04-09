using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FactorialCSh
{
    public class Program
    {
        /// <summary>
        /// Вычисление факториала.
        /// </summary>
        /// <param name="n">Число, факториал которого требуется найти.</param>
        /// <returns>Факториал данного числа.</returns>
        public static int Factorial(int n)
        {
            if (n == 1)
            {
                return 1;
            }

            return n * Factorial(n - 1);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Введите число, факториал которого нужно вычислить");
            var inputString = Console.ReadLine();
            int num = int.Parse(inputString);
            Console.WriteLine(Factorial(num));
            Console.ReadKey();
        }
    }
}
