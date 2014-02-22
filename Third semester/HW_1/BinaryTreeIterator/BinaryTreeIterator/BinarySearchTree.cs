using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace BinaryTreeIterator
{
    public class BinarySearchTree : IEnumerable
    {
        /// <summary>
        /// Node of the tree
        /// </summary>
        private class Node
        {
            /// <summary>
            /// Node data
            /// </summary>
            public int Value { get; set; }
            
            /// <summary>
            /// Left branch
            /// </summary>
            public Node Left { get; set; }
            
            /// <summary>
            /// Right branch
            /// </summary>
            public Node Right { get; set; }

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="value">Value</param>
            /// <param name="left">Left branch</param>
            /// <param name="right">Right branch</param>
            public Node(int value, Node left, Node right)
            {
                this.Value = value;
                this.Left = left;
                this.Right = right;
            }
        }

        /// <summary>
        /// Root of the tree
        /// </summary>
        private Node Root { get; set; }

        /// <summary>
        /// Method for finding specific value in the tree
        /// </summary>
        /// <param name="value"></param>
        /// <returns> Node with specified value or null if value is not in the tree</returns>
        public bool Find(int value)
        {
            Node tmp = this.Root;

            while (tmp != null)
            {
                if (tmp.Value == value)
                {
                    return true;
                }

                if (tmp.Value > value)
                {
                    tmp = tmp.Left;
                }
                else
                {
                    tmp = tmp.Right;
                }
            }

            return false;
        }

        /// <summary>
        /// Method for adding value to the tree
        /// </summary>
        /// <param name="newValue">Value</param>
        public void Insert(int newValue)
        {
            Node tmp = new Node(newValue, null, null);

            if (this.Root == null)
            {
                this.Root = tmp;
                return;
            }

            Node flag = this.Root;
            
            while ((flag.Left != null) || (flag.Right != null))
            {
                if ((newValue < flag.Value) && (flag.Left != null))
                    flag = flag.Left;
                if ((newValue >= flag.Value) && (flag.Right != null))
                    flag = flag.Right;
                if (((newValue < flag.Value) && (flag.Left == null)) || ((newValue >= flag.Value) && (flag.Right == null)))
                    break;
            }
            
            if (newValue < flag.Value)
                flag.Left = tmp;
            else
                flag.Right = tmp;
        }

        /// <summary>
        /// Method which returns new Iterator
        /// </summary>
        /// <returns>new Iterator</returns>
        public IEnumerator GetEnumerator()
        {
            return new Iterator(this);
        }

        /// <summary>
        /// Returns GetEnumerator()
        /// </summary>
        /// <returns>GetEnumerator()</returns>
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        /// <summary>
        /// Iterator class
        /// </summary>
        
        class Iterator : IEnumerator
        {
            /// <summary>
            /// Constructor which makes a list of nodes
            /// </summary>
            /// <param name="tree">Concrete Tree</param>
            public Iterator(BinarySearchTree tree)
            {
                MakeList(tree.Root);
            }

            /// <summary>
            /// Position of Iterator
            /// </summary>
            int position = -1;

            /// <summary>
            /// List of nodes
            /// </summary>
            private List<int> list = new List<int>();

            /// <summary>
            /// Method which builds a list from tree
            /// </summary>
            /// <param name="root">Root of selected subtree</param>
            private void MakeList(Node root)
            {
                if ((root.Left == null) && (root.Right == null))
                {
                    list.Add(root.Value);
                    return;
                }

                MakeList(root.Left);
                MakeList(root.Right);
            }

            /// <summary>
            /// Method which moves the cursor to the next element
            /// </summary>
            /// <returns>'True' if iteraror is not out of list, 'False' in different situation</returns>
            public bool MoveNext()
            {
                position++;
                return (position < list.Count);
            }

            /// <summary>
            /// Method which returns cursor to the initial position 
            /// </summary>
            public void Reset()
            {
                position = -1;
            }

            /// <summary>
            /// Returns current element
            /// </summary>
            object IEnumerator.Current
            {
                get
                {
                    return Current;
                }
            }

            /// <summary>
            /// Returns current element
            /// </summary>
            public int Current
            {
                get
                {
                    return this.list[position];
                }
            }
        }
    }
}
