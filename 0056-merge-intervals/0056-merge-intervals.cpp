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


//         //class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>>ans;
//         sort(intervals.begin(),intervals.end());
//         ans.push_back(intervals[0]);
//         for(int i=1;i<intervals.size();i++){
//             if(ans.back()[1]>=intervals[i][0]){
//                 ans.back()[1]=max(intervals[i][1],ans.back()[1]);}
//                 else{
//                 ans.push_back(intervals[i]);
//                 }
            
//         }
//         return ans;
//     }
// };
    }
};