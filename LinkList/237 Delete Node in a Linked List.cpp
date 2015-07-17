/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list 
should become 1 -> 2 -> 4 after calling your function.
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
    void deleteNode(ListNode* node) {
        auto next = node->next;
        //node是一个指针，*node是一个ListNode对象, 下面这句话等同于node->val = node->next->val; node->next = node->next->next;
        *node = *node->next; 
        delete next;//删掉指向原来node->next的那个指针，因为这个指针指向的那个node对象已经被复制到node,所以现在这个node没有用了,指针也不需要了
    }
};
