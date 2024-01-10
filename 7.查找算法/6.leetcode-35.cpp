/*************************************************************************
	> File Name: 6.leetcode-35.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 10 Jan 2024 06:17:34 PM CST
 ************************************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0, tail = nums.size(), mid; // 目标值可能比数组中所有数都大
        while (head < tail) {
            mid = (head + tail) / 2;
            if (nums[mid] < target) head = mid + 1;
            else tail = mid;
        }
        return head;
    } // 000001111
};
