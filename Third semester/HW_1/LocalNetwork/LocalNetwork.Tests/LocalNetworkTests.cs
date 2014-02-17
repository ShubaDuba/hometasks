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
            int[] operatingSystems = new int[3];
            operatingSystems[0] = 1;
            operatingSystems[1] = 0;
            operatingSystems[2] = 3;
            int[] infectionProbability = new int[4];
            infectionProbability[0] = 10;
            infectionProbability[1] = 5;
            infectionProbability[2] = 15;
            infectionProbability[3] = 7;
            bool[] isInfected = new bool[3];
            isInfected[0] = false;
            isInfected[1] = true;
            isInfected[2] = false;
            LocalNetwork network = new LocalNetwork(adjMatrix, operatingSystems, isInfected, infectionProbability);
            Assert.AreEqual(network.NumberOfInfectedMachines, 1);
            Assert.IsTrue(!network.FullInfected());
            Random rand = new Random();

            while (!network.FullInfected())
            {
                network.NextMove(rand);
            }

            Assert.IsTrue(network.FullInfected());
        }
    }
}
