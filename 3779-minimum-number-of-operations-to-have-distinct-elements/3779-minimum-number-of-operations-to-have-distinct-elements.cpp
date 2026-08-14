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
        
    }
};