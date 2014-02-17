using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace LocalNetwork
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
            Console.WriteLine("Enter the number of machines on the network\n");
            int numberOfMachines = int.Parse(Console.ReadLine());
            
            Console.WriteLine("Enter the number of Operating Systems");
            Console.WriteLine("(operating system will be named by integers starting from zero)\n");
            int numberOfOS = int.Parse(Console.ReadLine());
           
            Console.WriteLine("Enter the probability of infection for each OS(%) in line separated by spaces");
            Console.WriteLine("Example: If the number of OS is 3 then if you insert '30 40 50'");
            Console.WriteLine("Probability for OS '0' will be 30%, for '1' will be 40% and 50% for '2'\n");
            int[] probabilityMatrix = new int[numberOfOS];
            Parser.ArrayParse(probabilityMatrix);

            Console.WriteLine("Enter the adjacency matrix(1 = connected, 0 = not connected or self connected");
            Console.WriteLine("Input example: If the number of machines in system is 3");
            Console.WriteLine("0 1 1");
            Console.WriteLine("1 0 1");
            Console.WriteLine("1 1 0\n");
            bool[,] adjacencyMatrix = new bool[numberOfMachines, numberOfMachines];
            Parser.ArrayParse(adjacencyMatrix, numberOfMachines);
            
            Console.WriteLine("Enter the installed operating systems in line separated by spaces");
            Console.WriteLine("Example: If the number of machines in system is 3 and OS number is 6");
            Console.WriteLine("Input:'2 5 0' => 1st computer's OS is '2', 2nd - '5', 3rd - '0'\n");
            int[] operatingSystems = new int[numberOfMachines];
            Parser.ArrayParse(operatingSystems);
           
            Console.WriteLine("Enter the state of each computer in line separated by spaces");
            Console.WriteLine("(0 = not infected, 1 = infected)");
            Console.WriteLine("Example: If the number of machines in system is 3");
            Console.WriteLine("Input:'0 1 0' => 2nd computer is infected, unlike the 1st and 3rd\n");
            bool[] isInfected = new bool[numberOfMachines];
            Parser.ArrayParse(isInfected);

            LocalNetwork network = new LocalNetwork(adjacencyMatrix, operatingSystems, isInfected, probabilityMatrix);
//          network.NumberOfInfectedMachineCount();
            Console.WriteLine("Next comes the system status:\n");
            Random rand = new Random();

            while (!network.FullInfected())
            {
                network.PrintState();
                network.NextMove(rand);
                Console.WriteLine();
                Thread.Sleep(1000);
            }

            Console.WriteLine("All machines are infected");
            Console.ReadKey();
        }  
    }
}
