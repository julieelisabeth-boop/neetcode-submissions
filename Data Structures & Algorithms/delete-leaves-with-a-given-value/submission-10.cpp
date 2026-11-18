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

    TreeNode* help(TreeNode* root, int target)
    {
        if (root==nullptr) {return nullptr;}


        root->left=help(root->left,target);
        root->right=help(root->right,target);

        if (root->left==nullptr && root->right==nullptr)
        {
            if(root->val==target)
            {
            delete root;
            return nullptr;
            }
            return root;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* facit=help(root, target);
        return facit;
    }
    
};