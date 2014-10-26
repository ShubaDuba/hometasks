﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTreeIterator
{
    class Program
    {
        static void Main(string[] args)
        {
            BinarySearchTree tree = new BinarySearchTree();
            tree.Insert(5);
            tree.Insert(10);
            tree.Insert(30);
            foreach (int value in tree)
            {
                Console.Write(value + " ");
            }
            Console.Write(tree.Root().Right_.Value_);
            Console.ReadKey();
        }
    }
}