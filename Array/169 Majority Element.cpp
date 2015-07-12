/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:

    int majorityElement(vector<int>& nums) {
       int counter = 1;
       int target = nums[0];//假设第一个元素是我们要找的多数元素
       for (int i = 1; i < nums.size(); i++)//从第二个元素开始遍历
       {
            if (nums[i] == target)//如果正在遍历的元素与假设元素相同，计数器加1
                counter++;
            else//否则，计数器减1
                counter--;
            if (counter == 0)//如果计数器等于0，更改假设目标，并将计数器重置为1 //相当于抵消了一个元素。
            {
                target = nums[i];
                counter = 1;
            }
       }
       return target;
    }
};
