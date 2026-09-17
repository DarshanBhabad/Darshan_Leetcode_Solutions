class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        


// DP QUESTION we will solve using sliding window + little of dp
// left and right bndry
int n=arr.size();
int l=0;
int sum=0;
int ans=INT_MAX;
int best=INT_MAX;
vector<int>left(n,INT_MAX); //to store the == target founded subarrays upto current index with minimum length
for(int r=0;r<n;r++){
    sum+=arr[r];
   while(sum>target){ //to maintain window always with always sum<=target 
       sum-=arr[l];
         l++;
   }

   if(sum==target){//found subarray
     int length=r-l+1; //length of discovered subarray

       //now check if previously we have founded any  it will be possible only when l>0 as we moved forward 
       if(l>0 && left[l-1]!=INT_MAX){ // there exist prev subarray i.e l>0 and l(l-1) ---> best founded upto prev index
          ans=min(ans, length+left[l-1]);

       } 
       //update for current new bndry upto new/current (right) insertion in left vector
       best=min(best,length);
   }


       left[r]=best;



   

}


if(ans!=INT_MAX) return ans;
return -1;


    }
};