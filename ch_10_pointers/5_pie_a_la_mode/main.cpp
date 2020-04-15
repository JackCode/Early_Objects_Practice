// This program finds the mode of an array of 30 integers
// NOTE: Only finds least mode in case of multi modal

#include <iostream>

#define NUM_PEOPLE 30

using namespace std;

int get_mode(int *const data, int size);
void sort_array(int *const data, int size);

int main() {

    int* ptr = new int [NUM_PEOPLE];

    for (int i = 0; i < NUM_PEOPLE; i++)
    {
        cout << "Enter integer: ";
        cin >> *(ptr+i);
    }
    
    cout << "\nMode: " << get_mode(ptr, 7) << endl;

    return 0;
}

int get_mode(int *const data, int size) {

    sort_array(data, size);

    int currentCount = 1, currentNum = *data,
        modeCount = 0, mode;

    for ( int count = 1; count < size; count++ )
    {
        currentNum = *(data + count);

        if ( currentNum == *(data + count - 1) )
            currentCount++;
        else
            currentCount = 1;
        
        
        if ( currentCount > modeCount )
        {
            mode = currentNum;
            modeCount = currentCount;
        }
    }

    return mode;

}

void sort_array(int *const data, int size) {

    bool swap;
    int temp;

    do
    {
        swap = false;

        for ( int count = 0; count < size-1; count ++ )
        {
            if (*(data + count) > *(data + count + 1))
            {
                temp = *(data + count);
                *(data + count) = *(data + count + 1);
                *(data + count + 1) = temp;
                swap = true;
            }
        }
    } while (swap);
    

}