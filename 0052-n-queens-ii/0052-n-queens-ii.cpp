class Solution {
public:
    int ans=0;
    bool isValid(vector<string> &board, int &r, int &c){
        int n=board.size();
        for(int i=r;i>=0;i--) if(board[i][c]=='Q') return false;
        for(int i=r,j=c;i>=0 && j>=0;i--,j--) if(board[i][j]=='Q') return false;
        for(int i=r,j=c;i>=0 && j<n;i--,j++) if(board[i][j]=='Q') return false;

        return true;
    }

    void bt(vector<string> &board, int i){
        if(i==board.size()){
            ans++;
            return;
        }

        for(int j=0;j<board.size();j++){
            if(isValid(board,i,j)){
                board[i][j]='Q';
                bt(board,i+1);
                board[i][j]='.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n,string(4,'.'));
        bt(board,0);
        return ans;
    }
};