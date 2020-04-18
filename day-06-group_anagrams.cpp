// Problem link: https://leetcode.com/problems/group-anagrams

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time complexity = O(n * k log k); k = max length string in strs
// Space complexity = O(n)
vector<vector<string>> groupAnagrams_1(vector<string>& strs) {
    // "eat", "tea", "tan", "ate", "nat", "bat"

    // keys are sorted word of each word in strs
    // "ate" -> "eat", "tea", "ate"
    // "ant" -> "tan", "nat"
    // "abt" -> "bat"

    vector<vector<string>> groupedAnagrams;
    unordered_map<string, vector<string>> map;

    for (int i = 0; i < (int)strs.size(); ++i) {
        string word = strs[i];

        sort(word.begin(), word.end());
        map[word].push_back(strs[i]);
    }

    for (auto node : map) {
        vector<string> groupedAnagram = node.second;
        groupedAnagrams.push_back(groupedAnagram);
    }

    return groupedAnagrams;
}


string getFreqKey(string word) {
    string freqKey = "";

    vector<int> wordCounts(26, 0);
    for (char ch : word) {
        ++wordCounts[ch - 'a'];
    }

    for (int count : wordCounts) {
        freqKey += to_string(count);
    }

    return freqKey;
}

// Time complexity = O(n * k); k = max length string in strs
// Space complexity = O(n)
vector<vector<string>> groupAnagrams_2(vector<string>& strs) {
    // "eat", "tea", "tan", "ate", "nat", "bat"

    // keys are word counts frequency of each word in strs
    // "12100..." -> "abbc", "cabb"
    // "1...." -> "eat", "tea", "ate"
    // "...." -> "tan", "nat"
    // "...." -> "bat"
    vector<vector<string>> groupedAnagrams;
    unordered_map<string, vector<string>> map;

    for (int i = 0; i < (int)strs.size(); ++i) {
        string word = strs[i];

        string freqKey = getFreqKey(word);
        map[freqKey].push_back(word);
    }

    for (auto node : map) {
        vector<string> groupedAnagram = node.second;
        groupedAnagrams.push_back(groupedAnagram);
    }

    return groupedAnagrams;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = groupAnagrams_2(strs);

    for (auto anagrams : groupedAnagrams) {
        for (auto word : anagrams) {
            cout << word << ", ";
        }
        cout << endl;
    }
}
