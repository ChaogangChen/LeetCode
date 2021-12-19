/*
LeetCode 700 二叉搜索树中的搜索
https://leetcode-cn.com/problems/search-in-a-binary-search-tree/
*/
/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root->left == nullptr && root->right == nullptr && root->val != val) return nullptr;
        if (root->val == val) return root;
        if (val > root->val) {
            if (root->right != nullptr) return searchBST(root->right, val);
            else return nullptr;
        }
        if (val < root->val){
            if (root -> left != nullptr) return searchBST(root->left, val);
            else return nullptr;
        }
        return nullptr;
    }
};