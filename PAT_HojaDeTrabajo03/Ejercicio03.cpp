#include "Ejercicio03.h"
Node<int>* Ejercicio03::copyList(Node<int>* head)
{
    if (head == nullptr) {
        return nullptr;
    }

    
    Node<int>* curr = head;
    while (curr != nullptr) {
        Node<int>* newNode = new Node<int>();
        newNode->value = curr->value;
        newNode->next = curr->next;
        newNode->random = nullptr;
        curr->next = newNode;
        curr = newNode->next;
    }

    
    curr = head;
    while (curr != nullptr) {
        if (curr->random != nullptr) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    Node<int>* newHead = head->next;
    Node<int>* prev = head;
    curr = head->next;
    while (curr != nullptr) {
        prev->next = curr->next;
        prev = curr;
        curr = curr->next;
        prev->next = (curr != nullptr) ? curr->next : nullptr;
    }

    return newHead;
}
