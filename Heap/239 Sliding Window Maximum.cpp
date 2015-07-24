/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].
*/

/************************Solution One***********************/
class Solution {
public:
   int findMax(vector<int> &nums, int begin, int end)
   {
       int ans = nums[begin];
       for (int i = begin+1; i < end; i++)
       {
           if (nums[i] > ans) ans = nums[i];
       }
       return ans;
   }
   vector<int> maxSlidingWindow(vector<int>& nums, int k){   
        vector<int> maxNums;
        if (nums.empty())
            return maxNums;
        m_currentMaxNum = findMax(nums, 0, k);
        maxNums.push_back(m_currentMaxNum);
        for (int i = 1; i <= nums.size() - k; ++i)
        {
            maxNums.push_back(maxSlidingWindowInternal(nums, i, i + k));
        }
        return maxNums;
    }
    
    int maxSlidingWindowInternal(vector<int>& nums, int begin, int end){

        //如果新加入的值比当前窗口内的值大
        if (nums[end -1] >= m_currentMaxNum)
        {
            m_currentMaxNum = nums[end -1];//则update当前的最大值
            return m_currentMaxNum;//并返回该最大值
        }
        //如果新加入的值比当前窗口内的最大值要小，而且弹出的值不是该最大值， 则返回原有最大值
        if (nums[begin - 1] < m_currentMaxNum)
        {
            return m_currentMaxNum;
        }
        
        //否则，在新窗口内查找最大值，并将其返回
         m_currentMaxNum = findMax(nums, begin, end);

        //返回最大值
        return m_currentMaxNum;
    }
    private:
    //保存当前窗口内的最大值
        int m_currentMaxNum;
};

/************************Solution Two***********************/

class Solution {

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    map<int, int> mp;
    vector<int> vec;
    if (nums.empty())
        return vec;
     //先把前K个值压入   
    for (int i = 0; i < k; i++)
    {
        mp[nums[i]]++;
    }
    map<int, int>::iterator iter;
    for (int i = k; i < nums.size(); i++)
    {
        iter = mp.end();iter--; //从map尾部开始遍历
        vec.push_back(iter->first);//压入最后的那个值（当前map内的最大值， 即是当前窗口的最大值）
        mp[nums[i-k]]--;//从window删除的那个元素对应的键值要减1
        if(mp[nums[i-k]] == 0) //如果该值对应的键已经为0，则将其删除
            mp.erase(nums[i-k]);
        mp[nums[i]]++;//新加入的值要加1
    }
    iter = mp.end();iter--;//加入最后的一个值
    vec.push_back(iter->first);

    return vec;
    }
};

/************************Solution Three***********************/

/*Sliding window minimum/maximum = monotonic queue. I smelled the solution just when I read the title. 
This is essentially same idea as others' deque solution, but this is much more standardized and modulized. 
If you ever need to use it in your real product, this code is definitely more preferable.

What does Monoqueue do here:

It has three basic options:

push: push an element into the queue; O (1) (amortized)

pop: pop an element out of the queue; O(1)

max: report the max element in queue;O(1)

It takes only O(n) time to process a N-size sliding window minimum/maximum problem.

Note: different from a priority queue (which takes O(nlogn)), it doesn't pop the max element.
It pops the first element in queue;*/

/*

std::pair主要的作用是将两个数据组合成一个数据，两个数据可以是同一类型或者不同类型。
例如std::pair<int,float> 或者 std：：pair<double,double>等。
pair实质上是一个结构体，其主要的两个成员变量是first和second，这两个变量可以直接使用。初始化一个pair可以使用构造函数，
也可以使用std::make_pair函数，make_pair函数的定义如下：
template pair make_pair(T1 a, T2 b) { return pair(a, b); }
*/

#include <deque>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Monoqueue //自己创建一个Monoqueue类
{
    deque< pair<int, int> > m_deque; //deque('deck') : double-end queue, 元素是pair对象
    public:
		void push(int val)
	//	{1,3,-1,5,4,6,-2,8,9,1};
		{
		    int count = 0;
		    while(!m_deque.empty() && m_deque.back().first < val)
		    {
		        count += m_deque.back().second + 1;
		        m_deque.pop_back();
		    }
		    m_deque.push_back(make_pair(val, count));
		}
		int max()
		{
		    return m_deque.front().first;
		}
		void pop()
		{
		    if (m_deque.front().second > 0)
		    {
		        m_deque.front().second --;
		        return;
		    }
		    m_deque.pop_front();
		}
		void show()
		{
			for(auto it = m_deque.begin(); it != m_deque.end(); ++it)
			{
				cout << (*it).first << "," << (*it).second << "; ";
				//cout << *it << endl;
			}
			cout << endl;
		}
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> results;
    if (nums.empty())
        return results;
    Monoqueue mq;
    size_t i = 0;
    for (;i < k; ++i) //push first K ints;
    {
        mq.push(nums[i]);
    }
    for (; i < nums.size(); ++i)
    {
        results.push_back(mq.max()); 
        cout << "before pop: "; mq.show(); 
        cout << "i = " << i << ": " << endl;
        cout << "将" << mq.max() << "压入结果" << endl;
        mq.pop(); 
		cout << "after pop: "; mq.show(); 	
        mq.push(nums[i]); 
        cout << "after push: "; mq.show();
        cout << endl;
    }
	
	results.push_back(mq.max());    
    for (int i:results)
    {
    	cout << i<< " ";
	}
	cout << endl; 
    return results;
}

int main()
{

	vector<int> v = {1,2,3,4,3,2,1};
	maxSlidingWindow(v,2);
	
}
