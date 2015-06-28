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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
        return head;
        ListNode *pre, *post;
        pre = head;
        post = pre->next;
        ListNode* cur;
        // after this, pre->val != post->val
        // all the duplicates numbers (e.g.,1-1-1-2-2) will be removed
        while (pre && post && pre->val == post->val)
        {
            cur = post->next;
            while(cur && cur->val == post->val)
                cur = cur->next;
            if (!cur)
                return nullptr;
            else
            {
                pre = cur;
                post = pre->next;
                head = pre;
            }
        }
        //treat the following situation
        //1-2-2-3
        //1-2-3-3-4
        while(pre && post)
        {
            cur = post->next;
            if (cur && cur->val == post->val)
            {
                while (cur && cur->val == post->val)
                {
                    cur = cur->next;
                }
                pre->next=cur;
                post= cur;
                continue;
            }
            pre= post;
            post = post->next;
        }
        return head;

    }
};
