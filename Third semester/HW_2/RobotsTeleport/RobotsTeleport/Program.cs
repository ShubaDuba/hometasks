using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RobotsTeleport
{
    /// <summary>
    /// Class which have methods to parse arrays
    /// </summary>
    class Parser
    {
        /// <summary>
        /// Method which parses console input into array of integers
        /// </summary>
        /// <param name="array">Array of int</param>
        public static void ArrayParse(int[] array)
        {
            string tmp = Console.ReadLine();
            string[] split = tmp.Split(new Char[] { ' ' });
            int flag = 0;

            foreach (string s in split)
            {
                if (s.Trim() != "")
                {
                    array[flag++] = int.Parse(s);
                }
            }
        }

        /// <summary>
        /// Method which parses console input into array of booleans
        /// </summary>
        /// <param name="array">Array of booleans</param>
        public static void ArrayParse(bool[] array)
        {
            string tmp = Console.ReadLine();
            string[] split = tmp.Split(new Char[] { ' ' });
            int flag = 0;

            foreach (string s in split)
            {
                if (s.Trim() != "")
                {
                    array[flag++] = (int.Parse(s) == 1);
                }
            }
        }

        /// <summary>
        /// Method which parses adjacency matrix
        /// </summary>
        /// <param name="matrix">Adjacency matrix</param>
        /// <param name="size">Size of matrix</param>
        public static void ArrayParse(bool[,] matrix, int size)
        {
            for (int i = 0; i < size; ++i)
            {
                string tmp = Console.ReadLine();
                string[] split = tmp.Split(new Char[] { ' ' });
                int flag = 0;

                foreach (string s in split)
                {
                    if (s.Trim() != "")
                    {
                        matrix[i, flag++] = (int.Parse(s) == 1);
                    }
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Insert number of nodes in graph, plz");
            int numberOfnodes = int.Parse(Console.ReadLine());

            Console.WriteLine("\nInsert matrix. 0 = not connected or itself, 1 = connected)");
            bool[,] graph = new bool[numberOfnodes, numberOfnodes];
            Parser.ArrayParse(graph, numberOfnodes);

            Console.WriteLine("\nEnter the robots position");
            bool[] position = new bool[numberOfnodes];
            Parser.ArrayParse(position);

            Robots net = new Robots(graph, position);

            if (net.IsDestructable())
            {
                Console.WriteLine("true");
            }
            else
            {
                Console.WriteLine("false");
            }

            Console.ReadKey();
        }
    }
}
