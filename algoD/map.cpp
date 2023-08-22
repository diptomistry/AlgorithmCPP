#include<bits/stdc++.h>
using namespace std;

int main() {
    // Example with map (ordered map)
    map<int, string> orderedMap;
    orderedMap[2] = "Alice";
    orderedMap[1] = "Bob";
    orderedMap[3] = "Charlie";

    cout << "map (ordered):" << endl;
    //for (auto it = ordered_Map.begin(); it != ordered_Map.end(); it++)
    for (map<int, string>::iterator it = orderedMap.begin(); it != orderedMap.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    // Example with unordered_map (unordered map)
    unordered_map<int, string> unorderedMap;
    unorderedMap[2] = "Alice";
    unorderedMap[1] = "Bob";
    unorderedMap[3] = "Charlie";

    cout << "unordered_map (unordered):" << endl;
    for (unordered_map<int, string>::iterator it = unorderedMap.begin(); it != unorderedMap.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
