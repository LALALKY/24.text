#include<stdio.h> 
char op[4]={'+','-','*','/'};
float cal(float x,float y,int op)
{
	switch(op)
	{
		case 0: return x+y;
		case 1: return x-y;
		case 2: return x*y;
		case 3: return x/y;
	}
 } 
 
//A (OP1) B (OP2) C (OP3) D  OP为运算符 
float structure_1(float i,float j,float k,float t,int op1,int op2,int op3)
{
	float r1,r2,r3;
	r1 = cal(i,j,op1);
    r2 = cal(r1,k,op2);
    r3 = cal(r2,t,op3);
    return r3;
}//对应 ((Aop1B)op2C)op3D  

float structure_2(float i,float j,float k,float t,int op1,int op2,int op3)
{
   float r1,r2,r3;
   r1 = cal(j,k,op2);
   r2 = cal(i,r1,op1);
   r3 = cal(r2,t,op3);
   return r3;
}//对应  (Aop1(Bop2C))op3D

float structure_3(float i,float j,float k,float t,int op1,int op2,int op3)
{
   float r1,r2,r3 ;
   r1 = cal(k,t,op3);
   r2 = cal(j,r1,op2);
   r3 = cal(i,r2,op1);
   return r3;
}//对应 Aop1(Bop2(Cop3D))
 
float structure_4(float i,float j,float k,float t,
int op1,int op2,int op3)
{ 
   float r1,r2,r3;
   r1 = cal(j,k,op2);
   r2 = cal(r1,t,op3);
   r3 = cal(i,r2,op1);
   return r3;
}//对应 Aop1((Bop2C)op3D)
 
 float structure_5(float i,float j,float k,float t,
int op1,int op2,int op3)
{
   float r1,r2,r3 ;
   r1 = cal(i,j,op1);
   r2 = cal(k,t,op3);
   r3 = cal(r1,r2,op2);
   return r3;
}//对应 (Aop1B)op2(Cop3D)

get24(int i,int j,int k,int t)
{
	int op1,op2,op3;
     int flag=0;
     for(op1=1;op1<=4;op1++)
     {
         for(op2=1;op2<=4;op2++)
         {
             for(op3=1;op3<=4;op3++)
             {
				 if(structure_1(i,j,k,t,op1,op2,op3)==24)
				 {
					 printf("((%d%c%d)%c%d)%c%d=24\n",i,op[op1],j,op[op2],k,op[op3],t);
					 flag = 1;
				 }
				 if(structure_2(i,j,k,t,op1,op2,op3)==24)
				 {
					 printf("(%d%c(%d%c%d))%c%d=24\n",i,op[op1],j,op[op2],k,op[op3],t);
					 flag = 1;
				 }
				 if(structure_3(i,j,k,t,op1,op2,op3)==24)
				 {
					 printf("%d%c(%d%c(%d%c%d))=24\n",i,op[op1],j,op[op2],k,op[op3],t);
					 flag = 1;
				 }
				 if(structure_4(i,j,k,t,op1,op2,op3)==24)
				 {
					 printf("%d%c((%d%c%d)%c%d)=24\n",i,op[op1],j,op[op2],k,op[op3],t);
					 flag = 1;
				 }
				 if(structure_5(i,j,k,t,op1,op2,op3)==24)
				 {
					 printf("(%d%c%d)%c(%d%c%d)=24\n",i,op[op1],j,op[op2],k,op[op3],t);
					 flag = 1;
				 }
			 }
	     }
	 }
			 return flag;
}
int main()
{
	char e;
	float a,b,c,d;
    int n[4];
    int i;
loop:    printf("请依次输入抽到的牌\n(A为1，J为11，Q为12，K为13)\n");
    for(i=0;i<4;i++)
    {
	    scanf("%d",&n[i]);
//	    printf("n%d为%d",i,n[i]);
	    while (n[i]<=0&&n[i]>13)
	    {
		    printf("请输入正确的牌\n");
		    scanf("%d",&n[i]);
	    }
    }
    a=n[0];b=n[1];c=n[2];d=n[3];
//    printf("%d",n[1]);
    get24(a,b,c,d);
    printf("请问您是否继续计算(是输入y，否输入任意字母)");
	scanf("%c",&e);
	if(e=='y')
	goto loop;
	else
	return 0;
//    else
//    printf("对不起，这四个数无法组成24点");//1-20内整数都可以组成24点 
}
