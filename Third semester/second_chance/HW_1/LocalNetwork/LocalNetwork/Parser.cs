using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalNetwork
{
    /// <summary>
    /// Class that contains methods for arrays parsing
    /// </summary>
    static class Parser
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

        public static void ComputersInitialize(Computer[] array)
        {
            string tmp = Console.ReadLine();
            string[] split = tmp.Split(new Char[] { ' ' });
            int flag = 0;

            foreach (string s in split)
            {
                if (s.Trim() != "")
                {
                    switch (s)
                    {
                        case "L":
                            array[flag++] = new Computer(OperatingSystem.Linux);
                            break;
                        case "M":
                            array[flag++] = new Computer(OperatingSystem.Mac);
                            break;
                        case "W":
                            array[flag++] = new Computer(OperatingSystem.Windows);
                            break;
                    }
                }
            }
        }
    }
}
