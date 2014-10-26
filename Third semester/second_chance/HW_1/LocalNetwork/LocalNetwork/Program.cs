using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace LocalNetwork
{
    class Program
    {
        static void Main(string[] args)
        {            
            LocalNetwork network = new LocalNetwork();
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
