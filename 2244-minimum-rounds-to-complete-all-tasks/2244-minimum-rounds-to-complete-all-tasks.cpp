class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        //if task is single of its difficulty level we return -1; not possible
        // as in each round we can 2 or 3 of same difficulty
         unordered_map<int,int>freq;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]]++;

        }
        int ans=0;
       
    for(auto p:freq){
         int v = p.second;

            // Single task cannot be completed
            if (v == 1) return -1;

            int d3 = v / 3;
            int rem3 = v % 3;

            if (rem3 == 1) {
                d3--;
                d3 += 2;
            }
            else if (rem3 == 2) {
                d3++;
            }

            int d2 = v / 2;
            int rem2 = v % 2;

            if (rem2 == 1) {
                d2--;
                d2 += 2;
            }

            ans += min(d3, d2);
            }

            return ans;
    }
};