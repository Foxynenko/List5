#include <iostream>

using namespace std;

// Визначення структури вузла
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Функція для виведення зв'язаного списку
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Функція для видалення вузла зі списку
void deleteNode(ListNode* node) {
    if (!node || !node->next) {
        return;
    }

    ListNode* nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    delete nextNode;
}

int main() {
    // Приклад 1
    ListNode* head1 = new ListNode(4);
    head1->next = new ListNode(5);
    head1->next->next = new ListNode(1);
    head1->next->next->next = new ListNode(9);

    cout << "Original List 1: ";
    printList(head1);

    ListNode* node1 = head1->next;
    deleteNode(node1);

    cout << "Updated List 1: ";
    printList(head1);

    // Приклад 2
    ListNode* head2 = new ListNode(4);
    head2->next = new ListNode(5);
    head2->next->next = new ListNode(1);
    head2->next->next->next = new ListNode(9);

    cout << "Original List 2: ";
    printList(head2);

    ListNode* node2 = head2->next->next;
    deleteNode(node2);

    cout << "Updated List 2: ";
    printList(head2);

    return 0;
}
