#include<iostream>
#include<vector>
using namespace std;

vector<int> solution4(vector<int> num_list) {
	if (num_list[num_list.size() - 1] > num_list[num_list.size() - 2]) {
		num_list.push_back(num_list[num_list.size() - 1] - num_list[num_list.size() - 2]);
	}
	else {
		num_list.push_back(2 * num_list[num_list.size() - 1]);
	}

	return num_list;
}

int main() {
	//for (auto& p : vector<int>())
	//	cout << p << " "; 
	//cout << endl;
	
	for (auto& p : solution4({ 2, 1, 6 })) cout << p << " "; cout << endl; // 2 1 6 5
	for (auto& p : solution4({ 5, 2, 1, 7, 5 })) cout << p << " "; cout << endl; // 5 2 1 7 5 10
}
