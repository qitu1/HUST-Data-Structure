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
typedef int ElemType; //����Ԫ�����Ͷ���

/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{  //˳���˳��ṹ���Ķ���
	ElemType * elem;
	int length;
	int listsize;
}SqList;

    //���Ա��ϵĶ���Lists
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
	printf("    ��ѡ����Ĳ���[0~18]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
	   	 printf("������Ҫ���������Ա����ƣ�\n");
	   	 scanf("%s",filename);
		 if(InitList(L[i_num])==OK) {
		 	printf("���Ա����ɹ���\n");
		 	printf("������Ԫ�أ��ÿո��������0������\n");
	        for(int i=0;i<L[i_num].listsize;i++){
	        	int num;
				scanf("%d",&num);
				if(num==0) break;
				else L[i_num].elem[L[i_num].length++]=num; 
			}
		 }
		 else printf("���Ա���ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	   case 2:
	   	if(L[i_num].elem==NULL)
         {
             printf("���Ա�����!\n");
             getchar();getchar();
             break;
         }
		 if(DestroyList(L[i_num])==OK) 
		     printf("���Ա����ٳɹ���\n");
		     else printf("���Ա�����ʧ�ܣ�\n");     
		 getchar();getchar();
		 break;
	   case 3:
		 if(ClearList(L[i_num])==OK)
		     printf("���Ա���ճɹ���\n");
		     else printf("���Ա����ʧ�ܣ�\n");      
		 getchar();getchar();
		 break;
	   case 4:
	   	 if(ListEmpty(L[i_num])==TRUE) 
			printf("���Ա�Ϊ�գ�\n");
		 else if(ListEmpty(L[i_num])==INFEASIBLE) 
			printf("���Ա����ڣ�\n");
		 else printf("���Ա�Ϊ�գ�\n");         
		 getchar();getchar();
		 break;
	   case 5:
	   	 n=ListLength(L[i_num]);
		 printf("���Ա���Ϊ%d",n);
		 getchar();getchar();
		 break;
	   case 6:
	   	 printf("��������Ҫ��ȡ��Ԫ����ţ�\n");
	     scanf("%d",&i);
	   	 GetElem(L[i_num],i,e);  
		 getchar();getchar();
		 break;
	   case 7:
	   	printf("��������Ҫ���ҵ�Ԫ�أ�\n");
	    scanf("%d",&e);
	   	LocateElem(L[i_num],e); 
		 getchar();getchar();
		 break;
	   case 8:
	   	 printf("������Ҫ��ȡǰ����Ԫ�أ�\n");
	     scanf("%d",&e);
	   	 PriorElem(L[i_num],e,pre);   
		 getchar();getchar();
		 break;
	   case 9:
	     printf("������Ҫ��ȡ��̵�Ԫ�أ�\n");
	     scanf("%d",&e);
	   	 NextElem(L[i_num],e,next);       
		 getchar();getchar();
		 break;
	   case 10:
	   	 printf("������Ҫ�����Ԫ�غ�λ��,�ÿո����\n");
	   	 scanf("%d %d",&e,&i);
	   	 if(ListInsert(L[i_num],i,e)==OK) printf("����ɹ�\n"); 
		 getchar();getchar();
		 break;
	   case 11:
	   	 printf("������Ҫɾ����Ԫ�����\n"); 
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
            printf("�ļ�����ɹ�\n�ļ���Ϊ%s\n",filename);
         }
		getchar();getchar();
         break;
	   case 14:
	   	 if(L[i_num].elem!=NULL){
            printf("���Ա��Ѵ��ڣ��޷����أ�");
            getchar();getchar();
            break;
         }
	   	 printf("������Ҫ���ص��ļ���:\n ");
		 scanf("%s", filename);
		 if(LoadList(L[i_num], filename)==OK){
                printf("�ļ����سɹ�\n");
		 }
		else{
                printf("�ļ�����ʧ�ܣ�");
         }
         break;
       case 15:
	   	 printf("������Ҫ�ڵڼ��������:\n ");
           printf("*ֻ֧����%d��˳����ϲ���*\n",MAX_NUM);
		   scanf("%d",&i_num);
           	 if((i_num<1)||(i_num>MAX_NUM))
		    {
		 	printf("��ѡ����ȷ��Χ��Ĭ�϶Ե�һ�����Ա���в���\n");
		 	i_num=1;
		    }
		   printf("���ڶԵ�%d������в���\n",i_num);
           getchar(); getchar();
         break;
	   case 16:
	   	 MaxSubArray(L[i_num]);
		 getchar();getchar();
		 break;
	   case 17:
	   	 printf("��������Ҫ���������ĺ�k:\n");
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
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
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
// 2.������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
	if(L.elem) {//������Ա�L����
        free(L.elem);  //�ͷ�����Ԫ�ؿռ�
        L.elem = NULL; //����δ��ʼ��״̬
        L.length = 0;
        L.listsize = 0;
        return OK;
    }
    else return INFEASIBLE;
}

status ClearList(SqList& L)
// 3.������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
     if(L.elem==NULL){
        return INFEASIBLE;
    }
    L.length=0;
    free(L.elem);
    return OK;
}

status ListEmpty(SqList L)
// 4.������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
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
// 5.������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if(L.elem) return L.length; //���ر�
    else return INFEASIBLE;
} 

status GetElem(SqList L,int i,ElemType &e) 
// 6.������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
	if(!L.elem){
		printf("���Ա�����!\n");
		return INFEASIBLE;
	}
    if(i<1||i>L.length) 
	{
		printf("�����iֵ���淶!\n");
		return ERROR;
	}
    e=L.elem[i-1];
    printf("�����Ա�ĵ�%d��Ԫ����%d\n",i,e);
    return OK;
}

int LocateElem(SqList L,ElemType e)
// 7.������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
{
    if(L.elem){
        int i;
        //printf("%d\n",L.elem[0]);
        for(i=1;i<=L.length;i++){//����˳�������ָ��Ԫ��e
            if (L.elem[i-1] == e) {
            	printf("Ԫ��%d�ڸ����Ա��е�һ�γ��ֵ�λ�������%d\n",e,i);
            	return i;//���ҳɹ����򷵻�Ԫ���߼����i
			}
        }
        printf("Ԫ��%d�ڸ����Ա��в�����\n",e);
        return 0;//û���ҵ�ָ����Ԫ��e������ʧ�ܣ�����0
    }
    else {
		printf("���Ա�����!\n");
		return INFEASIBLE;
	}
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// 8.������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if (L.elem){
        int i;
        for(i=1;i<L.length;i++){//�ӵڶ���Ԫ�ؿ�ʼ�������Ա�L
            if(L.elem[i] == e){ //�����ҵ�eԪ��
                pre=L.elem[i-1];//��ȡ���Ա�L��Ԫ��e��ǰ����������pre��
                printf("�����Ա���Ԫ��%d��ǰ��Ԫ����%d\n",e,pre);
                return OK;
            }
        }
        printf("�޷��ҵ�Ԫ��%d��ǰ��\n",e);
        return ERROR;//û��ǰ��������ERROR
    }
    else {
		printf("���Ա�����!\n");
		return INFEASIBLE;
	}
}

status NextElem(SqList L,ElemType e,ElemType &next)
// 9.������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    
	if (L.elem){
        int i;
        for(i=0;i<L.length-1;i++){//�������Ա�L�������ڶ���Ԫ��
            if(L.elem[i] == e){ //�����ҵ�eԪ��
                next=L.elem[i+1];//��ȡ���Ա�L��Ԫ��e�ĺ�̣�������next��
                printf("�����Ա���Ԫ��%d�ĺ��Ԫ����%d\n",e,next);
                return OK;
            }
        }
        printf("�޷��ҵ�Ԫ��%d�ĺ��\n",e);
        return ERROR;//û��ǰ��������ERROR
    }
    else {
		printf("���Ա�����!\n");
		return INFEASIBLE;
	}
}

status ListInsert(SqList &L,int i,ElemType e)
// 10.������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    //i�ĺϷ�ֵΪ1<=i<=L.length+1
    if(i<1 || i>L.length+1) {               //iֵ���Ϸ�
    	printf("�����iֵ���淶!\n");
		return ERROR;
	}
    if(L.elem){
        if(L.length>=L.listsize){           //��ǰ�洢�ռ����������ӷ���
            int *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
            if(!newbase) exit(OVERFLOW);    //�洢����ʧ��
            L.elem = newbase;               //�»�ַ
            L.listsize += LISTINCREMENT;    //���Ӵ洢����
        }
        int *q = &(L.elem[i-1]);    //qΪ����λ��
        for(int *p = &(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p;
        //����λ�ü�֮���Ԫ�غ���
        *q=e;           //����e
        ++L.length;     //����һ
        return OK;
    }
    else {
		printf("���Ա�����!\n");
		return INFEASIBLE;
	}
}

status ListDelete(SqList &L,int i,ElemType &e)
// 11.������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    
	if(L.elem){
		if(i<1||i>L.length){
		printf("ɾ��λ�ò��淶\n");
		return ERROR;
		}
        int *q = &(L.elem[i-1]);    //qΪ��ɾ��Ԫ�ص�λ��
        e=*q;                       //����i��Ԫ�ر�����e��
        ++q;           
        for(int *p = &(L.elem[L.length-1]);p>=q;++q) 
            *(q-1)=*q;
        //��ɾ��Ԫ��λ�ü�֮���Ԫ��ǰ��
        --L.length;     //����һ
        printf("ɾ���ɹ�,ɾ������%d\n",e);
        return OK;
    }
    else {
		printf("���Ա�����!\n");
		return INFEASIBLE;
	}
}

status ListTraverse(SqList L)
//12.������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
	if (L.elem){
        int i;
        if(L.length == 0){          //��Ϊ0��Ϊ�����Ա�
            printf("�����Ա�");
            return 0;
        }
        for(i=0;i<L.length;i++){    //�������Ա�L
            if(i!=L.length-1)
                printf("%d ",L.elem[i]);
            else printf("%d",L.elem[i]);
        }
        return OK;
    }
    else {
		printf("���Ա�����!\n");
		return INFEASIBLE;
	}
}


status  SaveList(SqList &L,char FileName[])
// 13.������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    if(L.elem){
        FILE *fp;
        fp=fopen(FileName,"wb");     //��ֻ����ʽ���ļ�
        if(fp==NULL){               //�ļ�Ϊ��
            printf("�ļ�Ϊ��!");
            exit (-1);
        }
        for(int i=0;i<L.length;i++){    
            fprintf(fp,"%d " ,L.elem[i]);   //�����Ա�L�ĵ�Ԫ��д���ļ���
        }
        fclose(fp);
        printf("д��ɹ���");
        return OK;
    }
    else {
		printf("���Ա�����!\n");
		return INFEASIBLE;
	}
}
status  LoadList(SqList &L,char FileName[])
// 14.������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
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
            printf("�ļ�Ϊ��!");
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
		printf("���Ա�����!\n");
		return INFEASIBLE;
	}
	for(int i=0;i<L.length;i++){
		sum=0;
		for(int j=0;j<L.length-i;j++){
			sum+=L.elem[i+j];
			if(sum>max) max=sum;
		}
	}
	printf("�����Ա�����������������Ϊ%d\n",max);
	return max; 
}

status SubArrayNum(SqList& L,ElemType k){
	if(!L.elem){
		printf("���Ա�����!\n");
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
	printf("�����Ա��к�Ϊ%d���������������Ϊ%d\n",k,count);
	return count;
}

status SortList(SqList& L){
	if(!L.elem){
		printf("���Ա�����!\n");
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
	printf("����ɹ���\n");
	return OK;
}


