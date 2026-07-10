class Solution {
public:

   //smaller version (length) TC-O(n*m)
int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0, minutes = 0;

        int dr[] = {-1,1,0,0}; //for boundries updates
        int dc[] = {0,0,-1,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }

        while(!q.empty() && fresh){  //fresh acts as bool in cpp 0 treated as false and any non-zero -1,1 treated as true
            int sz = q.size();

            while(sz--){ //check all older before newly infected  as for current minute
            // if more than 1 infected at curr min they can infect simultaneously 
            //maintain order in queue 1st min infected after them 2nd like that
                auto [i,j] = q.front();
                q.pop();

                for(int k=0;k<4;k++){ //4 possible neighbours
                    int ni=i+dr[k], nj=j+dc[k]; //new i and new j

                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1){ //bndry check and  check if fresh then only rotten it
                        grid[ni][nj]=2; //no need of visited mark it rotten noneed of visited
                        fresh--;
                        q.push({ni,nj});  
                    }
                }
            }
            minutes++;  // update only if all curr min  rotten done thier work of infecting neighbours
        }

        return fresh ? -1 : minutes;
    }
};


//           // TC=O(n*m)

//  bool check(int i, int j,vector<vector<int>>& grid,vector<vector<bool>>& vis, int n, int m)
//     {
//         if(i < 0 || j < 0 || i >= n || j >= m)
//             return false;

//         if(vis[i][j])
//             return false;

//         if(grid[i][j] != 1)   // only fresh oranges can be infected
//             return false;

//         return true;
//     }

//     int orangesRotting(vector<vector<int>>& grid) {
     

//         //as we know at every minute only 4 side adjavent orages gets rotten by rotten orange 
//         // so we need to use BFS with travel immediate neight=bours 1st (DFS - each neighbour in deep)
//  int n = grid.size();
//         int m = grid[0].size();

//         vector<vector<bool>> vis(n, vector<bool>(m, false));

//         queue<pair<int,int>> q;

//         int fresh = 0;

//         // Put all rotten oranges into queue  // so that if there are more tha 1 rotten oranges will infect simultaneously
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {

//                 if(grid[i][j] == 2) {
//                     q.push({i,j});
//                     vis[i][j] = true;
//                 }

//                 if(grid[i][j] == 1)
//                     fresh++;
//             }
//         }

//         if(fresh == 0)
//             return 0;

//         int minutes = 0;

//         while(!q.empty()) {

//             int sz = q.size();
//             bool infected = false;

//             //Did at least one fresh orange become rotten during this minute?" => infected  is used

//             while(sz--) { 
//                 //sz is used because  newly infected should NOT be processed immediately.They must wait until the next minute.
//                 // suppose at start 2 are infected all there infections of at 1st  min should be done 
//                 // they both pushed in queue at sart only and sz makes sure they  complete their work at 1st min

//                 auto p = q.front();
//                 q.pop();

//                 int i = p.first;
//                 int j = p.second;

//                 // top
//                 if(check(i-1,j,grid,vis,n,m)) {
//                     vis[i-1][j] = true;
//                     grid[i-1][j] = 2;
//                     q.push({i-1,j});
//                     fresh--;
//                     infected = true;
//                 }

//                 // bottom
//                 if(check(i+1,j,grid,vis,n,m)) {
//                     vis[i+1][j] = true;
//                     grid[i+1][j] = 2;
//                     q.push({i+1,j});
//                     fresh--;
//                     infected = true;
//                 }

//                 // left
//                 if(check(i,j-1,grid,vis,n,m)) {
//                     vis[i][j-1] = true;
//                     grid[i][j-1] = 2;
//                     q.push({i,j-1});
//                     fresh--;
//                     infected = true;
//                 }

//                 // right
//                 if(check(i,j+1,grid,vis,n,m)) {
//                     vis[i][j+1] = true;
//                     grid[i][j+1] = 2;
//                     q.push({i,j+1});
//                     fresh--;
//                     infected = true;
//                 }
//             }
//             // before newly infected set is proceeded check if in prev set does any of get infected
//             if(infected)
//                 minutes++;
//         }

//         if(fresh > 0)
//             return -1;

//         return minutes;
    
//     }
// };