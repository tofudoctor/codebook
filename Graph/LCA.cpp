// 先把兩個點跳到同一層，同時往上跳直到跳到LCA的下一層
// 跳超過則fa[i, j] = 0, depth[0] = 0
#include <bits/stdc++.h>

using namespace std;

const int N = 40010, M = N * 2;

int n, m;
int depth[N], fa[N][16]; // 深度, f[i, j] = 第i個點的2^j祖先是誰
vector<int> g[N];

void add(int a, int b)
{
    g[a].push_back(b);
}

void bfs(int root)
{
    memset(depth, 0x3f, sizeof depth);
    queue<int> q;
    depth[0] = 0, depth[root] = 1;
    q.push(root);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (auto son : g[t])
        {
            if (depth[son] > depth[t] + 1)
            {
                depth[son] = depth[t] + 1;
                q.push(son);
                fa[son][0] = t;
                for (int k = 1; k <= 15; k ++ )
                    fa[son][k] = fa[fa[son][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 15; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if (a == b) return a;
    for (int k = 15; k >= 0; k -- )
        if (fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

int main()
{
    scanf("%d", &n);
    int root = 0;

    for (int i = 0; i < n; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b == -1) root = a;  // a is root
        else add(a, b), add(b, a);
    }

    bfs(root);

    scanf("%d", &m);
    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int p = lca(a, b);
        if (p == a) puts("1");
        else if (p == b) puts("2");
        else puts("0");
    }

    return 0;
}