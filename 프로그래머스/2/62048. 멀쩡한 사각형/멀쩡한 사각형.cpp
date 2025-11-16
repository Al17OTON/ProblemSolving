using namespace std;

int euclidean(int a, int b) {
    if(a % b == 0) return b;
    return euclidean(b, a % b);
}

long long solution(int w,int h) {
    long long W = (long long)w;
    long long H = (long long)h;
    long long euc = (long long)euclidean(w, h);
    return (W * H) - (W + H - euc);
}