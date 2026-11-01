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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == nullptr && q == nullptr)     // begge tomme: ens
        {
            return true;
        }

        if (p == nullptr || q == nullptr)     // kun den ene tom: ikke ens
        {
            return false;
        }

        if (p->val != q->val)                 // forskellig værdi: ikke ens
        {
            return false;
        }

        // ens, hvis venstre sider er ens OG højre sider er ens
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
