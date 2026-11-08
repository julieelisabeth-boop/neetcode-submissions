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
    int pre = 0;     // peger på den næste rod i preorder

    TreeNode* help(vector<int>& preorder, vector<int>& inorder, int start, int slut)
    {
        int antal = slut - start + 1;   // hvor mange tal er der i stykket
        if (antal <= 0) //ikke flere tal tilbage
        {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[pre]);   // roden er den næste i preorder
        pre++;                                          // ryk frem til den næste rod

        int pos = start;                                // find roden i inorder
        for (int i = start; i <= slut; i++)
        {
            if (inorder[i] == node->val)
            {
                pos = i;
                break;
            }
        }

        node->left = help(preorder, inorder, start, pos - 1);   // venstre stykke først
        node->right = help(preorder, inorder, pos + 1, slut);   // så højre stykke

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = 0;                                        // start forfra
        return help(preorder, inorder, 0, inorder.size() - 1);
    }
};
