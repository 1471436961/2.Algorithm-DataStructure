/*************************************************************************
	> File Name: 8.leetcode-349.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 10 Jan 2024 06:33:36 PM CST
 ************************************************************************/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> h; // 用哈希表实现的集合，会自动去重
        vector<int> ret;
        for (auto x : nums1) h.insert(x);
        for (auto x : nums2) {
            if (h.find(x) == h.end()) continue;
            ret.push_back(x);
            h.erase(h.find(x));
        }
        return ret;
    }
    // 去重技巧：1.利用set集合；2.找到后删除
};
