/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

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
    //in this function: k < sizeof the linklist
    ListNode *rotateRightHelper(ListNode *head, int k)
    {
    	ListNode *fast = head;
        ListNode *slow = head;
        //让fast和slow拉开k的距离
        while(k > 0)
        {
            fast = fast->next;
            k--;
        }
        //fast和slow同时前进，直到fast到最后一个节点
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        //fast指向原来的head
        fast->next = head;
        head = slow->next;//slow->next是新的head
        slow->next = nullptr;//slow->next指向null
        return head;
        
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next)
            return head;
        ListNode *tmp = head;
        // find out the size of the linklist
        int size = 1;
        while(tmp->next)
        {
            tmp = tmp->next;
            size++;
        }
        // if size <= k, k = k%size;
        if (size <= k)
        	rotateRightHelper(head, k%size);
        else
        	rotateRightHelper(head, k);  
    }
};
