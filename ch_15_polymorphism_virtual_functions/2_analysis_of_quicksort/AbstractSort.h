#ifndef ABSTRACT_SORT_H_
#define ABSTRACT_SORT_H_

class AbstractSort {
 public:
  AbstractSort() { this->numComparisons = 0; }
  int get_num_compares() { return this->numComparisons; }
  virtual void sort(int arr[], int size)=0;

 protected:
  bool compare(int elementA, int elementB) { 
      this->numComparisons++;
      return elementA > elementB; }
  
 private:
  int numComparisons;

};

#endif