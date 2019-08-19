#pragma once
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int QUDataType;

typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _tail;
}Queue;


void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_tail = NULL;
}

void QueueDestory(Queue* pq)
{
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}

	pq->_front = pq->_tail = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;

	return node;
}

void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);

	QueueNode* newnode = BuyQueueNode(x);
	if (pq->_tail == NULL)
	{
		pq->_front = pq->_tail = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq && pq->_front != NULL);

	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;

	if (pq->_front == NULL)
	{
		pq->_tail = NULL;
	}
}

QUDataType QueueFront(Queue* pq)
{
	assert(pq && pq->_front != NULL);
	
	return pq->_front->_data;
}

QUDataType QueueBack(Queue* pq)
{
	assert(pq && pq->_tail != NULL);

	return pq->_tail->_data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_front;
	size_t size = 0;
	while (cur)
	{
		++size;
		cur = cur->_next;
	}

	return size;
}


void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}