using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ArrayZeroElementsCount.Tests
{
    [TestClass]
    public class ArrayZeroElementsCountTests
    {
        [TestMethod]
        public void сountTest()
        {
            int[] array = new int[3];
            array[0] = 1;
            array[1] = 0;
            array[2] = 0;
            ZeroElementsCounter counter = new ZeroElementsCounter();
            Assert.AreEqual(counter.count(array), 2);
        }
    }
}
