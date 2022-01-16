#include<iostream>
using namespace std;
#define inf 0x3f3f3f3f 

void Prim(int c[][10], int n) {
	int lowcost[10];
	int closest[10];
	bool s[10];
	s[1] = true;
	for (int i = 2; i <= n; i++) {
		lowcost[i] = c[1][i];
		closest[i] = 1;
		s[i] = false;
	}
	for (int i = 1; i < n; i++) {
		int min = inf;
		int j = 1;
		for (int k = 2; k <= n; k++) {
			if ((lowcost[k] < min) && (!s[k])) {
				min = lowcost[k];
				j = k;
			}
		}
		cout << j << "---" << closest[j] << endl;    //这里输出最小生成树
		s[j] = true;
		for (int k = 2; k <= n; k++) {
			if ((c[j][k] < lowcost[k]) && (!s[k])) {
				lowcost[k] = c[j][k];
				closest[k] = j;
			}
		}
	}
}


int main() {
	int a, b, w, n;
	int c[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			c[i][j] = inf;
		}
	}
	cout << "请输入带权连通图顶点数（不大于10）：";
	cin >> n;
	cout << "请输入所有对顶点及其权值" << endl;
	for (int i = 1; i <= 10; i++) {
		cin >> a >> b >> w;
		c[a][b] = w;
		c[b][a] = w;
	}
	Prim(c, n);
	return 0;
}
