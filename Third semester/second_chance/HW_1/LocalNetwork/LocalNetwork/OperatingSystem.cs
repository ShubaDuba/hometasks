using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalNetwork
{
    public class OperatingSystem
    {
        /// <summary>
        /// Class constructor
        /// </summary>
        /// <param name="prob">System's probability of infection</param>
        public OperatingSystem(int prob)
        {
            infectionProbability_ = prob;
        }

        /// <summary>
        /// Method called by computer with this OS, targeted by virus
        /// </summary>
        /// <param name="rand">Random number generator</param>
        /// <returns>True is computer was successfully infected</returns>
        public bool tryToInfect(Random rand)
        {
            return (rand.Next(100) > infectionProbability_);
        }

        private int infectionProbability_;

        //Available operating systems
        /// <summary>
        /// OS Linux. Infection probability = 90%
        /// </summary>
        public static OperatingSystem Linux = new OperatingSystem(95);

        /// <summary>
        /// MacOS. Infection probability = 88%
        /// </summary>
        public static OperatingSystem Mac = new OperatingSystem(88);

        /// <summary>
        /// OS Windows. Infection probability = 75%
        /// </summary>
        public static OperatingSystem Windows = new OperatingSystem(75);
    }
}
