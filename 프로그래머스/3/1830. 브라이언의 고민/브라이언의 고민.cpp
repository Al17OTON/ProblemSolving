#include <string>
#include <vector>

using namespace std;

bool check(char c) {
    return c >= 'A' && c <= 'Z';
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(string sentence) {
    string answer = "";

    bool invalid = false;
    int N = sentence.size();
    int count[26] = { 0 };
    bool v[26] = { false };

    for (int i = 0; i < N; ++i) {
        if (!check(sentence[i])) ++count[sentence[i] - 'a'];
    }

    vector<string> vec1;
    vec1.push_back("");
    for (int i = 0; i < N && !invalid; ++i) {
        char a = sentence[i];

        // 규칙 2
        if (!check(a) && count[a - 'a'] == 2) {
            int j;
            for (j = i + 1; j < N && a != sentence[j]; ++j);
            if (j - i < 2) invalid = true;
            vec1.push_back(sentence.substr(i + 1, j - (i + 1)));
            vec1.push_back("");
            v[a - 'a'] = true;
            i = j;
        }
        // 규칙 1
        else if (!check(a)) {
            if (vec1.back().empty() || v[a - 'a']) {
                invalid = true;
                break;
            }
            else {
                char pre = vec1.back().back();
                vec1.back().pop_back();
                v[a - 'a'] = true;

                if (!vec1.back().empty()) vec1.push_back("");
                vec1.back().push_back(pre);

                int end = (i - 1) + (count[a - 'a'] * 2 + 1);
                if (end > N) {
                    invalid = true;
                    break;
                }
                for (int idx = i; idx < end && !invalid; ++idx) {
                    char b = sentence[idx];
                    if ((idx - (i - 1)) % 2 == 0) {
                        if (!check(b)) {
                            invalid = true;
                        }
                        vec1.back().push_back(b);
                    }
                    else {
                        if (check(b) || a != b) {
                            invalid = true;
                        }
                    }
                }
                i = end - 1;
                vec1.push_back("");
            }
        }
        else {
            vec1[vec1.size() - 1] += a;
        }
    }

    for (int i = 0; i < vec1.size() && !invalid; ++i) {
        string& str = vec1[i];
        if (str.empty()) continue;
        bool flag = false;
        for (int j = 0; j < str.size() && !flag; ++j) {
            if (!check(str[j])) flag = true;
        }

        if (flag) {
            if (str.size() % 2 == 0 || str.size() == 1 || (count[str[1] - 'a'] * 2 + 1) != str.size()) invalid = true;
            for (int j = 0; j < str.size() && !invalid; ++j) {
                char b = str[j];
                if (j % 2 == 0) {
                    if (!check(b)) invalid = true;
                    else answer += b;
                }
                else {
                    if (str[1] != b) invalid = true;
                }
            }
        }
        else {
            answer += str;
        }

        if (i != vec1.size() - 1) answer += " ";
    }

    if (!answer.empty() && answer.back() == ' ') answer.pop_back();
    if (invalid) answer = "invalid";

    return answer;
}