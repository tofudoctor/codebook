vector<int> ans;
int in[MXN];

bool toposort(){ // 0 base
    queue<int> q;
    for(int i = 0;i < n;i++){
        if(!in[i]){
            q.push(i);
            ans.push_back(i);
        }
    }

    while(!q.empty()){
        int p = q.front();
        for(auto son : g[p]){
            if(!--in[son]){
                q.push(son);
                ans.push_back(son);
            }
        }
        q.pop();
    }

    return ans.size() == n;
}