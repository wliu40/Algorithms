/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

class Solution {
public:
    //计算n！
    int factorial(int n)
    {
    	int ans = 1;
    	for (int i = 2; i <= n; i++)
    	{
    		ans *= i;
    	}
    	return ans;
    }
    /*
    *比如，n = 4, k = 18; 则需要改变后面四个数字(size = 4)；
    *ans = "", helper = "1234"; size = 4, 循环共执行四次:
    *18-1 = 17, 17 / (4-1)! = 17 / 6 = 2, 加入helper[2]到ans, ans = "3", erase helper[2]后， helper = "124"; 18 - 2*6 = 6;
    *6-1 = 5, 5/(3-1)! = 2, 加入helper[2]到ans, ans = "34", erase helper[2]后，helper = "12"; 6 - 2*2 = 2;
    *2-1 = 1, 1/(2-1)! = 1, 加入helper[1]到ans, ans = "342", erase helper[1]后，helper = "1"; 2 - 1*1 = 1;
    *1-1 = 0, 0/0! = 0, 加入helper[0]到ans, ans = "3421", erase helper[0]后，helper = "";
    *循环结束
    */
    string getPermutation(int n, int k)
    {
        //得到size的大小，比如k = 17, 则需要改变最后面的四个数字，size = 4;
    	int size = 1;
    	while (k > factorial(size)){
    		size++;
    	}
        //得到s的初始值， 比如n=4, 则s="1234";
    	string s = "";
    	int i = 1;
    	while (i <= n)
    	{
    		s += '0' + i;
    		i++;
    	}
    	//截取s中前面不变的部分, 比如 s = "12345", k = 17, 因为只需要改变后面四个数字，所以ans = "1"；
    	string ans(s.substr(0, s.size() - size));
    	//截取s中后面需要改变的部分，上例中，helper = "2345"；
    	string helper(s.substr(s.size()-size, size));
    	//从helper中按次序提取出需要的字符，加入到ans里
    	int divisor;
    	int index;
    	for (int i = 0; i < size; i++)
    	{
    		divisor = factorial(size-i-1);
    		index = (k-1) / divisor;		
    		ans += helper[index];
    		k -= index*divisor;
    		helper.erase(index, 1);//删掉那个已经用过的字符
    	}
    	return ans;
    }
};
