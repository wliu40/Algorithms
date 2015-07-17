/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater 
than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 
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
    ListNode* partition(ListNode* head, int x) {
        if (!head)
            return head;
        ListNode *pseudoHead = new ListNode(0);
        pseudoHead->next = head;
        ListNode *pre = pseudoHead;
        ListNode *post = head;
        ListNode *k = pre;
        while(post)
        {
            if (post->val < x)
            {
                if (pre != k)
                {
                    pre->next = post->next;
                    post->next = k->next;
                    k->next = post;
                    post = pre->next;
                    k = k->next;
                    continue;
                }
                k = k->next;
            }
            
            pre = post;
            post = post->next;
            
        }
        return pseudoHead->next;
        
    }
};
