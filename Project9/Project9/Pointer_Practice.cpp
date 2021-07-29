#include<iostream>

using namespace std;

void change(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i]++;
	}
}

int* sum(int* result, int a, int b) {
	*result = a + b;

	return result;
}
int main() {
	int Array[] = { 0, 1, 2 };

	change(Array, 3);

	for (int i = 0; i < 3; i++) {
		cout << Array[i]<<endl;
	}

	int A = 1, B = 2;
	int result = 0;
		cout << *sum(&result, A, B) << endl;
	

	return 0;
}