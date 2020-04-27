#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

struct ListNode {
    double entry;
    ListNode* next;

    ListNode(double entry1, ListNode* next1 = nullptr) {
      entry = entry1;
      next = next1;
    }
  };

class LinkedList {
 public:
  LinkedList();
  LinkedList(const LinkedList&);
  ~LinkedList();
  void print();
  void add(double value);
  void remove(double value);
  bool isMember(ListNode* obj, double value);
  void reverse();
  ListNode* getFirstNode() { return head; }

 private:
  ListNode* head;
};

#endif