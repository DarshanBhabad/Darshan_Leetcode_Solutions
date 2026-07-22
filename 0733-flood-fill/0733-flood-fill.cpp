class Solution {
public:
    int m, n;

    bool check(int i, int j, int e, vector<vector<int>>& image) {
        return (i >= 0 && i < m &&
                j >= 0 && j < n &&
                image[i][j] == e);//only tt=t  //if thes ecpn then true else false  
                //==e that is it isnt visited (==color) saves work of visited && isn't !=e so safe to visit
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int e) {

        image[sr][sc] = color;

        int dr[4] = {-1, 1, 0, 0}; // optimization on 4 ifs in my approach just syntacally
        int dc[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = sr + dr[k];
            int nc = sc + dc[k];

            if (check(nr, nc, e, image))
                dfs(image, nr, nc, color, e);
        }
        return;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        m = image.size();
        n = image[0].size();

        int e = image[sr][sc];
    //no need of visited as image[sr][sc]==color will do its work
        if (e == color)
            return image; // no need of performing DFS if start is laready same as color
            //i.e image[sr][sc]=1 and color=1  so adjacent sames i.e 1's already color so no need 

        dfs(image, sr, sc, color, e);

        return image;
    }
};



// BOTH TC = O(m*n);




              //my solution 

// class Solution {
// public:
// int m;
// int n;
// void dfs(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<bool>>& visited,int e){
//     //starting node image[sr][sc]
//     // if(image[sr][sc]!=e) return;
//     visited[sr][sc]=true;
//     image[sr][sc] = color;
//     if(check(sr,sc-1,m,n,e,image,visited))  dfs(image,sr,sc-1,color,visited,e);
//      if(check(sr,sc+1,m,n,e,image,visited))   dfs(image,sr,sc+1,color,visited,e);
//       if(check(sr-1,sc,m,n,e,image,visited))  dfs(image,sr-1,sc,color,visited,e);
//        if(check(sr+1,sc,m,n,e,image,visited))  dfs(image,sr+1,sc,color,visited,e);
// return;
// }
// bool check(int i,int j,int m,int n,int e,vector<vector<int>>& image,vector<vector<bool>>& visited){
//     if(i>m-1||i<0||j>n-1||j<0||image[i][j]!=e||visited[i][j]) return false;
//     return true;
// }

// vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         //using DFS
//      m=image.size();
//      n=image[0].size();
//         int e=image[sr][sc];
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//          dfs(image,sr,sc,color,visited,e);

//           return image;
//     }
// };