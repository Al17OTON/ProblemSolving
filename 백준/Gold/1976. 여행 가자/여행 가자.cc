#include <iostream>
#define MAX 200

using namespace std;

int N, M, uni[MAX + 1];

int find(int x)
{
	if (uni[x] == x) return x;
	return uni[x] = find(uni[x]);
}

void setuni(int x, int y)
{
	x = find(x); y = find(y);

	uni[x] = y;
}

bool isuni(int x, int y)
{
	x = find(x); y = find(y);

	if (x == y) return true;
	return false;
}

int main()
{
	int i, j, a, startsetnum;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (i = 0; i <= N ; i++) uni[i] = i;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cin >> a;
			if (a == 1)
			{
				setuni(j + 1, i + 1);
			}
		}
	}

	cin >> a;
	
	startsetnum = find(a);

	for (i = 1; i < M; i++)
	{
		cin >> a;
		if (startsetnum != find(a))
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}