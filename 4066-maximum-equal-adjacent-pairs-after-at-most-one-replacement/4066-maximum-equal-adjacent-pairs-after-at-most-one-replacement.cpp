class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        //already existed pairs;
        int n=nums.size();
        int already=0;
        // unordered_map<pair<int,int>,int>m; //{x,y},freq of pair
        map<pair<int,int>, int> m;//{x,y},freq of pair
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) already++;
            else  m[{nums[i-1],nums[i]}]++;
        }

        //now traverse each pair 
        int fans=0;
        
        for(auto &p:m){
            int x=p.first.first;
            int y=p.first.second;
            int ans=p.second; //{x,y}
            if(m.find({y,x})!=m.end()){ //found
                ans+=m[{y,x}]; //potential replacement //{x,y}
            }
            fans=max(fans,ans);

        }
        return fans+already;
    }
};