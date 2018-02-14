#include <iostream>

using namespace std;

//------------------------- code I wrote ------------------------------

#define item_type int

void swap(item_type* a, item_type* b)
{
    item_type temp = *a;
    *a = *b;
    *b = temp;
}

//------------------------- code I wrote ------------------------------

int partition(item_type s[], int l, int h)
{
    int i; /* counter */
    int p; /* pivot element index */
    int firsthigh; /* divider position for pivot element */
    p = h;
    firsthigh = l;

    // this for loop down here ensures that the elements left of the pivot are less than the pivot
    // and that the elements right of the pivot are larger than the pivot

    for (i=l; i<h; i++)
    {
        if (s[i] < s[p])
        {
            swap(&s[i],&s[firsthigh]);
            firsthigh++;
        }
    }

    // then, we swap the element on the highest index and the pivot, so that the pivot is in the correct place
    swap(&s[p],&s[firsthigh]);
    return(firsthigh); // we return the pivot position
}

void quicksort(item_type s[], int l, int h)
{
    int p; /* index of partition */
    if ((h-l)>0)
    {
        p = partition(s,l,h);
        quicksort(s,l,p-1);
        quicksort(s,p+1,h);
    }
}

int main()
{
    item_type A[10] {2, 6, 7, 9, 10, 4, 5, 8, 1, 3};
    quicksort(A, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
