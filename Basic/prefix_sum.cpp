// 1D 
// build
for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
// calculate a[l] + ... + a[r]
ans = s[r] - s[l - 1];


// 2D 
// build
for(int i = 1;i <= m;i++)
    for(int j = 1;j <= n;j++)
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
// calculate a[r1][c1] + ... + a[r2][c2]
ans = s[r2][c2] - s[r2][c1 - 1] - s[r1 - 1][c2] + s[r1 - 1][c1 - 1]; 