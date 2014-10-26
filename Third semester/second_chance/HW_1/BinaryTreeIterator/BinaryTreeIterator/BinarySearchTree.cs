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
            public int Value_ { get; set; }
            
            /// <summary>
            /// Left branch
            /// </summary>
            public Node Left_ { get; set; }
            
            /// <summary>
            /// Right branch
            /// </summary>
            public Node Right_ { get; set; }
        }

        /// <summary>
        /// Root of the tree
        /// </summary>
        private Node Root_ { get; set; }

        /// <summary>
        /// Public method to get the root of the tree
        /// </summary>
        /// <returns>Tree root</returns>
        public Node Root()
        {
            return Root_;
        }

        /// <summary>
        /// Method for finding specific value in the tree
        /// </summary>
        /// <param name="value">Value to find</param>
        /// <returns> Node with specified value or null if value is not in the tree</returns>
        public Node Find(int value)
        {
            Node tmp = this.Root_;

            while ((tmp != null) || (tmp.Value_ != value))
            {
                if (tmp.Value_ == value)
                {
                    return tmp;
                }

                if (tmp.Value_ > value)
                {
                    tmp = tmp.Left_;
                }
                else
                {
                    tmp = tmp.Right_;
                }
            }

            return null;
        }

        /// <summary>
        /// Method for adding value to the tree
        /// </summary>
        /// <param name="value">Value to add</param>
        public void Insert(int value)
        {
            Node tmp = new Node();
            tmp.Value_ = value;
            tmp.Left_ = null;
            tmp.Right_ = null;

            if (this.Root_ == null)
            {
                this.Root_ = tmp;
                return;
            }

            Node flag = this.Root_;
            
            while ((flag.Left_ != null) || (flag.Right_ != null))
            {
                if ((value < flag.Value_) && (flag.Left_ != null))
                    flag = flag.Left_;
                if ((value >= flag.Value_) && (flag.Right_ != null))
                    flag = flag.Right_;
                if (((value < flag.Value_) && (flag.Left_ == null)) || ((value >= flag.Value_) && (flag.Right_ == null)))
                    break;
            }
            
            if (value < flag.Value_)
                flag.Left_ = tmp;
            else
                flag.Right_ = tmp;
        }

        /// <summary>
        /// Returns GetEnumerator()
        /// </summary>
        /// <returns>GetEnumerator()</returns>
        IEnumerator IEnumerable.GetEnumerator()
        {
            return new Iterator(this);
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
            /// List of ints
            /// </summary>
            private List<int> list = new List<int>();

            /// <summary>
            /// Method which builds a list from tree
            /// </summary>
            /// <param name="tree">Selected tree</param>
            private void MakeList(BinarySearchTree tree)
            {
                if (tree.Root_ == null)
                {
                    return;
                }

                BinarySearchTree tmpTree1 = new BinarySearchTree();
                tmpTree1.Root_ = tree.Root_.Left_;
                MakeList(tmpTree1);
                this.list.Add(tree.Root_.Value_);
                BinarySearchTree tempTree2 = new BinarySearchTree();
                tempTree2.Root_ = tree.Root_.Right_;
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
                    return this.list[position];
                }
            }
        }
    }
}
