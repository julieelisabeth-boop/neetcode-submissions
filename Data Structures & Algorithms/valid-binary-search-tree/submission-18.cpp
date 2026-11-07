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
    bool valid=true;


    bool tjek(TreeNode* root, long long nedre, long long oevre)
{
    if (root==nullptr) {return true;}

    if (root->val<=nedre || root->val>=oevre) {return false;}

    return tjek(root->left, nedre, root->val) && tjek(root->right, root->val, oevre);

}


    bool isValidBST(TreeNode* root) {
        return tjek(root, LLONG_MIN, LLONG_MAX);
    }
};

