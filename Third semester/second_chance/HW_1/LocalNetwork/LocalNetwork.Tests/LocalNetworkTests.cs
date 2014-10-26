using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using LocalNetwork;

namespace LocalNetwork.Tests
{
    [TestClass]
    public class LocalNetworkTests
    {
        [TestMethod]
        public void NetworkTest()
        {
            bool[,] adjMatrix = new bool[3, 3];
            adjMatrix[0, 0] = false;
            adjMatrix[0, 1] = true;
            adjMatrix[0, 2] = true;
            adjMatrix[1, 0] = true;
            adjMatrix[1, 1] = false;
            adjMatrix[1, 2] = true;
            adjMatrix[2, 0] = true;
            adjMatrix[2, 1] = true;
            adjMatrix[2, 2] = false;
            Computer[] computers = new Computer[3];
            computers[0] = new Computer(OperatingSystem.Mac);
            computers[1] = new Computer(OperatingSystem.Linux);
            computers[2] = new Computer(OperatingSystem.Windows);

            bool[] isInfected = new bool[3];
            isInfected[0] = false;
            isInfected[1] = true;
            isInfected[2] = false;
            LocalNetwork network = new LocalNetwork(adjMatrix, isInfected, computers);
            Assert.AreEqual(network.NumberOfInfectedMachines(), 1);
            Assert.IsTrue(!network.FullInfected());
            Random rand = new Random();

            while (!network.FullInfected())
            {
                network.NextMove(rand);
            }

            Assert.AreEqual(network.NumberOfInfectedMachines(), 3);
        }
    }
}
