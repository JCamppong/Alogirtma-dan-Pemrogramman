#include <iostream>

using namespace std;

// Definisi struktur node untuk linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // Simpan node berikutnya
            curr->next = prev; // Balikkan pointer ke node sebelumnya
            prev = curr; // Geser prev ke node saat ini
            curr = nextTemp; // Geser curr ke node berikutnya
        }
        
        return prev; // prev sekarang adalah head dari linked list yang sudah terbalik
    }
};

// Fungsi untuk menampilkan linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    // Membuat linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Linked list sebelum reverse: ";
    printList(head);
    
    // Memanggil fungsi untuk membalikkan linked list
    Solution sol;
    head = sol.reverseList(head);
    
    cout << "Linked list setelah reverse: ";
    printList(head);
    
    // Dealokasi memory untuk mencegah kebocoran memori
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    
    return 0;
}