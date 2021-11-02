/*
LeetCode 94 二叉树的中序遍历
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
*/
#include <vector>
#include <iostream>
using namespace std;
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 使用递归完成题目
class Solution {
public:
    vector<int> verse(TreeNode* root, vector<int> res){
        if (root -> left != nullptr) verse(root, res);
        res.push_back(root->val);
        if (root -> right != nullptr) verse(root, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        verse(root, res);
        return res;
    }
};

// 使用迭代完成题目
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        TreeNode* current;
    }
};
/*
迭代解题思路

*/
