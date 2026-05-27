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
TreeNode* inordersuccessor(TreeNode* root){
    while(root!=NULL && root->left!=NULL){ //both condn should be true then only update 
        root=root->left;
    }
    return root;
}


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)  return NULL;

        if(key<root->val) root->left=deleteNode( root->left,  key);
        else if(key>root->val) root->right=deleteNode( root->right,  key);
        else{ //root->val==Key 
        //case 1 and 2  noot to be del has 0 or 1 child
        if(root->left==NULL) {
        TreeNode* temp =root->right;
        delete(root);
        return temp;
       }
       else if(root->right==NULL) {
        TreeNode* temp =root->left;
        delete(root);
        return temp;
       }
       else{ //node  has 2 childs
       TreeNode* IS= inordersuccessor(root->right); //  find leftmost node in right subtree we 
       //pass right subtree here now write func to find leftmost in it
       root->val = IS->val;
       root->right=deleteNode(root->right,IS->val); //deleyte the iorder successor


       }
        }


      return root;  
    }
};