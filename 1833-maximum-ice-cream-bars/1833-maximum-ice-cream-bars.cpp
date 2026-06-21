class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        //GRFREADY APPROACH as he can buy in any order
        sort(costs.begin(),costs.end());
int cnt=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]>coins) break;
            if(costs[i]<=coins) {
                cnt++;
                coins-=costs[i];
            }

        }
        return cnt;
    }
};