/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
Node* levelo(Node* root){ 
    if (root==NULL) return root;  
    //BFS breadth first search travelling

    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    Node* prev=NULL;
  
    while(q.size()>0){
        Node* curr=q.front();
        q.pop();
       
       //level change
        if(curr==NULL){  
          
           if(prev) prev->next=NULL;
           prev=NULL;   //for next level set prev to NULL
            if(!q.empty()){   //if quue does have already some elements in it then only push NULL to seperate them from next level  otherwise we cant push NULL at queue's front...
                 
                q.push(NULL); // TO push NULL before putting next level ele in queue
                
            }
           
        }

        // same level
       else{
        if(prev) prev->next=curr;
        prev=curr; //update prev to curr for sam elevel

        if(curr->left) q.push(curr->left); //curr->left isn't NULL it exist
        if(curr->right) q.push(curr->right);
       
        }
    }
return root;
    }


    Node* connect(Node* root) {

      return  levelo(root);
    }
};