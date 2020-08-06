/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class temp1
{
    public int[] vi;
    void fun(int[] temp)
    {
        temp[0]=10;
    }
    temp1(int k)
    {
        vi = new int[k];
    }
	public static void main (String[] args)  throws java.lang.Exception{
		
        temp1 t1 = new temp1(5);
        
        // fun(ab);
        for(int i=0;i<5;i++)
        //    / System.out.println(ab[i]);
            t1.vi[i]=i*10;
        t1.fun(t1.vi);
        for(int i=0;i<5;i++)
            System.out.println(t1.vi[i]);
            // t1.vi[i]=i*10;
        
    }
	
}
