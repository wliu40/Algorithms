//Implement int sqrt(int x).

//Compute and return the square root of x.

//http://blog.csdn.net/wdxin1322/article/details/38045907

class Solution {
public:
    int mySqrt(int x) {
        
    /* 二分查找法
    if (x == 1)
       return 1;
    double low = 0;
    double high = max(x, 1);
    double ans = (low + high) / 2;
    
    while ( abs(ans * ans - x) > 0.001 )
    {
        if (ans * ans > x)
            high = ans;
        else
            low = ans;
        ans = (low + high) / 2;
    }
    return ans;
    */
    
    //牛顿迭代法
     if (x==1 || x == 0)
        return x;
     double val = x;//最终  
     double last;//保存上一个计算的值  
     do  
     {  
       last = val;  
       val =(val + x/val) / 2;  
     }while(fabs(val-last) > 0.0001);
     return floor(val);
    }
};
