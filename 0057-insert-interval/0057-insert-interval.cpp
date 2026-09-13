class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
       
        for(int i = 0; i < n; i++) {

            // interval is completely before newInterval
            if(intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
            }

            // interval is completely after newInterval
            // current interval is completely after newinterval so successfully push newinterval and update the newinterval to current 
            else if(intervals[i][0] > newInterval[1]) {
                ans.push_back(newInterval);
                newInterval = intervals[i];
            }

            // overlapping
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        ans.push_back(newInterval);//new interval gets updated and then pushed

        return ans;
    }
};