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
// we know BST property that  inorder is sorted so we just have to cal diff betn prev and curr node 
int mindiff=INT_MAX;
TreeNode* prev=NULL;

void inorder(TreeNode* root){
    if(root==NULL) return; //Bc

    inorder(root->left);
    if(prev!=NULL){
        mindiff=min(mindiff,root->val-prev->val);
    }
    prev=root;
    inorder(root->right);

    return;

}

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return mindiff;
        
    }
};