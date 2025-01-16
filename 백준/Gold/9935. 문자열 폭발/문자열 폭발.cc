#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, bomb, tmp = "";

	bool flag = true;

	cin >> s >> bomb;

	for (int i = 0; i < s.length(); i++)								//문자열을 앞에서 부터 하나씩 임시 변수에 넣는다.
	{
		tmp += s[i];
		if (tmp.length() >= bomb.length())								//임시변수가 폭탄문자보다 길어지면 폭탄 검사를 실시한다.
		{
			flag = true;
			for (int j = 0; j < bomb.length(); j++)						//폭탄문자 길이만큼 뒤에서 부터 검사하여 폭탄문자가 있다면 제거한다.
			{
				if (tmp[tmp.length() - bomb.length() + j] != bomb[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				tmp.erase(tmp.length() - bomb.length(), bomb.length());	//폭탄 제거
			}
		}
	}
	if (tmp.empty())
	{
		cout << "FRULA" << '\n';
	}
	else
	{
		cout << tmp << '\n';
	}
}