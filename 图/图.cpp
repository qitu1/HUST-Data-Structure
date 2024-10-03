#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
#define Gnum 100
typedef int status;
typedef int KeyType;
typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef struct {
	KeyType  key;
	char others[20];
} VertexType; //�������Ͷ���

typedef struct stack{
    int elem[MAX_VERTEX_NUM];
    int p;
} stack; //ջ�Ķ���
//ջ�ĺ���
void iniStack(stack &S)//�ú�����ʼ��ջS
{
    S.p = 0;
}
int isEmptyStack(stack &S)
//�ж��ǲ��ǿ�ջ�����򷵻�1�������򷵻�0
{
    if (S.p) return 0;
    else return 1;
}
int push(stack &S, KeyType e)
//�ú�����Ԫ�ؽ�ջ���ɹ��򷵻�1��ʧ�ܷ���0
{
    if (S.p == MAX_VERTEX_NUM - 1)
        return OVERFLOW;
    else S.elem[++S.p] = e;
    return OK;
}
KeyType pop(stack &S)
//�ú�����Ԫ�س�ջ�����س�ջ��Ԫ��ֵ
{
    if (S.p == 0) return ERROR;
    else  return S.elem[S.p--];
}
typedef struct ArcNode {         //�������Ͷ���
	int adjvex;              //����λ�ñ��
	struct ArcNode* nextarc;	   //��һ������ָ��
} ArcNode;
typedef struct VNode {				//ͷ��㼰���������Ͷ���
	VertexType data;       	//������Ϣ
	ArcNode* firstarc;      	 //ָ���һ����
} VNode, AdjList[MAX_VERTEX_NUM];
typedef  struct {  //�ڽӱ�����Ͷ���
	AdjList vertices;     	 //ͷ�������
	int vexnum, arcnum;   	  //������������
	GraphKind  kind;        //ͼ������
} ALGraph;

void (*VisitFunc)(VertexType);
int visited[MAX_VERTEX_NUM];
void DFS(ALGraph G, int v);
int w;

struct ptr{
    void *pused[100],*pfree[100];
    int len_used,len_free;
    } pm;
typedef struct QNode{
	VertexType data;
	struct QNode *next;
}QNode,*Queue;
typedef struct{
	Queue front;
	Queue rear;
}Linkqueue;
void free0(void *p)
{
    pm.pfree[pm.len_free++]=p;
    memset(p,0,sizeof(ArcNode));
    free(p);
}
int pd;

status issame(VertexType V[])//�ж϶����ظ� 
{
	int i=0;
	int mark[100000]={0};
	while(V[i].key!=-1)
	{
		if(mark[V[i].key]>0){return 1;}
		mark[V[i].key]++;
		i++;
	}
	return 0;
}
int Locate (ALGraph G,KeyType VR)
{
    int i=0;
    for(i;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==VR) return i;
    }
    return -1;
}

status InitQueue(Linkqueue &Q)
{
	Q.front=Q.rear=(QNode *)malloc(sizeof(QNode));
	if(!Q.front)return ERROR;
	Q.front->next=NULL;
	return OK;
} 
status QueueEmpty(Linkqueue Q)
{
	if(Q.front==Q.rear)return TRUE;
	else return FALSE;
}
status enQueue(Linkqueue &Q,VertexType value)
{
	Queue p=(Queue)malloc(sizeof(QNode));
	if(!p)return ERROR;
	p->data=value;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}
status deQueue(Linkqueue &Q,VertexType &value)
{
	if(Q.front==Q.rear)return ERROR;
	Queue p=Q.front->next;
	value=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
	Q.rear=Q.front;
	free(p);
	return OK;
}
 
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2]);
status DestroyGraph(ALGraph &G);
status LocateVex(ALGraph G,KeyType u);
status PutVex(ALGraph &G,KeyType u,VertexType value);
status FirstAdjVex(ALGraph G,KeyType u);
status NextAdjVex(ALGraph G,KeyType v,KeyType w);
status InsertVex(ALGraph &G,VertexType v);
status DeleteVex(ALGraph &G,KeyType v);
status InsertArc(ALGraph &G,KeyType v,KeyType w);
status DeleteArc(ALGraph &G,KeyType v,KeyType w);
void visit(VertexType v);
void DFS(ALGraph G, int v);
status DFSTraverse(ALGraph &G,void (*visit)(VertexType));
status BFSTraverse(ALGraph &G,void (*visit)(VertexType));
void Putin(int VR[][2], ArcNode *p, int &k, int i);
status SaveGraph(ALGraph G,char FileName[]);
status LoadGraph(ALGraph &G, char FileName[]) ;
status ShortestPathLength(ALGraph G,KeyType v,KeyType w);
void VerticesSetLessThank(ALGraph G,KeyType v,KeyType k);
status ConnectedComponentsNums(ALGraph G);

int main(void) {
	KeyType op, j = 0, j1 = 0, k = 0,i = 0,u,v,w;
	VertexType V[30],value;
	KeyType VR[100][2];
	ALGraph G[Gnum];
	char FileName[100];
	while (op) {
		
						printf("                                             ͼ �� �� �� �� �� �� \n");
						printf("            ****************************************************************************************\n");
						printf("            *    	  1. Createraph(����ͼ��)            7. InsertVex(���붥��)                    *\n");
						printf("            *    	  2. DestroyGraph������ͼ��        8. DeleteVex(ɾ������)                    *\n");
						printf("            *    	  3. LocateVex�����Ҷ��㣩           9.InsertArc(���뻡)                       *\n");
						printf("            *    	  4. PutVex(���㸳ֵ)                10.DeleteArc(ɾ����)                      *\n");
						printf("            *    	  5. FirstAdjVex(��һ�ڽӵ�)         11. DFSTraverse(���������������          *\n");
						printf("            *    	  6. NextAdjVex(��һ�ڽӵ�)          12. BFSTraverse(���������������)         *\n");
						printf("            *   	  0. Exit                            13. Adjacency List(�ڽӱ�)                *\n");
						printf("            *    	  14. SaveGraph(�����ļ�)            15. LoadGraph(��ȡ�ļ�)                   *\n");
						printf("            *		  16.VerticesSetLessThank(����С��k�Ķ��㼯��)                                 *\n");
						printf("            *             17.ShortestPathLength (��������·���ͳ���)                                 *\n");
						printf("            *             18.ConnectedComponentsNums (ͼ����ͨ����)                                    *\n");
						printf("            *             19.ChooseGraph (ѡ�����ĸ�ͼ����)                                            *\n");
						printf("            ****************************************************************************************\n");
						printf("            ��ѡ����Ĳ���[0~19]:");
						scanf("%d", &op);
						switch (op) {
							case 0:
								break;

							case 1:
								printf("               ���������ݣ�") ;
								do {
									scanf("%d%s",&V[i].key,V[i].others);
								} while(V[i++].key!=-1);
								i=0;
								do {
									scanf("%d%d",&VR[i][0],&VR[i][1]);
								} while(VR[i++][0]!=-1);
								if (CreateCraph(G[k],V,VR)==ERROR) 
									printf("               �������ݴ��޷�����\n");
								else printf("               %d��ͼ�����ɹ���\n",k + 1);
								break;

							case 2:
								if (DestroyGraph(G[k]) == OK) printf("               ͼ�����ٳɹ���\n");
								else printf("               ͼ������ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 3:
								printf("               ��������Ҫ���ҽ���keyֵ��");
								scanf("%d",&u);
								i = LocateVex(G[k],u);
								if(i != -1) {
									printf("               ���ҳɹ����ý����ϢΪ��\n");
									visit(G[k].vertices[i].data);
								} else printf("               ����ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 4:
								printf("               ��������Ҫ��ֵ�Ľ��keyֵ:");
								scanf("%d",&u);
								printf("               �����븳ֵ��Ľ��keyֵ:");
								scanf("%d",&value.key);
								printf("               �����븳ֵ��Ľ��othersֵ:");
								scanf("%s",value.others);
								if(PutVex(G[k],u,value)) {
									printf("��ֵ�ɹ������ڸý�����ϢΪ��\n");
									visit(G[k].vertices[LocateVex(G[k],value.key)].data);
								}
								else printf("��ֵʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 5:
								printf("               ��������Ҫ���ҵ�һ�ڽӵ����keyֵ��");
								scanf("%d",&u);
								i = FirstAdjVex(G[k],u);
								if(i != -1) {
									printf("               ���ҵ�����һ�ڽӵ���Ϣ���£�\n");
									visit(G[k].vertices[i].data);
								} else printf("               ����ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 6:
								printf("               ��������Ҫ������һ�ڽӵ����keyֵv��");
								scanf("%d",&v);
								printf("               ��������Ҫ������һ�ڽӵ����keyֵw��");
								scanf("%d",&w);
								i = NextAdjVex(G[k], v, w);
								if(i != -1) {
									printf("               ���ҳɹ���v���ڽӶ��������w����һ�ڽӶ�����Ϣ���£�\n");
									visit(G[k].vertices[i].data);
								} else printf("               ����ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 7:
								int keyforsib;
								printf("               ��������Ҫ����Ľ���keyֵ��");
								scanf("%d",&value.key);
								printf("               ��������Ҫ����Ľ���others��");
								scanf("%s",value.others);
								i = InsertVex(G[k],value);
								if(i == OK) {
									printf("               ����ɹ���\n");
								} else printf("               ����ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 8:
								printf("               ��������Ҫɾ���Ľ��keyֵ��");
								scanf("%d",&v);
								i = DeleteVex(G[k],v);
								if(i == OK) {
									printf("               ɾ���ɹ���\n");
								} else printf("               ɾ��ʧ�ܣ�\n");
								getchar();
								getchar();
								break;

							case 9:
								printf("               ��������Ҫ����Ļ�ͷ��keyֵ��");
								scanf("%d",&v);
								printf("               ��������Ҫ����Ļ�β��keyֵ��");
								scanf("%d",&w);
								i = InsertArc(G[k],v,w);
								if(i == OK) printf("               ���뻡�ɹ���\n");
								else printf("               ���뻡ʧ�ܣ�");
								getchar();
								getchar();
								break;

							case 10:
								printf("               ��������Ҫɾ���Ļ�ͷ��keyֵ��");
								scanf("%d",&v);
								printf("               ��������Ҫɾ���Ļ�β��keyֵ��");
								scanf("%d",&w);
								i = DeleteArc(G[k],v,w);
								if(i == OK) printf("               ɾ�����ɹ���\n");
								else printf("               ɾ����ʧ�ܣ�");
								getchar();
								getchar();
								break;

							case 11:
								DFSTraverse(G[k],visit);
								printf("               �����������������ɣ�\n");
								getchar();
								getchar();
								break;

							case 12:
								BFSTraverse(G[k],visit);
								printf("               �����������������ɣ�\n");
								getchar();
								getchar();
								break;

							case 13:
								for(i=0; i<G[k].vexnum; i++) {
									ArcNode *p=G[k].vertices[i].firstarc;
									printf("               %d %s",G[k].vertices[i].data.key,G[k].vertices[i].data.others);
									while (p) {
										printf(" %d",p->adjvex);
										p=p->nextarc;
									}
									printf("\n");
								}
								getchar();
								getchar();
								break;

						case 14:
						printf("�����������ļ�����");
						scanf("%s", FileName);
						printf("����������ͼ����ţ�");
						scanf("%d", &k);
						if(SaveGraph(G[k],FileName) == OK)printf("���ļ��ɹ���\n");
						else printf("���ļ�ʧ�ܣ����Ժ�����\n");
						getchar();getchar();
						break;

					case 15:
						printf("�����������ļ�����");
						scanf("%s", FileName);
						printf("����������ͼ����ţ�");
						scanf("%d", &k);
						LoadGraph(G[k],FileName);
						printf("���ļ��ɹ���\n");
						getchar();getchar();
						break;
						
			case 16:
			printf("�����붥��Ĺؼ��ּ����Ҿ��룡\n");
			int kn;
			scanf("%d%d",&v,&kn);
			printf("�붥�����С��%d�Ķ�����\n",kn);
			VerticesSetLessThank(G[k],v,kn); 
			getchar();getchar();
			break;
		case 17:
			printf("��������������Ĺؼ���!\n");
			scanf("%d%d",&v,&w);
			if(ShortestPathLength(G[k],v,w)!=20){
			printf("���������������·����%d",ShortestPathLength(G[k],v,w));
		}
		else
		printf("����������֮�䲻����·��\n");
			getchar();getchar();
			break;
		case 18:
			printf("ͼ����ͨ������%d����\n",ConnectedComponentsNums(G[k]));
			getchar();getchar();
			break;
		
		case 19://ѡ�����ĸ�ͼ���в���
           	printf("������Ҫ�ڵڼ���ͼ����:\n ");
           	printf("*ֻ֧����%d��ͼ�ϲ���*\n",Gnum);
		   	scanf("%d",&k);
		   	printf("���ڶԵ�%d��ͼ���в���\n",k);
		 	if((k<0)||(k>99))
		 	{
		 		printf("��ѡ����ȷ��Χ��\n");
		 		k=0;
		 	}
		 	getchar(); getchar();
        	break;
        	}
	}
}


/*************************
 * ��������: CreateGraph
 * ��ʼ������ͼG������
 * �������: ����ͼG
 *************************/
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2]) 
{

	int i = 0,j,one = -1,two = -1;
	do {
		if(i > MAX_VERTEX_NUM) return ERROR;
		G.vertices[i].data = V[i];
		G.vertices[i].firstarc = NULL;
	} while (V[i++].key != -1);//���ͷ���
	G.vexnum = i - 1;
	for(i = 0, j = 0; i < G.vexnum; i++) {
		for(j = 0; j < G.vexnum ; j++) {
			if(V[i].key == V[j].key && i != j)
				return ERROR;
		}
	}
	i = 0;
	ArcNode *p;
	while (VR[i][0] != -1) {
		one = -1;
		for(j = 0; j < G.vexnum; j++)
			if (VR[i][0] == G.vertices[j].data.key) {
				one = j;
				break;
			}
		if(one == -1)return ERROR;
		for(j = 0; j < G.vexnum; j++)
			if (VR[i][1] == G.vertices[j].data.key) {
				two = j;
				break;
			}
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p -> adjvex = two;
		p -> nextarc = G.vertices[one].firstarc;
		G.vertices[one].firstarc = p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p -> adjvex = one;
		p -> nextarc = G.vertices[two].firstarc;
		G.vertices[two].firstarc = p;
		i++;
	}//��ӱ߽��
}

/**************************
 * ��������: DestroyGraph
 * ��ʼ������ͼG�Ѵ���
 * �������: ����ͼG
 *
 *************************/
status DestroyGraph(ALGraph &G) {
	int i;
	ArcNode *p, *q;//�����͵�ָ��p,q
	for(i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;//pָ���i���ڵ�� ��һ�������ڸýڵ��ָ��
		while(p) { //p��Ϊ��,�����ν�qָ����һ����,�ͷ�p,����ٽ�pָ��q����ʼ��һ��ѭ��
			q = p->nextarc;
			free(p);
			p = q;
		}
	}
	G.vexnum = 0;//֮��ͼ����Ϣ,������Ŀ,����Ŀ,kind��Ϊ0
	G.arcnum = 0;
	return OK;
}

/******************************************************************
 * ��������: LocateVex
 * ��ʼ������ͼG���ڣ�u��G�еĶ��������ͬ����
 * ��������: ��u��ͼG�д��ڣ����ض���u����Ϣ�����򷵻�������Ϣ
 *
 ******************************************************************/
status LocateVex(ALGraph G,KeyType u) {
	int i;
	for(i=0; i<G.vexnum; i++) {
		if(u == G.vertices[i].data.key)//�жϽڵ������Ƿ���ͬ
			return i;//������ҳɹ�������i��ֵ
	}
	return -1;
}


/***************************************
 * ��������: PutVex
 * ��ʼ������ͼG���ڣ�v��G�е�ĳ������
 * ��������: ��v��ֵvalue
 **************************************/
status PutVex(ALGraph &G,KeyType u,VertexType value) {
	int i = LocateVex(G,u);
	if(i != -1) {

		if(LocateVex(G,value.key) != -1) return ERROR;
		else {
			G.vertices[i].data.key = value.key;
			strcpy(G.vertices[i].data.others,value.others);
			return OK;
		}
	} else return ERROR;
}

/********************************************************************
 * ��������: FirstAdjVex
 * ��ʼ������ͼG���ڣ�v��G�е�ĳ������
 * ��������: ����v�ĵ�һ���ڽӶ��㣬���vû���ڽӶ��㣬����"��"
 ********************************************************************/
status FirstAdjVex(ALGraph G,KeyType u) {
	ArcNode *p;
	status v1 = LocateVex(G, u);
	if(v1 == -1)  return -2;
	p = G.vertices[v1].firstarc;//����LocateVex����,���ݷ���ֵ����pָ���
	if(p)  return p->adjvex;
	else   return -1;

}

/***********************************************************************************
 * ��������: NextAdjVex
 * ��ʼ������ͼG���ڣ�v��G��һ������,w��v���ڽӶ���
 * ��������: ����v�ģ������w����һ���ڽӶ��㣬���w�����һ���ڽӶ��㣬����"��"
 ***********************************************************************************/
status NextAdjVex(ALGraph G,KeyType v,KeyType w) {
	ArcNode *p;
	int v1 = LocateVex(G, v);
	int w1 = LocateVex(G, w);
	if(v1 == -1 || w1 == -1)
	return -1;
	p = G.vertices[v1].firstarc;
	while (p && p->adjvex != w1)
	{
		p = p->nextarc;
	}
	if(!p) return -3;//���ݷ���ֵ���ж��Ƿ����ڽӵ�,�Ƿ������һ���ڽӵ�
	if(!p->nextarc) return -1;
	else return p->nextarc->adjvex;
}


/*************************************************
 * ��������: InsertVex
 * ��ʼ������ͼG���ڣ�v��G�еĶ��������ͬ����
 * ��������: ��ͼG�������¶���v
 *************************************************/
status InsertVex(ALGraph &G,VertexType v) {
	int i = 0;
	if(G.vexnum >= MAX_VERTEX_NUM || LocateVex(G,v.key) != -1)return ERROR;
	while(G.vertices[i].data.key != -1)i++;
	G.vertices[i].data.key = v.key;
	G.vertices[i].firstarc = NULL;
	strcpy(G.vertices[i].data.others,v.others);
	G.vexnum++;
	return OK;
}


/***************************************************
 * ��������: DeleteVex
 * ��ʼ������ͼG���ڣ�v��G��һ������
 * ��������: ��ͼG��ɾ������v����v��صĻ�
 ***************************************************/
status DeleteVex(ALGraph &G,KeyType v) {
	int i = 0, j;
	ArcNode *p, *q;
	if(G.vertices[0].data.key != -1 && G.vertices[1].data.key == -1) return ERROR;
	j = LocateVex(G, v);
	if(j == -1 )
		return ERROR;
	p = G.vertices[j].firstarc;
	while(p) {
		q = p;
		p = p->nextarc;
		free(q);
		G.arcnum--;
		i++;
	}
	G.vexnum--;
	for(i = j; i < G.vexnum; i++)
		G.vertices[i] = G.vertices[i+1];
	for(i = 0; i < G.vexnum; i++) {
		p = G.vertices[i].firstarc;
		while(p) {
			if(p->adjvex == j) {
				if(p == G.vertices[i].firstarc) {
					G.vertices[i].firstarc = p->nextarc;
					free(p);
					p = G.vertices[i].firstarc;
				} else {
					q -> nextarc = p -> nextarc;
					free(p);
					p = q -> nextarc;
				}
			} else {
				if(p->adjvex > j)
					p->adjvex--;
				q = p;
				p = p->nextarc;
			}
		}
	}
	return OK;
}


/********************************************************************
 * ��������: InsertArc
 * ��ʼ����:ͼG���ڣ�v��w��G�Ķ���
 * ��������: ��ͼG�����ӻ�<v,w>�����ͼG������ͼ������Ҫ����<w,v>
 ********************************************************************/
status InsertArc(ALGraph &G,KeyType v,KeyType w) {
	ArcNode *p,*q;
	int  i, j;
	i = LocateVex(G, v);
	j = LocateVex(G, w);
	if(i == -1 || j == -1)
		return ERROR;
	p = G.vertices[i].firstarc;
	while(p) {
		if( p -> adjvex == j)return ERROR;
		p = p -> nextarc;
	}
	G.arcnum++;
	p=(ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	p->nextarc = G.vertices[i].firstarc;
	G.vertices[i].firstarc = p;
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = i;
	p->nextarc = G.vertices[j].firstarc;
	G.vertices[j].firstarc = p;
	return OK;
}

/*********************************************************************
 * ��������: DeleteArc
 * ��ʼ����:ͼG���ڣ�v��w��G�Ķ���
 * ��������: ��ͼG��ɾ����<v,w>�����ͼG������ͼ������Ҫɾ��<w,v>
 *********************************************************************/
status DeleteArc(ALGraph &G,KeyType v,KeyType w) {
	ArcNode *p, *q;
	int i, j;
	i = LocateVex(G, v);
	j = LocateVex(G, w);
	if(i < 0 || j < 0)
		return ERROR;

	p = G.vertices[i].firstarc;
	while(p && p->adjvex != j) {
		q = p;
		p = p->nextarc;
	}
	if(p && p->adjvex == j) {
		if(p == G.vertices[i].firstarc)
			G.vertices[i].firstarc = p->nextarc;
		else
			q->nextarc = p->nextarc;
		free(p);
		G.arcnum--;
	} else if(!p) return ERROR;
	p = G.vertices[j].firstarc;
	while(p && p->adjvex != i) {
		q = p;
		p = p->nextarc;
	}
	if(p && p->adjvex == i) {
		if(p == G.vertices[j].firstarc)
			G.vertices[j].firstarc=p->nextarc;
		else
			q->nextarc=p->nextarc;
		free(p);
	}
	return OK;
}


/*************************************************
 * ��������: DFS
 * ��ʼ������ͼG����
 * ��������: ��Ϊ���ʵĽڵ�������������������
 *************************************************/
void DFS(ALGraph G, int v) {
	visited[v] = TRUE;
	VisitFunc(G.vertices[v].data);
	for(w = FirstAdjVex(G,G.vertices[v].data.key); w >= 0; w = NextAdjVex(G,G.vertices[v].data.key,w))
		if(!visited[w]) DFS(G,w);
}


/***************************************************************************************************
 * ��������: DFSTraverse
 * ��ʼ������ͼG����
 * ��������: ������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
 ***************************************************************************************************/
status DFSTraverse(ALGraph &G,void (*visit)(VertexType)) {
	int i = -1;
	VisitFunc = visit;
	for(; i < G.vexnum; i++) visited[i] = FALSE;
	for(i = 0; i < G.vexnum; i++)
		if(!visited[i]) DFS(G,i);
}


/***********************************************************************************************
 * ��������: BFSTraverse
 * ��ʼ������ͼG����
 * ��������: ���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
 ***********************************************************************************************/
status BFSTraverse(ALGraph &G,void (*visit)(VertexType)) {
	int queue[21] = { MAX_VERTEX_NUM };
	int flag[20] = { MAX_VERTEX_NUM };
	int head = 0, tail = 1;
	queue[0] = 0;
	flag[0] = 1;
L1:
	while (head != tail) {
		if(head < G.vexnum)visit(G.vertices[queue[head]].data);
		ArcNode* p = G.vertices[queue[head]].firstarc;
		while (p) {
			int loc = LocateVex(G, G.vertices[p->adjvex].data.key);
			if (!flag[loc]) {
				queue[tail] = loc;
				tail++;
				flag[loc] = 1;
			}
			p = p->nextarc;
		}

		head++;
	}
	if(tail <= G.vexnum)  {
		tail++;
		queue[head] = LocateVex(G, G.vertices[head].data.key);
		goto L1;
	}
}

/****************************
 * ��������: visit
 * ��ʼ������ͼG����
 * ��������: ���ʽڵ�һ��
 ****************************/
void visit(VertexType v) {
	printf("               key = %d,others = %s\n",v.key,v.others);
}

/*****************************
 * ��������: Putin
 * ��ʼ������p����
 * ��������: ��ͼ�й�ϵ������VR������
 *****************************/
void Putin(int VR[][2], ArcNode *p, int &k, int i) {
	if(p==NULL) return;
	if(p->nextarc) Putin(VR, p->nextarc, k, i);
	int d;
	for(d=0; d<k; d++) {
		if(VR[d][1]==i&&VR[d][0]==p->adjvex) return;
	}
	VR[k][0]=i;
	VR[k][1]=p->adjvex;
	k++;
}


/*****************************
 * ��������: SaveGraph
 * ��ʼ������ͼG����
 * ��������: ����ͼΪ�ļ�
 *****************************/
status SaveGraph(ALGraph G, char FileName[]) {
	FILE* fp;
	int VR[100][2]= {0};
	fp=fopen(FileName,"w");
	int i, j, k, f;
	k=0;
	for(i=0; i<G.vexnum; i++) {
		fprintf(fp,"%d %s ", G.vertices[i].data.key, G.vertices[i].data.others);
	}
	fprintf(fp,"-1 nil ");
	for(i=0; i<G.vexnum; i++) {
		Putin(VR, G.vertices[i].firstarc, k, i);
	}
	for(i=0; i<k; i++) {
		j=VR[i][0];
		f=VR[i][1];
		fprintf(fp,"%d %d ", G.vertices[j].data.key, G.vertices[f].data.key);
	}
	fprintf(fp,"-1 -1");
	fclose(fp);
	return OK;
}

/*****************************
 * ��������: LoadGraph
 * ��ʼ����:�ļ�����
 * ��������: ���ļ��м���ͼ
 *****************************/
status LoadGraph(ALGraph &G, char FileName[]) {
	FILE* fp;
	fp=fopen(FileName,"r");
	int i, j, k;
	char str[20];
	VertexType V[20];
	KeyType VR[100][2];
	i=0;
	while(fscanf(fp,"%d %s ", &V[i].key, V[i].others)!=EOF) {
		if(V[i].key<0) break;
		i++;
	}
	i=0;
	while(fscanf(fp,"%d %d ", &VR[i][0], &VR[i][1])!=EOF) {
		i++;
	}
	fclose(fp);
	if(CreateCraph(G,V,VR)==OK) {
		ArcNode *f, *q;
		f=G.vertices[2].firstarc;
		q=f->nextarc;
		f->nextarc=q->nextarc;
		q->nextarc=f;
		G.vertices[2].firstarc=q;
		return OK;
	} else return ERROR;
}


int distance[21];
status ShortestPathLength(ALGraph G,KeyType v,KeyType w)//���ض���v�붥��w�����·������ 
{
	int i,j,n;
	VertexType top;
	top.key=v;
	Linkqueue Q;
	InitQueue(Q);
	for(i=0;i<G.vexnum;i++)
	distance[G.vertices[i].data.key]=20;
	distance[v]=0;
	int k=LocateVex(G,v);
	enQueue(Q,G.vertices[k].data);
	while(!QueueEmpty(Q))
	{
		deQueue(Q,top);
		if(top.key==w)break;
		for(j=FirstAdjVex(G,top.key);j>=0;j=NextAdjVex(G,top.key,G.vertices[j].data.key))//����λ�� 
		{
			if(distance[G.vertices[j].data.key]==20)
			{
				distance[G.vertices[j].data.key]=distance[top.key]+1;
				enQueue(Q,G.vertices[j].data);
			}
		}
	}
	n=distance[w];
	return n;
}
void VerticesSetLessThank(ALGraph G,KeyType v,KeyType k)//�����붥��v����С��k�Ķ��㼯�� 
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		j=ShortestPathLength(G,v,G.vertices[i].data.key);
		if(j<k&&G.vertices[i].data.key!=v)
		visit(G.vertices[i].data);
	}
}
bool mark[20];
void dfs(ALGraph &G,KeyType v)
{
	mark[v]=TRUE;
	for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,G.vertices[w].data.key)) 
	{
		if(!mark[G.vertices[w].data.key])dfs(G,G.vertices[w].data.key);
	}
}
status ConnectedComponentsNums(ALGraph G)//��ͼ����ͨ�������� 
{
	int count=0,i;
	for(i=0;i<G.vexnum;i++)
	mark[G.vertices[i].data.key]=FALSE;//��������¼�ؼ��� 
	for(i=0;i<G.vexnum;i++)
	{
		if(!mark[G.vertices[i].data.key])
		{
			dfs(G,G.vertices[i].data.key);
			count++;
		}
	}
	return count;
 } 
 
