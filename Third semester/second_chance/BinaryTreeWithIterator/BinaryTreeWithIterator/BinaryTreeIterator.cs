using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTreeWithIterator
{
    /// <summary>
    /// Abstract binary tree iterator
    /// </summary>
    public abstract class BinaryTreeIterator
    {   
        /// <summary>
        /// Current iterator's node
        /// </summary>
        public BinaryTreeNode Current { get; set; }

        /// <summary>
        /// Advances the iterator to the next position
        /// </summary>
        /// <returns>
        /// Returns <see langword="true"/> if iterator has moved to the next node,
        /// otherwise - <see langword="false"/>
        /// </returns>
        public abstract bool Next();

        /// <summary>
        /// Checks if it is possible to move iterator to the next node
        /// </summary>
        /// <returns>
        /// Returns <see langword="true"/> if iterator can be moved to the next node,
        /// otherwise - <see langword="false"/>
        /// </returns>
        public bool HasNext()
        {
            return Current != null;
        }
    }

    /// <summary>
    /// Breadth first binary tree iterator
    /// </summary>
    public class BinaryTreeBreadthFirstIterator : BinaryTreeIterator
    {
        /// <summary>
        /// Initializes new breadth-first binary tree iterator
        /// </summary>
        /// <param name="Root">
        /// Root node of the traversing tree
        /// </param>
        public BinaryTreeBreadthFirstIterator(BinaryTreeNode Root)
        {
            Current = Root;
            if (Current == null)
            {
                return;
            }

            if (Current.LeftBranch != null)
            {
                NodeQueue.Enqueue(Current.LeftBranch);
            }

            if (Current.RightBranch != null)
            {
                NodeQueue.Enqueue(Current.RightBranch);
            }
        }

        /// <summary>
        /// Advances the iterator to the next position
        /// </summary>
        /// <returns>
        /// Returns <see langword="true"/> if iterator has moved to the next node,
        /// otherwise - <see langword="false"/>
        /// </returns>
        public override bool Next()
        {
            if (Current == null)
            {
                return false;
            }

            if (NodeQueue.Count > 0)
            {
                Current = NodeQueue.Dequeue();
                if (Current.LeftBranch != null)
                {
                    NodeQueue.Enqueue(Current.LeftBranch);
                }

                if (Current.RightBranch != null)
                {
                    NodeQueue.Enqueue(Current.RightBranch);
                }

            }
            else
            {
                Current = null;
            }

            return HasNext();
        }

        private  Queue<BinaryTreeNode> NodeQueue = new Queue<BinaryTreeNode>();        
    }
}
