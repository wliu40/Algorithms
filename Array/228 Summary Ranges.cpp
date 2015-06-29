/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0; i < nums.size();)
        {
            string s = "";
            int j = i;
            // increse j until reach a none-successive number
            while (j < nums.size() && nums[j] - nums[i] == j - i)
            {
                j++;
            }
            //if j only incresed one 
            if (j - i == 1)
                s += to_string(nums[i]);
            // if j increased a range of numbers    
            else 
            {
                s += to_string(nums[i]);
                s += "->";
                s += to_string(nums[j-1]);
            }
            // add the string to vector
            ans.push_back(s);
            //update i
            i = j;
        }
        return ans;
    }
};
