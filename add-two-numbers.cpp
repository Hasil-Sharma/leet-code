// https://leetcode.com/problems/add-two-numbers/description/
#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    int add(ListNode ** result, int a, int b, int carry){
        int tempSum, carryOn;
        tempSum = a + b + carry;
        (*result) = new ListNode((tempSum) % 10);
        carryOn = tempSum / 10;
        return carryOn;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result;
        ListNode *temp1, *temp2, **tempResult, *temp3;
        int carryOn = 0, tempValue;
        temp1 = l1;
        temp2 = l2;
        tempResult = (&result);
        while(temp1 || temp2){
            
            carryOn = (temp1 && temp2) ? this->add(tempResult, temp1->val, temp2->val, carryOn) : carryOn;
            carryOn = (temp1 && !temp2) ? this->add(tempResult, temp1->val, 0, carryOn) : carryOn;
            carryOn = (!temp1 && temp2) ? this->add(tempResult, 0, temp2->val, carryOn) : carryOn;
            
            temp1 = (temp1) ? temp1->next : temp1;
            temp2 = (temp2) ? temp2->next : temp2;
            
            
            tempResult = &((*tempResult)->next);
            
        }
        
        if (carryOn) this->add(tempResult, 0, 0, carryOn);
        
        return result;
        
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
