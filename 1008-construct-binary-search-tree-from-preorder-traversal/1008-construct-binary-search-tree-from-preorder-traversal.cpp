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
//     // APPROACH 1 : Recursion  TC is O(n^2) 
// void BuildTree(TreeNode* &root,TreeNode*  currnode){ //root pass by ref becaus eroot->left it should change the orginal root's left and not the curr pass left or local variable
// // normal pas sby val will create BuildTree(root->left,currnode); // root->left  as a new local var and has no link with root so refer original root
//     if(root==NULL){ 
//         root=currnode; 
//     return ;}
//    if(currnode->val<root->val) BuildTree(root->left,currnode);
//    else BuildTree(root->right,currnode);
//    return;
// }

//     TreeNode* bstFromPreorder(vector<int>& preorder) {
           
//         TreeNode* root=new TreeNode(preorder[0]);
       
//          for(int i=1;i<preorder.size();i++){
//             TreeNode* currnode=new TreeNode(preorder[i]);
//              BuildTree(root,currnode);
//         }  
       
//       return  root;


// APPROACH 2 MONOTONIC STACK : stck that stores all elemnts in either asc or desc order

// here as seq is preorder we wil try to maintain stack in asc order
 // TC is O(n) as each node is pushed na dpopped only once

TreeNode* bstFromPreorder(vector<int>& preorder) {
           
        TreeNode* root=new TreeNode(preorder[0]);
       stack<TreeNode*>s;
       s.push(root); if(preorder.size()==1) return root;
         for(int i=1;i<preorder.size();i++){
           TreeNode* currn= new TreeNode(preorder[i]);
            if(currn->val<s.top()->val) {
                s.top()->left=currn;
                s.push(currn);
            }
            else{
            TreeNode* trackn; //  it is a pointer it will keep track of a prev top node directly pointing to taht nodes mem location 
               while(!s.empty() && s.top()->val<currn->val){
                trackn= s.top();   
                s.pop();

                
               }
               trackn->right=currn;
               s.push(currn);
            }
        }  
       
      return  root;
        
    }
};