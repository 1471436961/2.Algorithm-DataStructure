/*************************************************************************
	> File Name: 9.leetcode-3.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 10 Jan 2024 07:15:44 PM CST
 ************************************************************************/

class Solution {
public:
    bool check(string &s, int l) {
        int cnt[256] = {0}, k = 0; 
        // cnt统计窗口内每一种字符出现的次数，k统计窗口内不同字符数量
        for (int i = 0; s[i]; i++) {
            cnt[s[i]] += 1;
            if (cnt[s[i]] == 1) k +=1;
            if (i >= l) {
                cnt[s[i - l]] -= 1;
                if (cnt[s[i - l]] == 0) k -= 1;
            }
            if (l == k) return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int head = 0, tail = s.size(), mid;
        while (head < tail) {
            mid = (head + tail + 1) / 2;
            if (check(s, mid)) head = mid;
            else tail = mid - 1;
        }
        return head;
    } // 1111100000
};
