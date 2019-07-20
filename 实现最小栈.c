typedef int STDataType;

typedef struct Stack
{
	STDataType* _array;
	size_t _top;
	size_t _capacity;
}Stack;

void StackInit(Stack* ps);//��ʼ��
void StackDestory(Stack* ps);//����
void StackPush(Stack* ps, STDataType x);//β��
void StackPop(Stack* ps);//βɾ
STDataType StackTop(Stack* ps);//ȡ����ǰջ��Ԫ��
int StackEmpty(Stack* ps);//�ж�ջ�Ƿ�Ϊ��
int StackSize(Stack* ps);//�ж�ջ�е�Ԫ�ظ���


void StackInit(Stack* ps)//��ʼ��
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackDestory(Stack* ps)//����
{
	assert(ps && ps->_array != NULL);

	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)//β��
{
	assert(ps);
    
	if (ps->_top == ps->_capacity)//�ж������Ƿ���
	{
		size_t new_capacity = ps->_array == 0 ? 8 : (ps->_capacity) * 2;//��Ŀ������ж������Ƿ���
		ps->_array = (STDataType*)realloc(ps->_array, new_capacity*sizeof(STDataType));
		assert(ps->_array);//�ж��Ƿ����뵽�ڴ�
		ps->_capacity = new_capacity;
	}
	//��������
	ps->_array[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)//βɾ
{
	assert(ps && ps->_array != NULL);

	--ps->_top;//��ջ��ָ����ǰ�ƶ�һλ����ɳ�ջ
}

STDataType StackTop(Stack* ps)//ȡ����ǰջ��Ԫ��
{
	assert(ps && ps->_array != NULL);

	return ps->_array[ps->_top - 1];
}

int StackEmpty(Stack* ps)//�ж�ջ�Ƿ�Ϊ��
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)//�ж�ջ�е�Ԫ�ظ���
{
	assert(ps);

	return ps->_top;
}


typedef struct {
    Stack q1;
    Stack q2;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* st = (MinStack*)malloc(sizeof(MinStack));
    StackInit(&st->q1);
    StackInit(&st->q2);
    
    return st;
}

void minStackPush(MinStack* obj, int x) {
  StackPush(&obj->q1,x);
    if(StackEmpty(&obj->q2) == 0)
    {
         StackPush(&obj->q2,x);
    }
    else
    {
        if(StackTop(&obj->q2) >= x)
        {
             StackPush(&obj->q2,x);
        }
    }
}

void minStackPop(MinStack* obj) {
  if(StackTop(&obj->q1) == StackTop(&obj->q2))
  {
      StackPop(&obj->q1);
      StackPop(&obj->q2); 
  }
  else
  {
      StackPop(&obj->q1);   
  }
}

int minStackTop(MinStack* obj) {
  return StackTop(&obj->q1);
}

int minStackGetMin(MinStack* obj) {
  return StackTop((&obj->q2));
}

void minStackFree(MinStack* obj) {
    StackDestory(&obj->q1);
    StackDestory(&obj->q2);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
