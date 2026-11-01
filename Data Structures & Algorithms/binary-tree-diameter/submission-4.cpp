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
    int bedste = 0;     // den længste sti, vi har set indtil nu

    int hoejde(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int venstre = hoejde(root->left);
        int hojre = hoejde(root->right);

        bedste = max(bedste, venstre + hojre);   // stien gennem denne knude

        return 1 + max(venstre, hojre);          // dybden opad
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        bedste = 0;        // start forfra
        hoejde(root);      // går gennem hele træet og opdaterer bedste
        return bedste;     // svaret
    }
};
