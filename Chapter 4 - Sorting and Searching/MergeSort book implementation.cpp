// Mergesort_debug.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

// this doesn't sort right; probably because of my faulty queue implementation... have to revisit this

//------------------------- code I wrote ------------------------------

#define item_type int
#define QUEUE_SIZE 10

struct queue
{
	item_type array[QUEUE_SIZE];
	int queue_size;
};

void init_queue(queue* q)
{
	q->queue_size = 0;
}

void enqueue(queue* q, item_type item)
{
	for (int i = q->queue_size; i >= 1; i--)
	{
		q->array[i] = q->array[i - 1];
	}
	q->array[0] = item;
	q->queue_size++;
}

bool empty_queue(queue* q)
{
	if (q->queue_size == 0)
	{
		return true;
	}
	return false;
}

item_type headq(queue* q)
{
	return q->array[(q->queue_size) - 1];
}

item_type dequeue(queue* q)
{
	q->queue_size--;
	return q->array[q->queue_size];
}

//------------------------- code I wrote ------------------------------

void merge(item_type s[], int low, int middle, int high)
{
	int i; /* counter */
	queue buffer1, buffer2; /* buffers to hold elements for merging */
	init_queue(&buffer1);
	init_queue(&buffer2);
	for (i = low; i <= middle; i++)
		enqueue(&buffer1, s[i]);
	for (i = middle + 1; i <= high; i++)
		enqueue(&buffer2, s[i]);
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
		middle = (low + high) / 2;
		mergesort(s, low, middle);
		mergesort(s, middle + 1, high);
		merge(s, low, middle, high);
	}
}

int main()
{
	
	item_type A[10]{ 2, 6, 7, 9, 10, 4, 5, 8, 1, 3 };
	mergesort(A, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}

	/*
	
	// enqueue() unit test

	queue* q = new queue;
	init_queue(q);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	
	*/
	return 0;
}

