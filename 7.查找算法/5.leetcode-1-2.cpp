/*************************************************************************
	> File Name: 5.leetcode-1-2.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 10 Jan 2024 06:01:16 PM CST
 ************************************************************************/

class Solution {
public:
    int binary_search(vector<int> &nums, vector<int> &ind, int b, int x) {
        int head = b, tail = nums.size() - 1, mid;
        while (head <= tail) {
            mid = (head + tail) / 2;
            if (nums[ind[mid]] == x) return mid;
            if (nums[ind[mid]] < x) head = mid + 1;
            else tail = mid - 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ind(n, 0);
        for (int i = 0; i < n; i++) ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j) -> bool {
            return nums[i] < nums[j];
        });
        vector<int>ret(2);
        for (int i = 0; i < n; i++) {
            int j = binary_search(nums, ind, i + 1, target - nums[ind[i]]); 
            if (j == -1) continue;
            ret[0] = ind[i];
            ret[1] = ind[j];
        }
        return ret;
    }
};
