﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace BinaryTreeIterator
{
    public class BinarySearchTree<T> : IEnumerable where T : IComparable<T>, new()
    {
        /// <summary>
        /// Node of the tree
        /// </summary>
        public class Node
        {
            /// <summary>
            /// Node data
            /// </summary>
            public T Value_ { get; set; }
            
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
        public Node Root_ { get; private set; }

        /// <summary>
        /// Method for finding specific value in the tree
        /// </summary>
        /// <param name="value">Value to find</param>
        /// <returns> Node with specified value or null if value is not in the tree</returns>
        public Node Find(T value)
        {
            Node tmp = this.Root_;

            while ((tmp != null) || (tmp.Value_.CompareTo(value) != 0))
            {
                if (tmp.Value_.CompareTo(value) == 0)
                {
                    return tmp;
                }

                if (tmp.Value_.CompareTo(value) > 0)
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
        public void Insert(T value)
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
                if ((value.CompareTo(flag.Value_) < 0) && (flag.Left_ != null))
                    flag = flag.Left_;
                else if ((value.CompareTo(flag.Value_) >= 0) && (flag.Right_ != null))
                    flag = flag.Right_;
                else if (((value.CompareTo(flag.Value_) < 0) && (flag.Left_ == null)) || ((value.CompareTo(flag.Value_) >= 0) && (flag.Right_ == null)))
                    break;
            }
            
            if (value.CompareTo(flag.Value_) < 0)
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
            return new Iterator<T>(this);
        }

        /// <summary>
        /// Iterator class
        /// </summary>
        class Iterator<Q> : IEnumerator where Q : IComparable<Q>, new()
        {
            /// <summary>
            /// Constructor which makes a list of nodes
            /// </summary>
            /// <param name="tree">Concrete Tree</param>
            public Iterator(BinarySearchTree<Q> tree) 
            {
                MakeList(tree);
            }

            /// <summary>
            /// Position of Iterator
            /// </summary>
            private int position = -1;

            /// <summary>
            /// List of ints
            /// </summary>
            private List<Q> list = new List<Q>();

            /// <summary>
            /// Method which builds a list from tree
            /// </summary>
            /// <param name="tree">Selected tree</param>
            private void MakeList(BinarySearchTree<Q> tree)
            {
                if (tree.Root_ == null)
                {
                    return;
                }

                BinarySearchTree<Q> tmpTree1 = new BinarySearchTree<Q>();
                tmpTree1.Root_ = tree.Root_.Left_;
                MakeList(tmpTree1);
                list.Add(tree.Root_.Value_);
                BinarySearchTree<Q> tempTree2 = new BinarySearchTree<Q>();
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
                return position < list.Count;
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
