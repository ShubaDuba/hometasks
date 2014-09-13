using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace BinaryTreeWithIterator.Tests
{
    [TestClass]
    public class BinaryIteratorTests
    {
        [TestMethod]
        public void IteratorTest()
        {
            BinaryTreeNode tree = new BinaryTreeNode(
                10,
                new BinaryTreeNode(
                    8,
                    new BinaryTreeNode(
                        6,
                        new BinaryTreeNode(
                            4,
                            null,
                            null),
                        null),
                    new BinaryTreeNode(
                        23,
                        null,
                        null)),
                new BinaryTreeNode(
                    12,
                    new BinaryTreeNode(
                        7,
                        null,
                        null),
                    new BinaryTreeNode(
                        20,
                        null,
                        null)));
            BinaryTreeBreadthFirstIterator Iterator = new BinaryTreeBreadthFirstIterator(tree);
            int[] expected = new[] { 10, 8, 12, 6, 23, 7, 20, 4 };
            int index = 0;
            while (Iterator.HasNext())
            {
                Assert.AreEqual(expected[index++], Iterator.Current.GetValue());
                Iterator.Next();
            }

            Assert.IsNull(Iterator.Current);
        }
    }
}
