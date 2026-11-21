class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

 int n =nums.size();
        int  cnt=0;
       vector<int>ps(n,0);

       //calculatint the prefix sum for each index
       ps[0]=nums[0];
       for(int i=1;i<n;i++){
        ps[i]=ps[i-1]+nums[i];

       }
       unordered_map<int,int>m;
       for(int j=0 ;j<n;j++){
        if(ps[j]==k)cnt++; //case:1 ps is required sum i.e k
        
        //case2.... ps[i-1]=ps[j]-k  -- imp formula 
        int val=ps[j]-k;
        if(m.find(val)!=m.end()){
            //value exist 
            cnt+=m[val]; //cnt incresed by freq of that val
        }
        
        m[ps[j]]++;//current chya before sarv add ahet ps map madhe and we are finding subarray(continuous) so later chya entirs map madhe naslya tari chalel

       }


      return cnt;  
        

       // for problem Longest subarray with sum K 178 tuf 

//        class Solution{
// public:
//     int longestSubarray(vector<int> &nums, int k){
// // Suppose your current window sum is 5. You remove the leftmost element, but the sum can either increase or decrease depending on whether that element is negative or positive.

// // Therefore, there is no reliable condition for shrinking the window.

// // We want the longest subarray whose sum equals k.

// // Suppose:
// // \[
// // prefix[j] - prefix[i] = k
// // \]

// // Rearranging:
// // \[
// // prefix[i] = prefix[j] - k
// // \]

// // So, for every index j, we need to check whether the prefix sum sum - k has appeared before.

// // To maximize the length, store the first occurrence of every prefix sum. 
// // as our reuired sum is from i to j 

// unordered_map<long long,int>m; //{sum, index}
// int ans=0;
// long long sum=0;

// for(int i=0;i<nums.size();i++){
//     sum+=nums[i];
//     if(sum==k) ans=max(ans,i+1); //length i+1;

//     if(m.find(sum-k)!=m.end(){
//         ans=max(ans,i-m[sum-k]); // we store only the 1st ocuurence of sum 
//     }
//       // Store only the first occurrence
//             if(mp.find(sum) == mp.end()) {
//                 mp[sum] = i;
//             }


// }



// return ans;


//         //sliding window only for non -ve integers 
//         // int sum=0;
//         // int ans=0;
//         // int i=0;
//         // int j=0;
//         // int n=nums.size();
//         // while(j<n){
//         //     sum+=nums[j];

//         //      while(sum > k && i <= j) {
//         //         sum -= nums[i];
//         //         i++; 
//         //         // remove all the ocuurences which causing some to overload
//         //     }
//         //       if(sum==k)ans=max(ans,j-i+1);
           
//         //       j++;
//         //    }
          
           
//         // }
//         // return ans;
//     }
// };

    }
};