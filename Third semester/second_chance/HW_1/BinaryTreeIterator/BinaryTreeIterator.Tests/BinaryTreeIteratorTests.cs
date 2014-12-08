using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace BinaryTreeIterator.Tests
{
    [TestClass]
    public class BinaryTreeIteratorTests
    {
        private BinarySearchTree<int> tree;
        [TestInitialize]
        public void Initialize()
        {
            tree = new BinarySearchTree<int>();
            tree.Insert(5);
            tree.Insert(30);
            tree.Insert(10);
        }

        [TestMethod]
        public void InsertTest()
        {
            Assert.AreEqual(tree.Root_.Value_, 5);
            Assert.AreEqual(tree.Root_.Left_, null);
            Assert.AreEqual(tree.Root_.Right_.Value_, 30);
            Assert.AreEqual(tree.Root_.Right_.Left_.Value_, 10);
        }

        [TestMethod]
        public void IteratorTest()
        {
            foreach (int value in tree)
            {
                Assert.IsTrue((value == 5) || (value == 10) || (value == 30));
            }
        }
    }
}
