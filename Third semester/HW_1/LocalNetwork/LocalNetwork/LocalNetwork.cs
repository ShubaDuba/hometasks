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
        /// Class constructor
        /// </summary>
        /// <param name="adjacencyMatrix">Matrix describing the connection between computers</param>
        /// <param name="operatingSystems">Matrix describing the operating system of each computer</param>
        /// <param name="isInfected">Matrix that shows the status of each computer(True = not infected, False = infected)</param>
        /// <param name="infectionProb">Matrix that shows probability of infection for each OS(%)</param>
        public LocalNetwork(bool[,] adjacencyMatrix, int[] operatingSystems, bool[] isInfected, int[] infectionProb)
        {
            this.AdjacencyMatrix = adjacencyMatrix;
            this.OperatingSystems = operatingSystems;
            this.InfectionMap = isInfected;
            this.InfectionProbability = infectionProb;
            this.NumberOfInfectedMachineCount();
        }

        /// <summary>
        /// Matrix describing the connection between computers
        /// </summary>
        public bool[,] AdjacencyMatrix { get; set; }
        
        /// <summary>
        /// Matrix describing the operating system of each computer
        /// </summary>
        public int[] OperatingSystems { get; set; }
        
        /// <summary>
        /// Matrix that shows the status of each computer(True = not infected, False = infected)
        /// </summary>
        public bool[] InfectionMap { get; set; }

        /// <summary>
        /// Matrix that shows probability of infection for each OS
        /// </summary>
        public int[] InfectionProbability { get; set; }

        /// <summary>
        /// The number of infected machines
        /// </summary>
        public int NumberOfInfectedMachines { get; set; }
        
        /// <summary>
        /// Method for printing of system status
        /// </summary>
        public void PrintState()
        {
            for (int i = 0; i < InfectionMap.Length; ++i)
            {
                Console.Write("{0}:", i);
                if (InfectionMap[i])
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
        /// The transition to the next state
        /// </summary>
        public void NextMove(Random rand)
        {
            bool[] tmpMatrix = InfectionMap;

            for (int i = 0; i < InfectionMap.Length; ++i)
            {
                if (InfectionMap[i])
                {
                    for (int j = 0; j < InfectionMap.Length; ++j)
                    {
                        if ((AdjacencyMatrix[i, j]) && (!InfectionMap[j]) && (!tmpMatrix[j]))
                        {
                            if (rand.Next(100) < InfectionProbability[OperatingSystems[j]])
                            {                                
                                tmpMatrix[j] = true;
                                ++NumberOfInfectedMachines;
                            }
                        }
                    }
                }
            }

            InfectionMap = tmpMatrix;
        }
        
        /// <summary>
        /// Method which counts the number of infected machines
        /// </summary>
        public void NumberOfInfectedMachineCount()
        {
            this.NumberOfInfectedMachines = 0;
            for (int i = 0; i < InfectionMap.Length; ++i)
            {
                if (InfectionMap[i])
                {
                    ++NumberOfInfectedMachines;
                }
            }
        }

        /// <summary>
        /// Method to determine infection of all network
        /// </summary>
        /// <returns>True if all computers are infected</returns>
        public bool FullInfected()
        {
            if (NumberOfInfectedMachines == InfectionMap.Length)
            {
                return true;
            }

            return false;
        }
    }
}
