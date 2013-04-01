using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using ColSortCSh;

namespace ColSortCSh.Tests
{
    [TestClass]
    public class ColSortTest
    {
        [TestMethod]
        public void ColSwapTest()
        {
            int[,] numbers = new int[3, 3] { { 2, 3, 2 }, { 1, 2, 6 }, { 6, 4, 5 } };
            Program.ColSwap(numbers, 1, 0, 3);
            int[,] result = new int[3, 3] { { 3, 2, 2 }, { 2, 1, 6 }, { 4, 6, 5 } };
            CollectionAssert.AreEqual(numbers, result);
        }

        [TestMethod]
        public void PrintTest()
        {
            int[,] numbers = new int[3, 3] { { 2, 3, 2 }, { 1, 2, 6 }, { 6, 4, 5 } };
            Program.ArrayPrint(numbers, 3, 3);
        }

        [TestMethod]
        public void SortTest()
        {
            int[,] numbers = new int[3, 3] { { 2, 3, 2 }, { 1, 2, 6 }, { 6, 4, 5 } };
            Program.ColSort(numbers, 3, 3);
            int[,] result = new int[3, 3] { { 2, 2, 3 }, { 1, 6, 2 }, { 6, 5, 4 } };
            CollectionAssert.AreEqual(numbers, result);
        }
    }
}
