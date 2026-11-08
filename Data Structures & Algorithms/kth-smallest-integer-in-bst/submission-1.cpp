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
int val=0;
int x=0;

    void help(TreeNode* root, int k)
    {
        if (root==nullptr) {return;}

        help(root->left,k);
        x++;
        if (k==x) {val=root->val; return;}

        help(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        val=0;
        x=0;
        help(root,k);
        return val;
    }
};
