#include<iostream>
#include<cmath>
using namespace std;

const int MAXN = 8;
int board[MAXN] = {0}, clnUsed[MAXN] = {0}, cnt = 0;
// 检查当前行所选列与已选列是否满足对角线规则
bool checkBoard(int row, int selected) {
    for (int cln = 0; cln < row; cln++) {
        if (board[cln] == selected || abs(row - cln) == abs(selected - board[cln]))
            return false;
    }
    return true;
}
// 输出放置位置，放置皇后的位置以'Q'表示，未放置皇后的位置以'*'表示
void printBoard() {
    for (int row = 0; row < MAXN; row++) {
        for (int cln = 0; cln < MAXN; cln++)
            cout << (board[row] == cln ? "Q " : "* ");
        cout << '\n';
    }
    cout << '\n';
}
// 使用递归实现回溯搜索，L表示左侧的禁止列，M表示已选择的列，R表示右侧的禁止列
void dfs(int row, int L, int M, int R) {
    if (row == MAXN) {
        printBoard();
        cnt++;
        return;
    }
    int available = ~(L | M | R);
    while (available) {
        int cln = available & (~available + 1);
        available ^= cln;
        if (checkBoard(row, cln)) {
            board[row] = cln;
            dfs(row + 1, (L | cln) << 1, M | cln, (R | cln) >> 1);
            board[row] = 0; // 回溯
        }
    }
}
int main() {
    int n = MAXN;
    int N_ONES = (1 << n) - 1;
    dfs(0, 0, 0, 0);
    cout << "Total solutions: " << cnt << endl;
    return 0;
} 