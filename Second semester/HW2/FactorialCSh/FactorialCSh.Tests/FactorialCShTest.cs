using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace FactorialCSh.Tests
{
    [TestClass]
    public class FactorialCShTest
    {
        [TestMethod]
        public void FactorialTest()
        {
            int num = 10;
            Assert.AreEqual(Program.Factorial(num), 3628800);
        }
    }
}
