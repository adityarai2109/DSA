#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node *prev;
  node *next;
};

node *HEAD = NULL;
node *TAIL = NULL;

void push(int data)
{
  node *temp = new node();
  temp->data = data;
  temp->prev = NULL;
  temp->next = NULL;
  if (HEAD == NULL && TAIL == NULL)
  {
    HEAD = temp;
    TAIL = temp;
  }
  else
  {
    temp->prev = TAIL;
    temp->prev->next = temp;
    TAIL = temp;
  }
}

void unshift(int data)
{
  node *temp = new node();
  temp->data = data;
  temp->prev = NULL;
  temp->next = NULL;
  if (HEAD == NULL && TAIL == NULL)
  {
    HEAD = temp;
    TAIL = temp;
  }
  else
  {
    temp->next = HEAD;
    temp->next->prev = temp;
    HEAD = temp;
  }
}

void pushAfter(int data, int point)
{
  node *ptr = HEAD;
  while (ptr->data != point)
  {
    ptr = ptr->next;
  }
  node *temp = new node();
  temp->data = data;
  temp->prev = ptr;
  temp->next = ptr->next;
  ptr->next->prev = temp;
  ptr->next = temp;
}

void pushBefore(int data, int point)
{
  node *ptr = TAIL;
  while (ptr->data != point)
  {
    ptr = ptr->prev;
  }
  node *temp = new node();
  temp->data = data;
  temp->next = ptr;
  temp->prev = ptr->prev;
  ptr->prev->next = temp;
  ptr->prev = temp;
}

void pop()
{
  if (TAIL == NULL)
  {
    return;
  }
  node *ptr = TAIL;
  ptr->prev->next = NULL;
  TAIL = ptr;
}
void shift()
{
  if (HEAD == NULL)
  {
    return;
  }

  node *ptr = HEAD;
  ptr->next->prev = NULL;
  HEAD = ptr;
}

void deleteSpecificNode(int data)
{
  node *ptr = HEAD;
  while (ptr->data != data)
  {
    ptr = ptr->next;
  }
  ptr->prev->next = ptr->next;
  ptr->next->prev = ptr->prev;
}

void printForward()
{
  cout << "\nForward List : ";
  node *ptr = HEAD;
  while (ptr != NULL)
  {
    cout << ptr->data;
    if (ptr->next != NULL)
    {
      cout << " <=> ";
    }
    ptr = ptr->next;
  }
  cout << "\n\n";
}

void printBackward()
{
  cout << "\nBackward List : ";
  node *ptr = TAIL;
  while (ptr != NULL)
  {
    cout << ptr->data;
    if (ptr->prev != NULL)
    {
      cout << " <=> ";
    }
    ptr = ptr->prev;
  }
  cout << "\n\n";
}

int main()
{
  push(1);
  push(2);
  push(3);
  push(26);
  push(73);
  pushAfter(10, 3);
  printForward();
  push(4);
  pushBefore(20, 3);
  printForward();
  push(5);
  printForward();
  unshift(0);
  printForward();
  pop();
  printForward();
  shift();
  printForward();
  deleteSpecificNode(3);
  printForward();
  // printBackward();
  return 0;
}