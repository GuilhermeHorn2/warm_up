#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

class Node
{
public:
 int data;
 Node *next;
 Node(int x)
 {
  data = x;
 }
 ~Node() {}
};

class Min_stack
{
public:
 Node *min = nullptr;
 Node *top = nullptr;
 // contructor
 Min_stack() {}
 // push
 void push(int val)
 {
  Node *novo = new Node(val);
  novo->next = top;
  top = novo;
  int x = 0;
  if (min == nullptr || val < min->data)
  {
   x = val;
  }
  else
  {
   x = min->data;
  }
  // the idea is to have a second stack that tracks what is the min up to that point
  Node *novo_min = new Node(x);
  novo_min->next = min;
  min = novo_min;
 }
 // pop
 void pop()
 {
  top = top->next;
  min = min->next;
 }
 // top
 int get_top()
 {
  return top->data;
 }
 // min
 int get_min()
 {
  return min->data;
 }
 ~Min_stack() {}
};

main()
{
 /* ?\n;||(or) e &&(and)*/
 Min_stack *s = new Min_stack();
 s->push(5);
 s->push(10);
 s->push(9);
 s->push(4);
 s->push(87);
 int x = s->get_min();
 std::cout << x;
 s->pop();
 std::cout << (char)10;
 x = s->get_top();
 std::cout << x;

 return 0;
}
