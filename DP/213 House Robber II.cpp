/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that 
he will not get too much attention. This time, all houses at this place are arranged in a circle. That means 
the first house is the neighbor of the last one. 
Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money 
you can rob tonight without alerting the police.
*/

class Solution {
public:
    //当房子线形排列时候的解
    int robLinear(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return nums[0] > nums[1]? nums[0]:nums[1];

        if (nums[0] > nums[1])
            nums[1] = nums[0];
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i]+ nums[i-2] > nums[i-1])
                nums[i] = nums[i]+ nums[i-2];
            else
                nums[i] = nums[i-1];
        }
        return nums[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if (nums.size() <= 2)
        return robLinear(nums);
        if (nums.size() == 3)
        //如果只有三个房子
        return max(max(nums[0], nums[1]), nums[2]);
        //如果有更多的房子， 那么最后一个房子要么被抢劫，要么不会被抢劫
        vector<int> v_no_last;//除去最后一个房子
        vector<int>v_no_last_three;//除去最后两个房子，并且除去第一个房子
        v_no_last.assign(nums.begin(), nums.end()-1);//copy nums的内容
        v_no_last_three.assign(nums.begin()+1, nums.end() - 2);
        int x1 = robLinear(v_no_last);//找线形排列的解
        int x2 = robLinear(v_no_last_three) + nums[nums.size() - 1];//加上最后一个房子内的钱
        return x1 > x2? x1:x2;//返回更大的值
    }
};
