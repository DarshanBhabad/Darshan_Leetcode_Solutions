class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        //brute force
        int cnt=0;
        for(int i=0;i<arr1.size();i++){
            bool c =true;
            for(int j=0;j<arr2.size();j++){
                int s=abs(arr1[i]-arr2[j]);
                if(s<=d) c=false;  
            }
            if(c) cnt++;

        }
        return cnt;
    }
};