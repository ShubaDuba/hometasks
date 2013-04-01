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
    }
}
