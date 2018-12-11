#include<vector>
#include<sstream>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isNonDecreasing(vector<int> v) {
        for (int i = 0; i < v.size()-1; i++) {
            if (v[i] > v[i+1]) {
                return false;
            }
        }

        return true;
    }

    bool checkPossibility(vector<int>& nums) {
        if (isNonDecreasing(nums)) {
            return true;
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            int aux = nums[i];
            nums[i] = nums[i+1];
            if (isNonDecreasing(nums)) {
                return true;
            } else {
                nums[i] = aux;
            }
        }

        nums[nums.size()-1] = nums[nums.size()-2];
        if (isNonDecreasing(nums)) {
            return true;
        } else {
            return false;
        }
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().checkPossibility(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
