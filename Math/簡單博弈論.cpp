// 先手必敗:a_1 ^ a_2 ^...^ a_k = 0
// 先手必勝:a_1 ^ a_2 ^...^ a_k != 0

const int n, m // n = 石頭堆數   m = s[n]數量
int s[n], f[m]; // s[n] = 可一次拿走的石頭數   f[m] = 記憶化搜索sg

memset(f, -1, sizeof f);
int sg(int x){
    if(f[x] != -1) return f[x];
    
    unorded_set<int> S;
    for(int i = 0;i < m;i++){
        if(x > s[i]) S.insert(sg[x - s[i]]);
    }
    
    // mex 找出集合中沒出現最小的正整數
    for(int i = 0;;i++)
        if(!S.count(i))
            return f[x] = i;
}