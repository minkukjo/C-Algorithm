#include <iostream>
#include <set>
#include <string>
using namespace std;

// dfs ����Ž������ Ǯ����� �ϰ���

int map[10];
set<int> s;

void dfs(bool check[], int count, int n, int r, string temp)
{
	if (count == r)
	{
		int sum = atoi(temp.c_str());
		s.insert(sum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			temp.append(to_string(map[i]));
			check[i] = true;
			dfs(check, count + 1, n, r,temp);
			check[i] = false;
			if (map[i] > 9)
			{
				temp.pop_back();
				temp.pop_back();
			}
			else
			{
				temp.pop_back();
			}
			
		}
	}
}

int main()
{
	int n, r;
	bool check[11] = { false, };
	string temp;
	cin >> n;
	cin >> r;

	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
	}




	dfs(check, 0, n, r,temp);

	cout << s.size() << endl;

	return 0;
}