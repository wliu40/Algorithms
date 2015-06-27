/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, 
not the kth distinct element.
----------------------------------------
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.
-----------------------------------------
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //创建一个优先队列
        priority_queue<int> pq;
        for (int i:nums)
            pq.push(i);
        //弹出k-1个元素
        while (k > 1){ 
            pq.pop(); k--;
        }
        //返回的top元素即是第k大的元素
        return pq.top();
        
        /*下面的代码维护了一个最大堆，也可以通过，8ms. 但是会改变nums*/
        /*
        make_heap(nums.begin(), nums.end());
        while (k > 1){ 
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
            k--;
        }
        return nums[0];
        */
    }
};
