using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RobotsTeleport
{
    public class Robots
    {
        /// <summary>
        /// Adjacency matrix
        /// </summary>
        private bool[,] GraphMatrix;
        
        /// <summary>
        /// Number of nodes
        /// </summary>
        private int NumberOfNodes;
        
        /// <summary>
        /// Shows in which nodes robots are
        /// </summary>
        private bool[] RobotPosition;
        
        /// <summary>
        /// Shows which connected component node belongs
        /// </summary>
        private bool[] ConnecteсtionComponents;
        
        /// <summary>
        /// Indicates whether the node is passed
        /// </summary>
        private bool[] CheckedIn;     

        /// <summary>
        /// Class constructor
        /// </summary>
        /// <param name="graphMatrix">Adjacency matrix</param>
        /// <param name="robotPosition">Is robot on the Node or not</param>
        public Robots(bool[,] graphMatrix, bool[] robotPosition)
        {
            this.GraphMatrix = graphMatrix;
            this.RobotPosition = robotPosition;
            this.NumberOfNodes = GraphMatrix.GetLength(1);
            this.ConnecteсtionComponents = new bool[NumberOfNodes];
            this.CheckedIn = new bool[NumberOfNodes];
            
            for (int i = 0; i < NumberOfNodes; ++i)
            {
                this.CheckedIn[i] = false;
            }

            this.InitializeConnectionComponents(0);
        }

        /// <summary>
        /// Method which counts destructability of robots
        /// </summary>
        /// <returns>true if destructable, false if undestructable</returns>
        public bool IsDestructable()
        {
            int tmp1 = 0;
            int tmp2 = 0;
            
            for (int i = 0; i < NumberOfNodes; ++i)
            {
                if (RobotPosition[i])
                {
                    if (ConnecteсtionComponents[i])
                    {
                        ++tmp1;
                    }
                    else
                    {
                        ++tmp2;
                    }
                }
            }

            if ((tmp1 == 1) || (tmp2 == 1))
            {
                return false;
            }

            return true;
        }

        /// <summary>
        /// Method which divides our graph into two connection components.
        /// </summary>
        /// <param name="node">Node which begins an operation</param>
        public void InitializeConnectionComponents(int node)
        {
            ConnecteсtionComponents[node] = true;
            for (int i = 0; i < NumberOfNodes; ++i)
            {
                if ((!CheckedIn[i]) && (GraphMatrix[i, node]))
                {
                    CheckedIn[i] = true;
                    for (int j = 0; j < NumberOfNodes; ++j)
                    {
                        if ((GraphMatrix[i,j]) && (!ConnecteсtionComponents[j]))
                        {
                            ConnecteсtionComponents[j] = true;
                            InitializeConnectionComponents(j);
                        }
                    }
                }
            }
        }

    }
}
