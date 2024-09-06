int kth_element(int l, int r, int k){  // (l, r]
    if(r - l < 2) return a[l];
    int x = a[l + r >> 1], i = l - 1, j = r;
    while(i < j){
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) swap(a[i], a[j]);
    }
    int sl = i - l;
    if(k <= sl) return kth_element(l, i, k);
    return kth_element(i, r, k - sl);
}