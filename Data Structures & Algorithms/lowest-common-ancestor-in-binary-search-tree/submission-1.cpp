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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

       TreeNode* node = root;

    while (node != nullptr)
        if (p->val < node->val && q->val < node->val) //hvis p og q værdi er under root
            {return lowestCommonAncestor(root->left, p, q);}// begge til venstre, ryk noden til venstre
        else if (p->val > node->val && q->val > node->val) //hvis p og q værdi er over root
            {return lowestCommonAncestor(root->right, p, q);}// begge til højre, ryk noden til højre
        else
            {return root;}              // de skilles, eller node er p/q så retuner bare node
    return nullptr;
    }
};
