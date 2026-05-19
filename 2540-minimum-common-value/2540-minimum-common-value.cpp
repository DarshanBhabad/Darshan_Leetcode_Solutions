class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        //int m=max(nums1.size(),nums2.size());
        // for(int i=0;i<m;i++){

        // }

        int m=nums1.size();
        int n=nums2.size();
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]==nums2[j]){
                return nums1[i];
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return -1;
    }
};