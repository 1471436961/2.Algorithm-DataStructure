/*************************************************************************
	> File Name: 10.leetcode-4.cpp
	> Author: zhouyingda
	> Mail: 
	> Created Time: Wed 10 Jan 2024 07:45:24 PM CST
 ************************************************************************/

#include <cinttypes>
class Solution {
public:
    /* 将问题泛化为找两个数组中排名第K的元素
     * 两个数组各取前K/2个元素，假设两个数组选取的最后一个元素分别为a和b且a<b,
     * 则所选取的K个元素中最多有K-2个元素比小，即a的最大排名为K-1，
     * 舍弃a对应数组所选取的全部元素，问题变成在剩下的元素中找排名第K/2的元素，
     * 循环执行上述过程，直到k=1，取两个剩余元素的最小值即可*/
    int findK(vector<int> &n1, int ind1, vector<int> &n2, int ind2, int k) {
        int n = n1.size(), m = n2.size();
        if (k == 1) {
            int a = (n1.size() == ind1 ? INT32_MAX : n1[ind1]);
            int b = (n2.size() == ind2 ? INT32_MAX : n2[ind2]);
            return min(a, b);
        }
        if (n == ind1) return n2[k - 1];
        if (m == ind2) return n1[k - 1];
        // 下面三行代码保证两个数组选取的元素数量不会超过其剩余元素数量且一共为K个
        int cnt1 = min(k / 2, n - ind1);
        int cnt2 = min(k - cnt1, m - ind2);
        cnt1 = k - cnt2;
        if (n1[ind1 + cnt1 - 1] <= n2[ind2 + cnt2 - 1]) {
            return findK(n1, ind1 + cnt1, n2, ind2, k - cnt1);
        }
        return findK(n1, ind1, n2, ind2 + cnt2, k - cnt2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if ((n + m) % 2) return findK(nums1, 0, nums2, 0, (n + m) / 2 + 1);
        double a = findK(nums1, 0, nums2, 0, (n + m) / 2);
        double b = findK(nums1, 0, nums2, 0, (n + m) / 2 + 1);
        return (a + b) / 2.0;    
    }
};
