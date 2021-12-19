/*
LeetCode 563 二叉树的坡度
https://leetcode-cn.com/problems/binary-tree-tilt/
*/
#include <cmath>
using namespace std;

//Definition for a binary tree node.
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
    int res = 0;
    int calu(TreeNode *root){
        if (root == nullptr) return 0;
        int sumLeft = calu(root->left);
        int sumRight = calu(root->right);
        res += abs(sumLeft - sumRight);
        return sumRight + sumLeft + root->val;
    }
    int findTilt(TreeNode* root) {
        calu(root);
        return res;    
    }
};