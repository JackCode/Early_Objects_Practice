#include <iostream>
using namespace std;

void get_scores(int[], int);

int main()
{
    int numScores = 0, 
        perfectScores = 0;
    cout << "How many scores? ";
    cin >> numScores;
    cout << "\n";
    
    int scores[numScores];

    get_scores(scores, numScores);

    for (int i = 0; i < numScores; i++)
    {
        if (scores[i] == 100)
            perfectScores++;
    }

    cout << "There were " << perfectScores << " perfect scores!\n";

    return 0;
}

void get_scores(int scores[], int size)
{
    for(int i = 0; i < size; i++)
    {
        do
        {
            cout << "Enter score: ";
            cin >> scores[i];

            if (scores[i] < 0 || scores[i] > 100)
                cout << "Invalid Entry.\n";

        } while (scores[i] < 0 || scores[i] > 100);
    }
}