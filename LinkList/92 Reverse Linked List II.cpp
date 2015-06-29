/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pseudoHead = new ListNode(0);
        pseudoHead->next = head;
        ListNode *tmp = pseudoHead;
        //m_Node is the previous node of mNode
        ListNode *m_Node, *mNode, *nNode;
        for (int i = 1; i < m; i++){
            tmp = tmp->next;
        }
        m_Node = tmp;
        mNode = tmp->next;
        ListNode *pre = nullptr;
        ListNode *post = mNode;
        //reverse the nodes from mNode to nNode
        for (int i = m; i <= n; i++)
        {
            tmp = post;
            post = post->next;
            tmp->next = pre;
            pre = tmp;
        }
        //adjust the head and tail of the nodes segment(mNode to nNode)
        m_Node->next = pre;
        mNode->next = post;
        
        return pseudoHead->next;
    }
};
