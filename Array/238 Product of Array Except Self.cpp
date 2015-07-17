/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of 
all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose 
of space complexity analysis.)
*/

class Solution {
public:
    /* basic idea:
    *  假设有四个元素：nums = { nums[0], nums[1], num2[2], num2[3] };
    *  那么我们需要创建两个vector， left和right
    *  left =  {         1，                     nums[0],        nums[0]*nums[1],   nums[0]*nums[1]*nums[2] };
    *  right = { nums[1]*nums[2]*nums[3]],   nums[2]*nums[3],        nums[3],            1  };
    
    *  vector<int> left (nums.size(), 1);
    *  vector<int> right (nums.size(), 1);
    
    *  用如下方法建立left, right
    *  for (int i = 1; i < nums.size(); i++)  
    *      left[i] = nums[i-1]*left[i-1];
    *  for (int i = nums.size() - 2;i >= 0; i--)
    *      right[i] = nums[i+1]*right[i+1];
    
    *  然后，依次令ans[i] = left[i]*right[i]
    *  for (int i = 0; i <nums.size(); i++)
    *      ans[i] = left[i]*right[i];
    
    *  最后 return ans;
    */


    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> right(nums.size(), 1);
        int left = 1;
        //假设有四个元素,则: 
        //right = { nums[1]*nums[2]*nums[3]],  nums[2]*nums[3],  nums[3],  1 }; 
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            right[i] = nums[i+1] * right[i+1];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            right[i] *= left;
            left *= nums[i]; //left依次等于1， nums[0]，nums[0]*nums[1], nums[0]*nums[1]*nums[2]....
        }
        return right;
    }
};
