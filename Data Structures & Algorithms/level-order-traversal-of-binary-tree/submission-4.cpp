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


void help(TreeNode* root, int height,vector<vector<int>>& res)
{
    if (root==nullptr)
    {return;}

    if (res.size()==height)
    {
       res.push_back({});;
    }
    res[height].push_back(root->val);
    help(root->left, height+1, res);
    help(root->right, height+1, res);
};
    
vector<vector<int>> levelOrder(TreeNode* root) {
vector<vector<int>> result;

    help(root,  0, result);

    return result;
}
};
