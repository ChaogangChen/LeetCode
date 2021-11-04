/*
LeetCode 104 二叉树的最大深度
https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
*/
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
# include <iostream>
# include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
////////!!!!!!!!!!!!!!!!栈不适合用来做这道题
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0; //!!!!!!!!!!!!!!小心空的情况
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            depth ++;
            for(int i = q.size(); i > 0; i--){
                TreeNode* t = q.front();
                q.pop();
                if (t->left != nullptr) q.push(t->left);
                if (t->right != nullptr) q.push(t->right);
            }
        }
        return depth;
    }
};