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
            tree.Insert(3);
        }

        [TestMethod]
        public void InsertTest()
        {
            Assert.AreEqual(tree.Root.Value, 2);
            Assert.AreEqual(tree.Root.Left.Value, 1);
            Assert.AreEqual(tree.Root.Right.Value, 3);
        }

/*      [TestMethod]
        public void RemoveTest()
        {
            tree.Remove(2);
            Assert.AreEqual(tree.Root.Value, 3);
            Assert.AreEqual(tree.Root.Left.Value, 1);
            Assert.AreEqual(tree.Root.Right, null);
        }*/

        [TestMethod]
        public void IteratorTest()
        {
            foreach (BinarySearchTree.Node node in tree)
                Assert.IsTrue(node != null);
        }
    }
}
