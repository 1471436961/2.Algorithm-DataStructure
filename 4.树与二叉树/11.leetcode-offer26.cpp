/*************************************************************************
	> File Name: 12.leetcode-offer26.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 28 Sep 2023 11:36:36 PM CST
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool match_one(TreeNode *A, TreeNode *B) {
        if (A == NULL) return B == NULL;
        if (B == NULL) return false;
        if (A->val != B->val) return false;
        return match_one(A->left, B->left) && match_one(A->right, B->right); 
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == NULL) return B == NULL;
        if (B == NULL) return false;
        if (A->val == B->val && match_one(A, B)) return true;
        if (isSubStructure(A->left, B)) return true;
        if (isSubStructure(A->right, B)) return true;
        return false;
    }
};
