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
// void calcsum(TreeNode* root, int targetSum){
    
// }

bool calsum(TreeNode* root, int targetSum,int currsum){
    if(root==NULL) return  false;  //we didnt get target sum from path upto leaft node
    currsum+=root->val;
    if(root->left==NULL && root->right==NULL)
    return currsum==targetSum;
    //currsum is passed by value so every recursive call gets its own currsum
    //therefore leftsubtree recursive calls get thir separate copy of curr sum and right gets their own
        

        bool l=calsum(root->left,targetSum,currsum);
        bool r=calsum(root->right, targetSum,currsum);

        return l||r;

}

    bool hasPathSum(TreeNode* root, int targetSum) {
    
        // return l||r;
        return calsum(root,targetSum,0);








        
    }
};