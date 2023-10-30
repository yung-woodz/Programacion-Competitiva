#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, set<string>> relations;

    for (int i = 0; i < n; i++) {
        string person1, arrow, person2;
        cin >> person1 >> arrow >> person2;

        if (arrow == "->" || arrow == "??") {
            relations[person1].insert(person2);
        }
    }

    set<string> all_people;

    // Agregar todos los nombres al conjunto de personas
    for (const auto& entry : relations) {
        all_people.insert(entry.first);
        all_people.insert(entry.second.begin(), entry.second.end());
    }

    set<string> sources;

    // Encontrar personas sin relaciones de rumor
    for (const auto& person : all_people) {
        if (relations.find(person) == relations.end()) {
            sources.insert(person);
        }
    }

    // Imprimir las posibles fuentes de rumor
    for (const string& source : sources) {
        cout << source << endl;
    }

    return 0;
}
