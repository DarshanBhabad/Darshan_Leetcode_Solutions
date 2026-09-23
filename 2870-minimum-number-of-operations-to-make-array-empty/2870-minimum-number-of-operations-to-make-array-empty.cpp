class Solution {
public:
    int minOperations(vector<int>& nums) {
        //same as 2244 min rnds to complete all tasks
        //if task is single of its difficulty level we return -1; not possible
        // as in each round we can 2 or 3 of same difficulty
         unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;

        }
        int ans=0;
        //TC
        // Total: O(n+k)=O(n), since k≤n.
        //sc  O(k)
       
    for(auto p:freq){
         int v = p.second;

         //choice 1 selectimg 3 

            // Single task cannot be completed
            if (v == 1) return -1;

            int d3 = v / 3;  
            int rem3 = v % 3;

            if (rem3 == 1) { //not possible to take in grps of 3  // so 
            // remove one grp of 3  so these grps 3 + 1 of remainder = 4    
            // now choose them in grps of 2  so d3-- and tehn d3+=2 
                d3--;
                d3 += 2;
            }
            else if (rem3 == 2) { // less than 3 v=2
                d3++;  //0+2 or if  v=5  d3=1  and d3++=2  whcih adds choosing remanining 2 in next rnd 
            }

            //chjoice 2 celectimng in grps of 2

            int d2 = v / 2;
            int rem2 = v % 2;

            if (rem2 == 1) {  // ex v=5   so reduce one d2 choice so it will give 2 and rekmainder 1 
            // adds upto 3  so d2-- and d2+=1  
                d2--;
                d2 += 1;
            }

            ans += min(d3, d2);
            }

            return ans;
    }
};