#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string num;

bool cmp(const string& a, const string& b) {
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

void increase(string& a) {
    for(int i = a.size() - 1; i >= 0; --i) {
        if(a[i] == '9') {
            a[i] = '0';
        }
        else {
            a[i] += 1;
            break;
        }
    }
    if(a[0] == '0') a = '1' + a;
}

string get_reverse(string& a) {
    string tmp = a;
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int main() {
    cin >> num;
    
    string left = num.substr(0, num.size() / 2);
    string right = num.substr(num.size() / 2 + (num.size() % 2));

    if(num.size() == 1) {
        if(num[0] != '9') cout << (char)(num[0] + 1);
        else cout << "11";
    }
    else if(num.size() % 2 == 0) {
        string tmp = get_reverse(left);
        if(cmp(right, tmp)) {
            cout << left + tmp;
        } else {
            tmp = left;
            increase(tmp);
            if(tmp.size() == left.size()) cout << tmp + get_reverse(tmp);
            else {
                cout << tmp;
                tmp.pop_back();
                cout << get_reverse(tmp);
            }
        }
    } else {
        string tmp = get_reverse(left);
        if(cmp(right, tmp)) {
            cout << left + num[num.size() / 2] + tmp;
        } else {
            tmp = left + num[num.size() / 2];
            increase(tmp);
            if(tmp.size() > left.size() + 1) {
                tmp.pop_back();
                cout << tmp + get_reverse(tmp);
            } else {
                cout << tmp;
                tmp.pop_back();
                cout << get_reverse(tmp);
            }
        }
    }
}