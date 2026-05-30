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

    //Option 2 
    // void inorder(TreeNode* root,vector<int> &ans)
    // {
    //    if(root==NULL)   return ;
    
    //    inorder(root->left, ans);
    //    ans.push_back(root->val);
    //    inorder(root->right, ans);

    // }

    // int minDiffInBST(TreeNode* root) 
    // {
    //     vector<int>ans;
    //     inorder(root,ans);

    //     int minDiff=abs(ans[1]-ans[0]);

    //     for(int i=0;i<ans.size()-1;i++)
    //     {
    //         int diff=abs(ans[i+1]-ans[i]);

    //         if(diff < minDiff)
    //         {
    //             minDiff=diff;
    //         }

    //     }

    //     return minDiff;
};