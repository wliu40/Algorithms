//Determine whether an integer is a palindrome. Do this without extra space.

//回文数字： 比如：12321， 123321是回文数字， 100021则不是
//求出一个数字的逆序数字，如果该数字与原数字相等，则是一个回文数字
//不用担心越界问题。
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int x1 = x;
        int x2 = 0;
        while(x1 > 0)
        {
            x2 *= 10;
            x2 += x1 % 10;
            x1 /= 10;
        }
        return x2 == x;
    }
};
