// spfa shortest path
int spfa(int st, int ed){
    memset(dis, 0x3f, sizeof dis);
    dis[st] = 0;
    queue<int> q;
    q.push(st);
    v[st] = true;

    while(!q.empty()){
        int p = q.front();
        q.pop();
        v[p] = false;

        for(auto it : g[p]){
            int son = it.first, w = it.second;
            if(dis[son] > dis[p] + w){
                dis[son] = dis[p] + w;
                if(!v[son]){
                    v[son] = true;
                    q.push(son);
                }
            }
        }
    }

    return dis[ed];
}

// check negetive loop
// if TLE try stack
bool spfa(){
    memset(dis, 0x3f, sizeof dis);
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    v[0] = true;

    while(!q.empty()){
        int p = q.front();
        q.pop();
        v[p] = false;

        for(auto it : g[p]){
            int son = it.first, w = it. second;
            if(dis[son] > dis[p] + w){
                dis[son] = dis[p] + w;
                cnt[son] = cnt[p] + 1;

                if(cnt[son] >= n) return true;
                if(!v[son]){
                    v[son] = true;
                    q.push(son);
                }
            }
        }
    }

    return false;
}