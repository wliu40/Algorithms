/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

class Solution {
public:

    int numTrees(int n) {
        vector<int> ans(n+1); // DP, prepare vector to store the results from 1 to n
        //初始化base case
        ans[0] = 1;
        //i代表节点的个数，使用动态规划，依次求出当节点数是1，2, 3...一直到n的解，这些解依次储存到ans[1], ans[2]...到ans[n-1]
        //动态规划： 大问题的解建立在小问题的解的基础上： 例如当求解ans[4]时，会用到已经求得的ans[0], ans[1], ans[2], ans[3]的值. 
        for (int i = 1; i <= n; i++)
        {
            //e.g., 假设 i == 4; 则节点1,2,3,4都可能是root, 所以要用Loop把所有的这些可能的子树都加起来
            //假设1是root,则1的左边子树只能为空(只有1种这样的子树)，右边子树是一个三个节点的子树（有ans[3]这么多种不同的子树）
            //所以对于1是root的情况，共有ans[0]*ans[3]这么多种不同的子树。
            //又比如，假设3是root，则3的左子树有ans[3-1]种可能，右子树有ans[4-3]种可能。共有ans[2]*ans[1]多种不同的子树
            for (int root = 1; root <= i; root++)
                ans[i] += ans[root-1]*ans[i-root];
        }
        return ans[n]; //返回节点数为n的解
    }
};
