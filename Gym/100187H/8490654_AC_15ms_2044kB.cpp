#include<cstdio>
#include <cmath>
#include<iostream>
#include <algorithm>
using namespace std;
struct node {
	double loca[3], locb[3], locc[3];
	double a, b, c;
} data[3];
double Cos[3][4];
double dist(double a[], double b[]) {
	return sqrt((a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]));
}
int main() {
	for (int i = 0; i < 2; i++) {
		scanf("%lf%lf", &data[i].loca[0], &data[i].loca[1]);
		scanf("%lf%lf", &data[i].locb[0], &data[i].locb[1]);
		scanf("%lf%lf", &data[i].locc[0], &data[i].locc[1]);
	}
	for (int i = 0; i < 2; i++) {
		data[i].a = dist(data[i].locb, data[i].locc);
		data[i].b = dist(data[i].loca, data[i].locc);
		data[i].c = dist(data[i].locb, data[i].loca);
	}
	for (int i = 0; i < 2; i++) {
		Cos[i][0] = (data[i].a*data[i].a + data[i].b*data[i].b - data[i].c*data[i].c)/(2*data[i].a*data[i].b);
		Cos[i][1] = (data[i].a*data[i].a + data[i].c*data[i].c - data[i].b*data[i].b)/(2*data[i].a*data[i].c);
		Cos[i][2] = (data[i].b*data[i].b + data[i].c*data[i].c - data[i].a*data[i].a)/(2*data[i].c*data[i].b);
	}
	sort(Cos[0], Cos[0] + 3);
	sort(Cos[1], Cos[1] + 3);
	bool flag = true;
	for (int i = 0; i < 3; i++) {
		if (abs(Cos[0][i]-Cos[1][i]) > 1e-9) {
			flag = false;
			break;
		}
	}
	if (flag) printf("YES\n");
	else printf("NO\n");
	return 0;	
}