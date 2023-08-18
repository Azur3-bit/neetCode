// *
// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ostream& operator<<(ostream& stream, ListNode node) {
    ListNode* nodePointer = &node;
    stream << "[";
    while (nodePointer != nullptr) {
        stream << nodePointer->val << ", ";
        nodePointer = nodePointer->next;
    }
    stream << "]";
    return stream;
}
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
auto _ = []() {
    cin.tie(0)->sync_with_stdio(0);
    //cout << "sws = false" << endl;
    return 0;
}();

int solution = []() {
    string list1, list2;
    ofstream out("user.out");
    while (cin >> list1 >> list2) {
        list1 = list1.substr(1, list1.size() - 1);
        list2 = list2.substr(1, list2.size() - 1);
        //cout << firstList << secondList << endl;
        int currentSum{0}, index{0};
        //string digits1 = "", digits2 = "";
        for (index = 0; true; index += 2) {
            if (index < list1.size())
                currentSum += list1[index] - '0';
            if (index < list2.size())
                currentSum += list2[index] - '0';
            if (currentSum || list1.size() > index || list2.size() > index)
                out << (index ? "," : "[") << currentSum % 10;
            else
                break;
            currentSum = currentSum >= 10;
        }
        out << "]" << endl;
    }
    exit(0);
    return 0;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return nullptr;
    }
};
