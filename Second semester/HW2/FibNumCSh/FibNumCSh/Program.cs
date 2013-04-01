using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FibNumCSh
{
    class Program
    {
        private static int FibItterative(int n)
        {
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
            Console.WriteLine(FibItterative(num));
            Console.ReadKey();
        }
    }
}
