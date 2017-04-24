#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define STACK_INIT_SIZE 20 //栈的空间 
#define STACKINCREMENT 10 //给栈加大的幅度，不够+10 

typedef char ElemType;
typedef struct{
		ElemType *base;
		ElemType *top;
		int stackSize;
}sqStack;

void InitStack(sqStack *s){//栈的初始化 
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));//分配空间 
	if(!s->base)
	{
		exit(0);//分配失败退出 
	}
	s->top = s->base;//栈顶和栈底指向同一位置，初始化 
	s->stackSize = STACK_INIT_SIZE;//初始化容量 
}

void Push(sqStack *s,ElemType e){//入栈 
	if(s->top - s->base>=s->stackSize){//检查栈是否满了 
		s->base=(ElemType *)realloc(s->base,(s->stackSize+STACKINCREMENT)*sizeof(ElemType));
		if(!s->base){
			exit(0);
		}
	}
	*(s->top) = e;
	s->top++;
}

void Pop(sqStack *s,ElemType *e){//弹出 
	if(s->top ==s->base){
	return;
	}
	*e = *--(s->top); 
}

int StackLength(sqStack s){//求栈当前容量 
	return(s.top - s.base);
}

int main(){
	ElemType c;
	sqStack s;
	int len,i,sum=0;
	
	InitStack(&s);
	
	printf("请输入二进制数，输入#符号表示结束！\n");
	scanf("%c",&c);
	while(c!='#'){
		Push(&s,c);
		scanf("%c",&c);
	}
	getchar();//吃回车  
	len=StackLength(s);
	printf("栈的当前容量是：%d\n",len);
	for(i=0;i<len;i++){
		Pop(&s,&c);
		sum+=(c-48)*pow(2,i);
	}
	printf("转化为十进制数是：%d\n",sum);
	return 0;
}
