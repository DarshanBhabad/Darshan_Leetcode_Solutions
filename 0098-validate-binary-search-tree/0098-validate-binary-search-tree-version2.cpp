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

//MY method : by storing inorder seq

// void inorderseq(vector<int>&inorder,TreeNode* root){//direct refrence instead of copy changes will happen at originalloc
  
//   if(root==NULL) return;
//   inorderseq(inorder,root->left);
//   inorder.push_back(root->val);
//   inorderseq(inorder,root->right);
  

// }

//     bool isValidBST(TreeNode* root) {
//         //validate  Binary seearch tree 
//         //Inorder sequesnce should be in sorted order 
//         vector<int>inorder;
//         inorderseq(inorder,root);
//         for(int i=1;i<inorder.size();i++){
//             if(inorder[i-1]>=inorder[i])return false;
//         }
//         return true;


            // Method 2

bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
    //To be a valid BST : for left subtree of curr node max will be nodes val only 
    //and for right subtree max will NULL i.e -infy and min is nodes val

    if(root==NULL) return true;

    if(min!=NULL && root->val<=min->val) return false; //right subtree of curr node 

    if(max!=NULL && root->val>=max->val ) return false; //in left subtree of given node val should be les sthan nodes val

    return helper(root->left,min,root) && helper(root->right,root, max);


}

bool isValidBST(TreeNode* root) {

  return  helper(root, NULL,NULL);
  //inittially for root max and min are NULL 
  //we  represented -infy and +infy by NULL


        
    }
};