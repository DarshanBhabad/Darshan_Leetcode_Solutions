class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        //prefix and suffix
        vector<int>na(n);
        vector<int>pa(n);
       //maximum height on left  of current 
        // Previous maximum
        pa[0] = height[0];

        for(int i = 1; i < n; i++) {
            pa[i] = max(pa[i-1], height[i]);
        }
       // maximum ht on right of currnet 
        // Next maximum
        na[n-1] = height[n-1];

        for(int i = n-2; i >= 0; i--) {
            na[i] = max(na[i+1], height[i]);
        }

         int ans = 0;

        for(int i = 0; i < n; i++) {
            int water = min(pa[i], na[i]) - height[i];
            ans += water;
        }
        return ans;

    }
};