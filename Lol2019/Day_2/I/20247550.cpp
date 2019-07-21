#include <bits/stdc++.h>

using namespace std;

int br(char ch)//1 - op -1 - cl
{
	switch(ch)
	{
		case '[':
			return 1;
			break;
		case ']':
			return -1;
			break;

		case '(':
			return 2;
			break;
		case ')':
			return -2;
			break;

		case '{':
			return 3;
			break;
		case '}':
			return -3;
			break;
	}
}

int main()
{
	string s;
	cin >> s;
	stack<int> st;
	for(int i = 0; i < s.length(); i++)
	{
		int num = br(s[i]);
		if(num > 0)//open bracket
		{
			st.push(num);
		}
		else //close bracket
		{
			if(st.empty() || st.top() != -num)
			{
				cout << "no";
				exit(0);
			}
			else
			{
				st.pop();
			}
		}
	}
	cout << (st.empty() ? "yes" : "no");
}
