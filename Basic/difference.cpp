// 1D 
// insert
void insert(int l, int r, int c){
    b[l] += c;
    b[r + 1] -= c;
}
// build
for(int i = 1;i <= n;i++) insert(i, i, a[i]);


// 2D
// insert
void insert(int r1, int c1, int r2, int c2, int c){
    b[r1][c1] += c;
    b[r1][c2 + 1] -= c;
    b[r2 + 1][c1] -= c;
    b[r2 + 1][c2 + 1] += c;
}
// build 
for(int i = 1;i <= m;i++)
    for(int j = 1;j <= n;j++)
        insert(i, j, i, j, a[i][j]);