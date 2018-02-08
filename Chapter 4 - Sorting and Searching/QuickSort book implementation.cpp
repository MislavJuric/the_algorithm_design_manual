#include <iostream>

using namespace std;

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

int partition(item_type s[], int l, int h)
{
    int i; /* counter */
    int p; /* pivot element index */
    int firsthigh; /* divider position for pivot element */
    p = h;
    firsthigh = l;

    // 1 3 4 7 2 - testni niz
    // 1 2 4 7 3

    for (i=l; i<h; i++)
    {
        if (s[i] < s[p])
        {
            swap(&s[i],&s[firsthigh]);
            firsthigh++;
        }
    }
    swap(&s[p],&s[firsthigh]);
    return(firsthigh); // pozicija pivota
}
