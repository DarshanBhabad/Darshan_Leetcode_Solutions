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
class BSTIterator {
public:
    //TreeNode* next;
    
    int nextptr;
    vector<TreeNode*>v;


    void inorder(TreeNode* root){
    if(root==NULL) return ;
    inorder(root->left);
    v.push_back(root);
    inorder(root->right);
    return ;
}
    BSTIterator(TreeNode* root) { //constructor of class BST iterator actual mem allocation happens here
       
      //O(n)
      nextptr=-1;   // as values of node are greater than 0
      inorder(root);
        //for specific object nextptr values will be maintained
    }


    int next() { //O(1)
        nextptr++;
     
     return v[nextptr]->val;


        
    }
    
    bool hasNext() { //O(1)
    
       return nextptr+1<v.size(); //we dont have to update nextptr just check
        
    }

// USING STACK
//     class BSTIterator {
//     private: stack<TreeNode*> mystack;
// public:
//     BSTIterator(TreeNode* root) {
//         pushAll(root);
//     }
    
//     int next() {
//         TreeNode* top=mystack.top();
//         mystack.pop();
//         if(top->right) pushAll(top->right);
//         return top->val;
//     }
    
//     bool hasNext() {
//         return !mystack.empty();
//     }
//     void pushAll(TreeNode* root){ //TC O(h) ht
//         while(root){
//             mystack.push(root);
//             root=root->left;
//         }
//     }
// };
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */