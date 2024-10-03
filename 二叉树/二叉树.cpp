#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define treesnum 100
#define _CRT_SECURE_NO_WARNINGS 1
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define root T
#define name others
#define filename Filename
#define L T
#define NODENUMBER 100//结点数最大值 

typedef int ElemType; //数据元素类型定义
typedef int status;
typedef int KeyType;
typedef struct {
	KeyType  key;
	char others[20];
} TElemType; //二叉树结点类型定义

typedef struct BiTNode { //二叉链表结点的定义
	TElemType  data;
	struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;
typedef BiTNode BTN;


status Dis_visit(char e);
void visit(BTN *T);
status InitBiTree(BiTree *T);
status CreateBiTree(BTN *&T);
status DestroyBiTree(BTN *&T);
status ClearBiTree(BTN *&T);
status BiTreeEmpty(BTN *T);
int BiTreeDepth(BTN *T);
BTN* LocateNode(BTN *T,int e);//e是关键字
status Assign(BiTree &T,KeyType e,TElemType value);
BTN* GetParent(BTN *T,int e);//找兄弟先找双亲
BTN* GetSibling(BTN *T,int e);
status InsertNode(BTN *&T,int e,int LR,BTN *&c);
status DeleteNode(BiTree &T,KeyType e);
BiTree Getfather(BiTree T, KeyType e);
status PreOrderTraverse(BTN *T);//已简化，非递归
status InOrderTraverse(BTN *T);
status PostOrderTraverse(BTN *T);
void OneLevel(BTN *T,int h);//遍历一层
status LevelOrderTraverse(BTN *T);
void read(BTN *&T,FILE *fp);
status ReadBiTree(BTN *&T);//读文件
status SaveBiTree(BTN *T);
status TreeDisplay(BiTree T,int depth,status (* visit)(char e));
status MaxPathSum(BiTree T);
BiTNode* LowestCommonAncestor(BiTree T,KeyType e1,KeyType e2);
status InvertTree(BiTree &T);
int MPS(BiTree T);

int max(int x,int y)
{
    return x>y?x:y;
}

BiTree T[treesnum];
int main()
{

	ElemType op=1,j = 0,k=0, lr = 3;
	KeyType key,key1,key2;
	BiTNode* t;
	BiTNode *pforassign=(BTN *)malloc(sizeof(BTN));
	BTN *pforsib=(BTN *)malloc(sizeof(BTN));
	BTN *pforloc=(BTN *)malloc(sizeof(BTN));
	BTN *pforins=(BTN *)malloc(sizeof(BTN));
	for(int i = 0; i < treesnum ; i++) 
		T[i] = NULL;
	j = 0;
	char Filename[100];
	while(op){
printf("                                            二 叉 树 的 基 本 操 作 \n");
						printf("            ****************************************************************************************\n");
						printf("            *    	  1. CreateBiTree(创建二叉树)       8.InsertNode(插入结点)                     *\n");
						printf("            *    	  2. DestroyBiTree（销毁二叉树）    9.DeleteNode(删除结点)                     *\n");
						printf("            *    	  3. ClearBiTree（清空二叉树）      10. PreOrderTraverse(先序遍历)             *\n");
						printf("            *    	  4. BiTreeDepth(二叉树深度)        11. InOrderTraverse(中序遍历)              *\n");
						printf("            *    	  5. LocateNode(查找结点)           12. PostOrderTraverse(后序遍历)            *\n");
						printf("            *    	  6. Assign(结点赋值)               13. LevelOrderTraverse(按层遍历)           *\n");
						printf("            *    	  7. GetSibling（兄弟结点）         14. TreeDisplay(树的图形结构)              *\n");
						printf("            *   	  17.ChooseTree（选择在哪个树操作） 15. ReadBiTree   （读取文件）              *\n"); 
						printf("            *   	  0. Exit                           16. SaveBiTree   （保存文件）              *\n");
						printf("    	    *		  18. MaxPathSum  （最大路径和）    19. LowestCommonAncestor（最近公共祖先）   *\n");
						printf("    	    *		  20. InvertTree  （翻转二叉树）    21. BiTreeEmpty(判空)                      *\n");         
						printf("            ****************************************************************************************\n");
						printf("            请选择你的操作[0~21]:\n");
						scanf("%d", &op);
						switch (op) {
							case 0:
								break;

							case 1:
								if(CreateBiTree(T[k])) printf("               二叉树创建成功！\n");
								else printf("               二叉树创建失败！\n");
								break;

							case 2:
								if (DestroyBiTree(T[k]) == OK) printf("               二叉树销毁成功！\n");
								else printf("               二叉树销毁失败！\n");
								getchar();
								getchar();
								break;

							case 3:
								if (DestroyBiTree(T[k]) == OK) printf("               二叉树清除成功！\n");
								getchar();
								getchar();
								break;

							case 4:
								printf("               二叉树的深度为%d！\n", BiTreeDepth(T[k]));
								getchar();
								getchar();
								break;

							case 5:
								int keyforlocate;
								printf("               请输入你要查找结点的关键字：");
								scanf("%d",&keyforlocate);
								pforloc = LocateNode(T[k],keyforlocate);
								if(pforloc) {
									printf("               已找到，结点信息如下：\n");
									visit(pforloc);
								} else printf("               未找到！\n");
								getchar();
								getchar();
								break;

							case 6:
								pforassign->lchild=NULL;
								pforassign->rchild=NULL;//保证安全
								printf("               请输入你要赋值的结点的关键字：");
								scanf("%d",&pforassign->data.key);
								TElemType e;
								printf("               请输入：");
								scanf("%d %s",&e.key,e.others);
								if(Assign(T[k],pforassign->data.key,e)) {
									printf("               赋值完成，现在该结点信息如下：\n");
									visit(LocateNode(T[k],e.key));
								} else printf("               未找到！\n");
								getchar();
								getchar();
								break;

							case 7:
								int keyforsib;
								printf("               请输入你要查找其兄弟的结点的key值：");
								scanf("%d",&keyforsib);
								pforsib = GetSibling(T[k],keyforsib);
								if(pforsib) {
									printf("               已找到，兄弟结点信息如下：\n");
									visit(pforsib);
								} else printf("               未找到！\n");
								getchar();
								getchar();
								break;

							case 8:
								int keyforins;
								BTN * pForInsert;
								printf("               请输入你要插入的结点key值(0表示根节点)：");
								scanf("%d",&keyforins);
								if(keyforins == 0) {
									pForInsert = (BiTNode*)malloc(sizeof(BiTNode));
									printf("               请输入你要赋值的结点的key值：");
									scanf("%d",&pForInsert -> data.key);
									printf("               请输入others：");
									scanf("%s",pForInsert -> data.others);//新结点生成
									pForInsert -> rchild = T[k];
									T[k] = pForInsert;
									break;
								}
								lr=3;
								while(lr != 0 && lr != 1) {
									printf("               请输入0（左孩子）或1（右孩子)：");
									scanf("%d",&lr);
								}
								pforins=(BTN *)malloc(sizeof(BTN));
								pforins -> lchild = NULL;
								pforins -> rchild = NULL;//保证安全
								printf("               请输入你要赋值的结点的key值：");
								scanf("%d",&pforins->data.key);
								printf("               请输入others：");
								scanf("%s",&pforins->data.others);
								if(InsertNode(T[k],keyforins,lr,pforins)==OK) printf("               插入完成！\n");
								else printf("               插入失败！\n");
								getchar();
								getchar();
								break;

							case 9:
								int keyfordel;
								printf("               请输入你要删除的结点的关键字：");
								scanf("%d",&keyfordel);
								if(DeleteNode(T[k],keyfordel)==OK) printf("               删除成功！\n");
								else printf("               删除失败！");
								getchar();
								getchar();
								break;

							case 10:
								if(PreOrderTraverse(T[k])==OK) printf("               前序遍历完成！\n");
								else printf("               前序遍历失败！\n");
								getchar();
								getchar();
								break;

							case 11:
								if(InOrderTraverse(T[k])==OK) printf("               中序遍历完成！\n");
								else printf("               中序遍历失败！\n");
								getchar();
								getchar();
								break;

							case 12:
								if(PostOrderTraverse(T[k])==OK) printf("               后序遍历完成！\n");
								else printf("               后序遍历失败！\n");
								getchar();
								getchar();
								break;

							case 13:
								if(LevelOrderTraverse(T[k])==OK) 
									printf("               按层遍历完成！\n");
								else printf("               按层遍历失败！\n");
								getchar();
								getchar();
								break;

							case 14:
								if (!T[k]) {
									printf("                   二叉树不存在！\n");
									getchar();
									getchar();
									break;
								}
								if(BiTreeEmpty(T[k]) == OK)
									printf("                   二叉树为空树！\n");
								else {
									printf("                   该二叉树为:\n");
									TreeDisplay(T[k],1, Dis_visit);
								}
								getchar();
								getchar();
								break;
							
							case 15:
								if(ReadBiTree(T[k])==OK) printf("               读取成功！\n");
								else printf("               读取失败！\n");
								getchar();
								break;

							case 16:
								if(SaveBiTree(T[k])==OK) printf("               储存成功！\n");
								else printf("               储存失败！\n");
								getchar();
								break;

							case 17://选择在哪个树进行操作
           						printf("请输入要在第几个树操作:\n ");
           						printf("*只支持在%d个树上操作*\n",treesnum);
		   						scanf("%d",&k);
		   						printf("正在对第%d个树进行操作\n",k);
		 						if((k<0)||(k>99))
		 							{
		 								printf("请选择正确范围！\n");
		 								k=0;
		 							}
		 						getchar(); getchar();
         						break;
         						
    
    			case 18:
	    		if(!T[k])  printf("二叉树不存在！\n");
                else
                {
                    printf("最大路径和为：%d。\n",MaxPathSum(T[k]));
                }
	    		getchar();getchar();
	    		break;
	    	case 19:
	    	
	    		if(!T[k]) printf("二叉树不存在！\n");
                else
                {
                    printf("输入你要查找最近公共祖先的两个关键字：");
                    scanf("%d%d",&key1,&key2);
                    t=LowestCommonAncestor(T[k],key1,key2);
                    if(t)printf("最近公共祖先为(%d,%s)。\n",t->data.key,t->data.others);
                    else printf("查找失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    	case 20:
	    		if(!T[k]) printf("二叉树不存在！\n");
                else
                {
                    if(InvertTree(T[k]))  printf("二叉树翻转成功！\n");
                    else printf("二叉树翻转失败！\n");
                }
	    		getchar();getchar();
	    		break;
	    		
	    		case 21:
					if(BiTreeEmpty(T[k]) == OK)
						printf("                   二叉树为空树！\n");
					else {
							printf("                   该二叉树不为空！\n");
						}
					getchar();
					getchar();
					break;
							default://确保输入的数字有意义
								printf("                   请输入[0~21]实现菜单功能");
								break;
						
						}//end of switch
					}//end of while
}//end of main
				
status Dis_visit(char e) {
	printf("%c",e);//依次调用该函数，用来打印
}


void visit(BTN *T) {
	printf("               key：%d,others：%s\n",T->data.key,T->data.others);
}

/**
 * 函数名称: InitBiTree
 * 初始条件：二叉树T不存在
 * 操作结果: 构造空树二叉树T
 *
 */
status InitBiTree(BiTree *T) {
	*T = (BiTree)malloc(sizeof(BiTNode));
	(*T) -> lchild = NULL;
	(*T) -> rchild = NULL;
	strcpy((*T) -> data.others,"#");
	(*T) -> data.key = 0;//初始化二叉树,将左右指针指向空

	return OK;
}


/**
 * 函数名称: DestroyBiTree
 * 初始条件：二叉树T已存在
 * 操作结果: 销毁二叉树T
 *
 */
status DestroyBiTree(BTN *&T) {

	free(T);
	T = NULL;
	return OK;
}

status ClearBiTree(BTN *&T) {
	if(T) {
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
	}
	InitBiTree(&T);
	return OK;
}


/**
 * 函数名称: CreateBiTree
 * 初始条件：二叉树T已存在
 * 操作结果: 创建二叉树
 *取材于课本,依次输入节点值，并用key标记节点
 */
status CreateBiTree(BTN *&T) {
	int definition;
	printf("               输入key，切勿重复，为空则输入0：");
	scanf("%d",&definition);
	getchar();
	if(!definition) {
		T=NULL;
	} else {
		T=(BTN*)malloc(sizeof(BTN));
		T->data.key=definition;
		printf("               输入others：");
		scanf("%s",&T->data.others);
		getchar();
		getchar();
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}




/**
 * 函数名称: BiTreeEmpty
 * 初始条件：无
 * 操作结果: 二叉树判空
 *
 */
status BiTreeEmpty(BTN *T) {
	if(T) return FALSE;
	else return TRUE;
}





/**
 * 函数名称: BiTreeDepth
 * 初始条件：二叉树T已存在
 * 操作结果: 返回T的深度
 *
 */
status BiTreeDepth(BiTree T) {
	int depth = 0;
	if(T) {
		int lchilddepth = BiTreeDepth(T->lchild);
		int rchilddepth = BiTreeDepth(T->rchild);
		depth = (lchilddepth>=rchilddepth?(lchilddepth+1):(rchilddepth+1));
	}//使用递归,得到左右子树的深度,并比较大小,之后返回最大的深度
	return depth;
}


BiTNode* LocateNode(BiTNode *T,int e) {
	if (!T) return NULL;

	BTN *pForLocate=NULL;
	if(T->data.key==e) {
		pForLocate=T;
		return pForLocate;
	} else {
		pForLocate=LocateNode(T->lchild,e);
		if(pForLocate) 	return pForLocate;
		else {
			pForLocate=LocateNode(T->rchild,e);
			if(pForLocate) 	return pForLocate;
		}
	}
	return NULL;
}


status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!T) return ERROR;
    if(LocateNode(T,value.key)&&e!=value.key)//未找到关键字 
            return ERROR;
    if(T->data.key==e) {
        T->data.key=value.key;
        strcpy(T->data.others,value.others);
        return OK;
    }
    while(T){
        if(Assign(T->lchild,e,value))
            return Assign(T->lchild,e,value);
        else return Assign(T->rchild,e,value);
    }

    /********** End **********/
}


BTN* GetParent(BTN *T,int e) {
	if (!T) return NULL;
	BTN *pForParent=NULL;

	if(!T->lchild && !T->rchild) return NULL;
	else if(!T->lchild) {
		if(T->rchild->data.key==e) {
			pForParent=T;
			return pForParent;
		}
	} else if(!T->rchild) {
		if(T->lchild->data.key==e) {
			pForParent=T;
			return pForParent;
		}
	} else if(T->lchild->data.key==e||T->rchild->data.key==e) {
		pForParent=T;
		return pForParent;
	}

	pForParent=GetParent(T->lchild,e);
	if(pForParent) 	return pForParent;
	pForParent=GetParent(T->rchild,e);
	if(pForParent) 	return pForParent;

	return NULL;
}

BTN* GetSibling(BTN *T,int e) {
	BTN *pforsib = GetParent(T,e);//找双亲
	if (!pforsib) return NULL;
	else if(!pforsib->lchild||!pforsib->rchild) return NULL;
	else if(pforsib->lchild->data.key==e) return pforsib->rchild;
	else if(pforsib->rchild->data.key==e) return pforsib->lchild;
	else return NULL;//看起来无用，保证安全。
}

status InsertNode(BTN *&T,int e,int LR,BTN *&c) {
	BTN *pforinsert=LocateNode(T,e);
	if(!pforinsert) return ERROR;//关键字e的结点e不存在
	else if(LR==0) {
		if(!pforinsert->lchild) {
			pforinsert->lchild=c;
		} else {
			BTN *inserttemp=pforinsert->lchild;
			pforinsert->lchild=c;
			c->rchild=inserttemp;
		}
		return OK;
	} else if(LR==1) {
		if(!pforinsert->rchild) {
			pforinsert->rchild=c;
		} else {
			BTN *inserttemp=pforinsert->rchild;
			pforinsert->rchild=c;
			c->rchild=inserttemp;
		}
		return OK;
	} else {
		printf("               LR的值应为1或0");
		return ERROR;
	}

}

BiTree Getfather(BiTree T, KeyType e){
    if(T->lchild!=NULL){
        if(T->lchild->data.key == e)
            return T;
        else{
            BiTree left = Getfather(T->lchild,e);
            if(left) return left;
        }
    }
    if(T->rchild!=NULL){
        if(T->rchild->data.key == e)
            return T;
        else{
            BiTree right = Getfather(T->rchild,e);
            if(right) return right;
        } 
    }

}

status DeleteNode(BiTree &T,KeyType e)
//删除结点。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTree loce = LocateNode(T, e); 
    if (!loce) return ERROR;

    BiTree pl = NULL, pr = NULL, parent;
    parent = Getfather(T, e); 

    if (!loce->lchild && !loce->rchild && parent) // e是叶子（度为0）
    {
        if (parent->lchild == loce)
            parent->lchild = NULL;
        else parent->rchild = NULL;
        free(loce);
        loce = NULL;
        return OK;
    }

    if (loce != T) {//e不是根节点
        if (!parent) return ERROR;
        if (parent->lchild == loce)
            pl = loce;
        else  pr = loce;

        if (loce->lchild && !loce->rchild) //结点e不是根节点且度为1
        {
            if (pl)
                parent->lchild = loce->lchild; // parent为空指针的情况在上面已经讨论过
            else if (pr)
                parent->rchild = loce->lchild;
            free(loce);
            loce = NULL;
        } 
        else if (loce->rchild && !loce->lchild) //结点e不是根节点且度为1
        {
            if (pl)
                parent->lchild = loce->rchild;
            else if (pr)
                parent->rchild = loce->rchild;
            free(loce);
            loce = NULL;
        } 
        else if (loce->rchild && loce->lchild) //结点e不是根节点且度为2
        {
            if (parent->lchild == loce)
                parent->lchild = loce->lchild;
            if (parent->rchild == loce)
                parent->rchild = loce->lchild;
            BiTree temp1 = loce->lchild, temp2 = temp1->rchild;
            while (temp2) {
                temp1 = temp2;
                temp2 = temp2->rchild;
            }   
            temp1->rchild = loce->rchild;
            free(loce);
            loce = NULL;
        }
    } 


    else { //e是根节点
        if (loce->lchild == NULL && loce->rchild) // deg == 1
            T = loce->rchild;
        else if (loce->rchild == NULL && loce->lchild)
            T = loce->lchild;
        else if (!loce->rchild && !loce->lchild) {
            free(loce);
            return OK;
        } 
        else // deg == 2
        {
            BiTree temp1 = loce->lchild, temp2 = temp1->rchild;
            while (temp2) //找左子树的最右结点
            {
                temp1 = temp2;
                temp2 = temp2->rchild;
            }
            temp1->rchild = loce->rchild;
            T = loce->lchild;
            free(loce);
            loce = NULL;
        }
        return OK;
    }
    
    return OK;
    /********** End **********/
}
status PreOrderTraverse(BTN *T) { //非递归
	BTN *stack[NODENUMBER];//构建指针栈，空间换时间
	int top=0;//栈顶
	BTN *pforPreT=T;
	do {
		while(pforPreT) {
			if(top==NODENUMBER-1) return OVERFLOW;//栈满
			stack[top++]=pforPreT;//当前结点入栈
			visit(pforPreT);
			pforPreT=pforPreT->lchild;
		}
		if(top) {
			top--;
			pforPreT=stack[top]->rchild;
		}
	} while(top||pforPreT);
	return OK;
}

status InOrderTraverse(BTN *T) {
	if(T) {
		InOrderTraverse(T->lchild);
		visit(T);
		InOrderTraverse(T->rchild);
	}
	return OK;
}

status PostOrderTraverse(BTN *T) {
	if(T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(T);
	}
	return OK;
}

void OneLevel(BTN *T,int h) {
	if(T) {
		if(h==1) visit(T);
		else {
			OneLevel(T->lchild,h-1);
			OneLevel(T->rchild,h-1);
		}
	}
}

status LevelOrderTraverse(BTN *T) {
	if(!T) return ERROR;

	int d=BiTreeDepth(T);
	int i;
	for(i=1; i<=d; i++) {
		OneLevel(T,i);
	}
	return OK;
}

status TreeDisplay(BiTree T,int depth,status (* visit)(char e)) {
	if(!T) {
		printf("\n");
		return OK;
	}
	int i=0;
	for(; i<depth; i++)
		printf("                ");
	Dis_visit(*(T -> data.others));
	printf("\n");
	if(T->lchild||T->rchild) {
		TreeDisplay(T->lchild,depth+1,Dis_visit);
		TreeDisplay(T->rchild,depth+1,Dis_visit);
	}
	return OK;
}

void read(BTN *&T,FILE *fp) {
	int definition;
	fscanf(fp," %d ",&definition);
	if(!definition) T=NULL;
	else {
		T=(BTN*)malloc(sizeof(BTN));
		T->data.key=definition;

		fscanf(fp," %s ",&T->data.others);
		read(T->lchild,fp);
		read(T->rchild,fp);
	}
}

status ReadBiTree(BTN *&T) {
	FILE *fp;
	char filename[100];
	printf("               输入要读取的文件名：");
	scanf("%s",&filename);
	getchar();
	if ((fp=fopen(filename,"rb"))==NULL) {
		printf("               读取发生错误\n");
		return ERROR;
	}
	read(T,fp);

	fclose(fp);

	return OK;
}

status SaveBiTree(BTN *T) { //非递归先序储存
	FILE *fp;
	BTN *pforsave=T;
	BTN *stack[NODENUMBER];
	int top=0;
	char filename[100];
	printf("输入要存入的文件名: ");
	scanf("%s",&filename);

	if((fp=fopen(filename,"wb"))==NULL) {
		printf("存储发生错误\n");
		return ERROR;
	}

	do {
		while(pforsave) {
			if(top==NODENUMBER-1) return OVERFLOW;//栈满
			stack[top++]=pforsave;//当前结点入栈
			fprintf(fp," %d ",pforsave->data.key);//采用“ %d "是lr=3为了在读取时前后两个数据不会混淆
			fprintf(fp," %s ",pforsave->data.name);
			pforsave=pforsave->lchild;
		}
		fprintf(fp," %d ",0);
		if(top) {
			top--;
			pforsave=stack[top]->rchild;
		}
	} while(top||pforsave);
	fprintf(fp," %d ",0);
	fclose(fp);
	return OK;
}

int MPS(BiTree T)
{

	if(!T) return 0;
	int l=MPS(T->lchild);
	int r=MPS(T->rchild);
	return max(l,r)+T->data.key;
}
status MaxPathSum(BiTree T)
//最大路径和
{
	int ans=MPS(T);
	return ans;
}

BiTNode* LowestCommonAncestor(BiTree T,KeyType e1,KeyType e2)
//最近公共祖先
{
	if(LocateNode(T->lchild,e1))
    {
		if(LocateNode(T->lchild,e2))  return LowestCommonAncestor(T->lchild,e1,e2);
		return T;
	}
	else
	{
		if(LocateNode(T->rchild,e2))  return LowestCommonAncestor(T->rchild,e1,e2);
		return T;
	}
}
status InvertTree(BiTree &T)
//翻转二叉树
{
	if(!T)  return OK;
	BiTNode*t;
	t=T->lchild;
	T->lchild=T->rchild;
	T->rchild=t;
	InvertTree(T->lchild);
	InvertTree(T->rchild);
	return 1;
}
