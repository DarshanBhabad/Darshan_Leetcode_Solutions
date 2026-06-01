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
          //APPROACH 1
   
    void inorder(TreeNode* root, vector<int>& inor){
        if(root == NULL) return;

        inorder(root->left, inor);
        inor.push_back(root->val);
        inorder(root->right, inor);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> inor;
        inorder(root, inor);

        return inor[k - 1];
        
    }
};