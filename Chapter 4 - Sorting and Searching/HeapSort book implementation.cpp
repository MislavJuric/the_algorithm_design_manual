#include <iostream>

using namespace std;

//------- definitions I added --------

#define item_type int
#define PQ_SIZE 1000

//------- definitions I added --------

typedef struct
{
    item_type q[PQ_SIZE+1]; /* body of queue */
    int n; /* number of queue elements */
} priority_queue;

int pq_parent(int n)
{
    if (n == 1) return(-1);
    else return((int) n/2); /* implicitly take floor(n/2) */
}

int pq_young_child(int n)
{
    return(2 * n);
}

// ------------------- I wrote this -------------------
void pq_swap(priority_queue* q, int p1, int p2)
{
    item_type temp = q[p1]; // error: cannot convert 'priority_queue' to 'int' in initialization
    q[p1] = q[p2];
    q[p2] = temp;
}
// ------------------- I wrote this -------------------

void bubble_up(priority_queue *q, int p) // minheap implementacija
{
    if (pq_parent(p) == -1) return; /* at root of heap, no parent */
    if (q->q[pq_parent(p)] > q->q[p])
    {
        pq_swap(q,p,pq_parent(p)); // ova funkcija ne postoji
        bubble_up(q, pq_parent(p));
    }
}

pq_insert(priority_queue *q, item_type x)
{
    if (q->n >= PQ_SIZE)
    {
        printf("Warning: priority queue overflow insert x=%d\n",x);
    }
    else
    {
        q->n = (q->n) + 1;
        q->q[ q->n ] = x;
        bubble_up(q, q->n);
    }
}

pq_init(priority_queue *q)
{
    q->n = 0;
}

make_heap(priority_queue *q, item_type s[], int n) // item_type deklarirati
{
    int i; /* counter */
    pq_init(q);
    for (i=0; i<n; i++)
    pq_insert(q, s[i]);
}

bubble_down(priority_queue *q, int p)
{
    int c; /* child index */
    int i; /* counter */
    int min_index; /* index of lightest child */
    c = pq_young_child(p);
    min_index = p;
    for (i=0; i<=1; i++)
    {
        if ((c+i) <= q->n)
        {
            if (q->q[min_index] > q->q[c+i])
                min_index = c+i;
        }
    }
    if (min_index != p)
    {
        pq_swap(q,p,min_index);
        bubble_down(q, min_index);
    }
}


item_type extract_min(priority_queue *q)
{
    int min = -1; /* minimum value */
    if (q->n <= 0)
    {
        printf("Warning: empty priority queue.\n");
    }
    else
    {
        min = q->q[1];
        q->q[1] = q->q[ q->n ];
        q->n = q->n - 1;
        bubble_down(q,1);
    }
    return(min);
}

heapsort(item_type s[], int n)
{
    int i; /* counters */
    priority_queue q; /* heap for heapsort */
    make_heap(&q,s,n);
    for (i=0; i<n; i++)
    {
        s[i] = extract_min(&q);
    }
}

int main()
{

    return 0;
}
