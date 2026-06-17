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

int countsum(TreeNode* root, int n){

if(root==NULL) return 0; //BC
n=n*10+root->val;
 // Leaf node
if (root->left == NULL && root->right == NULL)
    return n;
int l=countsum(root->left,n);
int r=countsum(root->right,n);

return l+r;
}


int sumNumbers(TreeNode* root) {
     //int n=0;
  return   countsum(root,0);




        
    }
};