using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace RobotsTeleport.Tests
{
    [TestClass]
    public class RobotsTeleportTests
    {
        [TestMethod]
        public void GraphTest()
        {
            bool[,] matrix = new bool[4, 4];
            matrix[0, 0] = false;
            matrix[0, 1] = true;
            matrix[0, 2] = false;
            matrix[0, 3] = false;
            matrix[1, 0] = true;
            matrix[1, 1] = false;
            matrix[1, 2] = true;
            matrix[1, 3] = false;
            matrix[2, 0] = false;
            matrix[2, 1] = true;
            matrix[2, 2] = false;
            matrix[2, 3] = true;
            matrix[3, 0] = false;
            matrix[3, 1] = false;
            matrix[3, 2] = true;
            matrix[3, 3] = false;
            bool[] position = new bool[4];
            position[0] = true;
            position[1] = false;
            position[2] = false;
            position[3] = true;

            Robots graph1 = new Robots(matrix, position);
            Assert.IsFalse(graph1.IsDestructable());

            position[1] = true;
            position[0] = false;

            Robots graph2 = new Robots(matrix, position);
            Assert.IsTrue(graph2.IsDestructable());
            
        }
    }
}
