using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices; 

namespace ClassLibrary1
{
    //public interface IClass1
    //{
    //    [DispId(0)]
    //    int Add(int xx, int yy);
    //};

    [ComVisible(true), ClassInterface(ClassInterfaceType.AutoDual)]
    public class Class1
    {

        public Class1() { }
       
        [ComVisible(true)]
        public int Add(int xx, int yy)
        {
            return xx + yy;
        }
    }
}
