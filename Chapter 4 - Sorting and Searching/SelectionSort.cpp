#include <iostream>

using namespace std;

// my selection sort implementation

#define item_type int

void SelectionSort(item_type A[], int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        int min = A[i];
        int min_index = i;
        for (int j = i + 1; j < array_size; j++)
        {
            if (A[j] < min)
            {
                min = A[j];
                min_index = j;
            }
        }
        item_type temp = A[i];
        A[i] = A[min_index];
        A[min_index] = temp;
    }
}

int main()
{
    item_type A[5] {2, 4, 3, 5, 1}; // hard-coding 5 in here again
    SelectionSort(A, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
