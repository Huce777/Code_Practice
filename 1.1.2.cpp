//皇后问题
#include<iostream>
#include<math.h>
using namespace std;

const int MAXN = 8;
int board[MAXN] = {0}, clnUsed[MAXN] = {0}, cnt = 0;
//检查当前行所选列与已选列是否满足对角线规则
bool checkBoard(int row,int selected){
    for(int cln = 0; cln < row; cln++)
        if(abs(row-cln)==abs(selected-board[cln]))
            return false;
    return true;
}
//输出放置位置，放置皇后的位置以'Q'表示，未放置皇后的位置以'*'表示
void printBoard(){
    for(int row = 0; row < MAXN; row++){
        for(int cln = 0; cln < MAXN; cln++)
            cout<< (board[row] == cln ? "Q " : "* ");
        cout<<'\n';
    }
    cout<<'\n';
}
//n表示棋盘的大小
int n;
//递归实现回溯搜索。参数D为回溯的层次，L表s示左侧的禁止列，M表示已选择列，R表示右侧禁止列
int dfs(int D,int L,int M,int R){
    //回溯层次达到n，表明这是一种符合要求的放置方案
    if(D==n){
        cnt++;
        return 1;
    }
    //查找当前行的可选列
    for(int i=0; i<n; i++)
        //通过位运算技巧选择可选列
        if( ( ( 1 << i ) & ( L | M | R ) ) == 0 )
            //记录已选列、左侧禁止列、右侧禁止列，然后继续下一层回溯
            dfs(D+1, (L | (1<<i))<<1, M | (1<<i), (R | (1<<i))>>1);
        return 0;
}
int main(){
    cin>>n;
    dfs(0,0,0,0);
    cout<<"Total number of solutions: "<<cnt<<'\n';
    return 0;
}