/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /* 假设k = 3; pseudoHead是个虚节点。假设start = pseudoHead;
	 * null --> 1 --> 2 --> 3 --> 4 --> 5--> 6 --> 7 --> 8 -->....
	 *   |		|	  |
	 * start   pre	 cur
	 *     （new_start）
	 * -------------------经过一次reverse内for循环以后：------------------------
	 * null --> 1 <-- 2 <-- 3     4 --> 5 --> 6 --> 7 --> 8 -->....
	 *   |			 	    |	  |
	 * start  	            pre  cur
	 * -------------------for循环后面两句以后：------------------------
	 * null --> 3 --> 2 --> 1 --> 4 --> 5 --> 6 --> 7 --> 8 -->....
	 *   |		|	 	   	|     |
	 * start   pre	     （new_start） cur
	 * ----------------return new_start,然后new_start又作为参数start开始下一轮--------------
	 * null --> 3 --> 2 --> 1 --> 4 --> 5 --> 6 --> 7 --> 8 -->....
	 * 						|     |     |
	 * 					  start  pre   cur
	 * 						  （new_start）
	 * -------------------经过一次reverse内for循环以后：------------------------
	 * null --> 3 --> 2 --> 1 --> 4 <-- 5 <-- 6     7 --> 8 -->....
	 * 						|	  	          | 	|	
	 * 					  start				 pre   cur
	 * -------------------for循环后面两句以后：------------------------
	 * null --> 3 --> 2 --> 1 --> 6 --> 5 --> 4 --> 7 --> 8 -->....
	 * 						|	  |	 	   	  |     |
	 * 					  start  pre    （new_start） cur
	 * ----------------return new_start,然后new_start又作为参数start开始下一轮--------------
	 * null --> 3 --> 2 --> 1 --> 6 --> 5 --> 4 --> 7 --> 8 --> 9 -->...	  
	 * 									      |     |     |
	 * 									    start  pre   cur
	 * ................
	 * 
	 * */
 
class Solution {
public:
    //find the length of the linklist
    int findLength(ListNode* head)
    {
        int size = 0;
        ListNode *cur = head;
        while(cur){
            size++;
            cur = cur->next;
        }
        return size;
    }
    //reverse K nodes and then return the newStart node
    ListNode *reverseOnce(ListNode* start, int k)
    {
        ListNode *pre = start->next;
        ListNode *post = pre->next;
        ListNode *newStart = start->next;
        ListNode *tmp;
        for (int i = 1; i < k; i++)
        {
            tmp = post->next;
            post->next = pre;
            pre = post;
            post = tmp;
        }
        start->next->next = post;
        start->next = pre;
        return newStart;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int times = findLength(head) / k;
        ListNode *pseudoHead = new ListNode(0);
        pseudoHead->next = head;
        ListNode *temp = pseudoHead;
        for (int i = 0; i < times; i++)
        {
            temp = reverseOnce(temp, k);
        }
        return pseudoHead->next;
    }
};
