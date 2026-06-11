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

    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        int sum=0;
        if(root->left && root->left->left==NULL && root->left->right==NULL) {
            sum+=root->left->val;
        }
       sum+= sumOfLeftLeaves(root->left);
       sum+= sumOfLeftLeaves(root->right);




        return sum;

        //APPROACH 2
//         class Solution {
// public:
//     int dfs(TreeNode* root, bool isLeft) {
//         if (root == NULL) return 0;

//         if (root->left == NULL && root->right == NULL) {
//             return isLeft ? root->val : 0;
//         }

//         return dfs(root->left, true) + dfs(root->right, false);
//     }

//     int sumOfLeftLeaves(TreeNode* root) {
//         return dfs(root, false);
//     }
// };

    }
};