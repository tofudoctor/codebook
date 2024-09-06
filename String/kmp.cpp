// |a| < |b| (1 base)

int f[N];
// find f[]
for(int i = 2, j = 0;i <= a.size();i++){
    while(j && a[i] != a[j + 1]) j = f[j];
    if(a[i] == a[j + 1]) j++;
    f[i] = j;
}
// find a in b 
for(int i = 1, j = 0;i <= b.size();i++){
    while(j && a[j + 1] != b[i]) j = f[j];
    if(a[j + 1] == b[i]) j++;
    if(j == a.size()){
        j = f[j];
        // print
    }
}