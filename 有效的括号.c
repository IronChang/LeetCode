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
void StackPrint(Stack* ps);//��ջ��ȡ��Ԫ��
void PintfStack(Stack* ps);//�鿴ջ��Ԫ��
void Test();


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
bool isValid(char * s)//�ж���Ч������
{
   	Stack st;
	StackInit(&st);
	
	char* symbol[3] = {"{}","()","[]"};
	
	while(*s)
	{
		if(*s == '(' || *s == '{' || *s == '[')
		{
			StackPush(&st,*s);
		}
		else if(*s == ')' || *s == '}' || *s == ']')
		{
			if(StackEmpty(&st) == 0)
			{ 
				return false;	
			}
			
			STDataType top = StackTop(&st);
			StackPop(&st);
			
			for(size_t i = 0;i < 3;++i)
			{
				if(*s == symbol[i][1])
				{
					if(top != symbol[i][0])
					{
						StackDestory(&st);
						return false;
					}
					else
					{
						break;
					}
				}
			}
		} 
		++s;  
	} 
    
    if(StackEmpty(&st) == 0)
    return true;
    else
    return false;
}
