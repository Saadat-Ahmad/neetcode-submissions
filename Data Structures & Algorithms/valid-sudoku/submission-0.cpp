class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(auto column : board){
            vector<int> colNum (9, 0);
            for(char num : column){
                if(num != '.') {
                    if(colNum[(num - '1')] == 1) return false;
                    colNum[(num - '1')] = 1;
                }
            }
        }
        for(int row = 0; row < 9; row++){
            vector<int> rowNum (9, 0);
            for(int col = 0; col < 9; col++){
                if(board[col][row] != '.') {
                    if(rowNum[(board[col][row] - '1')] ==  1) return false;
                    rowNum[(board[col][row] - '1')] = 1;
                }
            }
        }
        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                vector<int> blockNum (9, 0);
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(board[i+k][j+l] != '.'){
                            if (blockNum[board[i+k][j+l] - '1'] == 1) return false;
                            blockNum[board[i+k][j+l] - '1'] = 1;
                        }
                    }   
                }    
            }
        }
        return true;
    }
};
