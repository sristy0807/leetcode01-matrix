#define MAX 10000

#include <iostream>

using namespace std;

int grid[MAX][MAX];
int dist[MAX][MAX];

int m;
int n;

int dirX[4] = { -1,0,0,1 };
int dirY[4] = { 0,-1,1,0 };

int qX[MAX];
int qY[MAX];

void matrixOperation() {
	int head = 0;
	int tail = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0) {
				dist[i][j] = 0;
				qX[head] = i;
				qY[head] = j;
				head++;
				continue;
			}

			dist[i][j] = -1;
			continue;
		}
	}

	while (tail < head) {
		int r = qX[tail];
		int c = qY[tail];
		
		tail++;

		for (int i = 0; i < 4; i++)
		{
			int nR = r + dirX[i];
			int nC = c + dirY[i];

			if (nR >= m || nC >= n) continue;
			if (dist[nR][nC] != -1) continue;

			dist[nR][nC] = dist[r][c] + 1;

			qX[head] = nR;
			qY[head] = nC;
			head++;
		}
	}

}

int main() {
	cin >> m;
	cin >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}

	}

	matrixOperation();
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dist[i][j] <<" ";
		}
		cout << endl;

	}
	
}