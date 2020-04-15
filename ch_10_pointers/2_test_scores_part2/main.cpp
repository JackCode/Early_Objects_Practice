// This program dynamically allocates an array to store test scores
// and calculates the average of the scores.
// The list of scores is sorted and displayed accordingly.
// Includes student names with scores


#include <iostream>
#include <string>
using namespace std;

struct student {
    string name;
    double score;
};

void get_scores(student *const data, const int size);
void sort_scores(student *const data, const int size);
double get_avg(const student* const data, const int size);
void display_scores(const student* const data, const int size);

int main() {

    int numScores;
    student *scores;

    do
    {
        cout << "How many scores? ";
        cin >> numScores;

        if ( numScores < 1 )
            cout << "Invalid entry. Enter positive number.\n";

    } while (numScores < 1);

    scores = new student [numScores];       // Allocate memory for scores

    get_scores(scores, numScores);
    sort_scores(scores, numScores);
    display_scores(scores, numScores);

    cout << "\n";
    
    delete [] scores; // Free DAM

    return 0;
}

void get_scores(student *const data, const int size) {

    for ( int count = 0; count < size; count++ )
    {
        do 
        {
            cout << "Enter student first name: ";
            cin >> (data + count)->name;
            cin.ignore();
            cout << "Enter score for " << (data + count)->name << ": ";
            cin >> (data + count)->score;

            if ( (data + count)->score < 0)
                cout << "Invalid Entry. Score must be 0 or greater.\n";

        } while((data + count)->score < 0);
    }
}

void sort_scores(student *const data, const int size) {

    bool swap;
    double tempScore;
    string tempName;

    do 
    {
        swap = false;
        
        for ( int count = 0; count < (size-1); count ++ )
        {
            if ( (data + count)->score > (data + count + 1)->score )
            {
                tempScore = (data + count + 1)->score;
                tempName = (data + count + 1)->name;
                (data + count + 1)->score = (data + count)->score;
                (data + count + 1)->name = (data + count)->name;
                (data + count)->score = tempScore;
                (data + count)->name = tempName;
                swap = true;
            }
        }
    } while (swap);

}

double get_avg(const student* const data, const int size) {

    double total = 0;

    for ( int count = 0; count < size; count++ )
        total += (data + count)->score;

    return total / size;
}

void display_scores(const student* const data, const int size) {

    system("clear");

    for ( int count = 0; count < size; count++ )
        cout << (data + count)->name << ": " << (data + count)->score << endl;

    cout << "\nAverage score: " << get_avg(data, size) << endl;

}