#include <iostream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;

int count[200001][26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(count, 0, sizeof(count));
    int N = 0;
    while(true) {
        string word;
        cin >> word;
        
        if(word.size() == 1) break;

        for(int i = 0; i < word.size(); ++i) {
            ++count[N][word[i] - 'A'];
        }
        ++N;
    }

    string answer = "";
    int table_count[26] = {0};
    int check[26] = {0};
    int tmp[26] = {0};
    while(true) {
        string table;
        cin >> table;

        if(table.size() == 1) break;
        
        memset(table_count, 0, sizeof(table_count));
        memset(check, 0, sizeof(check));
        for(int i = 0; i < table.size(); ++i) {
            ++table_count[table[i] - 'A'];
        }

        for(int n = 0; n < N; ++n) {
            bool flag = true;
            memset(tmp, 0, sizeof(tmp));
            for(int i = 0; i < 26; ++i) {
                if(table_count[i] < count[n][i]) {
                    flag = false;
                    break;
                }
                else if(count[n][i] > 0) {
                    ++tmp[i];
                }
            }

            if(flag) {
                for(int i = 0; i < 26; ++i) {
                    if(tmp[i] > 0) ++check[i];
                }
            }
        }

        string maximum = "", minimum = "";
        int max_count = 0, min_count = 987654321;
        for(int i = 0; i < 26; ++i) {
            if(table_count[i] > 0) {
                if(max_count < check[i]) {
                    maximum = 'A' + i;
                    max_count = check[i];
                } else if(max_count == check[i]) {
                    maximum += 'A' + i;
                }

                if(min_count > check[i]) {
                    minimum = 'A' + i;
                    min_count = check[i];
                } else if(min_count == check[i]) {
                    minimum += 'A' + i;
                }
            }
        }
        answer += minimum + " " + to_string(min_count) + " " + maximum + " " + to_string(max_count) + "\n";
        
    }

    cout << answer;
}