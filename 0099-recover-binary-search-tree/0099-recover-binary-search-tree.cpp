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
void inorder(TreeNode* root,vector<TreeNode*>&ino)
{
    if(root==NULL) return;
    inorder(root->left,ino);
    ino.push_back(root);
    inorder(root->right,ino);
    return;
}
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>ino;
        inorder(root,ino);
        TreeNode* n1=NULL;
        TreeNode* n2=NULL;
        //property - inorder of BST is sorted in asc order
        for(int i=0;i<ino.size()-1;i++){
           
            if(ino[i]->val>ino[i+1]->val) {
         //as 2 nodes will cause the disturbance in sorted order 
         // there will be only two ways 
         //1)nodes are adjacent of each other ex. 1324  (3 and 2)
         //2)there are sorted order present betn them ex. 321 (3 and 1) 

                if(n1==NULL){ // so that  1st node is always preserved so that both cases will be handled
                    n1=ino[i];
                }
                n2=ino[i+1];
            }
        }
    swap(n1->val,n2->val);
        


        //APPROCH 2 TC=o(n) but sc=O(n) ===> morris inorder traversal for inorder func
        //also that n1 and n2 work we can do that in inorder func call only so that we dont have to use 
        // for loop again
    }
};