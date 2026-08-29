class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
   //go to each land cell and add its perimeter then if has land bndry on 4 side fro ach side reduce by one
//TC=O(n*m) SC=O(1)
         int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        int r[] = {-1, 1, 0, 0};
        int c[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {

                    ans += 4;

                    for (int k = 0; k < 4; k++) {
                        int nr = i + r[k];
                        int nc = j + c[k];

                        if (nr >= 0 && nr < n &&
                            nc >= 0 && nc < m &&
                            grid[nr][nc] == 1) {
                            ans--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};