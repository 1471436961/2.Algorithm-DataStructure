/*************************************************************************
	> File Name: 8.leetcode-102-1.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Sep 2023 10:24:45 PM CST
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        TreeNode *node;
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            int cnt = q.size();
            vector<int> temp;
            for (int i = 0; i < cnt; i++) {
                node = q.front();
                temp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    } // 广搜(队列)实现层序遍历
};
