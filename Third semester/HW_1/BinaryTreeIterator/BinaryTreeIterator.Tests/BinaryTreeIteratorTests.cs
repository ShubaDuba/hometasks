using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace BinaryTreeIterator.Tests
{
    [TestClass]
    public class BinaryTreeIteratorTests
    {
        private BinarySearchTree tree;
        [TestInitialize]
        public void Initialize()
        {
            tree = new BinarySearchTree();
            tree.Insert(2);
            tree.Insert(1);
            tree.Insert(124);
        }

        [TestMethod]
        public void IteratorTest()
        {
            foreach (int value in tree)
                Assert.IsTrue((value == 1) || (value == 2) || (value == 124));
        }

        [TestMethod]
        public void FindTest()
        {
            Assert.IsTrue(tree.Find(2));
            Assert.IsTrue(tree.Find(124));
            Assert.IsTrue(tree.Find(1));
            Assert.IsFalse(tree.Find(5));
        }
    }
}
