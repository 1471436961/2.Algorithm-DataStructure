/*************************************************************************
	> File Name: 14.leetcode-219.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Mon 08 Jan 2024 10:25:14 PM CST
 ************************************************************************/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ind(n);
        for (int i = 0; i < n; i++) ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j) -> bool {
            if (nums[i] != nums[j]) return nums[i] < nums[j]; // 值不同时按值排序
            return i < j; // 值相同时按下标排序
        });
        for (int i = 0, I = n -1; i < I; i++) {
            if (nums[ind[i]] - nums[ind[i + 1]]) continue;
            if (ind[i + 1] - ind[i] <= k) return true;
        }
        return false;
    }
};
