// 多重背包
const int N = 250000, M = 2010;
int v[N], w[N], n, V; // 體積/價值/n種物品/背包容量 
int dp[M];

int solve(){
    int cnt = 0;
    for(int i = 0, a, b, c;i < n;i++){
        cin >> a >> b >> c;
        
        int k = 1;
        while(k <= c){
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            
            c -= k;
            k <<= 1;
        }
        if(c){
            cnt++;
            v[cnt] = a * c;
            w[cnt] = b * c;
        }
    }
    
    n = cnt;
    
    for(int i = 1;i <= n;i++)
        for(int j = V;j >= v[i];j--)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            
    return dp[V];
}

// 區間DP
for(區間長度: len)
    for(區間的剖分點: i = 1 ~ n - len + 1)
        j = i + len - 1
        for(k = i ~ j)
            dp[] = ...