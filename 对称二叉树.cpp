/*
LeetCode 101 对称二叉树
https://leetcode-cn.com/problems/symmetric-tree/
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
# include <queue>
# include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 使用递归解题
class Solution {
public:
    bool reverse(TreeNode* a, TreeNode* b){
        if (!a && !b) return true;
        if (!a || !b) return false;
        return a->val == b->val &&  reverse(a->left, b->right) && reverse(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return reverse(root, root);
    }
};

// 使用队列解题
class Solution{
public:
    bool check(TreeNode* m, TreeNode *n){
        queue<TreeNode*> q;
        q.push(m);
        q.push(n);
        while (!q.empty()){
            m = q.front();q.pop();
            n = q.front();q.pop();
            if (!m && !n) continue;
            if (!m || !n) return false;
            if (m->val != n->val) return false;
            q.push(m->left);q.push(n->right);
            q.push(m->right);q.push(n->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root){
        return check(root, root);
    }
};