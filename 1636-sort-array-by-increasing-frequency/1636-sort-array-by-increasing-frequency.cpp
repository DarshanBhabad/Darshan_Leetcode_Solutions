class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        //TC=O(n+nlogn)//nlogn is push's and pop's tc
        unordered_map<int,int>m; //to store number and freq
//automatically it initializes key with value as 0
         for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
         }
// samllest freq should come on top so we have to use min heap as it amintains max ele on top
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto p:m){
            q.push({p.second,-p.first});  // as if 1st values are same we have to decide by whose 2nd value or who is bigger (deacresing order ) //for taht we will insert -ve number 
            //which will treat smaller as bigger


        }
        // now for queue freq will be 1st part ofpair and number will be second
        vector<int>ans;
     while(!q.empty()){
        int a=-q.top().second; //number // to make number origianl i.e -2 to 2
        int b=q.top().first;//freq
        while(b>0){
        ans.push_back(a);
        b--;
        }
        q.pop();
     }
                    

      return ans;  


// APPROACH 2 custom sort and map tc=n(logn)
// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         for (int num : nums) {
//             freq[num]++;
//         }

//         sort(nums.begin(), nums.end(), [&](int a, int b) { //custom sort considering freq 
//             if (freq[a] == freq[b]) {  // for tie-breaking cond'n 
//                 return a > b; //one who is bigger comes first
//             }
//             return freq[a] < freq[b];  //else one who has smaller freq comes first
//         });

//         return nums;
//     }
// };

      
    }
};