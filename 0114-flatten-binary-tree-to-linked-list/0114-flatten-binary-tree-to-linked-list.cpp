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


TreeNode* preorder(TreeNode* root){
    if(root==NULL) return NULL;
   TreeNode* l= preorder(root->left);
    TreeNode* r=preorder(root->right);
    if(l!=NULL){
        TreeNode* temp=l;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        temp->right=r;
        root->right=l;
        root->left=NULL;
        




    // root->right=l;
    // l->right=r;
    // root->left=NULL;
    // l->left=NULL;
    // r->left=NULL;


    }

    return root;
}

    void flatten(TreeNode* root) {
        // TreeNode* temp=root;
        preorder(root);
        // return temp;



        
    }
};