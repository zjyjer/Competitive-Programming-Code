#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MAXN 100005

int n;
long long A[2][MAXN];

int main() {
	int cas;
	scanf("%d", &cas);
	while (cas --) {
		scanf("%d", &n);
		memset(A, 0, sizeof(A));
		for (int i = 1; i <= n; ++ i) scanf("%I64d", &A[0][i]);
		int s = 0, start = 1, end = n;
		int finish = 1;
		for (int i = 1; i < n; ++ i, s = s ^ 1) {
			while (start < end && A[s][start] == 0) 
				start ++;
			start = std::max(start - 1, 1);
			while (end > start && A[s][end] == 0) 
				end --;
			end = std::min(n - i + 1, end + 1);
			if (start >= end) break;

			int inc = 1, dec = 1;
			for (int j = start; j < end; ++ j) {
				if (A[s][j + 1] < A[s][j]) inc = 0;
				else if (A[s][j + 1] > A[s][j]) dec = 0;
			}
			finish = inc | dec;

			if (!finish) {
				if (i == 1)
					printf("ugly series\n");
				else
					printf("%d\n", i - 2);
				break;
			}

			for (int j = start; j < end; ++ j)
				A[s ^ 1][j] = A[s][j + 1] - A[s][j];
			end -= 1;
		}
		if (finish)
			printf("nice series\n");
	}
	return 0;
}
