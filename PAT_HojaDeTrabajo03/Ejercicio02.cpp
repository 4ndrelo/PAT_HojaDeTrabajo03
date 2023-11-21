#include "Ejercicio02.h"

vector<vector<string>>* Ejercicio02::groupAnagrams(vector<string>& strings)
{
    vector<vector<string>>* result = new vector<vector<string>>();


    struct AnagramGroup {
        string sortedStr;
        vector<string> anagrams;
    };

    vector<AnagramGroup> anagramGroups;

 
    for (const string& str : strings) {
        
        string sortedStr = str;
        for (int i = 0; i < sortedStr.size(); i++) {
            for (int j = i + 1; j < sortedStr.size(); j++) {
                if (sortedStr[i] > sortedStr[j]) {
                    char temp = sortedStr[i];
                    sortedStr[i] = sortedStr[j];
                    sortedStr[j] = temp;
                }
            }
        }

        
        bool foundGroup = false;
        for (AnagramGroup& group : anagramGroups) {
            if (group.sortedStr == sortedStr) {
                group.anagrams.push_back(str);
                foundGroup = true;
                break;
            }
        }

      
        if (!foundGroup) {
            AnagramGroup newGroup;
            newGroup.sortedStr = sortedStr;
            newGroup.anagrams.push_back(str);
            anagramGroups.push_back(newGroup);
        }
    }

    for (const AnagramGroup& group : anagramGroups) {
        result->push_back(group.anagrams);
    }

    return result;
}
