class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

       //cnt continuous sequqnce and possible subarrays formed by it 
       
        //TC+O(n) SC=O(1) 
int n=nums.size();
         // long long total = (n*(n+1))/2 ;
        long long s=0;
        long long len=0;
        // int l=-1;
        // int r=n;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i] > maxK ) {
                // s+=(i-l)*(r-i);
                s+=(len)*(len+1)/2 ; // continuous valid valid elemnets  subarray
                len=0; // reset len to caluclate next valid seq 
            }
            else len++;
        }
 // Count the final valid segment
        s += len * (len + 1) / 2;
        
        return s;
    }
};