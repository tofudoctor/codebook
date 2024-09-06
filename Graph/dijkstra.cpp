int dis[N];
vector<PII> g[N];
bool v[N];

int dijkstra(int st, int ed){
    memset(dis, 0x3f, sizeof dis);
    dis[st] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, st});

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int p = x.second, pd = x.first;
        if(v[p]) continue;

        v[p] = true;

        for(auto it : g[p]){
            int son = it.first, w = it.second;
            if(pd + w < dis[son]){
                dis[son] = pd + w;
                pq.push({dis[son], son});
            }
        }
    }

    if(dis[ed] == 0x3f3f3f3f) return -1;
    return dis[ed];
}