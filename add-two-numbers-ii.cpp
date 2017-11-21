//https://leetcode.com/problems/add-two-numbers-ii/description/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void addToStack(ListNode* l, stack<ListNode*>& stk){
        do{
            stk.push(l);
        } while ( l = l->next );
    }
    void insertToStart(int val, ListNode **ans){
        ListNode *temp = new ListNode(val);
        temp->next = (*ans);
        *(ans) = temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> stk1, stk2;
        ListNode* ans = NULL;
        int val, carry = 0;
        this->addToStack(l1, stk1);
        this->addToStack(l2, stk2);
        
        while(!stk1.empty() || !stk2.empty()){
            // Till both the stacks are empty;
            val = ((!stk1.empty()) ? stk1.top()->val : 0) + ((!stk2.empty()) ? stk2.top()->val : 0) + carry;
            carry = val / 10;
            val = val % 10;
            insertToStart(val, &ans);
            if(!stk1.empty()) stk1.pop();
            if(!stk2.empty()) stk2.pop();
        }
        if(carry) insertToStart(carry, &ans);
        return ans;
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
