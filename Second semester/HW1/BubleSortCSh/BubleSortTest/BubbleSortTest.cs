using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using BubbleSortCSh;

namespace BubbleSortTest
{
    [TestClass]
    public class BubbleSortTest
    {
        [TestMethod]
        public void SortTest()
        {
            int[] array = new int[5] { -1, 2, 3, 4, -123 };
            Program.BubbleSort(array);
            int[] result = new int[5] { -123, -1, 2, 3, 4};
            CollectionAssert.AreEqual(result, array);
        }

        [TestMethod]
        public void PrintTest()
        {
            int[] array = new int[5] { -1, 2, 3, 4, -123 };
            Program.PrintArray(array);
        }
    }
}
