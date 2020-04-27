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
  
  // Modifiers
  void add(double value);
  void remove(double value);
  void reverse();

  // Other Functions
  void print();
  bool isMember(ListNode* obj, double value);
  ListNode* getFirstNode() { return head; }
  int search(double value);

 private:
  ListNode* head;
};

#endif