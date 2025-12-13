#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int num_c;
    int num_h = (num - 1) / w;
    if(((num - 1) / w) % 2 == 0) {
        num_c = (num - 1) % w;
    } else {
        num_c = w - ((num - 1) % w) - 1;
    }
    int n_c;
    int height = (n - 1) / w;
    if(height % 2 == 0) {
        n_c = (n - 1) % w;
    } else {
        n_c = w - ((n - 1) % w) - 1;
    }

    if(height % 2 == 0) {
        if(n_c < num_c) {
            return height - num_h;
        } else {
            return height - num_h + 1;
        }
    } else {
        if(n_c > num_c) {
            return height - num_h;
        } else {
            return height - num_h + 1;
        }
    }
}