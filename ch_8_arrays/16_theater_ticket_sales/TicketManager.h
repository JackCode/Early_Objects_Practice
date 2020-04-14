#ifndef TICKET_MANAGER_H
#define TICKET_MANAGER_H

#define NUM_ROWS 15
#define NUM_COLS 30

#include <fstream>
using namespace std;

class TicketManager {

    private:

        struct seatStruct {
            double price;
            bool sold;
        };

        seatStruct seats[NUM_ROWS][NUM_COLS];
        fstream seatPrices,
                 seatAvail;

        bool verify_bill(int numSeats, double pricePerSeat);
        void purchase_tickets(int row, int numSeats, int start);
        void print_ticket(int row, int s);

    public:

        TicketManager();
        ~TicketManager();

        void disply_seats();
        void request_tickets(int row, int numSeats, int start);
        void sales_report();        

};


#endif