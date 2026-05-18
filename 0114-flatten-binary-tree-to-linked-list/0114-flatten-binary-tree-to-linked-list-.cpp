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
    //with these i was loosing  like 2->3->4 but when i do l->right=r i.e 2->right=5 i was loosing the access to 3 and 4 so i have to make sure i traverse to end of 2 (using temp) and then only connect its right to r 



    }

    return root;
}

    void flatten(TreeNode* root) {
        // TreeNode* temp=root;
        preorder(root);
        // return temp;



        
    }
};

//OR Shraddha MAM
// TreeNode* nextright=NULL; //to track previously visited node so that we can add it to curr nodes right
// void flatten(TreeNode* root) {
//         if(root==NULL) return;
         
//          flatten(root->right) //convert right part to LL
//           flatten(root->left)
//           root->left=NULL;
//           root->right=nextright;
//            root = nextright ;
//            return;



        
//     }
// };
