// O(nlogn)
int fact[N], infact[N];
int qpow(int a, int k, int p);

for(int i = 1;i < N;i++){
    fact[i] = fact[i - 1] * i % mod;
    infact[i] = qpow(fact[i], mod - 2, mod);
}

cout << fact[a] * infact[a - b] % mod * infact[b] % mod;

// lucas
ll qpow(ll a, ll k);

ll C(ll a, ll b){
    ll res = 1;
    for(int i = 1, j = a;i <= b;i++, j--){
        res = res * j % p;
        res = res * qpow(i, p - 2) % p;
    }
    return res;
}

ll lucas(ll a, ll b){
    if(a < p && b < p) return C(a, b);
    return C(a % p, b % p) * lucas(a / p, b / p) % p;
}

cout << lucas(a, b);

// very big C
void get_primes(int n){
    for(int i = 2;i <= n;i++){
        if(!ch[i]) prime.push_back(i);
        for(int j = 0; prime[j] <= n / i;j++){
            ch[prime[j] * i] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int get(int a, int p){
    int res = 0;
    while(a){
        res += a / p;
        a /= p;
    }
    return res;
}

vector<int> mul(vector<int> a, int b){
    vector<int> c;
    int t = 0;
    for(int i = 0;i < a.size();i++){
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    
    while(t){
        c.push_back(t % 10);
        t /= 10;
    }
    
    return c;
}

get_primes(a);
    
for(int i = 0;i < prime.size();i++) sum[i] = get(a, prime[i]) - get(a - b, prime[i]) - get(b, prime[i]);

vector<int> ans;
ans.push_back(1);
for(int i = 0; i < prime.size();i++){
    for(int j = 0;j < sum[i];j++){
        ans = mul(ans, prime[i]);
    }
}
    
for(int i = ans.size() - 1;i >= 0;i--) cout << ans[i];