using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalNetwork
{
    /// <summary>
    /// Local Network class
    /// </summary>
    public class LocalNetwork
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

            /// <summary>
            /// Array of computers parsing from string which contains first letters of operating systems
            /// </summary>
            /// <param name="array">Array of computers</param>
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
        /// <summary>
        /// Class constructor
        /// </summary>
        /// <param name="adjacencyMatrix">Matrix describing the connection between computers</param>
        /// <param name="infectionMap">Matrix that shows the status of each computer(True = not infected, False = infected)</param>
        /// <param name="computers">Matrix which contains all network computers</param>
        public LocalNetwork(bool[,] adjacencyMatrix, bool[] infectionMap, Computer[] computers)
        {
            this.adjacencyMatrix_ = adjacencyMatrix;
            this.infectionMap_ = infectionMap;
            this.computers_ = computers;
            this.numberOfMachines_ = computers_.Length;
            this.NumberOfInfectedMachineCount();
        }

        /// <summary>
        /// Interactive class constructor
        /// </summary>
        public LocalNetwork()
        {
            Console.WriteLine("Enter the number of machines on the network");
            numberOfMachines_ = int.Parse(Console.ReadLine());

            Console.WriteLine("Enter the adjacency matrix(1 = connected, 0 = not connected or is itself");
            Console.WriteLine("Input example: If the number of machines in system is 3");
            Console.WriteLine("0 1 1\n1 0 1\n1 1 0\nseems every computer is connected with each other");
            adjacencyMatrix_ = new bool[numberOfMachines_, numberOfMachines_];
            Parser.ArrayParse(adjacencyMatrix_, numberOfMachines_);

            Console.WriteLine("Enter first letters of installed operating systems in line separated by spaces");
            Console.WriteLine("Currently allowed values: \"M\", \"L\", \"W\"");
            Console.WriteLine("Example: If the number of machines in system is 3");
            Console.WriteLine("Input:'M L W' => 1st computer's OS is 'MacOS', 2nd - 'Linux', 3rd - 'Шindows'\n");
            computers_ = new Computer[numberOfMachines_];
            Parser.ComputersInitialize(computers_);


            Console.WriteLine("Enter the state of each computer in line separated by spaces");
            Console.WriteLine("(0 = not infected, 1 = infected)");
            Console.WriteLine("Example: If the number of machines in system is 3");
            Console.WriteLine("Input:'0 1 0' => 2nd computer is infected, unlike the 1st and 3rd\n");
            infectionMap_ = new bool[numberOfMachines_];
            Parser.ArrayParse(infectionMap_);

            NumberOfInfectedMachineCount();
        }

        /// <summary>
        /// The transition to the next state
        /// </summary>
        public void NextMove(Random rand)
        {
            bool[] tmpMatrix = infectionMap_;

            for (int i = 0; i < numberOfMachines_; ++i)
            {
                if (infectionMap_[i])
                {
                    for (int j = 0; j < numberOfMachines_; ++j)
                    {
                        if ((adjacencyMatrix_[i, j]) && (!infectionMap_[j]) && (!tmpMatrix[j]))
                        {
                            if (computers_[j].tryToInfect(rand))
                            {
                                tmpMatrix[j] = true;
                                ++numberOfInfectedMachines_;
                            }
                        }
                    }
                }
            }

            infectionMap_ = tmpMatrix;
        }

        /// <summary>
        /// Method to get number of infected machines
        /// </summary>
        /// <returns>Number of infected machines</returns>
        public int NumberOfInfectedMachines()
        {
            return numberOfInfectedMachines_;
        }

        /// <summary>
        /// Number of infected machines counter
        /// </summary>
        private void NumberOfInfectedMachineCount()
        {
            this.numberOfInfectedMachines_ = 0;
            foreach (bool isInfected in infectionMap_)
            {
                if (isInfected)
                {
                    ++numberOfInfectedMachines_;
                }
            }
        }

        /// <summary>
        /// Method to determine infection of all computers in the network
        /// </summary>
        /// <returns>True if all computers are infected</returns>
        public bool FullInfected()
        {
            if (numberOfInfectedMachines_ == numberOfMachines_)
            {
                return true;
            }

            return false;
        }

        /// <summary>
        /// System status printing method
        /// </summary>
        public void PrintState()
        {
            for (int i = 0; i < infectionMap_.Length; ++i)
            {
                Console.Write("{0}:", i);
                if (infectionMap_[i])
                {
                    Console.Write("I ");
                }
                else
                {
                    Console.Write("N ");
                }
            }

            Console.WriteLine();
        }

        /// <summary>
        /// Number of computers
        /// </summary>
        private int numberOfMachines_;

        /// <summary>
        /// Matrix describing the connection between computers
        /// </summary>
        private bool[,] adjacencyMatrix_;
        
        /// <summary>
        /// Matrix that shows the status of each computer(True = not infected, False = infected)
        /// </summary>
        private bool[] infectionMap_;

        /// <summary>
        /// Array of computers
        /// </summary>
        private Computer[] computers_;
        
        /// <summary>
        /// Number of infected machines
        /// </summary>
        private int numberOfInfectedMachines_;        
    }
}
