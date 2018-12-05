
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        return 1;
    }
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<string> stringToStringVector(string input) {
    vector<string> output;
    stringstream ss;

    // take brackets out
    input = input.substr(1, input.length() - 2);

    ss.str(input);
    string item;
    char delim = ',';

    while (getline(ss, item, delim)) {
        trimLeftTrailingSpaces(item);
        trimRightTrailingSpaces(item);
        string itemNoQuotes = item.substr(1, item.length()-2);
        output.push_back(item);
    }

    return output;
}

int main() {
    string line;

    // get first word
    getline(cin, line);
    string S = line.substr(1, line.size()-2);

    // get from cin array of words
    getline(cin, line);
    vector<string> words = stringToStringVector(line);


    double ret = Solution().expressiveWords(S, words);
    cout << ret << endl;

    return 0;
}
