#include <iostream>
#include <time.h>
using namespace std;


void Print(int* b, const int k, int i) {
	if (i > k) {
		cout << endl;
		return;
	}
	else {
		cout << b[i] << " ";
		Print(b, k, i + 1);
	}
}
int proces(int *b, const int k, int i, int n, int &sum, int &count) {
	
	i = -15 + rand() * 90 / RAND_MAX;
	if (n >= k) {
		return 0;
	}
	if ((b[n] < 0) && (b[n] % 2 == 0)) {
		sum += b[n];
		count++;
		b[n] = 0;
	}
		
	return proces(b, k, i, n + 1, sum, count);
}
void imputE(int*& b, int k, int i) {
	
	if (i > k)
		return;
	else {
		b[i] = -15 + rand() * 90 / RAND_MAX;
		imputE(b, k, i + 1);
	}
}
int main() {
	const int k = 24;
	int sum = 0, count = 0, n = 0, i = 1;
	int* b = new int [k];
	srand((unsigned)time(NULL));
	imputE(b, k, 0);
	Print(b, k, 0);
	proces(b, k, i, n, sum, count);
	Print(b, k, 0);
	cout << endl;
	cout << "sum " << sum << endl;
	cout << "count " << count << endl;
	delete b;
	return 0;
}