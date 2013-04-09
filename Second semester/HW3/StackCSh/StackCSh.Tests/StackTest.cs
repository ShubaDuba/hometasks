using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace StackCSh.Tests
{
    [TestClass]
    public class StackTest
    {
        private Stack stack;
        [TestInitialize]
        public void Initialize()
        {
            stack = new Stack();
        }

        /// <summary>
        /// Тест добавления;
        /// </summary>
        [TestMethod]
        public void PushTest()
        {
            stack.Push(3);
            stack.Push(4);
            Assert.AreEqual(stack.head.data, 4);
            Assert.AreEqual(stack.head.next.data, 3);
        }

        /// <summary>
        /// Тест получения значения из непустого стэка.
        /// </summary>
        [TestMethod]
        public void PopTest()
        {
            stack.Push(3);
            stack.Push(4);
            Assert.AreEqual(stack.Pop(), 4);
            Assert.AreEqual(stack.Pop(), 3);
        }

        /// <summary>
        /// Тест получения значения из пустого стэка.
        /// </summary>
        [TestMethod]
        [ExpectedException(typeof(System.Exception))]
        public void PopFromEmptyStackTest()
        {
            stack.Push(2);
            stack.Pop();
            stack.Pop();
        }
    }
}
