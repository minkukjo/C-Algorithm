#include <iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int N, M;
		int DP[31][31] = { 0, };

		cin >> N >> M;
		// N���� ����Ʈ�� M���� ����Ʈ�� �մ� ����� ��
		// ���⼭�� 1���� ����Ʈ�� M���� ����Ʈ�� �մ� ����� ���� �̸� ã�Ƴ���
		for (int i = 1; i <= M; i++)
		{
			DP[1][i] = i;
		}

		for (int i = 2; i <= N; i++)
		{
			for (int j = i; j <= M; j++)
			{
				for (int k = j; k >= i; k--)
				{
					DP[i][j] += DP[i - 1][k - 1];
				}
			}
		}

		cout << DP[N][M] << endl;

	}
	return 0;
}