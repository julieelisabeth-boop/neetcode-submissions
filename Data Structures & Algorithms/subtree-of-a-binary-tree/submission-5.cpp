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


    bool sameTree(TreeNode* a, TreeNode* b)
    {
        if (a==nullptr && b==nullptr) {return true;} //er begge tomme? return ture og hop ud af funktionen
        if (a==nullptr || b==nullptr) {return false;} //er kun den ene tom? så kan de ikke være ens retunere false og hop ud;
        if (a->val!=b->val){ return false;} //vi ved her der ikke er nogle nullptr, så vi tjekker er værdierne ikke ens? return false hvis de ik er
        //hvis værdierne er ens kommer vi videre til sidtse trin:
        return sameTree(a->left, b->left) && sameTree(a->right, b->right);
        //her klader vi funktionen igen rekrusivt på venstre barn og højre barn

    //hele den her fukntionn tjekker egenligt bare om hele root a er ens med root b
        

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root==nullptr) {return false;} //hvis det en nullptr så retunere false vil aldrig kunne være ens
        if (sameTree(root,subRoot)) return true; //tjekker, om hele træet, der starter i root, er identisk med subRoot, altså alle noder under den også.
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot); //ellers kald rekursivt på venstre og højre, bare en af dem skal være true
    }
};
