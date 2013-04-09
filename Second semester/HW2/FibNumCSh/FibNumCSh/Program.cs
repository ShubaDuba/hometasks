using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FibNumCSh
{
    public class Program
    {
        /// <summary>
        /// Итеративное вычисление числа Фибоначчи.
        /// </summary>
        /// <param name="n">Номер искомого числа Фибоначчи.</param>
        /// <returns>Число Фибоначчи заданного номера.</returns>
        public static int FibIterative(int n)
        {
            if (n < 0)
                return Convert.ToInt32(Math.Pow(-1, n + 1)) * FibIterative(-n);
            if (n <= 2)
                return 1;
            int x = 1;
            int y = 1;
            int value = 0;
            for (int i = 3; i <= n; ++i)
            {
                value = x + y;
                x = y;
                y = value;
            }
            return value;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Введите номер числа Фибоначчи");
            var InputString = Console.ReadLine();
            int num = int.Parse(InputString);
            Console.WriteLine(FibIterative(num));
            Console.ReadKey();
        }
    }
}
