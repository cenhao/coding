/*
ID: cenhao11
PROG: frac1
LANG: C++11
*/

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

#define MAXN 181
int numerator[MAXN];

class Cmp {
	public:
		bool operator () (int a, int b) {
			int n1 = b * numerator[a];
			int n2 = a * numerator[b];
			return n1 >= n2;
		}
};

int gcd(int a, int b) {
	int c;
	if (b > a) {
		c = a; a = b; b = c;
	}

	while (b != 0) {
		c = a % b;
		a = b; b = c;
	}

	return a;
}

int main() {
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);

	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, Cmp> pq;
	numerator[1] = 0;
	pq.push(1);
	for (int i=2; i<=n; ++i) {
		numerator[i] = 1;
		pq.push(i);
	}

	while (!pq.empty()) {
		int denominator = pq.top();
		pq.pop();
		printf("%d/%d\n", numerator[denominator], denominator);
		int i;
		for (i=numerator[denominator]+1; i<=denominator; ++i) {
			if (gcd(i, denominator) == 1) {
				numerator[denominator] = i;
				pq.push(denominator);
				break;
			}
		}
	}

	return 0;
}

/*****
A very nice implementation
We notice that we can start with 0/1 and 1/1 as our ``endpoints'' and recursively generate the middle points by adding numerators and denominators.
0/1                                                              1/1
                               1/2
				 1/3                      2/3
		 1/4              2/5         3/5                 3/4
	 1/5      2/7     3/8    3/7   4/7   5/8       5/7         4/5

nclude <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int n;
FILE *fout;

//print the fractions of denominator <= n between n1/d1 and n2/d2 
void
genfrac(int n1, int d1, int n2, int d2)
{
	if(d1+d2 > n)	// cut off recursion
	return;

	genfrac(n1,d1, n1+n2,d1+d2);
	fprintf(fout, "%d/%d\n", n1+n2, d1+d2);
	genfrac(n1+n2,d1+d2, n2,d2);
}

void main(void)
{
	FILE *fin;

	fin = fopen("frac1.in", "r");
	fout = fopen("frac1.out", "w");
	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d", &n);

	fprintf(fout, "0/1\n");
	genfrac(0,1, 1,1);
	fprintf(fout, "1/1\n");
}
*/
