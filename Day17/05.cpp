#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//Race
vector<string> solution5(vector<string> players, vector<string> callings) {
    map<string, int> m;
    for (int Rank = 0; Rank < players.size(); Rank++)
        m[players[Rank]] = Rank;
    for (auto& name : callings) {
        int rank = m[name]; // rank = kai = 3
        swap(players[rank - 1], players[rank]); //swap poe and kai
        m[name] = rank - 1; //kai = 2
        m[players[rank]] = rank;    //poe  = 3
    }
    return players;
}
int main() {
    for (auto& p : solution5({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" }))
        cout << p << " "; cout << endl; // mumu kai mine soe poe
}
