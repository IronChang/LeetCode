typedef int STDataType;

typedef struct Stack
{
	STDataType* _array;
	size_t _top;
	size_t _capacity;
}Stack;

void StackInit(Stack* ps);//初始化
void StackDestory(Stack* ps);//销毁
void StackPush(Stack* ps, STDataType x);//尾插
void StackPop(Stack* ps);//尾删
STDataType StackTop(Stack* ps);//取到当前栈顶元素
int StackEmpty(Stack* ps);//判断栈是否为空
int StackSize(Stack* ps);//判断栈中的元素个数
void StackPrint(Stack* ps);//从栈中取出元素
void PintfStack(Stack* ps);//查看栈中元素
void Test();


void StackInit(Stack* ps)//初始化
{
	assert(ps);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackDestory(Stack* ps)//销毁
{
	assert(ps && ps->_array != NULL);

	free(ps->_array);
	ps->_array = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackPush(Stack* ps, STDataType x)//尾插
{
	assert(ps);
    
	if (ps->_top == ps->_capacity)//判断容量是否够用
	{
		size_t new_capacity = ps->_array == 0 ? 8 : (ps->_capacity) * 2;//三目运算符判断容量是否够用
		ps->_array = (STDataType*)realloc(ps->_array, new_capacity*sizeof(STDataType));
		assert(ps->_array);//判断是否申请到内存
		ps->_capacity = new_capacity;
	}
	//插入数据
	ps->_array[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)//尾删
{
	assert(ps && ps->_array != NULL);

	--ps->_top;//把栈顶指针向前移动一位，完成出栈
}

STDataType StackTop(Stack* ps)//取到当前栈顶元素
{
	assert(ps && ps->_array != NULL);

	return ps->_array[ps->_top - 1];
}

int StackEmpty(Stack* ps)//判断栈是否为空
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

int StackSize(Stack* ps)//判断栈中的元素个数
{
	assert(ps);

	return ps->_top;
}
bool isValid(char * s)//判断有效的括号
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
