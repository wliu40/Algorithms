class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        
        if (nums.size() == 0)
            return ans;
        //设想有一袋包含有各种颜色的球。当三个不同颜色的球碰撞在一起的时候，三个球会一起消失。
        //桌上有两个放球的坑，num1, num2；
        //
        //假设来了一个新球，那么如果1#球坑是空的，那么把球坑填上该球，num1 = 1; 
        //或者如果这个球的颜色与已经放好的球的颜色相同，1#坑计数器cnt1++;
        //如果来了一个新球，2#坑是空的，那么同理，把新球填入2号坑。如果2号坑非空，而且新球颜色与2#坑中球颜色一致，则cnt2++;
        //如果来了一个新球，与这两个坑中球的颜色都不同，那么三球相撞，三球同时消失，新球不用存到坑里，而且cnt1--; cnt2--;
        //最后坑里剩下的球的颜色就是多数的球的颜色
        int num1, num2, cnt1(0), cnt2(0);
        for (int i = 0; i < nums.size(); i++)
        {
            //如果cnt1是空的，代表三个不同元素出现过了一次，那么num1 = 新元素，且cnt1 = 1
            //或者nums[i]新元素等于num1, 那么cnt++;
        	if (cnt1 == 0 || nums[i] == num1)
			{
                cnt1++;
                num1 = nums[i];
            }
            else if (cnt2 == 0 || nums[i] == num2)
            {
                num2 = nums[i];
                cnt2++;
            }
            else
			{
            	cnt2--;cnt1--;
			} 
        }
        //检验所剩下的元素是否满足大于三分之一总数的要求，如果满足，push_back到结果
        cnt1 = cnt2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num1)
                cnt1++;
            if (nums[i] == num2)
                cnt2++;
        }
        if(cnt1 > nums.size() / 3)
            ans.push_back(num1);
        if (cnt2 > nums.size() / 3 && num1 != num2)
            ans.push_back(num2);
        return ans;
        
    }
};
