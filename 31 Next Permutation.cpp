/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        //处理只有一个元素和只有两个元素的特例
        if(nums.size() == 1)
            return;
        if (nums.size() == 2)
        {
            swap(nums[0], nums[1]);
            return;
        }
        int i;
        //找到第一个不相等的相邻元素
        for (i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i-1] != nums[i])
                break;
        }
        //如果找到一个相邻的递增元素,交换二者位置，返回
        if (nums[i-1] < nums[i]){
            swap(nums[i-1], nums[i]);
            return;
        }
        //否则的话找到一个范围，使其一直递增的范围（从后往前看）
        else
        {
            while(nums[i-1] >= nums[i]){
                i--;
                if (i == 0)
                    break;
            }
            //如果i==0，说明当下的permutation已经是最大值，下一个permutation应该是最小值
            //使用reverse，将整个vector reverse即可
            if (i == 0)
            {
                reverse(nums.begin(), nums.end());
                return;
            }
            //否则，reverse该递增范围(从后往前看)
            else
            {
                reverse(nums.begin()+i, nums.end());
                //for_each(nums.begin(), nums.end(),[](int val){cout<<val <<",";});
                //在该范围内，找到第一个大于nums[i-1]的元素并交换之
                for (int j = i; j < nums.size(); j++)
                {
                    if (nums[j] > nums[i-1]){
                        swap(nums[i-1], nums[j]);
                        return;
                    }
                }
            }
        }
    }
};
