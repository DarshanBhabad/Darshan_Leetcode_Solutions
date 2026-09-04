class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        
        int mne=INT_MAX;
        // vector<int>mx;
        vector<int>mn(n);
        for(int i=n-1;i>=0;i--){
             mne=min(mne,nums[i]);
             mn[i]=mne;

        }
int mxe=INT_MIN;
int ansi=-1;
        for(int i=0;i<n;i++){
             mxe=max(mxe,nums[i]);
             if(mxe-mn[i]<=k) {
                ansi=i;
               break; //got our smallest stable idx
             }
        }
        return ansi;
    }
};