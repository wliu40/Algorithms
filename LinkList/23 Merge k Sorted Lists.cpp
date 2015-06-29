//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, int> mp;
        ListNode* ans = new ListNode(0); // a pseudo head
        // the multimap stores the vals of the lists heads as keys, the index
        // of that ListNode as values
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
                mp.insert(make_pair(lists[i]->val, i));
        }
        
        ListNode *tmp = ans;
        int index;
        while (!mp.empty()){
            multimap<int, int>::iterator iter = mp.begin(); //iter is the first iterator of mp
            index = iter->second;
            //append that val to the ans
            tmp->next = new ListNode(iter->first);
            tmp = tmp->next;
            lists[index] = lists[index]->next;//update the ListNode
            mp.erase(iter);//erase the first key:val in mp
            if (lists[index])
                mp.insert(make_pair(lists[index]->val, index));
        }
        return ans->next;
        
    }
};
