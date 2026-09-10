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
int getavg(TreeNode* root,int & acnt,int & ncnt){
    //Base case
    
    //BC
    if(root==NULL) return 0;
    //refresh nodes cnt for each node
     int lcnt=0;//left nodes cnt
     int rcnt=0;//right nodes cnt
     // in lcnt and rcnt each node will kepp adding itself 
    
    int lsum=getavg(root->left,acnt,lcnt);//current node pass cnt as 0; i.e lcnt
    //now nodes below it lcnt becomes ncnt for them

   int  rsum=getavg(root->right,acnt,rcnt);//current node pass node cnt as 0; as on local level cnt=0;
   int tsum=lsum+rsum+root->val;
   ncnt=lcnt+rcnt+1;
    if(root->val==tsum/ncnt) acnt++;  //answer cnt
    return tsum;

}
    int averageOfSubtree(TreeNode* root) {
        int acnt=0;//ans cnt
        // int lsum=0;
        // int rsum=0;
        int ncnt=0; //ncnt
        int tsum=0;
        getavg(root,acnt,ncnt);
        return acnt;
        
    }
};