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
    vector<int> facit;

    void help(TreeNode* root)
    {
        if (root==nullptr) {return;}
        
        help(root->left);
        facit.push_back(root->val);
        help(root->right);
    };

    vector<int> inorderTraversal(TreeNode* root) {
        facit.clear();
        help(root);

        return facit;
        
    }
};