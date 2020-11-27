/* 任务1
有5个人坐在一起，问第5个人多少岁？他说比第4个人大2岁。
问第4个人岁数，他说比第3个人大2岁。
问第3个人，又说比第2人大两岁。
问第2个人，说比第1个人大两岁。
最后 问第1个人，他说是10岁。
请问第5个人多大？
*/

/*
任务 2
猴子第一天摘下N个桃子，当时就吃了一半，还不过瘾，就又多吃了一个。
第二天又将剩下的桃子吃掉一半，又多吃了一个。
以后每天都吃前一天剩下的一半零一个。
到第10天在想吃的时候就剩一个桃子了,
问第一天共摘下来多少个桃子？
并反向打印每天所剩桃子数。
*/

#include <stdio.h>

int Cmp[255] = {0};
/*冒泡程序*/
int MaoPao(int arr[], int Number)
{
  int i,j;
  for(i = 0; i<Number;i++)
  {
    for(j = i; j<Number; j++)
    {
      int Temp = 0;
      if(arr[j] < arr[i])
      {
        Temp = arr[i];
        arr[i] = arr[j];
        arr[j] = Temp;
      }
    }
  }
  for( i = 0; i< Number; i++)
    printf("%d\n", arr[i]);
  return;
}

int GetString()
{
  static Number = 0;
  int i = 0, Temp = 0;
  printf("Pleases Input CMP Numert: ");
  scanf("%d",&Number);
  for(i = 0; i<Number; i++)
  {
    printf("Please Input The %d Value is: ", i);
    scanf("%d",&Temp);
    Cmp[i] = Temp;
    printf("Input The %d Value is: %d\n", i,Cmp[i]);
  }

  return Number;


}
int GetPeachNum(int day)
{
  int Peach = 0; //桃子
  if(day == 10)
  {
    Peach = 1;
    printf("The %d day, And Peach Number is %d\n",day,Peach);
  }
  else
  {
    day++;
    Peach = (GetPeachNum(day)+1)*2;
    printf("The %d day, And Peach Number is %d\n",(day-1),Peach);
  }

  return Peach;
}
int GetYear(int Num)
{
  int year = 0;
  if(Num == 1)
  {
    year = 10;
    printf("The %d Person, Year is %d \n", Num,year);
  }
  else
  {
    Num --;
    year = GetYear(Num)+2;
    printf("The %d Person, Year is %d \n", (Num+1),year);
  }
  return year;
}

int main(){
  int Num = 0;
  printf("ok\n");
  GetYear(5);
  printf("\n\n");
  GetPeachNum(1);
  //printf("year = %d\n", GetYear(5));
  Num = GetString();
  MaoPao(Cmp, Num);
  system("pause");
  return 0;

}