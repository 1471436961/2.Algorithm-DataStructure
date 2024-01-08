/*************************************************************************
	> File Name: 10.leetcode-148-1.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 08 Jan 2024 09:18:46 PM CST
 ************************************************************************/
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
 // quick_sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;
        int l = head->val, r = head->val, z;
        ListNode *p = head, *h1 = nullptr, *h2 = nullptr, *q;
        while (p) l = min(p->val, l), r = max(p->val, r), p = p->next;
        if (l == r) return head;
        z = (l + r) >> 1; // 此处不能用向0取整的除法，否则可能死循环
        p = head;
        while (p) {
            q = p->next;
            if (p->val <= z) {
                p->next = h1;
                h1 = p;
            } else {
                p->next = h2;
                h2 = p;
            }
            p = q;
        }
        h1 = sortList(h1);
        h2 = sortList(h2);
        p = h1;
        while (p->next) p = p->next;
        p->next = h2;
        return h1; 
    }
};
