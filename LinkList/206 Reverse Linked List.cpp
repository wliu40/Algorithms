/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *post = head;
        ListNode *temp;
        //1 -> 2 -> 3 -> 4 -> 5 -> null
        //null <- 1 <- 2 <-3 < -4 < -5
        //  |    |
        // pre  post
        while (post)
        {
            temp = post;
            post = post->next;
            temp->next = pre;
            pre = temp;
        }
        return pre;
    }
};
