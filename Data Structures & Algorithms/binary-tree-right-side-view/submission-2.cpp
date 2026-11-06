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
    vector<int> facit;      // en værdi pr. niveau, set fra højre

    void besog(TreeNode* root, int hoejde)
    {
        if (root==nullptr)
        {
            return;
        }

        if (facit.size() == hoejde) //første gang ved denne højde
        {
            facit.push_back(root->val);
        }

        besog(root->right, hoejde+1);
        besog(root->left, hoejde+1);

    }

    vector<int> rightSideView(TreeNode* root)
    {
        facit.clear();
        besog(root, 0);
        return facit;

        // nulstil facit, kald besog på root med hoejde 0, og returner facit
    }
};

