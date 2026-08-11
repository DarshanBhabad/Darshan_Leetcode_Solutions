class Solution {
public:
 

    bool isValidSudoku(vector<vector<char>>& board) {
    //     visited<bool>c(9,false);
       
    //   if(checkc(board,c)) return  true;
       int n =board.size();
    //   checkr()
    //   check_s(),n
    // for each row;

    // TC=O(81) or O(1)  for 9*9 grid else O(N*N)

    unordered_set<char>r;
    for(int i=0;i<n;i++){
        r.clear(); //for new row
        for(int j=0;j<n;j++){
            if(board[i][j]!='.' && r.find(board[i][j])!=r.end()) return false;
        else if(board[i][j]!='.') r.insert(board[i][j]);
        }
        
    }

    r.clear();
    // for each column
    for(int i=0;i<n;i++){ // i act as cools
        r.clear(); //for new col
        for(int j=0;j<n;j++){// change cols
            if(board[j][i]!='.' && r.find(board[j][i])!=r.end()) return false;
        else if(board[j][i]!='.') r.insert(board[j][i]);
        }
    }

    r.clear();

    // 3*3 grid checking
     
unordered_set<char> s;

for(int row = 0; row < 9; row += 3){
    for(int col = 0; col < 9; col += 3){

        s.clear();

        for(int i = row; i < row + 3; i++){
            for(int j = col; j < col + 3; j++){

                if(board[i][j] != '.' && s.find(board[i][j]) != s.end())
                    return false;

                else if(board[i][j] != '.')
                    s.insert(board[i][j]);
            }
        }
    }
}

        


      return true;

     
      

        
    }
};