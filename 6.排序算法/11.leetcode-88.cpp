/*************************************************************************
	> File Name: 11.leetcode-88.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 08 Jan 2024 09:45:58 PM CST
 ************************************************************************/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, k = m + n - 1; // 从后向前归并
        while (p1 != -1 || p2 != -1) {
            if (p2 == -1 || (p1 != -1 && nums1[p1] >= nums2[p2])) {
                nums1[k--] = nums1[p1--];
            } else {
                nums1[k--] = nums2[p2--];
            }
        }
        return ;
    }
};
