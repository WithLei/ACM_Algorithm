#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define STACK_INIT_SIZE 20 //ջ�Ŀռ� 
#define STACKINCREMENT 10 //��ջ�Ӵ�ķ��ȣ�����+10 

typedef char ElemType;
typedef struct{
		ElemType *base;
		ElemType *top;
		int stackSize;
}sqStack;

void InitStack(sqStack *s){//ջ�ĳ�ʼ�� 
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));//����ռ� 
	if(!s->base)
	{
		exit(0);//����ʧ���˳� 
	}
	s->top = s->base;//ջ����ջ��ָ��ͬһλ�ã���ʼ�� 
	s->stackSize = STACK_INIT_SIZE;//��ʼ������ 
}

void Push(sqStack *s,ElemType e){//��ջ 
	if(s->top - s->base>=s->stackSize){//���ջ�Ƿ����� 
		s->base=(ElemType *)realloc(s->base,(s->stackSize+STACKINCREMENT)*sizeof(ElemType));
		if(!s->base){
			exit(0);
		}
	}
	*(s->top) = e;
	s->top++;
}

void Pop(sqStack *s,ElemType *e){//���� 
	if(s->top ==s->base){
	return;
	}
	*e = *--(s->top); 
}

int StackLength(sqStack s){//��ջ��ǰ���� 
	return(s.top - s.base);
}

int main(){
	ElemType c;
	sqStack s;
	int len,i,sum=0;
	
	InitStack(&s);
	
	printf("�������������������#���ű�ʾ������\n");
	scanf("%c",&c);
	while(c!='#'){
		Push(&s,c);
		scanf("%c",&c);
	}
	getchar();//�Իس�  
	len=StackLength(s);
	printf("ջ�ĵ�ǰ�����ǣ�%d\n",len);
	for(i=0;i<len;i++){
		Pop(&s,&c);
		sum+=(c-48)*pow(2,i);
	}
	printf("ת��Ϊʮ�������ǣ�%d\n",sum);
	return 0;
}
