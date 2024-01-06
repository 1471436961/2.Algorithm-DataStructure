/*************************************************************************
	> File Name: 7.leetcode-23.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 06 Jan 2024 11:08:21 PM CST
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair<int, int> PII;
        int n = lists.size();
        set<PII> s;
        for (int i = 0; i < n; i++) {
            if (lists[i] == nullptr) continue;
            s.insert(PII(lists[i]->val, i));
        } // 向堆中存入数据时存入链表所在的序号，使得取出结点时可以找到下一个结点的地址
        ListNode new_head, *p = &new_head, *q;
        new_head.next = nullptr;
        while (s.size()) {
            PII a = *s.begin();
            s.erase(s.begin());
            q = lists[a.second];
            lists[a.second] = lists[a.second]->next;
            p->next = q;
            q->next = nullptr;
            p = q;
            if (lists[a.second]) {
                s.insert(PII(lists[a.second]->val, a.second));
            }
        }
        return new_head.next;
    }
};
