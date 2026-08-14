class Solution {
public:
    int minOperations(vector<int>& nums) {

        //Sliding window remove elemnts when you get duplicate in current window 
        //window of size 3;

        int i=0;
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>m; // to maintain freq // also when you create new key it automatically get assigned with val 0 s+; so no need to initialize;

        for(int j=0;j<n;j++){
            m[nums[j]]++;// increase the count 

            while(m[nums[j]]>1){// duplicate present 
               m[nums[i]]--; //reduce freq;
               i++;
               cnt++;


            }

        }
if(cnt%3==0) return cnt/3; // we have max operation i.e removing 1st 3 elemnts so total such count cnt/3 ex 18   18/3 = 6  6 operations ... batch operation in group of 3
        return cnt/3+1; // else 20 20/3=6  and rem 2 will be one batch so 6+1=7



//TC = O(n)

//         class Solution {
// public:

// TRAVERS EFROM BACK as we will obtain duplicated at front side only as we have to rmv elemnts from st  // so just get the index of 1st elemnt which is duplicate from back and break as that the pnt from where we need to rmv elemts 
//     int minOperations(vector<int>& nums) {

//         int indexToRemove = -1;
//         unordered_map<int, bool> mp;
//         int n = nums.size();
//         for(int i=n-1; i>=0; i--)
//         {
//             if (mp.find(nums[i]) != mp.end()) //elemnt is already there
//             {
//                 indexToRemove = i;
//                 break;
//             }

//             mp[nums[i]] = 1; // new entry cnt 
//         }

//         if (indexToRemove == -1)
//             return 0;
        
//         return indexToRemove/3 + 1;
        
//     }

        
    }
};