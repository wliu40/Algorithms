/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        //找到中间的那个节点
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

        }
        ListNode *pre = slow;
        ListNode *post = pre->next;
        pre->next = nullptr;
        ListNode *tmp;
        //1->2->3->4 变为 1->2->3<-4
        //1->2->3->4->5 变为 1->2->3<-4<-5
        while(post)
        {
            tmp = post->next;
            post->next = pre;
            pre = post;
            post = tmp;
        }
        //从头和尾依次更改链接顺序
        ListNode *_head = head; 
        ListNode *_tail = pre;
        while(_head->next != _tail && _head != _tail)
        {
            tmp = _head->next;
            _head->next = _tail;
            _head = tmp;
            tmp = _tail->next;
            _tail->next = _head;
            _tail = tmp;
        }
    }
};
