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

bool nu=true;
int facit=0;

    int hojde(TreeNode* root)
    {
        if (root==nullptr)
        {
            return 0;
        }

        int left=hojde(root->left);
        int right=hojde(root->right);

        facit=left-right;
        if (facit>1 || facit<-1)
        {
            nu=false;
        }

        return max(left,right)+1;
    }

    bool isBalanced(TreeNode* root) {

       int hej=hojde(root);
        
        return nu;
    }
};
