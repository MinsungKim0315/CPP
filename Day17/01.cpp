#include<iostream>
#include<vector>
using namespace std;

int solution1(int a, int d, vector<bool> included) {
	int sum = 0;
	/*for (int i = 0; i < included.size(); i++) {
		if (included[i] == true) sum += a;
		a += d;
	}*/
	for (auto i : included) {
		if (i)sum += a;
		a += d;
	}
	return sum;
}

int main() {
	cout <<  solution1(3, 4, {true, false, false, true, true}) << endl;	//37
	cout <<  solution1(7, 1, { false, false, false, true, false, false, false }) << endl;	//10
}
