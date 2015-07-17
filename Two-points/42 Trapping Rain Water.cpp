#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int trap(vector<int>& height) {
    if (height.size() < 3)
        return 0;
    multimap<int, int> mp;
    priority_queue<int> pq;
    for (int i = 1; i < height.size(); i++)
    {
        mp.insert(make_pair(height[i], i)); 
    }
    int res = 0;
    pq.push(height[0]);
    multimap<int, int>::iterator it = mp.end();
    it--;
    for (int i = 1; i < height.size(); i++)
    {
        if (height[i] >= pq.top() || height[i] >= it->first)
            res += 0;
        else
            res += min( pq.top(), it->first )-height[i];
        //cout << height[i]<< ", " << pq.top() << ", " << it->first <<endl;
        pq.push(height[i]);
        for (auto iter = mp.begin(); iter != mp.end(); iter++)
        {
            if (iter->second == i) {
                mp.erase(iter);
                break;
            }
        }
    }
    return res;
    
}

int trap1(vector<int>& height) {
    priority_queue<int> left, right;
    int L(0), R(height.size() - 1), res(0);
    while(L < R)
    {
        if (height[L] > height[R]){
            right.push(height[R]);
            res += right.top() - height[R];
            R--;
        }
        else{
            left.push(height[L]);
            res += left.top() - height[L];
            L++;
        }
    }
    return res;
    
}

int trap2(vector<int>& height) {
    //建立two pointer， L， R
	// L从左到右扫描， R从右到左扫描，在此过程中维护两个最大值，leftMax和rightMax 
	// 
    int L(0), R(height.size() - 1), res(0), leftMax(0), rightMax(0);
    while(L < R)
    {
        if (height[L] > height[R]) //根据“短板理论”，如果右板比左板短，那么res += rightMax - height[R];
		{
            rightMax = max( height[R], rightMax );//维护一个右侧板最大值 
            res += rightMax - height[R];
            R--;//更新右侧pointer 
        }
        else//根据“短板理论”，如果左板比右板短，那么res += leftMax - height[L];
		{
            leftMax = max( leftMax, height[L] );//维护一个左板的最大值 
            res += leftMax - height[L];
            L++;//更新左侧pointer
        }
    }
    return res;
    
}
int main()
{	
	vector<int> v = {1027,740,9013,2980,498,13993,1513, 10,18182,24254,397,11664,27710};
    cout << trap(v) << endl;
    cout << trap1(v) << endl;
    cout << trap2(v) << endl;
}
