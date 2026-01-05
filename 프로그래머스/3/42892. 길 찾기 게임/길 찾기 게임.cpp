#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x, y, no;
};

bool cmp(const Node& a, const Node& b) {
    return a.x < b.x;
}

void dfs(int l, int r, const vector<Node>& node, vector<vector<int>>& answer) {
    if (l > r) return;
    // l ~ r 사이에서 가장 큰 y 값 탐색
    Node max_node = { 0, -1, 0 };
    int max_idx = -1;
    for (int i = l; i <= r; ++i) {
        if (node[i].y > max_node.y) {
            max_node = node[i];
            max_idx = i;
        }
    }

    answer[0].push_back(max_node.no);
    dfs(l, max_idx - 1, node, answer);
    dfs(max_idx + 1, r, node, answer);
    answer[1].push_back(max_node.no);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    answer.push_back(vector<int>());
    answer.push_back(vector<int>());
    vector<Node> tmp;

    for (int i = 0; i < nodeinfo.size(); ++i) {
        tmp.push_back({ nodeinfo[i][0], nodeinfo[i][1], i + 1 });
    }
    sort(tmp.begin(), tmp.end(), cmp);

    dfs(0, tmp.size() - 1, tmp, answer);

    return answer;
}