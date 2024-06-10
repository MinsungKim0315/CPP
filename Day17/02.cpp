#include<iostream>
#include<vector>
using namespace std;

int solution2(vector<int> num_list) {
	int sum1 = 0, sum2 = 1;
	for (int i = 0; i < num_list.size(); i++) {
		sum1 += num_list[i];
		sum2 *= num_list[i];
	}
	sum1 *= sum1;
	if (sum2 >= sum1) return 0;
	
	return 1;
}

int main() {
	cout << solution2({ 3, 4, 5, 2, 1 }) << endl;	//1
	cout << solution2({ 5, 7, 8, 3 }) << endl;	//0
}