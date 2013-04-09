using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace FibNumCSh.Tests
{
    [TestClass]
    public class FibNumCShTest
    {
        [TestMethod]
        public void FibNumTest()
        {
            int num = 0;
            Assert.AreEqual(Program.FibIterative(num), 1);
            num = 1;
            Assert.AreEqual(Program.FibIterative(num), 1);
            num = 10;
            Assert.AreEqual(Program.FibIterative(num), 55);
            num = -9;
            Assert.AreEqual(Program.FibIterative(num), 34);
        }
    }
}
