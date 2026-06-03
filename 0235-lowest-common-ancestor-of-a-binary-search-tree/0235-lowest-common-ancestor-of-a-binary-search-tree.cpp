/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    //     if(root==NULL) return NULL;
       
    //     if(root ==p || root==q) return root;
    //    TreeNode* l= lowestCommonAncestor( root->left,  p,  q);
    //    TreeNode* r= lowestCommonAncestor( root->right,  p,  q);
    
    // if(l && r) return root; //both are not  null;

    // if(l!=NULL) return l;
    // else
    // return r;

   // APPROACH 2
   if(root ==NULL) return NULL;
   if(root->val>p->val && root->val > q->val) //left subtree has p and q
   return lowestCommonAncestor( root->left,  p,  q);

   if(root->val<p->val && root->val < q->val) //right subtree has p and q
   return lowestCommonAncestor( root->right,  p,  q);

   else{ //LCA is p itself or q itself and if they both are in diff subtrees then root itself
   return root;
     

   }

        
    }
};