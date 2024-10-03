#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_NUM 10

typedef int status;
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct LNode{  //单链表（链式结构）结点的定义
      ElemType data;
      struct LNode *next;
    }LNode,*LinkList;
    
typedef struct{  //线性表的集合类型定义
     struct { char name[30];
               LinkList List;    
     } elem[10];
     int length;
}LISTS;
LISTS Lists;      //线性表集合的定义Lists    

status InitList(LinkList &L);
status DestroyList(LinkList &L);
status ClearList(LinkList &L);
status ListEmpty(LinkList L);
int ListLength(LinkList L);
status GetElem(LinkList L,int i,ElemType &e);
status LocateElem(LinkList L,ElemType e);
status PriorElem(LinkList L,ElemType e,ElemType &pre);
status NextElem(LinkList L,ElemType e,ElemType &next);
status ListInsert(LinkList &L,int i,ElemType e);
status ListDelete(LinkList &L,int i,ElemType &e);
status ListTraverse(LinkList L);
status SaveList(LinkList L,char FileName[]);
status LoadList(LinkList &L,char FileName[]);
status ReverseList(LinkList L);
status RemoveNthFromEnd(LinkList L,int n);
status Sortlist(LinkList L);

int main(void){
    char filename[30];
	int op=1;
    int i,n=1,len,i_num=1;
    LinkList L[MAX_NUM];
    for (i=0;i<MAX_NUM;i++)
	{
        L[i]=NULL;
	}
	ElemType e,pre,next;
while(op){
	system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. InitList       11. ListDelete\n");
	printf("    	  2. DertroyList    12. ListTraverse\n");
	printf("    	  3. ClearList      13. ReverseList\n");
	printf("    	  4. ListEmpty      14. RemoveNthFromEnd\n");
	printf("    	  5. ListLength     15. Sortlist\n");
	printf("    	  6. GetElem        16. SaveList\n");
	printf("    	  7. LocateElem     17. LoadList\n");
	printf("          8. PriorElem      18. ChooseList\n");     
	printf("          9. NextElem       \n");  
	printf("         10. ListInsert     \n");  
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~12]:");
	scanf("%d",&op);
    switch(op){	
	   case 1:
         //初始化线性表
		 if(InitList(L[i_num])==OK)
         {

             printf("请输入要保存的线性表名称\n");
             scanf("%s", filename);
             printf("线性表创建成功\n");
         }
		     else printf("线性表创建失败！\n");
		 getchar();getchar();
		 break;

	   case 2:
		 //毁线性表
		 if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
		 if(DestroyList(L[i_num])==OK)
         {
             printf("销毁线性表成功!\n");
         }
         else printf("销毁线性表失败！\n");
		 getchar();getchar();
		 break;

	   case 3:
		 //清空线性表
		 if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
         if(ClearList(L[i_num])==OK)
         {
            printf("线性表重置成功！\n");
         }
         else printf("线性表重置失败！\n");
		 getchar();getchar();
		 break;

	   case 4:
		 //判断是否为空
		 if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
         if(ListEmpty(L[i_num]))
         {
             printf("线性表为空！\n");
         }
         else printf("线性表不是空表！\n");
		 getchar();getchar();
		 break;

	   case 5:
	       //得到线性表长度
	       if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
         printf("线性表表长为%d\n",ListLength(L[i_num]));
		 getchar();getchar();
		 break;

	   case 6:
		 //得到某个元素
	       if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
		 printf("请输入要取结点的位置：\n");
		 scanf("%d",&i);
		 if(GetElem(L[i_num],i,e)==OK)
		 printf("第%d个结点的元素是：%d\n",i,e);
		 else  printf("输入位置错误！\n");
		 getchar();getchar();
		 break;

	   case 7:
       //查找e元素在线性表中的位置
		 if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
		 printf("请输入数据元素值：\n");
		 scanf("%d",&e);
         i = LocateElem(L[i_num],e);
		 if(i!=ERROR){
            printf("%d元素第一次出现位于第%d个位置！\n",e,i);
         }
		 else  printf("该元素不存在!\n");
		 getchar();getchar();
		 break;

	   case 8:
	       //求出前驱结点
	       if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
		 printf("请输入数据元素：\n");
		 scanf("%d",&e);
		 PriorElem(L[i_num],e,pre);
		 if(PriorElem(L[i_num],e,pre)==OK)
		 printf("其前驱元素为：%d\n",pre);
		 else if(PriorElem(L[i_num],e,pre)==OVERFLOW)
		 printf("顺序表中没有该元素！\n");
		 else  printf("其不存在前驱元素！\n");
		 getchar();getchar();
		 break;


	   case 9:
	       //求出后置节点
	       if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
         printf("请输入数据元素：\n");
		 scanf("%d",&e);
		 if(NextElem(L[i_num],e,next)==OK)
		 printf("其后继元素为：%d\n",next);
		 else if(NextElem(L[i_num],e,pre)==ERROR)
		 printf("顺序表中没有该元素！\n");
		 else
            {printf("其不存在后继元素！\n");}
		 getchar();getchar();
		 break;

	   case 10:
	       //插入元素
	       if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
		 printf("请输入您要插入的数据元素和位置，用空格隔开：\n");
		 scanf("%d %d",&e,&i);
		 if(ListInsert(L[i_num],i,e)==OK)
		 printf("插入数据元素成功！\n");
		 else
		 printf("插入数据元素失败！\n");
		 getchar();getchar();
		 break;

	   case 11:
	       //删除元素
	       if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
		 printf("请输入您要删除的数据元素的位置：\n");
		 scanf("%d",&i);
		 if(ListDelete(L[i_num],i,e)==OK)
		 printf("删除数据元素成功！\n");
		 else
		 printf("删除数据元素失败！\n");
		 getchar();getchar();
		 break;

	   case 12:
	       //遍历线性表中的元素
	       if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
         if(ListEmpty(L[i_num])) {
            printf("线性表是空表！\n");
            getchar();getchar();
		    break;
         }
         ListTraverse(L[i_num]);
		 getchar();getchar();
		 break;

       case 13:
         //反转线性表
         if(L[i_num]==NULL){
            printf("线性表不存在！");
            getchar();getchar();
		    break;
         }
         if(ReverseList(L[i_num])==OK){
            printf("反转完成");
         }
         getchar();getchar();
		 break;

       case 14:
       //删除倒数第n个元素
       if(L[i_num]==NULL){
        printf("线性表是空表");
        getchar();getchar();
		 break;
       }
       len=ListLength(L[i_num]);
       printf("请输入要删除的倒数第几个位置\n");
       scanf("%d" ,&i);
       if(i < 1 || i > len){
        printf("要删除的位置不合法!");
        getchar();getchar();
		 break;
       }
       RemoveNthFromEnd(L[i_num] ,i);
       printf("删除成功！");
       getchar();getchar();
		break;

       case 15:
       //线性表排序
       if(L[i_num]==NULL){
        printf("线性表是空表！");
        getchar();getchar();
		break;
       }
       Sortlist(L[i_num]);
       printf("排序成功");
        getchar();getchar();
		break;

	  case 16:
           //保存文件
           if(L[i_num] == NULL)
         {
             printf("线性表不存在!\n");
             getchar();getchar();
             break;
         }
         if(SaveList(L[i_num], filename)==OK){
            printf("文件保存成功!文件名为%s\n",filename);
         }
		 getchar();getchar();
         break;

	   case 17:
        //加载文件，需要输入需要加载的名称
        if((L[i_num]!=NULL)){
            printf("顺序表已存在，无法加载！");
        }else{
            printf("请输入要加载的文件名:\n ");
		    scanf("%s", filename);
		    if(LoadList(L[i_num], filename)==OK){
                printf("文件加载成功\n");
		    }
        }
		getchar();getchar();
         break;

	   case 18:
           //选择在哪个表进行操作
           printf("请输入要在第几个表操作:\n ");
           printf("*只支持在%d个顺序表上操作*\n",MAX_NUM);
		   scanf("%d",&i_num);
		   printf("正在对第%d个表进行操作\n",i_num);
		 if((i_num<1)||(i_num>10))
		 {
		 	printf("请选择正确范围！\n");
		 	i_num=1;
		 }
		 getchar(); getchar();
         break;

	   case 0:
         break;
	}//end of switch
	}//end of while
	printf("\t\t欢迎再次使用本系统！\n");
}//end of main()
status InitList(LinkList &L)
// 1.线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if(L==NULL){                                  //如果线性表不存在
        L=(LinkList)malloc(sizeof(LNode));
        L->next=NULL;
        return OK;
    }
    else return INFEASIBLE;
}

status DestroyList(LinkList &L)
// 2.如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if(L) {//如果线性表L存在
        LinkList p;
        while(L){
            p=L;                //将L赋给p，依次释放
            L=L->next;
            free(p);
        }
        return OK;
    }
    else return INFEASIBLE;
}

status ClearList(LinkList &L)
// 3.如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList p,q;
    p=L->next;
    while(p){
        q=p->next;       
        free(p);      //删除元素
        p=q;
    }
    L->next=NULL;     //表尾指向空
    return OK;
}

status ListEmpty(LinkList L)
// 4.如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;  //L不存在
    if(!L->next) return TRUE;  //L为空
    else return FALSE;
}

int ListLength(LinkList L)
// 5.如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList p;
    ElemType cnt=0;
    p=L->next;
    while(p){
        p=p->next;
        cnt++;       //计数
    }
    return cnt;
}

status GetElem(LinkList L,int i,ElemType &e)
// 6.如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList p;
    ElemType j=1;
    p=L->next;
    while(p){
        //printf("%d %d\n",p->data,j);
        p=p->next;
        j++;
        if(j==i){      //获取第i个元素
            e=p->data;
            return OK;
        }
    }
    return ERROR;      //i<1或者i超过线性表L的长度
}

status LocateElem(LinkList L,ElemType e)
// 7.如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList p;
    int j=1;
    p=L->next;
    while(p){
        if(p->data==e) return j;     //查找到e，返回位置序号
        p=p->next;
        j++;
    }
    return ERROR;                   //未找到e
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 8.如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList p,q;
    p=L;
    while(p->next){
        q=p->next;               //q是p的后继
        if(q->data==e && p!=L){  //q指向元素e，则p为e的前驱
            pre=p->data;
            return OK;     
        } 
        p=q;
    }
    return ERROR;                     //未找到e的前驱
}

status NextElem(LinkList L,ElemType e,ElemType &next)
// 9.如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList p,q;
    p=L;
    while(p->next){
        q=p->next;                  //q是p的后继
        if(p->data==e && q!=NULL){  //p指向元素e，则q为e的后继
            next=q->data;
            return OK;     
        } 
        p=q;
    }
    return ERROR;                     //未找到e的后继
}

status ListInsert(LinkList &L,int i,ElemType e)
// 10.如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList p,q;
    ElemType j=0;
    p=L;
    while(p){
        if(j==i-1){                            //第i-1个结点
            q=(LinkList)malloc(sizeof(LNode)); //生成新结点
            q->data=e;
            q->next=p->next;
            p->next=q;
            return OK;
        }
        p=p->next;
        j++;
    }
    return ERROR;      //i<1或者i超过线性表L的长度
}

status ListDelete(LinkList &L,int i,ElemType &e)
// 11.如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList p,q;
    ElemType j=0;
    p=L;
    while(p->next){
        if(j==i-1){                            //第i-1个结点
            q=p->next;                         //p为第i个结点
            e=q->data;                         //将第i个元素保存在e中
            p->next=q->next;                  
            free(q);                           //释放结点
            return OK;
        }
        p=p->next;
        j++;
    }
    return ERROR;      //i<1或者i超过线性表L的长度
}

status ListTraverse(LinkList L)
// 12.如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if(!L) return INFEASIBLE;
    LinkList p;
    p=L->next;
    if(!p) printf("空线性表");
    while(p){
        printf("%d",p->data);
        if(p->next) printf(" ");
        p=p->next;
    }
    return ERROR;                   //未找到e
}

status SaveList(LinkList L,char FileName[])
// 13.如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if(!L) return INFEASIBLE;
    FILE *fp;
    LinkList p=L->next;
    fp=fopen(FileName,"w");     //以只读方式打开文件
    while(p){
        if(p->next) fprintf(fp,"%d ",p->data);
        else fprintf(fp,"%d",p->data);
        p=p->next;
    }
        fclose(fp);
        return OK;

    /********** End 1 **********/
}

status LoadList(LinkList &L,char FileName[])
// 14.如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    if(L) return INFEASIBLE;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    LinkList p=L,q;
    int x;
    FILE *fp;
    fp=fopen(FileName,"r");
    while((fscanf(fp, "%d", &x))!=EOF){    //从文件中循环读取数据
        q=(LinkList)malloc(sizeof(LNode)); //生成新结点并分配内存
        q->data=x;                         //将读取的数据赋给q
        p->next=q;
        p=p->next;
    }
    p->next=NULL;                          //表尾,将p的next指针置空
    fclose(fp);
    return OK;;
}

status ReverseList(LinkList L)
{
    LinkList p ,prior,post;
    if(L==NULL ||ListEmpty(L)){
        return INFEASIBLE;
    }
    if(ListLength(L)==1){
        return OK;
    }
    prior=L->next;
    p=prior->next;
    post=p->next;
    while(1){
        p->next=prior;
        if(post==NULL){
            break;
        }
        prior=p;
        p = post;
        post =post->next;
    } 
    L->next->next=NULL;
    L->next=p;
    return OK;
}

status RemoveNthFromEnd(LinkList L,int n)
{
    int temp;
    int length=ListLength(L);
    if(L==NULL||L->next==NULL){
        return INFEASIBLE;
    }
    if(n < 1 || n > length){
        return ERROR;
    }
    ListDelete(L, length+1-n, temp);
    return OK;
}


status Sortlist(LinkList L)
{
	int t;
    if(L==NULL){
        return INFEASIBLE;
    }
    if(L->next==NULL){
        return OK;
    }
    LinkList ptr,done;
        for(done=NULL;L->next->next!=done;done=ptr){
            for(ptr =L->next ;ptr->next!=done ;){
                if(ptr->data > ptr->next->data){
                    t = ptr->data;
                    ptr->data=ptr->next->data;
                    ptr->next->data=t;
                }
                ptr = ptr->next;
            }
        }
    
    return OK;
}


