/*************************************************************************
	> File Name: 9.leetcode-862.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 16 Jul 2025 05:24:07 PM CST
 ************************************************************************/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        deque<int> q;
        q.push_back(0);
        int ans = n + 1;
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && sum[i] - sum[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && sum[i] < sum[q.back()]) q.pop_back();
            q.push_back(i);
        }
        if (ans == n + 1) return -1;
        return ans;
    }
};
