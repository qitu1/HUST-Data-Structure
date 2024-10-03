/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1 
#define OVERFLOW -2
#define MAX_NUM 10
typedef int status; 
typedef int ElemType; //数据元素类型定义

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{  //顺序表（顺序结构）的定义
	ElemType * elem;
	int length;
	int listsize;
}SqList;

    //线性表集合的定义Lists
/*-----page 19 on textbook ---------*/
status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList& L);
status ListEmpty(SqList L);
status ListLength(SqList L);
status GetElem(SqList L,int i,ElemType &e);
status LocateElem(SqList L,ElemType e); 
status PriorElem(SqList L,ElemType cur,ElemType &pre);
status NextElem(SqList L,ElemType cur,ElemType &next);
status ListInsert(SqList& L,int i,ElemType e);
status ListDelete(SqList& L,int i,ElemType& e); 
status ListTraverse(SqList L);
status SaveList(SqList &L,char FileName[]);
status LoadList(SqList &L,char FileName[]);
status MaxSubArray(SqList& L);
status SubArrayNum(SqList& L,ElemType k);
status SortList(SqList& L);
int main(void){
	int i,pre,next;
	int i_num=1;
	SqList L[MAX_NUM+1];
    for(i=0;i<MAX_NUM+1;i++)
    {
        L[i].elem = NULL;
        L[i].listsize = 0;
        L[i].length = 0;
    }
	int op=1;
    int n,e;
    char filename[30];
while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. InitList       11. ListDelete\n");
	printf("    	  2. DertroyList    12. ListTraverse\n");
	printf("    	  3. ClearList      13. SaveList\n");
	printf("    	  4. ListEmpty      14. LoadList\n");
	printf("    	  5. ListLength     15. LocateList\n");
	printf("    	  6. GetElem        16. MaxSubArray\n");
	printf("    	  7. LocateElem     17. SubArrayNum\n");
	printf("          8. PriorElem      18. SortList\n");     
	printf("          9. NextElem       \n");  
	printf("         10. ListInsert     \n");  
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~18]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
	   	 printf("请输入要创建的线性表名称：\n");
	   	 scanf("%s",filename);
		 if(InitList(L[i_num])==OK) {
		 	printf("线性表创建成功！\n");
		 	printf("请输入元素，用空格隔开，以0结束！\n");
	        for(int i=0;i<L[i_num].listsize;i++){
	        	int num;
				scanf("%d",&num);
				if(num==0) break;
				else L[i_num].elem[L[i_num].length++]=num; 
			}
		 }
		 else printf("线性表创建失败！\n");
		 getchar();getchar();
		 break;
	   case 2:
	   	if(L[i_num].elem==NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
		 if(DestroyList(L[i_num])==OK) 
		     printf("线性表销毁成功！\n");
		     else printf("线性表销毁失败！\n");     
		 getchar();getchar();
		 break;
	   case 3:
		 if(ClearList(L[i_num])==OK)
		     printf("线性表清空成功！\n");
		     else printf("线性表清空失败！\n");      
		 getchar();getchar();
		 break;
	   case 4:
	   	 if(ListEmpty(L[i_num])==TRUE) 
			printf("线性表为空！\n");
		 else if(ListEmpty(L[i_num])==INFEASIBLE) 
			printf("线性表不存在！\n");
		 else printf("线性表不为空！\n");         
		 getchar();getchar();
		 break;
	   case 5:
	   	 n=ListLength(L[i_num]);
		 printf("线性表长度为%d",n);
		 getchar();getchar();
		 break;
	   case 6:
	   	 printf("请输入你要获取的元素序号：\n");
	     scanf("%d",&i);
	   	 GetElem(L[i_num],i,e);  
		 getchar();getchar();
		 break;
	   case 7:
	   	printf("请输入你要查找的元素：\n");
	    scanf("%d",&e);
	   	LocateElem(L[i_num],e); 
		 getchar();getchar();
		 break;
	   case 8:
	   	 printf("请输入要获取前驱的元素：\n");
	     scanf("%d",&e);
	   	 PriorElem(L[i_num],e,pre);   
		 getchar();getchar();
		 break;
	   case 9:
	     printf("请输入要获取后继的元素：\n");
	     scanf("%d",&e);
	   	 NextElem(L[i_num],e,next);       
		 getchar();getchar();
		 break;
	   case 10:
	   	 printf("请输入要插入的元素和位置,用空格隔开\n");
	   	 scanf("%d %d",&e,&i);
	   	 if(ListInsert(L[i_num],i,e)==OK) printf("插入成功\n"); 
		 getchar();getchar();
		 break;
	   case 11:
	   	 printf("请输入要删除的元素序号\n"); 
		 scanf("%d",&i);
		 ListDelete(L[i_num],i,e);      
		 getchar();getchar();
		 break;
	   case 12: 
	   	 ListTraverse(L[i_num]);  
		 getchar();getchar();
		 break;
	   case 13: 
	     if(SaveList(L[i_num], filename)==OK){
            printf("文件保存成功\n文件名为%s\n",filename);
         }
		getchar();getchar();
         break;
	   case 14:
	   	 if(L[i_num].elem!=NULL){
            printf("线性表已存在！无法加载！");
            getchar();getchar();
            break;
         }
	   	 printf("请输入要加载的文件名:\n ");
		 scanf("%s", filename);
		 if(LoadList(L[i_num], filename)==OK){
                printf("文件加载成功\n");
		 }
		else{
                printf("文件加载失败！");
         }
         break;
       case 15:
	   	 printf("请输入要在第几个表操作:\n ");
           printf("*只支持在%d个顺序表上操作*\n",MAX_NUM);
		   scanf("%d",&i_num);
           	 if((i_num<1)||(i_num>MAX_NUM))
		    {
		 	printf("请选择正确范围！默认对第一个线性表进行操作\n");
		 	i_num=1;
		    }
		   printf("正在对第%d个表进行操作\n",i_num);
           getchar(); getchar();
         break;
	   case 16:
	   	 MaxSubArray(L[i_num]);
		 getchar();getchar();
		 break;
	   case 17:
	   	 printf("请输入你要求的子数组的和k:\n");
	   	 scanf("%d",&i);
	   	 SubArrayNum(L[i_num],i);	
		 getchar();getchar();
		 break;
	   case 18:
	   	 SortList(L[i_num]);
		 getchar();getchar();
		 break;
	case 0:
         break;
    return 0;
	}//end of switch
  }//end of while
printf("欢迎下次再使用本系统！\n");
}//end of main()
/*--------page 23 on textbook --------------------*/
status InitList(SqList& L){
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
if(!L.elem) exit(OVERFLOW);
	L.length=0;
L.listsize=LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList& L)
// 2.如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
	if(L.elem) {//如果线性表L存在
        free(L.elem);  //释放数据元素空间
        L.elem = NULL; //返回未初始化状态
        L.length = 0;
        L.listsize = 0;
        return OK;
    }
    else return INFEASIBLE;
}

status ClearList(SqList& L)
// 3.如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
     if(L.elem==NULL){
        return INFEASIBLE;
    }
    L.length=0;
    free(L.elem);
    return OK;
}

status ListEmpty(SqList L)
// 4.如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem==NULL){
        return INFEASIBLE;
    } 
    if(L.length==0){
        return TRUE;
    }
    return FALSE;
}

status ListLength(SqList L) 
// 5.如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if(L.elem) return L.length; //返回表长
    else return INFEASIBLE;
} 

status GetElem(SqList L,int i,ElemType &e) 
// 6.如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
	if(!L.elem){
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
    if(i<1||i>L.length) 
	{
		printf("输入的i值不规范!\n");
		return ERROR;
	}
    e=L.elem[i-1];
    printf("该线性表的第%d个元素是%d\n",i,e);
    return OK;
}

int LocateElem(SqList L,ElemType e)
// 7.如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    if(L.elem){
        int i;
        //printf("%d\n",L.elem[0]);
        for(i=1;i<=L.length;i++){//遍历顺序表，查找指定元素e
            if (L.elem[i-1] == e) {
            	printf("元素%d在该线性表中第一次出现的位置序号是%d\n",e,i);
            	return i;//查找成功，则返回元素逻辑序号i
			}
        }
        printf("元素%d在该线性表中不存在\n",e);
        return 0;//没有找到指定的元素e，查找失败，返回0
    }
    else {
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// 8.如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem){
        int i;
        for(i=1;i<L.length;i++){//从第二个元素开始遍历线性表L
            if(L.elem[i] == e){ //若查找到e元素
                pre=L.elem[i-1];//获取线性表L中元素e的前驱，保存在pre中
                printf("该线性表中元素%d的前驱元素是%d\n",e,pre);
                return OK;
            }
        }
        printf("无法找到元素%d的前驱\n",e);
        return ERROR;//没有前驱，返回ERROR
    }
    else {
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
}

status NextElem(SqList L,ElemType e,ElemType &next)
// 9.如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    
	if (L.elem){
        int i;
        for(i=0;i<L.length-1;i++){//遍历线性表L至倒数第二个元素
            if(L.elem[i] == e){ //若查找到e元素
                next=L.elem[i+1];//获取线性表L中元素e的后继，保存在next中
                printf("该线性表中元素%d的后继元素是%d\n",e,next);
                return OK;
            }
        }
        printf("无法找到元素%d的后继\n",e);
        return ERROR;//没有前驱，返回ERROR
    }
    else {
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
}

status ListInsert(SqList &L,int i,ElemType e)
// 10.如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    //i的合法值为1<=i<=L.length+1
    if(i<1 || i>L.length+1) {               //i值不合法
    	printf("输入的i值不规范!\n");
		return ERROR;
	}
    if(L.elem){
        if(L.length>=L.listsize){           //当前存储空间已满，增加分配
            int *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
            if(!newbase) exit(OVERFLOW);    //存储分配失败
            L.elem = newbase;               //新基址
            L.listsize += LISTINCREMENT;    //增加存储容量
        }
        int *q = &(L.elem[i-1]);    //q为插入位置
        for(int *p = &(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p;
        //插入位置及之后的元素后移
        *q=e;           //插入e
        ++L.length;     //表长加一
        return OK;
    }
    else {
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
}

status ListDelete(SqList &L,int i,ElemType &e)
// 11.如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    
	if(L.elem){
		if(i<1||i>L.length){
		printf("删除位置不规范\n");
		return ERROR;
		}
        int *q = &(L.elem[i-1]);    //q为被删除元素的位置
        e=*q;                       //将第i个元素保存在e中
        ++q;           
        for(int *p = &(L.elem[L.length-1]);p>=q;++q) 
            *(q-1)=*q;
        //被删除元素位置及之后的元素前移
        --L.length;     //表长减一
        printf("删除成功,删除的是%d\n",e);
        return OK;
    }
    else {
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
}

status ListTraverse(SqList L)
//12.如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
	if (L.elem){
        int i;
        if(L.length == 0){          //表长为0，为空线性表
            printf("空线性表");
            return 0;
        }
        for(i=0;i<L.length;i++){    //遍历线性表L
            if(i!=L.length-1)
                printf("%d ",L.elem[i]);
            else printf("%d",L.elem[i]);
        }
        return OK;
    }
    else {
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
}


status  SaveList(SqList &L,char FileName[])
// 13.如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    if(L.elem){
        FILE *fp;
        fp=fopen(FileName,"wb");     //以只读方式打开文件
        if(fp==NULL){               //文件为空
            printf("文件为空!");
            exit (-1);
        }
        for(int i=0;i<L.length;i++){    
            fprintf(fp,"%d " ,L.elem[i]);   //将线性表L的的元素写到文件中
        }
        fclose(fp);
        printf("写入成功！");
        return OK;
    }
    else {
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
}
status  LoadList(SqList &L,char FileName[])
// 14.如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    FILE* p;
    int c,j=0;
    ElemType* newbase;

    if(L.elem){
        return INFEASIBLE;
    }
        L.elem=(ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
        L.length=0;
        L.listsize=LIST_INIT_SIZE;
        p=fopen(FileName ,"rb");
        if(p==NULL){
            printf("文件为空!");
            exit (-1);
        }
       while((fscanf(p,"%d",&c))!=EOF)   {
            if(L.length>=L.listsize){
                newbase=(ElemType*)realloc(L.elem,sizeof(ElemType)*(L.listsize+LISTINCREMENT));
                if(newbase==NULL){
                    return OVERFLOW;
                }
                L.elem=newbase;
                L.listsize+=LISTINCREMENT;
            }
            L.elem[j++]=c;
            L.length++;
        }
    fclose(p);
    return OK;
}


status MaxSubArray(SqList& L){
	int sum,max=0;
	if(!L.elem){
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
	for(int i=0;i<L.length;i++){
		sum=0;
		for(int j=0;j<L.length-i;j++){
			sum+=L.elem[i+j];
			if(sum>max) max=sum;
		}
	}
	printf("该线性表的连续子数组的最大和为%d\n",max);
	return max; 
}

status SubArrayNum(SqList& L,ElemType k){
	if(!L.elem){
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
	int sum,count=0; 
	for(int i=0;i<L.length;i++){
		sum=0;
		for(int j=0;j<L.length-i;j++){
			sum+=L.elem[i+j];
			if(sum==k) count++;
		}
	}
	printf("该线性表中和为%d的连续子数组个数为%d\n",k,count);
	return count;
}

status SortList(SqList& L){
	if(!L.elem){
		printf("线性表不存在!\n");
		return INFEASIBLE;
	}
	int i,j,temp;
	for(i=0;i<L.length-1;i++){
		for(j=i+1;j<L.length;j++)
		{
			if(L.elem[i]>L.elem[j]){
				temp=L.elem[i];
				L.elem[i]=L.elem[j];
				L.elem[j]=temp;
			}
		}
	}
	printf("排序成功！\n");
	return OK;
}


