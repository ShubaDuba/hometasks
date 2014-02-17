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
        public class Node
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
        }

        /// <summary>
        /// Root of the tree
        /// </summary>
        public Node Root { get; set; }

        /// <summary>
        /// Method for finding specific value in the tree
        /// </summary>
        /// <param name="value"></param>
        /// <returns> Node with specified value or null if value is not in the tree</returns>
        public Node Find(int value)
        {
            Node tmp = this.Root;

            while ((tmp != null) || (tmp.Value != value))
            {
                if (tmp.Value == value)
                {
                    return tmp;
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

            return null;
        }

        /// <summary>
        /// Method for adding value to the tree
        /// </summary>
        /// <param name="newValue">Value</param>
        public void Insert(int newValue)
        {
            Node tmp = new Node();
            tmp.Value = newValue;
            tmp.Left = null;
            tmp.Right = null;

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

/*      /// <summary>
        /// Method for removing node with specified value
        /// </summary>
        /// <param name="value">Value</param>
        public void Remove(int value)
        {
            Node tmp1 = this.Find(value);
            if (tmp1 != null)
            {
                if (tmp1.Left == null && tmp1.Right == null)
                {
                    tmp1 = null;
                }
                else if (tmp1.Right == null)
                {
                    tmp1 = tmp1.Left;
                }
                else if (tmp1.Left == null)
                {
                    tmp1 = tmp1.Right;
                }
                else
                {
                    Node flag = tmp1.Right;

                    if (flag.Left == null)
                    {
                        Node tmp2 = tmp1;
                        tmp1 = flag;
                        tmp1.Left = tmp2.Left;
                    }
                    else
                    {
                        while (flag.Left != null)
                        {
                            flag = flag.Left;
                        }

                        int tmp = flag.Value;
                        flag = flag.Right;
                        tmp1.Value = tmp;
                    }
                }
            }
        }*/

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
                MakeList(tree);
            }

            /// <summary>
            /// Position of Iterator
            /// </summary>
            int position = -1;

            /// <summary>
            /// List of nodes
            /// </summary>
            private List<Node> list = new List<Node>();

            /// <summary>
            /// Method which builds a list from tree
            /// </summary>
            /// <param name="tree">Selected tree</param>
            private void MakeList(BinarySearchTree tree)
            {
                if ((tree.Root.Left == null) && (tree.Root.Right == null))
                {
                    list.Add(tree.Root);
                    return;
                }

                BinarySearchTree tmpTree1 = new BinarySearchTree();
                tmpTree1.Root = tree.Root.Left;
                MakeList(tmpTree1);
                this.list.Add(tree.Root);
                BinarySearchTree tempTree2 = new BinarySearchTree();
                tempTree2.Root = tree.Root.Left;
                MakeList(tempTree2);
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
            public Node Current
            {
                get
                {
                    return this.list[position];
                }
            }
        }
    }
}
