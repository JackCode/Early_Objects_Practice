#ifndef MENU_H_
#define MENU_H_

class Menu {
 public:
  Menu();
  void print_menu();
  int get_menu_choice();

 private:
  int menuChoice;
};

#endif