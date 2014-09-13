using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTreeWithIterator
{
    /// <summary>
    /// Node of the tree
    /// </summary>
    public class BinaryTreeNode
    {
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="value">Stored value</param>
        /// <param name="Left">Element of left branch </param>
        /// <param name="Right">Element of right branch</param>
        public BinaryTreeNode(int value, BinaryTreeNode Left, BinaryTreeNode Right)
        {
            this.Value = value;
            this.LeftBranch = Left;
            this.RightBranch = Right;
        }

        /// <summary>
        /// Stored value of the node
        /// </summary>
        private int Value { get; set; }

        /// <summary>
        /// Left child
        /// </summary>
        public BinaryTreeNode LeftBranch { get; set; }
        
        /// <summary>
        /// Right child
        /// </summary>
        public BinaryTreeNode RightBranch { get; set; }

        /// <summary>
        /// Method which gets node's stored value
        /// </summary>
        /// <returns>
        /// Value of the node
        /// </returns>
        public int GetValue()
        {
            return this.Value;
        }
    }
}

