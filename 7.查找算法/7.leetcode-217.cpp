/*************************************************************************
	> File Name: 7.leetcode-217.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 10 Jan 2024 06:23:31 PM CST
 ************************************************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> h; // 底层为哈希表,只存值用其即可
        for (auto x : nums) {
            if (h.find(x) != h.end()) return true;
            h.insert(x);
        }
        return false;
    }
};
