#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 200000

using namespace std;

int N;
pair<int, int> arr[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

int greedy()
{
	int n = 0;
	pq.push(arr[n].second);
	while (n < N - 1)
	{
		n++;
		pq.push(arr[n].second);
		if (arr[n].first >= pq.top())
		{
			pq.pop();
		}
	}
	return pq.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int n = 0; n < N; n++)
	{
		cin >> arr[n].first >> arr[n].second;
	}

	sort(arr, arr + N);


	cout << greedy() << endl;
}