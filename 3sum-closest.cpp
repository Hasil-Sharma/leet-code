// https://leetcode.com/problems/3sum-closest/description/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int res;
        
        sort(nums.begin(), nums.end());
        
        res = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < nums.size() - 2; i++){
            int k = nums.size() - 1, j = i + 1;
            int sum = nums[i] + nums[j] + nums[k];
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                if ( abs(sum - target) < abs(res - target))
                    res = sum;
                if (sum > target) k--;
                else if (sum < target) j++;
                else break;
            }
        }
        
        return res;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);
        
        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
