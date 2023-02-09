#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<string>> vec){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<vec[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<endl;
}
int main(){
    vector<vector<string>> board(8,vector<string>(8,". "));
    vector<vector<string>> square(8,vector<string>(8));
    board[0][0]=board[7][0] ="R ";
    board[0][1]=board[7][1] ="N ";
    board[0][2]=board[7][2] ="B ";
    board[0][3]=board[7][4] ="Q ";
    board[0][4]=board[7][3] ="K ";
    board[0][5]=board[7][5] ="B ";
    board[0][6]=board[7][6] ="N ";
    board[0][7]=board[7][7] ="R ";
    for(int i=0;i<8;i++){
        board[1][i]="P"+to_string(i+1);
        board[6][i]="P"+to_string(i+1);
    }
    display(board);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            square[i][j]="s"+
        }
    }
}