// This program dynamically allocates an array to store test scores
// and calculates the average of the scores.
// The list of scores is sorted and displayed accordingly.


#include <iostream>
using namespace std;

void get_scores(double *const data, const int size);
void sort_scores(double *const data, const int size);
double get_avg(const double* const data, const int size);
void display_scores(const double* const data, const int size);

int main() {

    int numScores;
    double *scores;

    do
    {
        cout << "How many scores? ";
        cin >> numScores;

        if ( numScores < 1 )
            cout << "Invalid entry. Enter positive number.\n";

    } while (numScores < 1);

    scores = new double [numScores];       // Allocate memory for scores

    get_scores(scores, numScores);
    sort_scores(scores, numScores);
    display_scores(scores, numScores);

    cout << "\n";
    
    delete [] scores; // Free DAM

    return 0;
}

void get_scores(double *const data, const int size) {

    for ( int count = 0; count < size; count++ )
    {
        do 
        {
            cout << "Enter score #" << (count+1) << ": ";
            cin >> *(data + count);

            if ( *(data + count) < 0)
                cout << "Invalid Entry. Score must be 0 or greater.\n";

        } while(*(data + count) < 0);
    }
}

void sort_scores(double *const data, const int size) {

    bool swap;
    double temp;

    do 
    {
        swap = false;
        
        for ( int count = 0; count < (size-1); count ++ )
        {
            if ( *(data + count) > *(data + count + 1) )
            {
                temp = *(data + count + 1);
                *(data + count + 1) = *(data + count);
                *(data + count) = temp;
                swap = true;
            }
        }
    } while (swap);

}

double get_avg(const double* const data, const int size) {

    double total = 0;

    for ( int count = 0; count < size; count++ )
        total += *(data + count);

    return total / size;
}

void display_scores(const double* const data, const int size) {

    system("clear");
    cout << "Scores" << "\n"
            "------\n";
    for ( int count = 0; count < size; count++ )
        cout << (count+1) << ": " << *(data + count) << endl;

    cout << "\nAverage score: " << get_avg(data, size) << endl;

}