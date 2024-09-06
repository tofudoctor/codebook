int p[MXN], sz[MXN], u;

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void Union(int a, int b){
    if(find(a) == find(b)) return;

    u--;
    sz[find(a)] += sz[find(b)];
    p[find(b)] = find(a);
    return;
}

// init
u = n;
for(int i = 0;i < n;i++){
    sz[i] = 1;
    p[i] = i;
}

