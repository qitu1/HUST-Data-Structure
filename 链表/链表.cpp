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
typedef int ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct LNode{  //��������ʽ�ṹ�����Ķ���
      ElemType data;
      struct LNode *next;
    }LNode,*LinkList;
    
typedef struct{  //���Ա�ļ������Ͷ���
     struct { char name[30];
               LinkList List;    
     } elem[10];
     int length;
}LISTS;
LISTS Lists;      //���Ա��ϵĶ���Lists    

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
	printf("    ��ѡ����Ĳ���[0~12]:");
	scanf("%d",&op);
    switch(op){	
	   case 1:
         //��ʼ�����Ա�
		 if(InitList(L[i_num])==OK)
         {

             printf("������Ҫ��������Ա�����\n");
             scanf("%s", filename);
             printf("���Ա����ɹ�\n");
         }
		     else printf("���Ա���ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 2:
		 //�����Ա�
		 if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 if(DestroyList(L[i_num])==OK)
         {
             printf("�������Ա�ɹ�!\n");
         }
         else printf("�������Ա�ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 3:
		 //������Ա�
		 if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         if(ClearList(L[i_num])==OK)
         {
            printf("���Ա����óɹ���\n");
         }
         else printf("���Ա�����ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 4:
		 //�ж��Ƿ�Ϊ��
		 if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         if(ListEmpty(L[i_num]))
         {
             printf("���Ա�Ϊ�գ�\n");
         }
         else printf("���Ա��ǿձ�\n");
		 getchar();getchar();
		 break;

	   case 5:
	       //�õ����Ա���
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         printf("���Ա��Ϊ%d\n",ListLength(L[i_num]));
		 getchar();getchar();
		 break;

	   case 6:
		 //�õ�ĳ��Ԫ��
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("������Ҫȡ����λ�ã�\n");
		 scanf("%d",&i);
		 if(GetElem(L[i_num],i,e)==OK)
		 printf("��%d������Ԫ���ǣ�%d\n",i,e);
		 else  printf("����λ�ô���\n");
		 getchar();getchar();
		 break;

	   case 7:
       //����eԪ�������Ա��е�λ��
		 if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("����������Ԫ��ֵ��\n");
		 scanf("%d",&e);
         i = LocateElem(L[i_num],e);
		 if(i!=ERROR){
            printf("%dԪ�ص�һ�γ���λ�ڵ�%d��λ�ã�\n",e,i);
         }
		 else  printf("��Ԫ�ز�����!\n");
		 getchar();getchar();
		 break;

	   case 8:
	       //���ǰ�����
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("����������Ԫ�أ�\n");
		 scanf("%d",&e);
		 PriorElem(L[i_num],e,pre);
		 if(PriorElem(L[i_num],e,pre)==OK)
		 printf("��ǰ��Ԫ��Ϊ��%d\n",pre);
		 else if(PriorElem(L[i_num],e,pre)==OVERFLOW)
		 printf("˳�����û�и�Ԫ�أ�\n");
		 else  printf("�䲻����ǰ��Ԫ�أ�\n");
		 getchar();getchar();
		 break;


	   case 9:
	       //������ýڵ�
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         printf("����������Ԫ�أ�\n");
		 scanf("%d",&e);
		 if(NextElem(L[i_num],e,next)==OK)
		 printf("����Ԫ��Ϊ��%d\n",next);
		 else if(NextElem(L[i_num],e,pre)==ERROR)
		 printf("˳�����û�и�Ԫ�أ�\n");
		 else
            {printf("�䲻���ں��Ԫ�أ�\n");}
		 getchar();getchar();
		 break;

	   case 10:
	       //����Ԫ��
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("��������Ҫ���������Ԫ�غ�λ�ã��ÿո������\n");
		 scanf("%d %d",&e,&i);
		 if(ListInsert(L[i_num],i,e)==OK)
		 printf("��������Ԫ�سɹ���\n");
		 else
		 printf("��������Ԫ��ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 11:
	       //ɾ��Ԫ��
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 printf("��������Ҫɾ��������Ԫ�ص�λ�ã�\n");
		 scanf("%d",&i);
		 if(ListDelete(L[i_num],i,e)==OK)
		 printf("ɾ������Ԫ�سɹ���\n");
		 else
		 printf("ɾ������Ԫ��ʧ�ܣ�\n");
		 getchar();getchar();
		 break;

	   case 12:
	       //�������Ա��е�Ԫ��
	       if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         if(ListEmpty(L[i_num])) {
            printf("���Ա��ǿձ�\n");
            getchar();getchar();
		    break;
         }
         ListTraverse(L[i_num]);
		 getchar();getchar();
		 break;

       case 13:
         //��ת���Ա�
         if(L[i_num]==NULL){
            printf("���Ա����ڣ�");
            getchar();getchar();
		    break;
         }
         if(ReverseList(L[i_num])==OK){
            printf("��ת���");
         }
         getchar();getchar();
		 break;

       case 14:
       //ɾ��������n��Ԫ��
       if(L[i_num]==NULL){
        printf("���Ա��ǿձ�");
        getchar();getchar();
		 break;
       }
       len=ListLength(L[i_num]);
       printf("������Ҫɾ���ĵ����ڼ���λ��\n");
       scanf("%d" ,&i);
       if(i < 1 || i > len){
        printf("Ҫɾ����λ�ò��Ϸ�!");
        getchar();getchar();
		 break;
       }
       RemoveNthFromEnd(L[i_num] ,i);
       printf("ɾ���ɹ���");
       getchar();getchar();
		break;

       case 15:
       //���Ա�����
       if(L[i_num]==NULL){
        printf("���Ա��ǿձ�");
        getchar();getchar();
		break;
       }
       Sortlist(L[i_num]);
       printf("����ɹ�");
        getchar();getchar();
		break;

	  case 16:
           //�����ļ�
           if(L[i_num] == NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
         if(SaveList(L[i_num], filename)==OK){
            printf("�ļ�����ɹ�!�ļ���Ϊ%s\n",filename);
         }
		 getchar();getchar();
         break;

	   case 17:
        //�����ļ�����Ҫ������Ҫ���ص�����
        if((L[i_num]!=NULL)){
            printf("˳����Ѵ��ڣ��޷����أ�");
        }else{
            printf("������Ҫ���ص��ļ���:\n ");
		    scanf("%s", filename);
		    if(LoadList(L[i_num], filename)==OK){
                printf("�ļ����سɹ�\n");
		    }
        }
		getchar();getchar();
         break;

	   case 18:
           //ѡ�����ĸ�����в���
           printf("������Ҫ�ڵڼ��������:\n ");
           printf("*ֻ֧����%d��˳����ϲ���*\n",MAX_NUM);
		   scanf("%d",&i_num);
		   printf("���ڶԵ�%d������в���\n",i_num);
		 if((i_num<1)||(i_num>10))
		 {
		 	printf("��ѡ����ȷ��Χ��\n");
		 	i_num=1;
		 }
		 getchar(); getchar();
         break;

	   case 0:
         break;
	}//end of switch
	}//end of while
	printf("\t\t��ӭ�ٴ�ʹ�ñ�ϵͳ��\n");
}//end of main()
status InitList(LinkList &L)
// 1.���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    if(L==NULL){                                  //������Ա�����
        L=(LinkList)malloc(sizeof(LNode));
        L->next=NULL;
        return OK;
    }
    else return INFEASIBLE;
}

status DestroyList(LinkList &L)
// 2.������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    if(L) {//������Ա�L����
        LinkList p;
        while(L){
            p=L;                //��L����p�������ͷ�
            L=L->next;
            free(p);
        }
        return OK;
    }
    else return INFEASIBLE;
}

status ClearList(LinkList &L)
// 3.������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    LinkList p,q;
    p=L->next;
    while(p){
        q=p->next;       
        free(p);      //ɾ��Ԫ��
        p=q;
    }
    L->next=NULL;     //��βָ���
    return OK;
}

status ListEmpty(LinkList L)
// 4.������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L) return INFEASIBLE;  //L������
    if(!L->next) return TRUE;  //LΪ��
    else return FALSE;
}

int ListLength(LinkList L)
// 5.������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    LinkList p;
    ElemType cnt=0;
    p=L->next;
    while(p){
        p=p->next;
        cnt++;       //����
    }
    return cnt;
}

status GetElem(LinkList L,int i,ElemType &e)
// 6.������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    LinkList p;
    ElemType j=1;
    p=L->next;
    while(p){
        //printf("%d %d\n",p->data,j);
        p=p->next;
        j++;
        if(j==i){      //��ȡ��i��Ԫ��
            e=p->data;
            return OK;
        }
    }
    return ERROR;      //i<1����i�������Ա�L�ĳ���
}

status LocateElem(LinkList L,ElemType e)
// 7.������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ����e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    LinkList p;
    int j=1;
    p=L->next;
    while(p){
        if(p->data==e) return j;     //���ҵ�e������λ�����
        p=p->next;
        j++;
    }
    return ERROR;                   //δ�ҵ�e
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 8.������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    LinkList p,q;
    p=L;
    while(p->next){
        q=p->next;               //q��p�ĺ��
        if(q->data==e && p!=L){  //qָ��Ԫ��e����pΪe��ǰ��
            pre=p->data;
            return OK;     
        } 
        p=q;
    }
    return ERROR;                     //δ�ҵ�e��ǰ��
}

status NextElem(LinkList L,ElemType e,ElemType &next)
// 9.������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    LinkList p,q;
    p=L;
    while(p->next){
        q=p->next;                  //q��p�ĺ��
        if(p->data==e && q!=NULL){  //pָ��Ԫ��e����qΪe�ĺ��
            next=q->data;
            return OK;     
        } 
        p=q;
    }
    return ERROR;                     //δ�ҵ�e�ĺ��
}

status ListInsert(LinkList &L,int i,ElemType e)
// 10.������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    LinkList p,q;
    ElemType j=0;
    p=L;
    while(p){
        if(j==i-1){                            //��i-1�����
            q=(LinkList)malloc(sizeof(LNode)); //�����½��
            q->data=e;
            q->next=p->next;
            p->next=q;
            return OK;
        }
        p=p->next;
        j++;
    }
    return ERROR;      //i<1����i�������Ա�L�ĳ���
}

status ListDelete(LinkList &L,int i,ElemType &e)
// 11.������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    LinkList p,q;
    ElemType j=0;
    p=L;
    while(p->next){
        if(j==i-1){                            //��i-1�����
            q=p->next;                         //pΪ��i�����
            e=q->data;                         //����i��Ԫ�ر�����e��
            p->next=q->next;                  
            free(q);                           //�ͷŽ��
            return OK;
        }
        p=p->next;
        j++;
    }
    return ERROR;      //i<1����i�������Ա�L�ĳ���
}

status ListTraverse(LinkList L)
// 12.������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(!L) return INFEASIBLE;
    LinkList p;
    p=L->next;
    if(!p) printf("�����Ա�");
    while(p){
        printf("%d",p->data);
        if(p->next) printf(" ");
        p=p->next;
    }
    return ERROR;                   //δ�ҵ�e
}

status SaveList(LinkList L,char FileName[])
// 13.������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin 1 *********/
    if(!L) return INFEASIBLE;
    FILE *fp;
    LinkList p=L->next;
    fp=fopen(FileName,"w");     //��ֻ����ʽ���ļ�
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
// 14.������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    if(L) return INFEASIBLE;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    LinkList p=L,q;
    int x;
    FILE *fp;
    fp=fopen(FileName,"r");
    while((fscanf(fp, "%d", &x))!=EOF){    //���ļ���ѭ����ȡ����
        q=(LinkList)malloc(sizeof(LNode)); //�����½�㲢�����ڴ�
        q->data=x;                         //����ȡ�����ݸ���q
        p->next=q;
        p=p->next;
    }
    p->next=NULL;                          //��β,��p��nextָ���ÿ�
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


