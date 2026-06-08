class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
    //     int st=-1;
    //     for(int i=0;i<n;i++ ){
    //         if(nums[i]<pivot){
    //             st++;
    //            swap(nums[i],nums[st]);
    //         }
    //     }
    //    // if(nums[i]>pivot) swap(nums[i],nums[n-1]); //when i=j at that setp

    vector<int>s;
    vector<int>g;
    vector<int>e;
    for(int i=0;i<n;i++){
        if(nums[i]<pivot)  s.push_back(nums[i]);
        else if(nums[i]>pivot) g.push_back(nums[i]);
        else e.push_back(nums[i]);
    }
    
  for(int i=0;i<s.size();i++){
   nums[i]=s[i];
  }
int m=s.size();
  for(int i=0;i<e.size();i++){
   nums[m+i]=e[i];
  }
  m+=e.size();
  for(int i=0;i<g.size();i++){
   nums[m+i]=g[i];
  }

        
        return nums;
    }
};