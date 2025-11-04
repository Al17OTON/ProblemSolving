#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Node {
    int num;
    int s, e;
    int need;
    vector<int> vec;
    
    Node(int num) {
        s = 0;
        e = num - 1;
        need = num;
        this->num = num;
        for(int i = 0; i < num; ++i) this->vec.push_back(0);
    }
    
    bool full() {
        return need == 0;
    }
    
    void insert_back(int num) {
        --need;
        vec[e--] = num;
    }
    void insert_front(int num) {
        --need;
        vec[s++] = num;
    }
};

vector<int> solution(int n) {
    vector<int> answer;
    vector<Node> a;
    
    for(int i = 1; i <= n; ++i) {
        Node node(i);
        a.push_back(node);
    }
    
    int s = 0, e = n - 1;
    int idx = 0;
    int num = 1;
    bool flag = true;
    while(s <= e) {
        
        if(flag && !a[idx].full()) a[idx].insert_front(num++);
        else if(!a[idx].full()) a[idx].insert_back(num++);
        
        if(idx == e && flag) {
            while(!a[idx].full()) a[idx].insert_front(num++);
        }
        
        if(idx == e && flag) {
            flag = false;
            --e;
        } else if(idx == s && !flag) {
            flag = true;
            ++s;
        }
        
        if(flag) ++idx;
        else --idx;
    }
    
    idx = 0;
    for(int i = 0; i < a.size(); ++i) {
        for(int j = 0; j < a[i].num; ++j) answer.push_back(a[i].vec[j]);
    }
    
    return answer;
}

/*

1 2 [9] 3 [10] [8] 4 5 6 7

1 


1 2 [12] 3 [13] [11] 4 [14] [15] [10] 5 6 7 8 9

1 2 [15] 3 [16] [14] 4 [17] [21] [13] 5 [18] [20] [19] [12] 6 7 8 9 10 11

1 2 [15] 3 [16] [14] 4 [17] [] [13] 5 [18] [19] [20] [12] 6 [7] [8] [9] [10] [11]

*/