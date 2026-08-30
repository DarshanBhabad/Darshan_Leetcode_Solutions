class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        //TC O(n) sc O(1)
        int n = nums.size();
        int mn=INT_MAX;
        int mnidx=-1;
        int mx=INT_MIN;
        int mxidx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<mn){
               mn=nums[i];
               mnidx=i;
            }
            if(nums[i]>mx) {
                mx=nums[i];
                mxidx=i;
            }
        }
        
        // // int ans=0;
        // return min(mnidx+1,n-mnidx)+min(mxidx,n-mxidx);

        //3 cases both front , both back, one front one back
        //1 both front 
        int f=max(mnidx+1,mxidx+1);
        int b=max(n-mnidx,n-mxidx);
        int fb=min(mnidx+1,n-mnidx)+min(mxidx+1,n-mxidx);


//min(initializer_list) pass as list
return min({f,b,fb});
        

    }
};