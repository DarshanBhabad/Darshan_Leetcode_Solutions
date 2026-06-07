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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int ,TreeNode*>s;
        unordered_set<int> ch;
        for(int i=0;i<descriptions.size();i++){
            //TreeNode* root=new TreeNode(descriptions[0][0]);
            // for(int j=0;j<descriptions[0].size();j++){
                if(s.find(descriptions[i][0])==s.end()  ){
                    TreeNode* root=new TreeNode(descriptions[i][0]);
                    s[descriptions[i][0]]=root;
                }
            // }
            if(s.find(descriptions[i][1])==s.end()&&descriptions[i][2]==1){
                TreeNode* lc=new TreeNode(descriptions[i][1]);
                s[descriptions[i][0]]->left=lc;
                s[descriptions[i][1]]=lc;
                ch.insert(descriptions[i][1]);

            }
            if(s.find(descriptions[i][1])==s.end()&&descriptions[i][2]==0){
                TreeNode* rc=new TreeNode(descriptions[i][1]);
                 s[descriptions[i][0]]->right=rc;
                s[descriptions[i][1]]=rc;
                ch.insert(descriptions[i][1]);
            }
            if(s.find(descriptions[i][1])!=s.end()&&descriptions[i][2]==0){
               
                 s[descriptions[i][0]]->right=s[descriptions[i][1]];
                 ch.insert(descriptions[i][1]);
               
            }
            if(s.find(descriptions[i][1])!=s.end()&&descriptions[i][2]==1){
               
                 s[descriptions[i][0]]->left=s[descriptions[i][1]];
                 ch.insert(descriptions[i][1]);
               
            }
    }
        for(auto &it : s){
    if(ch.find(it.first) == ch.end())   // the parent which didnt found in child
        return it.second;
}

return NULL;
        
    }
};