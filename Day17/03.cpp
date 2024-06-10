#include<iostream>
#include<vector>
#include<string>
using namespace std;

int solution3(vector<int> num_list) {
	string odd, even;
	for (int& num : num_list) {
		if (num % 2 == 0)odd += to_string(num);
		else even += to_string(num);
	}
	return stoi(odd) + stoi(even);
}

int main() {
	cout << solution3({ 3, 4, 5, 2, 1 }) << endl;	//351+42=393
	cout << solution3({ 5, 7, 8, 3 }) << endl;	//573+8=581
}