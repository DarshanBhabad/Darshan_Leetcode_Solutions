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

void BuildTree(TreeNode* &root,TreeNode*  currnode){ //root pass by ref becaus eroot->left it should change the orginal root's left and not the curr pass left or local variable
// normal pas sby val will create BuildTree(root->left,currnode); // root->left  as a new local var and has no link with root so refer original root
    if(root==NULL){ 
        root=currnode; 
    return ;}
   if(currnode->val<root->val) BuildTree(root->left,currnode);
   else BuildTree(root->right,currnode);
   return;
}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
           
        TreeNode* root=new TreeNode(preorder[0]);
       
         for(int i=1;i<preorder.size();i++){
            TreeNode* currnode=new TreeNode(preorder[i]);
             BuildTree(root,currnode);
        }  
       
      return  root;

        
    }
};