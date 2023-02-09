#include<bits/stdc++.h>
using std::cout, std::cin, std::vector, std::string, std::endl;

vector<vector<string>> board(8,vector<string>(8,". "));
vector<vector<char>> internal(8,vector<char>(8,'e'));
int count=0;

void display(vector<vector<string>> vec){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<vec[i][j]<<"  ";
        }
        cout<<" ";
        cout<<i+1;
        cout<<"\n";
    }
    cout<<endl;
    cout<<"a   b   c   d   e   f   g   h";
    cout<<"\n\n";
}

void solve1(int col1,char row1){
    cout<<"\nWhere do you wanna place?\n";
    int des_col;
    char des_row;
    cin>>des_col>>des_row;
    col1-=1;
    int des1=des_col-1;
    if(internal[col1][row1-'a']=='e'||internal[col1][row1-'a']=='b'){
        cout<<"\n--INVALID--\n\n";
        return;
    }
    // FOR PAWN
    else if(board[col1][row1-'a']=="P "){
        if(des1<col1-2||des1>=col1){
            cout<<"--Move not possible--\n";
            return;
        }
        else if((des1==col1-1)&&(internal[des1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
        else if((des1==col1-2)&&(internal[des1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
        count++;
    }
    // FOR KNIGHT
    else if(board[col1][row1-'a']=="N "){
        if(des1>7||des1<0||des_row-'a'>7||des_row-'a'<0){
            cout<<"--Move not possible--";
            return;
        }
        else if((des1==col1+1||des_row-'a'==row1-'a'+2)&&(internal[des1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
        else if((des1==col1-1||des_row-'a'==row1-'a'+2)&&(internal[des1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
        else if((des1==col1+1||des_row-'a'==row1-'a'-2)&&(internal[des1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
        else if((des1==col1-1||des_row-'a'==row1-'a'-2)&&(internal[des1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
        else if((des1==col1+2||des_row-'a'==row1-'a'+1)&&(internal[des1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
        else if((des1==col1+2||des_row-'a'==row1-'a'-1)&&(internal[des1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
        else if((des1==col1-2||des_row-'a'==row1-'a'+1)&&(internal[des1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
        else if((des1==col1-2||des_row-'a'==row1-'a'-1)&&(internal[des1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
    }
    // FOR ROOK //left part not done yet
    else if(board[col1][row1-'a']=="R "){
        if((des_row-'a'!=row1-'a')){
            cout<<"--Move not possible--\n";
            return;
        }
        else{
            bool b=true;
            for(int i=row1+1;i<=des_row;i++){
                if(board[i][des_row-'a']!=". "){
                    b=false;
                }
            }
            if(b && internal[des1][des_row-'a']=='e'){
                board[des1][des_row-'a'] =board[col1][row1-'a'];
                board[col1][row1-'a']=". ";
                internal[col1][row1-'a']='e';
                internal[des1][des_row-'a']='w';
            }
            else{
                cout<<"--Move not possible--\n";
                return;
            }
        }
    }
    
    display(board);
}

void solve2(int col1,char row1){
    cout<<"\nWhere do you wanna place?\n";
    int des_col;
    char des_row;
    cin>>des_col>>des_row;
    col1-=1;
    int des1=des_col-1;
    if(internal[col1][row1-'a']=='e'||internal[col1][row1-'a']=='w'){
        cout<<"\n--INVALID--\n\n";
    }
    else if(board[col1][row1-'a']=="P "){
        if(des1<col1-2||des1>=col1){
            cout<<"--Move not possible--\n";
            return;
        }
        else if((des1==col1-1)&&(internal[des1-1][des_row-'a']=='e')){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[col1][row1-'a']='e';
            internal[des1][des_row-'a']='w';
        }
        else if((des1==col1-2)&&(internal[des1-2][des_row-'a']==0)){
            board[des1][des_row-'a'] =board[col1][row1-'a'];
            board[col1][row1-'a']=". ";
            internal[des1][des_row-'a']==1;
        }
        count++;
    }
    
    display(board);
}

void display1(vector<vector<bool>> vec){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<vec[i][j]<<"  ";
        }
        cout<<" ";
        cout<<"\n";
    }
}
int main(){

    cout<<"-----THE CHESS GAME-----\n\n";
    char side1;
    cout<<"What side would you like to play as ? W/B\n";
    // cin>>side1;
    // side1=toupper(side1);
    char side2;
    (side1=='W')? side2='B':side2='W';
    // cout<<side1<<" "<<side2<<endl;
    board[0][0]=board[7][0] ="R ";
    board[0][1]=board[7][1] ="N ";
    board[0][2]=board[7][2] ="B ";
    board[0][3]=board[7][3] ="Q ";
    board[0][4]=board[7][4] ="K ";
    board[0][5]=board[7][5] ="B ";
    board[0][6]=board[7][6] ="N ";
    board[0][7]=board[7][7] ="R ";
    for(int i=0;i<8;i++){
        internal[7][i]=internal[6][i]='w';
    }
    for(int i=0;i<8;i++){
        internal[0][i]=internal[1][i]='b';
    }
    for(int i=0;i<8;i++){
        board[6][i]=board[1][i]="P ";
    }
    display(board);
    // display1(internal);
    int k1,k2,r11,r12,r21,r22,n11,n12,n21,n22,b11,b12,b21,b22,q1,q2;
    k1=k2=r11=r12=r21=r22=n11=n12=n21=n22=b11=b12=b21=b22=q1=q2=1;
    while(k1&&k2){
        if(count%2==0){
            cout<<"\nWHITE'S TURN: \n";
            // string str;
            int col;
            char row;
            cout<<"\nPick the piece you want to move: \n";
            cin>>col>>row;
            solve1(col,row);
            // count++;
        }
        else{
            cout<<"\nBLACK'S TURN: \n";
            cout<<"\nWHITE'S TURN: \n";
            // string str;
            int col;
            char row;
            cout<<"\nPick the piece you want to move: \n";
            cin>>col>>row;
            solve2(col,row);
            // count++;
        }
    }

}