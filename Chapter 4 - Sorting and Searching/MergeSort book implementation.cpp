#include <iostream>

using namespace std;

void merge(item_type s[], int low, int middle, int high)
{
    int i; /* counter */
    queue buffer1, buffer2; /* buffers to hold elements for merging */
    init_queue(&buffer1);
    init_queue(&buffer2);
    for (i=low; i<=middle; i++)
        enqueue(&buffer1,s[i]);
    for (i=middle+1; i<=high; i++)
        enqueue(&buffer2,s[i]);
    i = low;
    while (!(empty_queue(&buffer1) || empty_queue(&buffer2)))
    {
        if (headq(&buffer1) <= headq(&buffer2))
            s[i++] = dequeue(&buffer1);
        else
            s[i++] = dequeue(&buffer2);
    }
    while (!empty_queue(&buffer1)) s[i++] = dequeue(&buffer1);
    while (!empty_queue(&buffer2)) s[i++] = dequeue(&buffer2);
}

void mergesort(item_type s[], int low, int high)
{
    int i; /* counter */
    int middle; /* index of middle element */
    if (low < high)
    {
        middle = (low+high)/2;
        mergesort(s,low,middle);
        mergesort(s,middle+1,high);
        merge(s, low, middle, high);
    }
}

int main()
{

    return 0;
}