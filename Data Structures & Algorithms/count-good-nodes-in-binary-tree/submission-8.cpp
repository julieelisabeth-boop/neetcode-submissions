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

int count=0;

    void maxTjek(TreeNode* root, int maxHidtil)
    {
        if (root==nullptr)
        {
            return;
        }
        else if (root->val>=maxHidtil)
        {
            count++;
            maxHidtil=root->val;
        }

        maxTjek(root->left, maxHidtil);
        maxTjek(root->right, maxHidtil);
    }
    
    int goodNodes(TreeNode* root) {
        count = 0;
        maxTjek(root, root->val);
        return count; 
    }
};
