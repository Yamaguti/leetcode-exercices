#include<vector>
#include<sstream>
#include<iostream>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool problem_found = false;
        int problem = -1;

        for (int i = 0; i < nums.size() -1; i++) {
            if (nums[i] > nums[i+1]) {
                if (problem_found) {
                    return false;
                } else {
                    problem_found = true;
                    problem = i;
                }
            }
        }

        return (not problem_found)
        or (problem == 0)
        or (problem == nums.size()-2)
        or (nums[problem-1] <= nums[problem+1])
        or (nums[problem] <= nums[problem+2]);
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
