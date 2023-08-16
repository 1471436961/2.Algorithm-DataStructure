/*************************************************************************
	> File Name: 9.Leetcode-946.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Aug 2023 04:14:16 PM CST
 ************************************************************************/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int x = 0, n = pushed.size(); 
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty() || s.top() != popped[i]) {
                while (x < pushed.size() && pushed[x] != popped[i])  {
                    s.push(pushed[x]);
                    x += 1;
                }
                if (x == pushed.size()) return false;
                s.push(pushed[x]);
                x += 1;
            }
            s.pop();
        }
        return true;
    }
};
