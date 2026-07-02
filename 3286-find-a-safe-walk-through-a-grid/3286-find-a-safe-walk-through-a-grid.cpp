class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
//BFS
//TC=m*n*h  //SC=m*n = queue and best

//best[r][c] = maximum remaining health seen so far.



        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int>> q;

        // Lose health if starting cell is unsafe
        int startHealth = health - grid[0][0];

        if (startHealth <= 0)
            return false;

        vector<vector<int>> best(m, vector<int>(n, -1));  //initialize all val with -1

        best[0][0] = startHealth;
        q.push({0, 0, startHealth});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto cur = q.front();
            q.pop();

            int r = cur[0];
            int c = cur[1];
            int h = cur[2];

            if (r == m - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) { // for checking possible choices 
    //int dr[] = {1, -1, 0, 0};
       // int dc[] = {0, 0, 1, -1}; represents choices rows and col = up, down, r,l  and k traverse choices one by one 
                int nr = r + dr[k]; //new row
                int nc = c + dc[k]; //new col

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;  // check if bndry condn

                int newHealth = h - grid[nr][nc]; //new health for each choice

                if (newHealth <= 0)
                    continue;  //skip choice if helath is invalid

                // Already reached with equal or better health
                if (best[nr][nc] >= newHealth)
                    continue;   // we have alrady reached to that cell with better choice prev   
                    //best helps with takig optimal choice

                best[nr][nc] = newHealth;
                q.push({nr, nc, newHealth}); //puseh new cell and explore from there
                // ...   from st pos we go right and push health // sim down and push new helath but from [1][0] we can again go to [0][1] so best helps 
                // ...
            }
        }

        return false;










 
 //APPROACH 1

//         class Solution {
// public:
// //Plain DFS
// // TC = O(4^(m×n)) (exponential)
// // SC= O(m×n)


// TLE error become we have 4 choices up,down,r,l and for ach chouice we ahain go deep like for r we go up, d,r,l 


// bool check(vector<vector<int>>& grid,vector<vector<bool>>& vis,int health,int r, int c,int m , int n ){

//     // if(health < 0)
//     // return false;

//     if(r < 0 || c < 0 || r >= m || c >= n)
//     return false;  //bndry check

//     if(vis[r][c])   //already visited
//     return false; //alreadyy visited

//     if(grid[r][c]==1) health--;
//     if(health <= 0)
//     return false;  // after dectreasimng health if it becoems 0


//     if(r==m-1 && c==n-1)
//     return true;

    
//   vis[r][c] = true;

//     bool ans =
//         check(grid, vis, health, r+1, c, m, n) ||
//         check(grid, vis, health, r-1, c, m, n) ||
//         check(grid, vis, health, r, c+1, m, n) ||
//         check(grid, vis, health, r, c-1, m, n);
   
//    vis[r][c] = false;  // backtracking you have to make cells again unvisited to check poss solutions for calls

//     return ans;
// }



// bool findSafeWalk(vector<vector<int>>& grid, int health) {
// //BC
// int m=grid.size(); //rows
// int n=grid[0].size(); //col
// vector<vector<bool>> vis(m, vector<bool>(n,false)); //bool vector to mark visited
//  return check(grid,vis, health,0,0,m,n);







//     }
// };
        
    }
};