/*************************************************************************
	> File Name: 12.leetcode-21.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 08 Jan 2024 09:57:22 PM CST
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode ret, *p = &ret;
      while (list1 || list2) {
          if (list2 == NULL || (list1 && list1->val <= list2->val)) {
              p->next = list1;
              p = list1;
              list1 = list1->next;
          } else {
              p->next = list2;
              p = list2;
              list2 = list2->next;
          }
        }  
        return ret.next;
    }
};
