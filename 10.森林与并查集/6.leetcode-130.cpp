/*************************************************************************
	> File Name: 6.leetcode-130.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Tue 08 Jul 2025 04:11:14 PM CST
 ************************************************************************/

class UnionSet {
public:
    UnionSet(int n) : fa(n + 1) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        if (get(a) == get(b)) return ;
        fa[get(a)] = get(b);
        return ;
    }
    vector<int> fa;
}; // 精简版并查集

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        UnionSet u(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int ind = i * n + j + 1;
                if (board[i][j] != 'O') continue;
                if (i == 0 || i == m - 1) u.merge(ind, 0);
                if (j == 0 || j == n - 1) u.merge(ind, 0);
                // 由于连通的相互性，只需要连通相应点右边和下面的点
                if (j + 1 < n && board[i][j + 1] == 'O') u.merge(ind, ind + 1);
                if (i + 1 < m && board[i + 1][j] == 'O') u.merge(ind, ind + n);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'O') continue;
                int ind = i * n + j + 1;
                if (u.get(ind) != u.get(0)) board[i][j] = 'X';
            }
        }
        return ;
    }
}; // 可以通过 x * n + y + 1 将坐标映射到下标，然后利用并查集解决
