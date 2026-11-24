#include <string.h>
struct Node {
  char* data;
  Node* next;
};

struct Stack {
  Node* head = nullptr;
  unsigned long size = 0;
};

void Push(Stack* stack, const char* str) {
  Node* node = new Node;
  node->data = new char[strlen(str) + 1];
  strcpy(node->data, str);
  node->next = stack->head;
  stack->head = node;
  stack->size++;
}

void Pop(Stack* stack) {
  if (stack->head == nullptr) {
    return;
  }
  Node* old = stack->head;
  stack->head = old->next;
  delete[] old->data;
  delete old;
  stack->size--;
}

const char* Top(const Stack* stack) {
  if (stack->head == nullptr) {
    return nullptr;
  }
  return stack->head->data;
}

unsigned long Size(const Stack* stack) {
  return stack->size;
}

void Clear(Stack* stack) {
  while (stack->head != nullptr) {
    Pop(stack);
  }
}