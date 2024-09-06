void dfs(int x){
    v[x] = true;

    for(auto son : g[x])
        if(!v[son])
            dfs(son);
}

void bfs(int x){
    queue<int> q;
    v[x] = true;
    q.push(x);

    while(!q.empty()){
        int u = q.front();
        for(auto son : g[u]){
            if(!v[son]){
                q.push(son);
                v[son] = true;
            }
            
        }
        q.pop();
    }
}