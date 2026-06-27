class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        unordered_map<int,int>s;

        for(int i=0;i<nums.size();i++){
            s[nums[i]]++;
        }
        int maxcnt=0;
     int cnt; // singke element if seq not found 
     unordered_set<int>p;
        for(int i=0;i<nums.size();i++){
            if(p.find(nums[i])==p.end()){//element already not used or calculated
            p.insert(nums[i]);
              long long j = nums[i];
               cnt=0;
                //special case 
                if (j == 1) {
                    int ones = s[1];
                    if (ones % 2 == 0)   ones--;
                    maxcnt = max(maxcnt, ones);
                    continue;
                }
              while(j<INT_MAX){
                  //j<INT_MAX as given array will have only integers

                if(s[j]>=2) {
                    cnt+=2;  
                    if (j > INT_MAX / j) break;  //overflow offcourse you wont find j in array
                    if (s.find(j * j) == s.end()){
                        // if curr numbers square is not present in array that means it is last element
                        // of current sequence  2,2,4,16,4 ans=2,4,16,4,2 =5  as 16 square 256 is not in array that means it is an last element of curr seq and we have to stop
                        cnt--;      
                        break;
                    }
                     j *= j;

                }
                else if(s[j]==1){
                    cnt++;
                       break; 
                }
                else break;  // doesnt follow seq as element not present
                
              }
              // l cnt cant be even suppose nums = {2,2,4,4}  maxcnt=4 but it not valid should be odd so decrejment by 1
              if(cnt % 2 == 0)
             cnt--;
              maxcnt=max(maxcnt,cnt);
            }
        }
    
    
        return maxcnt;
    }
};