
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateList(ListNode* head, int K) {
    if(!head) return NULL;
    if(!K) return head;

    int n = 0;
    ListNode *cur = head;
    ListNode *last = head;

    while(cur) {
        n++;
        last = cur;
        cur = cur->next;
    }

    K %= n;

    cur = head;

    for(int i = 0; i < n - K - 1; i++)
        cur = cur->next;

    last->next = head;

    ListNode *temp = cur->next;
    cur->next = NULL;

    return temp;
}

ListNode* GetList(vector<int> &num) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < (int)num.size(); i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }
    
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    int K;
    cin >> K;

    ListNode* head = GetList(num);

    head = rotateList(head, K);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
    
    return 0;
}
