using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace PriorityQueue.Tests
{
    [TestClass]
    public class PriorityQueueTest
    {
        Queue queue;
        [TestInitialize]
        public void Initialize()
        {
            queue = new Queue();
        }
        [TestMethod]
        public void EnqueueTest()
        {
            Initialize();
            queue.Enqueue(2, 1);
            queue.Enqueue(1, 2);
            Assert.AreEqual(queue.Head.Value, 2);

        }
        [TestMethod]
        [ExpectedException(typeof(System.Exception))]
        public void DequeueTest()
        {
            queue.Enqueue(2, 3);
            queue.Enqueue(1, 4);
            Assert.AreEqual(queue.Dequeue(), 1);
        }
    }
}
