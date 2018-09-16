//随机四则运算题
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Random_number(/*int miner,int maxer*/);//产生随机数
char Random_Osymbol();   //产生随机运算符号
int start(char i,int x,int y);//开始运算
void testing(int ans,char s);

int number[2]={0},ans=-1;char c,s=0;

int main()
{
    printf("welcome!\n");
    Random_number();
    start(Random_Osymbol(),number[0],number[1]);
    testing(ans,s);
    return 0;
}

void Random_number()//产生随机数
{
   // int shu;
    srand((unsigned)time(NULL));int i;
    //shu=miner+(maxer-miner)*rand()/(RAND_MAX+1);
   // return shu;
    for (i=0; i<2; i++)
    {
     number[i]=rand()%10001;  //产生0-10000的随机数
    // printf("%d ",number[i]);
    }
}
char Random_Osymbol()   //产生随机运算符号
{
    char ss[4]={'+','-','*','/'};
    srand((unsigned)time(NULL));
    return ss[rand()%4];
}
int start(char i,int x,int y)//开始运算
{
    int temp;
    switch(i)
    {
        case '+':printf("%d+%d=",x,y);s=1;break;
        case '-':
                {
                    if(x<y)
                    {
                        temp=x;x=y;y=temp;
                    }
                    printf("%d-%d=",x,y);};s=2;break;
        case '*':printf("%d*%d=",x,y);s=3;break;
        case '/':
                {
                    if(!y)
                    {
                        temp=x;x=y;y=temp;
                    }
                    printf("%d/%d=",x,y);};s=4;break;
    }
    scanf("%d",&ans);
    return ans;
}
void testing(int ans,char s)//查看运算结果是否正确
{
    switch(s)
    {
        case 1:{if(ans==(number[0]+number[1]))printf("the answer is right!\n");
                else printf("the right answer is:%d",number[0]+number[1]);};break;
        case 2:{if(ans==(number[0]-number[1]))printf("the answer is right!\n");
                else printf("the right answer is:%d",number[0]-number[1]);};break;
        case 3:{if(ans==(number[0]*number[1]))printf("the answer is right!\n");
                else printf("the right answer is:%d",number[0]*number[1]);};break;
        case 4:{if(ans==(number[0]/number[1]))printf("the answer is right!\n");
                else printf("the right answer is:%d",number[0]/number[1]);};break;
    }
}
