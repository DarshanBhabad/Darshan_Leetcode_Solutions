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
    





        bool check(TreeNode* l, TreeNode* r){
    //BC //its just handles one side end before others or not 
// Both NULL
        if(l == NULL && r == NULL)
            return true;

        // One NULL
        if(l == NULL || r == NULL)
            return false;

        // Values different
        if(l->val != r->val)
            return false;

    return check(l->left,r->right) && check(l->right,r->left);
}
    bool isSymmetric(TreeNode* root) {
        //level order seperate vector for left and right and check diversion 

        //or
      return check(root->left,root->right);
    }
};