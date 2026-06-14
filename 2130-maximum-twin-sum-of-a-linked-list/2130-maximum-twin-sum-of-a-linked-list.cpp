/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        
        vector<ListNode*>v;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp);
            temp=temp->next;

        }
int n=v.size();
int sum=0;
        for(int i=0;i<=((n/2)-1);i++){
         sum=max(sum,v[i]->val+v[n-1-i]->val);

        }
return sum;

//APPROACH 2 ... NO vector , SC= O(1);
// twin nodes 1st node from start 1st node from end 2nd node from start is twin of 2nd node from last 
// i th node (n-1-i)th node;
//as number od nodes are even 

//  ListNode* middleNode(ListNode* head){
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast->next && fast->next->next){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         return slow;
//     }

//     ListNode* reverse(ListNode* head){
//         ListNode* prev = NULL;
//         ListNode* curr = head;
//         while(curr){
//             ListNode* temp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = temp;
//         }
//         return prev;
//     }

//     int pairSum(ListNode* head) {
//         ListNode* middle = middleNode(head);
//         ListNode* second = middle->next;
//         middle->next = NULL;
//         ListNode* first = reverse(head);  //we reversed the 1st part of list by finding middle node  then storing all second parts nodes in 2nd  then setting 1st part last node that is middle node of whole list as NULL and reversing the the 1st part (either you can reverse 1st part or 2nd part)
//         int res = 0;
//         while(first){
//             res = max(res,first->val + second->val);
//             first = first->next;
//             second = second->next;
//         }
//         return res;
//     }
// };
    }
};