/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLengt(ListNode *head) {
        int n = 0;
        while (head) {
            n += 1;
            head = head->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int n = getLengt(head);
        k %= n;
        if (k == 0) return head;
        ListNode *p = head, *q = head;
        for (int i = 0; i <= k; i++) p = p->next;
        while (p) p = p->next, q = q->next;
        p = q->next;//到这行代码时p已指向了空
        q->next = NULL;
        q = p;//不能直接用q，因为p是新链表的头指针
        while (q->next != NULL) q = q->next;
        q->next = head;
        return p;
    }
};
