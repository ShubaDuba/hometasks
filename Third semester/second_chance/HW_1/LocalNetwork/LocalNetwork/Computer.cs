using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalNetwork
{
    /// <summary>
    /// Computers class
    /// </summary>
    public class Computer
    {
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="os">Computer's operating system</param>
        public Computer(OperatingSystem os)
        {
            os_ = os;
        }

        /// <summary>
        /// This method is called if virus wants to infect computer 
        /// </summary>
        /// <param name="rand">Random number generator</param>
        /// <returns>True if computer was successfully infected</returns>
        public bool tryToInfect(Random rand)
        {
            return os_.tryToInfect(rand);
        }

        private OperatingSystem os_; 
    }
}
