class Solution {
public:

    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        // Time Complexity: O(n log n) (sorting dominates)


        //custome sort func to sort intervals by asc order of st time
        sort(intervals.begin(), intervals.end(), [](const  vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0])
        return a[1] > b[1];   // larger end first   smae st time [1,4],[1,5]
        return a[0] < b[0]; 
        });
        // const tells the compiler: "I want to read this data via reference to save memory, and I promise not to change it."   // refer to the mem that is allocated in interval vector only
    
    vector<vector<int>>ans;
    ans.push_back(intervals[0]); //insert 1st element(vector)

    for(int i=1;i<intervals.size();i++){
        // int n=ans.size(); //roews in ans
        if(intervals[i][1] > ans.back()[1])    //last  inseted elemnt  sorted order do st time will be lesser always
        {
            ans.push_back({min(intervals[i][1],ans.back()[1]),max(intervals[i][1],ans.back()[1])});
            // pr jusr insert ans.push_back(intervals[i]);  as it will also track end time 
        }
    }

    
return ans.size();


//  Sc=O(1)
// class Solution {
// public:
//     int removeCoveredIntervals(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
//             if (a[0] == b[0]) {
//                 return a[1] > b[1];
//             }
//             return a[0] < b[0];
//         });

//         int ans = 0;
//         int maxEnd = -1;

//         for (const auto& in : intervals) {  //for each interval
//             if (in[1] > maxEnd) { //check end time [1,4] [1,5] sorting already put [1,5] 1st so [1,4] covered by it
//                 ans++;
//                 maxEnd = in[1];
//             }
//         }

//         return ans;
//     }
// };
        
    }
};