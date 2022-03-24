#include <cstdio>
const int mod = 1e9 + 7;
const int MAX = 1e6 + 10;
int f[MAX][2][2];
int main() {
	int n;
	scanf("%d", &n);
	f[1][0][0] = f[1][1][0] = 1;
	for (int i = 2; i <= n; i++) {
		f[i][0][0] = (f[i - 1][1][0] + f[i - 1][1][1]) % mod;
		f[i][0][1] = f[i - 1][0][0];
		f[i][1][0] = (f[i - 1][0][0] + f[i - 1][0][1]) % mod;
		f[i][1][1] = f[i - 1][1][0];
	}
	int Ans = f[n][0][0];
	Ans = (Ans + f[n][0][1]) % mod;
	Ans = (Ans + f[n][1][0]) % mod;
	Ans = (Ans + f[n][1][1]) % mod;
	printf("%d\n", Ans);
	return 0;
}