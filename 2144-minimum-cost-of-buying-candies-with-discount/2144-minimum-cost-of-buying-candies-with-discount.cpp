class Solution {
public:
    int minimumCost(vector<int>& cost) {
        
        sort(cost.begin(),cost.end(),greater<int>());
        int fcost=0;
        //if(cost.size()==1) return cost[0];
        int cnt=0;
        for(int i=0;i<cost.size();i++){
            cnt++;
        if(cnt<=2) fcost+=cost[i];
            else{
                cnt=0;
                //i++;
            }


           
           
           
        }
        return fcost;
    }
};