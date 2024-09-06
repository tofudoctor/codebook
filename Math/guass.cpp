// a是增廣矩陣
double a[N][N], eps = 1e-6;

int guass(){
    int r, c;
    for(r = 0, c = 0;c < n;c++){
        // 找最大的開頭;
        int t = r;
        for(int i = r;i < n;i++){
            if(abs(a[i][c]) > abs(a[t][c]))
                t = i;
        }
        
        if(abs(a[t][c]) < eps) continue;
        
        // 換到上面
        for(int i = c;i <= n;i++) swap(a[t][i], a[r][i]);
        // 弄出leading one(每個數除開頭)
        for(int i = n;i >= c;i--) a[r][i] /= a[r][c];
        // 去掉底下的0
        for(int i = r + 1; i < n;i++){
            if(abs(a[i][c]) > eps){
                for(int j = n;j >= c;j--){
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }

    if(r < n){
        for(int i = r;i < n;i++){
            if(abs(a[i][n]) > eps)
                return 2;// 無解
        }
        return 1; // 無限多組解
    }
    for(int i = n - 1;i >= 0;i--){
        for(int j = i + 1;j < n;j++)
            a[i][n] -= a[i][j] * a[j][n];
    }
    return 0;// 有唯一解
}

void solve(int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= n;j++){
            cin >> a[i][j];
        }
    }
    
    int t = guass();
    
    if(t == 0){
        for(int i = 0;i < n;i++){
            if(abs(a[i][n]) < eps) cout << 0.00;
            else cout << fixed << setprecision(2) << a[i][n];
            cout << "\n";
        }
    }
    else if(t == 1) cout << "Infinite group solutions";
    else cout << "No solution";
}