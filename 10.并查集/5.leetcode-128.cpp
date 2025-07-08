/*************************************************************************
	> File Name: 5.leetcode-128.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 08 Jul 2025 03:22:22 PM CST
 ************************************************************************/
class UnionSet {
public:
    UnionSet(int n) : fa(n + 1), sz(n + 1) {
        for (int i = 0; i <= n; i ++) {
            fa[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        return fa[x] = (fa[x] == x ? x : find(fa[x]));
    }
    int merge(int a, int b) {
        int aa = find(a), bb = find(b);
        if (aa == bb) return 0;
        fa[aa] = bb;
        sz[bb] += sz[aa];
        return 1;
    }
    vector<int> fa, sz;
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), cnt = 0; // cnt记录当前用到了哪个下标
        unordered_map<int, int> h; // 哈希表用于数字到下标之间的映射
        UnionSet u(n);
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (h.find(x) !=h.end()) continue; // 重复数字不算
            h[x] = cnt++;
            if (h.find(x + 1) != h.end()) u.merge(h[x], h[x + 1]);
            if (h.find(x - 1) != h.end()) u.merge(h[x], h[x - 1]);
        }
        int ans = 0;
        for (int i = 0; i < cnt; i++) {
            ans = max(ans, u.sz[i]);
        }
        return ans;
    }
}; // 数字的连续性可以抽象为并查集的连通性
