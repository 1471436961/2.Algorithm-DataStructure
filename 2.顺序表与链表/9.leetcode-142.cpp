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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) break;
        } 
        //快慢指针相遇点距环起点的距离与头结点距环起点的距离一样
        if (q == NULL || q->next == NULL) return NULL;
        p = head;
        while (p != q) p = p->next, q = q->next;
        return p;
    }
};
