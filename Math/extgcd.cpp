int extgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int t = extgcd(b, a % b, y, x);
    y = y - a / b * x;
    return t;
}