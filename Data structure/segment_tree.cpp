// 查區間最大值
// 單點修改
struct Node{
    int l, r; // 左右端點
    int v; // [l. r]的最大值
}tr[N * 4];

void pushup(int u){
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r){
    tr[u] = {l, r}; // 存區間
    if(l == r) return; // 如果到葉節點=>停止
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r); // 遞迴建立左右子節點
}

void modify(int u, int x, int v){ // 把節點x改成v
    if(tr[u].l == x && tr[u].r == x) tr[u].v == v; // 找到子節點
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v); // 在左邊
        else modify(u << 1 | 1, x, v); // 在右邊
        pushup(u);
    }
}

int query(int u, int l, int r){ // u通常是根節點，l和r是要查詢的區間
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].v; // 樹中節點完全被[l, r]包含
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if(l <= mid) v = query(u << 1, l, r); // 在左邊
    if(r > mid) v = max(v, query(u << 1 | 1, l, r)); // 在右邊
    
    return v;
}

// 查最大連續子段和
// 單點修改

struct Node{
    int l, r;
    int sum, lmax, rmax, tmax; // 區間和/前綴最大和/後綴最大和/區間最大和
}tr[N * 4];

void pushup(Node &u, Node &l, Node &r){ // lr為子節點
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax, l.sum + r.lmax);
    u.rmax = max(r.rmax, r.sum + l.rmax);
    u.tmax = max({l.tmax, r.tmax, l.rmax + r.lmax});
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){ // u=當前節點, l=左子節點, r=右子節點
    if(l == r) tr[u] = {l, r, a[l], a[l], a[l], a[l]};
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int v) // 把第x個數改成v
{
    if (tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v, v, v, v};
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

Node query(int u, int l, int r) // 查詢[l, r]的資訊
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        else if (l > mid) return query(u << 1 | 1, l, r);
        else
        {
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

// 區間最大公因數
// w[l, r]都加上d
// 求 w[l, r]最大公因數
// 用線段樹維護差分數組
struct Node
{
    int l, r;
    LL sum, d; // 區間和/GCD
}tr[N * 4];

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

void pushup(Node &u, Node &l, Node &r)
{
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        LL b = w[r] - w[r - 1];
        tr[u] = {l, r, b, b};
    }
    else
    {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, LL v)
{
    if (tr[u].l == x && tr[u].r == x)
    {
        LL b = tr[u].sum + v;
        tr[u] = {x, x, b, b};
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

Node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        else if (l > mid) return query(u << 1 | 1, l, r);
        else
        {
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

void ask(int l, int r){ // 查[l, r]的gcd
    auto left = query(1, 1, l);
    Node right({0, 0, 0, 0});
    if (l + 1 <= r) right = query(1, l + 1, r);
    printf("%lld\n", abs(gcd(left.sum, right.d)));
}

void modify_diff(int l, int r, int d){ // [l, r] + d
    modify(1, l, d);
    if (r + 1 <= n) modify(1, r + 1, -d);
}

// w[l, r] + d
// 查詢w[l, r]之和
struct Node
{
    int l, r;
    LL sum, add; // 區間和 / 懶標
}tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add)
    {
        left.add += root.add, left.sum += (LL)(left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (LL)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, w[r], 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int d)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d;
        tr[u].add += d;
    }
    else    // 一定要分裂
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, d);
        if (r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

LL query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL sum = 0;
    if (l <= mid) sum = query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

// 掃描線+懶標線段樹
struct Segment
{
    double x, y1, y2;
    int k;
    bool operator< (const Segment &t)const
    {
        return x < t.x;
    }
}seg[N * 2];
struct Node
{
    int l, r;
    int cnt; // [l, r]被覆蓋幾次
    double len; // [l, r] 中 cnt > 0 的區間長度多長
}tr[N * 8];

vector<double> ys;

int find(double y)
{
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

void pushup(int u)
{
    if (tr[u].cnt) tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    else if (tr[u].l != tr[u].r)
    {
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    }
    else tr[u].len = 0;
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0};
    if (l != r)
    {
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u, int l, int r, int k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].cnt += k;
        pushup(u);
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

int solve(int n)
{
    ys.clear();
    for (int i = 0, j = 0; i < n; i ++ )
    {
        double x1, y1, x2, y2;
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        seg[j ++ ] = {x1, y1, y2, 1};
        seg[j ++ ] = {x2, y1, y2, -1};
        ys.push_back(y1), ys.push_back(y2);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    build(1, 0, ys.size() - 2);

    sort(seg, seg + n * 2);

    double res = 0;
    for (int i = 0; i < n * 2; i ++ )
    {
        if (i > 0) res += tr[1].len * (seg[i].x - seg[i - 1].x);
        modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
    }

    return res;
}

// w[l, r] * c
// w[l, r] + c
// 求 w[l, r] 區間和 % P的值
struct Node
{
    int l, r;
    int sum, add, mul; // 區間和 / 懶標(加乘)    
}tr[N * 4];

void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void eval(Node &t, int add, int mul)
{ // 對節點t修改
    t.sum = ((LL)t.sum * mul + (LL)(t.r - t.l + 1) * add) % p;
    t.mul = (LL)t.mul * mul % p;
    t.add = ((LL)t.add * mul + add) % p;
}

void pushdown(int u)
{
    eval(tr[u << 1], tr[u].add, tr[u].mul);
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1;
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, w[r], 0, 1};
    else
    {
        tr[u] = {l, r, 0, 0, 1};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int add, int mul)
{
    if (tr[u].l >= l && tr[u].r <= r) eval(tr[u], add, mul);
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, add, mul);
        if (r > mid) modify(u << 1 | 1, l, r, add, mul);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if (l <= mid) sum = query(u << 1, l, r);
    if (r > mid) sum = (sum + query(u << 1 | 1, l, r)) % p;
    return sum;
}

void modify_mul(int l, int r, int c){
    modify(1, l, r, 0, c);
}

void modify_add(int l, int r, int c){
    modify(1, l, r, c, 1);
}