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
//使用递归来实现回溯
void dfs(int row){
    //当行数达到棋盘的最大行数时表明回溯发现了一个可行解
    if(row==MAXN){
        printBoard();
        cnt++;
        return;
    }
    //未达到棋盘最大行数，继续进行递归回溯
    for(int cln = 0; cln < MAXN; cln++){
        //为当前行选择列后立即进行对角线规则检查
        if(clnUsed[cln] || !checkBoard(row,cln))
            continue;
        //标记已选列，回溯进入下一层
        clnUsed[cln] = 1, board[row] = cln;
        dfs(row+1);
        clnUsed[cln] = 0, board[row] = -1;
    }
}
int main(){
    dfs(0);
    cout<<cnt<<'\n';
    return 0;
}