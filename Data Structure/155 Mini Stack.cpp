/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

*/
//////////////////////solution one/////////////////////////////
class MinStack {
public:
    vector<int> v;
    vector<int> miniVals; //用以保存当前的最小值
    
    void push(int x) {
        v.push_back(x);
        if(miniVals.empty())
            miniVals.push_back(x);
            
        else if (x <= miniVals.back()) //如果当前要压入的值比当前的最小值还小(或者相等)，则压入，否则不做动作
            miniVals.push_back(x);
    }

    void pop() {
        if (miniVals.back() == v.back())//如果要从v中pop的元素和当前的最小元素一样，则MiniVals也要弹出最后的元素
            miniVals.pop_back();
        v.pop_back();
    }

    int top() {
        return v[v.size() - 1];
    }

    int getMin() {
        return miniVals.back(); //返回最后的元素，即是当前的最小元素
    }
};
///////////////////////solution two /////////////////////////////////
//Solution two is slower than solution 1
class MinStack {
public:
    vector<int> v;
    map<int, int> mp; //辅助map,保留所有的（值:该值出现次数）.
    void push(int x) {
        v.push_back(x);
        mp[x]++; //如果有新值，插入该值，并使该值对应的键+1
    }

    void pop() {
        mp[v.back()]--;
        if(mp[v.back()] == 0)
            mp.erase(v.back());//如果该值的次数是0次，删除该键值对
        v.pop_back();
    }

    int top() {
        return v[v.size() - 1];
    }

    int getMin() {
        return mp.begin()->first;//返回mp的第一个元素
    }
};
