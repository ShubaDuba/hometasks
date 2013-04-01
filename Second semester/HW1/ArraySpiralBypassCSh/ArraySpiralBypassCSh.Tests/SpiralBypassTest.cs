using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using ArraySpiralBypassCSh;
namespace SpiralBypass.Tests
{
    [TestClass]
    public class SpiralBypassTest
    {
        [TestMethod]
        public void OneDimArrayPrintTest()
        {
           int[] array = new int[3] { 1, 2, 3 };
           int size = 3;
           ArraySpiralBypass.PrintOneDimArray(array, size);
           array = new int[0];
           size = 0;
           ArraySpiralBypass.PrintOneDimArray(array, size);
        }

        [TestMethod]
        public void TwoDimArrayPrintTest()
        {
            int[,] array = new int[3, 3] { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
            int size = 3;
            ArraySpiralBypass.PrintTwoDimSquareArray(array, size);
            array = new int[0, 0];
            size = 0;
            ArraySpiralBypass.PrintTwoDimSquareArray(array, size);
        }

        [TestMethod]
        public void BypassTest()
        {
            int[,] array = new int[3, 3] { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
            int[] result = new int[9] { 5, 2, 3, 6, 9, 8, 7, 4, 1};
            int size = 3;
            CollectionAssert.AreEqual(ArraySpiralBypass.SpiralBypass(array, size), result);
        }
    }
}
