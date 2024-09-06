int dis[N];
vector<PII> g[N];

int bellman_ford(int st, int ed){
    memset(dis, 0x3f, sizeof dis);
    dis[st] = 0;
    
    for(int i = 0;i < k;i++){ // k times relaxation
        for(int p = 0;p < n;p++){
            for(auto it : g[p]){
                int son = it.first, d = it.second;
                if(dis[son] > dis[p] + d){
                    dis[son] = dis[p] + d;
                }
            }
        }
    }
    
    if(dis[ed] > INF / 2) return INF;
    return dis[ed];
}