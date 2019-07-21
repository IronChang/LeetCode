
typedef struct {
    int* data;//สýื้
    int front;//
    int tail;
    int count; 
} MyCircularQueue;


bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

    
    
/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* qu = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    qu->data = (int*)malloc(sizeof(int)*(k+1));
    qu->front = qu->tail = 0;
    qu->count = k+1;    
    return qu;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  if(myCircularQueueIsFull(obj))
  {
      return false;
  }
  else
  {
      obj->data[obj->tail] = value;
      obj->tail = (obj->tail+1)%obj->count;
      return true;
  }
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
   if(myCircularQueueIsEmpty(obj))
   {
       return false;
   }
    else
    {
        ++obj->front;
        obj->front %= obj->count;
        return true;
    }
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        return obj->data[obj->front];
    }
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
      if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    else
    {
        if(obj->tail == 0)
        {
            return obj->data[obj->count-1];
        }
        else
        {
            return obj->data[obj->tail-1];
        }
        
    }
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  if(obj->front == obj->tail)
   return true;
  else
   return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
  if((obj->tail+1)%obj->count == obj->front)
    return true;
  else
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
