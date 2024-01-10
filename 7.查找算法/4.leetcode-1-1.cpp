/*************************************************************************
	> File Name: 4.leetcode-1-1.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 10 Jan 2024 05:42:58 PM CST
 ************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h; 
        // unordered_map为哈希表，第一个类型为数组下标类型，第二个类型为哈希表中存储值的类型
        vector<int> ret(2);
        for (int i = 0, I = nums.size(); i < I; i++) {
            if (h.find(target - nums[i]) != h.end()) {
                ret[0] = h[target - nums[i]];
                ret[1] = i;
                break;
            }
            // h.find找到了返回一个迭代器，找不到返回h.end
            h[nums[i]] = i;
        }
        return ret;
    }
};
