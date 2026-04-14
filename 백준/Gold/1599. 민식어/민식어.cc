#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

struct Word {
    string original;
    string change;
};

unordered_map<char, char> hash_map = {
    {'a', 'a'},
    {'b', 'b'},
    {'k', 'c'},
    {'d', 'd'},
    {'e', 'e'},
    {'g', 'f'},
    {'h', 'g'},
    {'i', 'h'},
    {'l', 'i'},
    {'m', 'j'},
    {'n', 'k'},
    {'z', 'l'}, //ng
    {'o', 'm'},
    {'p', 'n'},
    {'r', 'o'},
    {'s', 'p'},
    {'t', 'q'},
    {'u', 'r'},
    {'w', 's'},
    {'y', 't'}
};

bool cmp(const Word& a, const Word& b) {
    return a.change < b.change;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    
    cin >> N;

    vector<Word> words;
    for(int n = 0; n < N; ++n) {
        string word, change = "";
        cin >> word;
        
        for(int i = 0; i < word.size(); ++i) {
            if(i + 1 < word.size() && word[i] == 'n' && word[i + 1] == 'g') {
                change += hash_map['z'];
                ++i;
            } else {
                change += hash_map[word[i]];
            }
        }
        
        words.push_back({word, change});
    }

    sort(words.begin(), words.end(), cmp);
    
    for(int n = 0; n < N; ++n) {
        cout << words[n].original << "\n";
    }
}