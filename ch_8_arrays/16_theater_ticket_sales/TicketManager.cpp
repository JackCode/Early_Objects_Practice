#include "TicketManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

TicketManager::TicketManager() {

    // Open seat info files
    seatAvail.open("seatAvailability.dat", ios::in);
    seatPrices.open("seatPrices.dat", ios::in);

    if ( !seatPrices || !seatAvail ) // Check for successful open
    {
        cout << "Error opening file for read.\n";
        return;
    }
    else
    {
        double tempPrice = 0;
        char tempSeatAvail;

        for ( int r = 0; r < NUM_ROWS ; r++ ) // Cycle through rows
        {
            if ( seatPrices >> tempPrice ) // Read until end of file
            {
                for ( int c = 0 ; c < NUM_COLS ; c++ ) // Cycle through columns
                {
                    if ( seatAvail >> tempSeatAvail ) // Read until end of file
                    {
                        seats[r][c].price = tempPrice;
                        seats[r][c].sold = (tempSeatAvail == '*') ? true : false; // * = available; # = not
                    }
                }
            }
        }

        // Close seat info files
        seatPrices.close();
        seatAvail.close();
    }

    return;
}

TicketManager::~TicketManager() {

    // Open seat info files
    seatAvail.open("seatAvailability.dat", ios::out | ios::trunc);

    if ( !seatAvail ) // Check for successful open
    {
        cout << "Error opening file for write.\n";
        return;
    }
    else
    {
        char avail;
        for ( int r = 0; r < NUM_ROWS; r++) // Cycle each row
        {
            for ( int c = 0; c < NUM_COLS; c++) // Cycle each col
            {
                avail = (seats[r][c].sold) ? '*' : '#';
                seatAvail << avail;//(seats[r][c].sold) ? '*' : '#'; // Write '*' for sold, '#' for not
            }

            seatAvail << endl;
        }

        // Close seat info files
        seatAvail.close();
    }

    return;

}

void TicketManager::disply_seats() {

    // Write column numbers
    cout << right << setw(65) << "Seats    # - Available    * - Sold" << endl << endl;
    cout << "         " 
         << " 1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30" << endl;

    for ( int r = 0; r < NUM_ROWS; r++ )
    {
        cout << "Row " << left << setw(5) << (r+1);
        
        for ( int c = 0; c < NUM_COLS; c++ )
        {
            cout << " " << ((seats[r][c].sold) ? '*' : '#') << " ";
        }

        cout << endl;
    }
    
}

void TicketManager::request_tickets( int row, int numSeats, int start ) {

    if ( row < 1 || row > 15)
    {
        cout << "Row " << row << " does not exist.\n";
        return;
    }
    else if ( (start + numSeats) > 31 )
    {
        cout << "Seat numbers greater than 30.\n";
        return;
    }
    else if( numSeats < 1 )
    {
        cout << "Must purchase at least one seat.\n";
        return;
    }
    else if ( start < 1 || start > 30)
    {
        cout << "Seat " << start << " does not exist.\n";
        return;
    }
    else
    {
        row--;   // Adjust to fit pos in array
        start--;

        for ( int i = start; i < (start + numSeats); i++) 
        {
            if ( seats[row][i].sold )
            {
                cout << "Row: " << (row+1) << " Seat: " << (i+1) << " is unavailable.\n";
                return;
            }
        }

        if ( verify_bill(numSeats, seats[row][0].price) )
        {
            purchase_tickets(row, numSeats, start);
            return;
        }
        else
        {
            cout << "\n -- Sale cancelled -- .\n";
            return;
        }
        
    }
    
    return;

}

bool TicketManager::verify_bill( int numSeats, double price ) {

    char confirm;
    
    cout << "Number of seats:" << numSeats << endl;
    cout << setprecision(2) << fixed;
    cout << "Price per seat: $" << price << endl;
    cout << "Total cost: $" << numSeats * price << endl;

    cout << "Confirm purchase (Y/n)";
    cin >> confirm;

    if ( confirm == 'y' or 'Y' )
        return true;
    else
        return false;
}

void TicketManager::purchase_tickets( int row, int numSeats, int start ) {

    double payment; 
    cout << "Payment: $";
    cin >> payment;

    if( payment < (numSeats * seats[row][0].price) )
    {
        cout << "Insufficient funds. -- SALE CANCELLED --\n";
        return;
    }
    else
    {
        system("clear");
        for ( int s = start; s < (start + numSeats) ; s++ )
        {

            print_ticket(row, s);
            // Change seat to sold
            seats[row][s].sold = true;

        }

        cout << setprecision(2) << fixed;
        cout << "Change: $" << (payment - (numSeats * seats[row][0].price)) << endl;
    }
    

}

void TicketManager::print_ticket(int row, int seat) {
    cout << "\n-------------------------" << endl;
    cout << "    ROW: " << (row+1) << "   SEAT: " << (seat+1) << endl; 
    cout << setprecision(2) << fixed;
    cout << "       Price: $" << seats[row][seat].price << endl;
    cout << "-------------------------\n" << endl;
}

void TicketManager::sales_report() {

    system("clear");

    int soldCount = 0;
    double sales = 0.0;

    for ( int r = 0; r < NUM_ROWS; r++ )
    {
        for ( int c = 0; c < NUM_COLS; c++ )
        {
            if ( seats[r][c].sold )
            {
                soldCount++;
                sales += seats[r][c].price;
            }
        }
    }

    cout << "     Seats Sold:  " << soldCount << endl;
    cout << "Seats Available:  " << (NUM_COLS * NUM_ROWS) - soldCount << endl;
    cout << setprecision(2) << fixed;
    cout << "  Current Sales: $" << sales << endl;
}