/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

*/
class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        /*curDigit is the last digit number of n, left/right is the left/right part of n, shift is 1, 10, 100...
        * e.g., n = 213, curDigit = 3, left = 21, right = 0, shift = 1, 
        * first loop:  since 3 > 1, assume the current digit is 1, then the numbers are: 
        * (00)1, (01)1, (02)1, (03)1,.. to (21)1, ans += (21+1)
        
        * next loop: n = 21, cur = 1, left = 2, right = 3, shift = 10. since 1 == 1.
        * so, when the candidates for left are 0,1,2 respectively, when left=0 or 1, the nums are: 010,011,012...019, 110,
        * 111,112,...119, (there are 20 in total), when left = 2, the only choices are 210,211,212,213, (4 in total),
        * so ans += left*shift; ans += right+1;
        
        * if curDigit < 1, you can think by your self...
        */
        
        //e.g., if n = 10524, curDigit = 5, then left = 10, right = 24, shift = 100
        int curDigit(0), left(0), right(0), shift(1); 
        long long ans(0);
        while(n > 0)
        {
            curDigit = n % 10;
            n /= 10;
            left = n;
            
            if (curDigit < 1)
            {
                ans += left * shift;
            }
            else if (curDigit > 1)
            {
                ans += (left+1) * shift;
            }
            else
            {
                ans += left * shift;
                ans += right+1;
            }
            right += curDigit * shift;
            shift *= 10;
        }
        return ans;
    }
};
