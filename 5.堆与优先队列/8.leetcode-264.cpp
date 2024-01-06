/*************************************************************************
	> File Name: 8.leetcode-264.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Sat 06 Jan 2024 11:34:23 PM CST
 ************************************************************************/

// 采用构造的方法，由第一个丑数开始乘以其最大质因数，依次生成丑数，并利用堆维护集合最值
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> s;
        s.insert(1);
        long long ans = 0;
        int flag = 0;
        while (n--) {
            ans = *s.begin();
            s.erase(s.begin());
            if (ans % 5 == 0) flag = 2;
            else if (ans % 3 == 0) flag = 1;
            else flag = 0;
            switch (flag) {
                case 0: s.insert(ans * 2);
                case 1: s.insert(ans * 3);
                case 2: s.insert(ans * 5);
            } // 利用switch语句和flag巧妙存入合适数量的数
        }
        return ans;
    }
};
