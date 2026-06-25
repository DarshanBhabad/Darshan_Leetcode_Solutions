class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
 int half;
 int ans=0;
 unordered_map<int,int>m;
        for(int i=0;i<n;i++){
             m[target]=0;
            for(int j=i;j<n;j++){
                
                if(nums[j]==target){
                    m[nums[j]]++;
                }
                half=(j-i+1)/2;
                if(m[target]>half) ans++;
                
            }
           
        }
        return ans;



        //Approach 2 
        //no extra space
//         class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target) 
//     {
        // First method

        // Declarations and initializations
        // int i, j, n, count, temp, ans;
        // n = nums.size();
        // ans = 0;

        // Actual logic
//         for(i=0; i<n; i++)
//         {
//             count = 0;
//             for(j=i; j<n; j++)
//             {
//                 if(nums[j] == target)
//                 count++;

//                 temp = j - i + 1;
//                 if(temp == 1)
//                 {
//                     if(count == 1)
//                     ans++;
//                 }
//                 else
//                 {
//                     if(count > temp/2)
//                     ans++;
//                 }
//             }
//         }

//         // Return answer
//         return ans;
//     }
// };
    }
};