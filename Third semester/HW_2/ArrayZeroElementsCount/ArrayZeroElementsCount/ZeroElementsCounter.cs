using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArrayZeroElementsCount
{
    public class ZeroElementsCounter
    {
        /// <summary>
        /// Method which counts number of zero elements in array
        /// </summary>
        /// <param name="array">Considered array</param>
        /// <returns>Number of zero elements</returns>
        public int count(int[] array)
        {
            int tmpValue = 0;

            for (int i = 0; i < array.Length; ++i)
            {
                if (array[i] == 0)
                {
                    ++tmpValue;
                }
            }

            return tmpValue;
        }
    }
}
