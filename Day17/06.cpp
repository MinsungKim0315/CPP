#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution6(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    for (auto i = 0; i < name.size(); i++) {
        m[name[i]] = yearning[i];
    }
    for (auto page1 : photo) {
        int sum = 0;
        for (auto name : page1) sum += m[name];
        answer.emplace_back(sum);
    }
    return answer;
}

int main() {
    vector<vector<string>> photo1
    {
      {"may", "kein", "kain", "radi"},
      {"may", "kein", "brin", "deny"},
      {"kon", "kain", "may", "coni" }
    };
    vector<vector<string>> photo2
    {
      {"kali", "mari", "don"},
      {"pony", "tom", "teddy"},
      {"con", "mona", "don"}
    };
    vector<vector<string>> photo3
    {
      {"may" },
      {"kein", "deny", "may"},
      {"kon", "coni"}
    };

    for (auto& p : solution6({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, photo1))
        cout << p << " "; cout << endl; // 19 15  6

    for (auto& p : solution6({ "kali", "mari", "don" }, { 11, 1, 55 }, photo2))
        cout << p << " "; cout << endl; // 67  0 55

    for (auto& p : solution6({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, photo3))
        cout << p << " "; cout << endl; //  5 15  0
}
