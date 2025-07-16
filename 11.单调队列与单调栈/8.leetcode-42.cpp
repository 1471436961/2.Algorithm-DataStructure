/*************************************************************************
	> File Name: 8.leetcode-42.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 16 Jul 2025 05:03:39 PM CST
 ************************************************************************/

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans = 0;
        for (int i = 0, n = height.size(); i < n; i++) {
            while (!s.empty() && height[s.top()] < height[i]) {
                int h = height[s.top()];
                s.pop();
                if (s.empty()) break;
                ans += (min(height[s.top()], height[i]) - h) * (i - s.top() - 1);
            }
            s.push(i);
        }
        return ans;
    }
};
