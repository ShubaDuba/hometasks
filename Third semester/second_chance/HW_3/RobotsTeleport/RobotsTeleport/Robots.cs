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
        /// Class constructor
        /// </summary>
        /// <param name="graphMatrix">Adjacency matrix</param>
        /// <param name="robotPosition">Is robot on the Node or not</param>
        public Robots(bool[,] graphMatrix, bool[] robotPosition)
        {
            graphMatrix_ = graphMatrix;
            robotPosition_ = robotPosition;
            numberOfNodes_ = graphMatrix_.GetLength(1);
            connecteсtionComponents_ = new bool[numberOfNodes_];
            checkedIn_ = new bool[numberOfNodes_];
            for (int i = 0; i < numberOfNodes_; ++i)
            {
                checkedIn_[i] = false;
            }

            InitializeConnectionComponents(0);
        }

        /// <summary>
        /// Method which counts destructability of robots
        /// </summary>
        /// <returns>true if destructable, false if undestructable</returns>
        public bool IsDestructable()
        {
            int tmp1 = 0;
            int tmp2 = 0;
            
            for (int i = 0; i < numberOfNodes_; ++i)
            {
                if (robotPosition_[i])
                {
                    if (connecteсtionComponents_[i])
                    {
                        ++tmp1;
                    }
                    else
                    {
                        ++tmp2;
                    }
                }
            }

            return !((tmp1 == 1) || (tmp2 == 1));
        }

        /// <summary>
        /// Method which divides our graph into two connection components.
        /// </summary>
        /// <param name="node">Node which begins an operation</param>
        private void InitializeConnectionComponents(int node)
        {
            connecteсtionComponents_[node] = true;
            for (int i = 0; i < numberOfNodes_; ++i)
            {
                if ((!checkedIn_[i]) && (graphMatrix_[i, node]))
                {
                    checkedIn_[i] = true;
                    for (int j = 0; j < numberOfNodes_; ++j)
                    {
                        if ((graphMatrix_[i,j]) && (!connecteсtionComponents_[j]))
                        {
                            connecteсtionComponents_[j] = true;
                            InitializeConnectionComponents(j);
                        }
                    }
                }
            }
        }

        /// <summary>
        /// Adjacency matrix
        /// </summary>
        private bool[,] graphMatrix_;

        /// <summary>
        /// Number of nodes
        /// </summary>
        private int numberOfNodes_;

        /// <summary>
        /// Shows in which nodes robots are
        /// </summary>
        private bool[] robotPosition_;

        /// <summary>
        /// Shows which connected component node belongs
        /// </summary>
        private bool[] connecteсtionComponents_;

        /// <summary>
        /// Indicates whether the node is passed
        /// </summary>
        private bool[] checkedIn_;     

    }
}
