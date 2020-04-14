#include <iostream>
#include "TicketManager.h"
using namespace std;

int print_menu();
void ticket_request(TicketManager&);

int main() {

    system("clear");

    TicketManager theater;

    while(true)
    {
        switch(print_menu())
        {
            case 1:
                system("clear");
                theater.disply_seats();
                break;
            case 2:
                ticket_request(theater);
                break;
            case 3:
                theater.sales_report();
                cout << "\n";
                break;
            case 4:
                return 0;
        }
    }

    return 0;
}

int print_menu() {

    int choice = 0;

    cout << "\n    Epic Rijks Theater" << endl;
    cout << "\n";
    cout << "1. Display Seating Chart\n";
    cout << "2. Request Tickets\n";
    cout << "3. Print Sales Report\n";
    cout << "4. Exit\n\n";

    do
    {
        cout << "Selection: ";
        cin >> choice;


        if ( choice < 1 || choice > 4)
        {
            cout << "Invalid entry.\n";
        }
    } while (choice < 1 || choice > 4);

    return choice;
}

void ticket_request(TicketManager& theater) {

    int row, start, numSeats;
    cout << "Select Row: ";
    cin >> row;
    cout << "Starting seat: ";
    cin >> start;
    cout << "How many seats: ";
    cin >> numSeats;

    theater.request_tickets(row, numSeats, start);
}