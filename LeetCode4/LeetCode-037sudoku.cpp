
int checkExist(int num, int r, int c, int row[][10], int col[][10], int block[][10]) {
    int x = r / 3 * 3 + c / 3;
    return row[r][num] || col[c][num] || block[x][num];
}
void update(int d, int i, int j, int flag, int row[][10], int col[][10], int block[][10]) {
    int x = i / 3 * 3 + j / 3;
    row[i][d] = flag;
    col[j][d] = flag;
    block[x][d] = flag;
}
int sudoku(char** board, int r, int c, int row[][10], int col[][10], int block[][10]) {
    if (c == 9 && r == 8) return 1;
    if (c == 9) {
        r += 1;
        c = 0;
    }
    int res;
    if (board[r][c] == '.') {
        for (int i = 1; i <= 9; i++) {
            if (!checkExist(i, r, c, row, col, block)) {
                board[r][c] = i + '0';
                update(i, r, c, 1, row, col, block);
                res = sudoku(board, r, c + 1, row, col, block);
                if (res == 1) break;
                update(i, r, c, 0, row, col, block);
                board[r][c] = '.';
            }
        }
        if (board[r][c] == '.') return 0;
        else return 1;
    }
    else {
        return sudoku(board, r, c + 1, row, col, block);
    }
}
void solveSudoku(char** board, int boardSize, int* boardColSize) {
    int x;//block[]
    int row[9][10] = { 0 };
    int col[9][10] = { 0 };
    int block[9][10] = { 0 };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            x = i / 3 * 3 + j / 3;
            row[i][board[i][j] - '0'] = 1;
            col[j][board[i][j] - '0'] = 1;
            block[x][board[i][j] - '0'] = 1;
        }
    }
    sudoku(board, 0, 0, row, col, block);
}
