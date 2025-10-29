#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 조건으로 트리를 구성하고 마지막 성적은 정렬해놓기 그리고 이분탐색으로 점수갯수 구하기
// 개발언어 - 직군 - 경력 - 소울푸드 - 성적

void sort_tree(vector<vector<vector<vector<vector<int>>>>>& tree) {
    for(int a = 0; a < 3; ++a) {
        for(int b = 0; b < 2; ++b) {
            for(int c = 0; c < 2; ++c) {
                for(int d = 0; d < 2; ++d) {
                    sort(tree[a][b][c][d].begin(), tree[a][b][c][d].end());
                }
            }
        }
    }
}

int binary_search(int target, const vector<int>& vec) {
    int l = 0, r = vec.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(vec[mid] >= target) {
            r = mid - 1;
        } else if(vec[mid] < target) {
            l = mid + 1;
        } 
    }
    
    return vec.size() - l;
}

int get_index(char a, int no) {
    // if(a.compare("cpp") || a.compare("backend") || a.compare("junior") ||a.compare("chicken")) {
    //     return 0;
    // } else if(a.compare("java") || a.compare("frontend") || a.compare("senior") || a.compare("pizza")) {
    //     return 1;
    // } else if(a.compare("python")) {
    //     return 2;
    // } else {
    //     return 3; // '-' 일때
    // }
    
    if(a == '-') return 3; // '-' 일 때
    
    if(no == 0) {
        if(a == 'c') return 0;
        else if(a == 'j') return 1;
        else return 2;
    } else if(no == 1) {
        if(a == 'b') return 0;
        else return 1;
    } else if(no == 2) {
        if(a == 'j') return 0;
        else return 1;
    } else {
        if(a == 'c') return 0;
        else return 1;
    }
}

void insert_info(string info, vector<vector<vector<vector<vector<int>>>>>& tree) {
    vector<int> index;
    int no = 0;
    bool flag = true;
    int i;
    for(i = 0; i < info.size(); ++i) {
        if(info[i] == ' ') {
            flag = true;
            ++no;
            if(no == 4) break;
        } else if(flag) {
            flag = false;
            index.push_back(get_index(info[i], no));
        }
    }
    
    int place = 1;
    int score = 0;
    for(int j = info.size() - 1; j > i; --j) {
        score += (info[j] - '0') * place;
        place *= 10;
    }
    
    tree[index[0]][index[1]][index[2]][index[3]].push_back(score);
}

int run_query(string q, vector<vector<vector<vector<vector<int>>>>>& tree) {
    vector<int> index;
    int no = 0;
    bool flag = true;
    int i;
    for(i = 0; i < q.size(); ++i) {
        if(q[i] == ' ') {
            flag = true;
            ++no;
            if(no == 7) break;
        } else if(flag && no % 2 == 0) {
            flag = false;
            index.push_back(get_index(q[i], no / 2));
        } else flag = false;
    }
    
    int place = 1;
    int score = 0;
    for(int j = q.size() - 1; j > i; --j) {
        score += (q[j] - '0') * place;
        place *= 10;
    }
    
    int sum = 0;
    // cout << index[0] << " " << index[1] << " " << index[2] << " " << index[3] << "\n";
    for(int a = index[0] == 3 ? 0 : index[0]; a <= (index[0] == 3 ? 2 : index[0]); ++a) {
        for(int b = index[1] == 3 ? 0 : index[1]; b <= (index[1] == 3 ? 1 : index[1]); ++b) {
            for(int c = index[2] == 3 ? 0 : index[2]; c <= (index[2] == 3 ? 1 : index[2]); ++c) {
                for(int d = index[3] == 3 ? 0 : index[3]; d <= (index[3] == 3 ? 1 : index[3]); ++d) {
                    sum += binary_search(score, tree[a][b][c][d]);
                }
            }
        }
    }
    
    return sum;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<vector<vector<vector<vector<int>>>>> tree;
    
    for(int a = 0; a < 3; ++a) {
        vector<vector<vector<vector<int>>>> av;
        tree.push_back(av);
        for(int b = 0; b < 2; ++b) {
            vector<vector<vector<int>>> bv;
            tree[a].push_back(bv);
            for(int c = 0; c < 2; ++c) {
                vector<vector<int>> cv;
                tree[a][b].push_back(cv);
                for(int d = 0; d < 2; ++d) {
                    vector<int> dv;
                    tree[a][b][c].push_back(dv);
                }
            }
        }
    }
    
    for(int i = 0; i < info.size(); ++i) insert_info(info[i], tree);
    sort_tree(tree);
    
    for(int i = 0; i < query.size(); ++i) answer.push_back(run_query(query[i], tree));
    
    return answer;
}