class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());  //asc order of st time if st time iss ame then asc of end time
int n=intervals.size();

        vector<vector<int>>ans;
        //ans.push_back({0,0});
 bool isemty=true; 
        for(auto i : intervals){
            if(isemty) {
                ans.push_back(i);
                isemty=false;
                continue;
            }
            if(ans.back()[1]>=i[0]){
                ans.back()[1]=max(i[1],ans.back()[1]);
            }
            else{
                ans.push_back(i);
            }

        }
        return ans;
    }
};