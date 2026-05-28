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
void inorderseq(vector<int>&inorder,TreeNode* root){//direct refrence instead of copy changes will happen at originalloc
  
  if(root==NULL) return;
  inorderseq(inorder,root->left);
  inorder.push_back(root->val);
  inorderseq(inorder,root->right);
  

}

    bool isValidBST(TreeNode* root) {
        //validate  Binary seearch tree 
        //Inorder sequesnce should be in sorted order 
        vector<int>inorder;
        inorderseq(inorder,root);
        for(int i=1;i<inorder.size();i++){
            if(inorder[i-1]>=inorder[i])return false;
        }
        return true;
    }
};