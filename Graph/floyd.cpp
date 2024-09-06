// init
for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
        if(i == j) dis[i][j] = 0;
        else dis[i][j] = INF;
    }
}

// dis[a][b] = distance of a to b
for(int k = 0;k < n;k++){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}