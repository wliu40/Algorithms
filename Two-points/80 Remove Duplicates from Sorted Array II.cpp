/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        //two pointers: k是一个pointer,记录当前“浓缩后”（最多可以重复一次）的index, i是另一个pointer,遍历整个数组
        //cnt记录当前有几个重复元素了
        int cnt(1),k(1);//因为从nums[1]开始，所以cnt初始化为1，k初始化为1
        for (int i = 1; i < nums.size(); i++)//i遍历整个数组
        {
            if (nums[i] == nums[i-1])//如果当前的nums[i]和nums[i-1]相等，cnt++;
                cnt++;
            else//否则，如果不相等，说明遇到了新的元素，cnt = 1;
                cnt = 1;
                
            if (cnt <= 2)//只要cnt <= 2, 那么就更改nums[k] = nums[i], 并且k++;
                nums[k++] = nums[i];
        }
        return k;
    }
};
