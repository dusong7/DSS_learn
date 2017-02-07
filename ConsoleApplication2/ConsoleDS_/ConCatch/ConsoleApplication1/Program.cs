using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 0;

            try
            {
                i = 3 / i;
            }
            catch(Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
