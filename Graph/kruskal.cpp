vector<pair<int, PII>> edges; // w a b

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal(){
    for(int i = 0;i < n;i++) p[i] = i;
    sort(edges.begin(), edges.end());

    int res = 0, cnt = 0;
    for(int i = 0;i < n;i++){
        int w = edges[i].F, a = edges[i].S.F, b = edges[i].S.S;
        a = find(a), b = find(b);

        if(a != b){
            p[a] = b;
            cnt++;
            res += w;
        }
    }

    if(cnt < n - 1) return res;
    return INF;
}