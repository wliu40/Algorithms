/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 插入排序原理：
template<typename T> //整數或浮點數皆可使用,若要使用物件(class)時必須設定大於(>)的運算子功能
void insertion_sort(T arr[], int len) {
	int i, j;
	T temp;
	for (i = 1; i < len; i++) {
		temp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > temp; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = temp;
	}
}
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *pseudoHead = new ListNode(INT_MIN);
        pseudoHead->next = head;
        
        ListNode *pre = head;
        ListNode *cur = head->next;
        ListNode *temp;
        while(cur)
        {
            //从pseudoHead开始寻找合适的插入位置
            for (temp = pseudoHead; temp->next->val < cur->val; temp = temp->next){}
            //如果当前节点的值比它之前的所有节点的值都大
            //则顺序后移pre和cur即可
            if (temp->next == cur)
            {
                pre = cur;
                cur = cur->next;
                continue;
            }
            //否则改变pre, cur, temp的链接关系
            pre->next = cur->next;
            cur->next= temp->next;
            temp->next = cur;
            cur = pre->next;
        }
        return pseudoHead->next;
    }
};
