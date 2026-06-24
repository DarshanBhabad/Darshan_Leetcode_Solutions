class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //min_heap keeps smallest element on top
        priority_queue<int,vector<int>,greater<int>>q;  //for maxx heap it is default no need to pass conteainer vector and sorting logic 
        //here it will maintain smallest element at root and pop will happen of root an then heap will 
        // organize itself  imagine trees maintain smallest element at root 
        // also at top just like stacks(heaps donr use them but just for understanding) 
        // it will store k largest elemnts 

        for(int x : nums){
            q.push(x);

            if(q.size()>k){
                q.pop();  // heap organizes itself so it will always keep k lergest and pop smalllest and reorganize itself 
            }
        }

        return q.top();
    }
};