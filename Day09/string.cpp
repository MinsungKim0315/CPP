#include<iostream>
#include<string>
using namespace std;

string part1(string str1, string str2) {
	string answer;
	for (int i = 0; i < str1.size(); i++) {
		/*answer.push_back(str1[i]);
		answer.push_back(str2[i]);*/
		answer += str1[i];
		answer += str2[i];
	}
	return answer;
}
string part2(string str1, int n) {
	string answer;
	answer = str1.substr(str1.size() - n);
	
	return answer;
}
string part3(string str1, int n) {
	string answer;
	answer = str1.substr(0, n);

	return answer;
}
string part4(string str1, int s, int e) {
	string  temp;
	temp = str1.substr(s, e-s+1);
	for (int i = s; i <= e; i++) {
		str1[i] = temp.back();
		temp.pop_back();
	}
	return str1;
}
int part5(string str1, string str2) {
	for (int i = 0; i < str1.size(); i++) {
		str1[i] = tolower(str1[i]);
	}
	/*for (auto& i : str1)
		i = toupper(i);*/
	for (int i = 0; i < str2.size(); i++) {
		str2[i] = tolower(str2[i]);
	}
	if (str1.find(str2) != -1) {
		return 1;
	}
	return 0;
}
int part6(string t, string p) {
	int count = 0;
	for (int i = 0; i <= t.size() - p.size(); i++) {
		if (stoi(t.substr(i, p.size())) <= stoi(p)) count += 1;
	}
	return count;
}
int part7(string str1, string str2) {
	for (int i = 0; i < str1.size(); i++) {
		if ((str1.substr(i)) == str2) {
			return 1;
		}
	}
	return 0;
}
int part8(string str1, string str2){
	for (int i = 1; i < str1.size(); i++) {
		if ((str1.substr(0, i)) == str2) {
			return 1;
		}
	}
	return 0;
}
int main() {
	cout << part1("aaaaa", "bbbbb") << endl;
	cout << part2("abcdefg", 3) << endl;
	cout << part3("abcdefg", 3) << endl;
	cout << part4("Progra21Sremm3", 6, 12) << endl;
	cout << part5("AbCdEfG", "aBc") << endl;
	cout << part6("10203", "15") << endl;
	cout << part7("banana", "ana") << endl;
	cout << part7("banana", "nan") << endl;
	cout << part8("banana", "ban") << endl;
	cout << part8("banana", "nan") << endl;
}
