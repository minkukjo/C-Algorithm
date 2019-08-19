#include <iostream>

using namespace std;

int map[1001][1001];
int d[1001][1001];

int main()
{
	int H, W,N;
	cin >> H >> W >> N;


	
	// 0�� ��, 1�� ��
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			cin >> map[i][j];
		}
	}

	d[1][1] = N-1;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (d[i][j] >= 1)
			{
				d[i + 1][j] += d[i][j] / 2;
				d[i][j + 1] += d[i][j] / 2;
				if (d[i][j] % 2 == 1) // �ش� ��ġ�� Ȧ���� ����� �湮�����Ƿ� ���� ���������
				{
					if (map[i][j] == 1) // ���������� �����Ѵٸ�?
					{
						d[i][j + 1]++;
					}
					else // �Ʒ������� �����Ѵٸ�?
					{
						d[i + 1][j]++;
					}
				}
			}
		}
	}

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			d[i][j] = (map[i][j] + d[i][j] % 2) % 2;
		}
	}
	int i = 1;
	int j = 1;
	while (i <= H && j <= W)
	{
		if (d[i][j] == 1)j++;
		else i++;
	}

	cout << i << " " << j << endl;
	

	return 0;
}