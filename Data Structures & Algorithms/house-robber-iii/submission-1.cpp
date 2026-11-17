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

    std::pair<int,int> help(TreeNode* root)
    {
       if (root==nullptr){return {0,0};}
        
        auto left=help(root->left);
        auto right=help(root->right);

int rob = root->val + left.second + right.second;
// vi robber root, så børnene må IKKE robbes → tag deres skip-værdi

int skip = std::max(left.first, left.second) + std::max(right.first, right.second);
// vi robber ikke root, så hvert barn må selv vælge → tag den højeste af rob og skip

        return {rob,skip};
    } 

    
    int rob(TreeNode* root) {
        {
        auto facit=help(root);
           return std::max(facit.first,facit.second);
        }
        
    }
};