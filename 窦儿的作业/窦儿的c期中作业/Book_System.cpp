#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define ERROR 0
#define OK 1
#define MAXSIZE 50//�ַ���������󳤶� 50
#define Max_Num 39877     //���ͼ���¼�� 
#define k 96			//k���� 
typedef int Status;
typedef int ElemType;
int flag=0;
//ͼ����Ϣ
typedef struct Book{
    char book_id[MAXSIZE];//��� 
    char book[MAXSIZE];//����
    char author[MAXSIZE];//����
    char publisher[MAXSIZE];//������ 
    int money;			//��� 
    char introduction[MAXSIZE];//���
    int num;					//���� 
    struct Book *next;
}LBook,*LinkBook;

typedef LinkBook HashList[Max_Num];//��Ź�ϣ�� 
LinkBook L;
HashList H; 
int cmp(LinkBook a,LinkBook b,int ctr){
	switch(ctr){
		case 1:
			return strcmp(a->book_id,b->book_id);
		case 2:
			return strcmp(a->book,b->book);	
		case 3:
			return strcmp(a->author,b->author);
		case 4:
			return strcmp(a->publisher,b->publisher);		
	}
}

//��ʼ����ϣ��
void InitHash(HashList &H){
	for(int i=0;i<=Max_Num;i++)
		H[i]=NULL; 
	return;
} 

//���㲢�������book_id�Ĺ�ϣֵ
int getHash(char *book_id,HashList H){
	int len =strlen(book_id);
    int val = 0;
	for(int i = 0; i < len ; i++){
		val =((val*k)%Max_Num + book_id[i]-' ' + 1)%Max_Num;
	}			//k������ת��Ϊʮ������ ,�����н���ȡģ 
	int d=1; //ƫ���� 
	while(H[val]!=NULL){//������ͻ 
		if(strcmp(H[val]->book_id,book_id)==0){//��ͬ�ַ��������ĳ�ͻ
			break;
		} 
		else{	//��ͬ�ַ��������ĳ�ͻ����������̽����ɢ�� 
			val=(val+d)%Max_Num;
			d++;
		} 
	}
    return val;//���ع�ϣֵ 
}

//�������ͼ���¼��ȫ����Ϣ 
void printBook(LinkBook p){
	if(p==NULL){
		printf("�����ڸ�ͼ��!\n");
		return; 
	}
	printf("------------------>\n");
	printf("�����Ǹ�ͼ��ȫ����Ϣ��\n");
	printf("ͼ�����:%s\nͼ������:%s\nͼ������:%s\n�ִ���:%d\n���:%d\n",p->book_id,p->book,p->author,p->num,p->money);
	printf("������:%s\n���:%s\n",p->publisher,p->introduction);
    printf("------------------>\n"); 
    return;
}

//��ʼ��ͼ����Ϣ 
Status InitBook(LinkBook &L){
    L=(LinkBook)malloc(sizeof(LBook));
    if(!L) return ERROR;
    L->next=NULL;
    L->num=0;
    return OK;
} 
 
//����ͼ����Ϣ
void DisBook(LinkBook L){
    LBook *p;
    p=L->next;//ָ���һ���ڵ� 
    if(p==NULL){
    	printf("û��ͼ�飡\n");
    	system("pause");
    	return;
	} 
    printf("��ʼչ������ͼ��Ĳ�����Ϣ\n");
    printf("------------------>\n");
    while(p)//p!=NULL
    {
        printf("ͼ�����:%s\nͼ������:%s\nͼ������:%s\n�ִ���:%d\n���:%d\n",p->book_id,p->book,p->author,p->num,p->money);
        printf("------------------>\n");
        p=p->next;
    }
    system("pause");
} 

 //ɾ��ͼ����Ϣ����,�������ɾ�� 
Status DelBook(LinkBook &L,char *i){ 
    LBook *p=L;
    while(p->next)
    {
        if(strcmp(p->next->book_id,i)==0){
            Book *s=p->next;
            p->next=s->next;//p->next=p->next->next
            free(s);
            L->num--;//������¼�� 
            return OK;
        }
         
        p=p->next;
    }
        return ERROR;
}

//��ʼ���ͼ����Ϣ(ǰ�巨)--����
Status AddBook(LinkBook &L,int e){
    LBook *p;
    int i,j;
    fflush(stdin);
    for(i=0;i<e;i++){
        p=(LinkBook)malloc(sizeof(LBook));
        printf("��ѡ��ͼ���ź�����:\n");
        scanf("%s%d",p->book_id,&j);
        p->num=j;
        printf("�����ͼ������ֺ��������Լ���������:\n");
        scanf("%s%s%s",p->book,p->author,p->publisher);
        printf("�����ͼ��ļ۸�:\n");
        scanf("%d",&j);
        p->money=j;
        printf("�����ͼ��ļ��:\n");
        scanf("%s",p->introduction);
        p->next=L->next;
        L->next=p;
        L->num++;		//��¼�� 
        int val=getHash(p->book_id,H);
    	H[val]=p;
    }
	return OK;   
}
 
//��ͼ����Ų���ͼ����Ϣ�����ظ�ͼ��ĵ�ַ 
LinkBook GetBook(LinkBook L,char *n,HashList H){
    int val=getHash(n,H);
	if(H[val]==NULL || strcmp(H[val]->book_id,n)==0)
		return H[val];
	else return NULL;
}

//��ͨ����������ͼ���ַ 
Status Search(){ 
    fflush(stdin);
    while(true){
		printf("------------------>\n");
		printf("������Ҫ����������:\n");
		printf("1.���  2.����  3.����  4.������  0.�˳�\n");
		int ctr;
		scanf("%d",&ctr);
		char s[MAXSIZE];
		LinkBook p=L->next;
		switch(ctr){
			case 1:
				scanf("%s",s);
				while(p){
					if(strcmp(p->book_id,s)==0)
						printBook(p);
					p=p->next;
				}
    			break;
    		case 2:
    			scanf("%s",s);
				while(p){
					if(strcmp(p->book,s)==0)
						printBook(p);
					p=p->next;
				}
    			break;
    		case 3:
    			scanf("%s",s);
				while(p){
					if(strcmp(p->author,s)==0)
						printBook(p);
					p=p->next;
				}
    			break;
    		case 4:
    			scanf("%s",s);
				while(p){
					if(strcmp(p->publisher,s)==0)
						printBook(p);
					p=p->next;
				}
    			break;
    		case 0:
    			return OK;
    		default:
    			printf("��Чָ�����������!\n");
    			break;
		} 
		system("pause"); 
		system("cls");	
	} 
}

//ͼ������ 
//ð���������Ҫ˼���������ԱȽϣ�ÿ�Ƚ�һ�λ��һ��������С����������� 
void BubbleSort(int (*cmp)(LinkBook,LinkBook,int)){
	printf("��ѡ������Ĺؼ���\n");
	printf("1.���  2.����  3.����  4.������\n");
	int ctr;
	scanf("%d",&ctr);
	LinkBook cur,tail;
	cur=L;
	tail=NULL; 
	if(cur==NULL||cur->next==NULL){
		return;
	}
	while(cur!=tail){
		while(cur->next!=tail){
			if(cmp(cur, cur->next,ctr)>0){	
				//������ϣ
				int p1=getHash(cur->book_id,H),p2=getHash(cur->next->book_id,H);
				LBook *htmp=H[p1];
				H[p1]=H[p2];
				H[p2]=htmp;
				//cur->next��cur��ֵ
				LBook tmp;
				strcpy(tmp.author,cur->author);
				strcpy(tmp.book,cur->book);
				strcpy(tmp.book_id,cur->book_id);
				strcpy(tmp.introduction,cur->introduction); 
				tmp.money=cur->money;
				tmp.num=cur->num;
				strcpy(tmp.publisher,cur->publisher);
				
				strcpy(cur->author,cur->next->author);
				strcpy(cur->book,cur->next->book);
				strcpy(cur->book_id,cur->next->book_id);
				strcpy(cur->introduction,cur->next->introduction); 
				cur->money=cur->next->money;
				cur->num=cur->next->num;
				strcpy(cur->publisher,cur->next->publisher); 
				
				strcpy(cur->next->author,tmp.author);
				strcpy(cur->next->book,tmp.book);
				strcpy(cur->next->book_id,tmp.book_id);
				strcpy(cur->next->introduction,tmp.introduction); 
				cur->next->money=tmp.money;
				cur->next->num=tmp.num;
				strcpy(cur->next->publisher,tmp.publisher);  
			}
			cur=cur->next;
		}
		tail=cur;
		cur=L;
	}
}

//�޸�ͼ����Ϣ
Status AlterBook(LinkBook p){
	fflush(stdin);
    if(p==NULL){
    	printf("�����ڸ�ͼ��!\n");
    	system("pause");
    	return ERROR;
	}
	while(true){
		system("pause");
		printf("------------------>\n");
		printf("ͼ��鵽,��ѡ���޸������޸�:\n");
		printf("1.���  2.����  3.����  4.������  5.���  6.����  7.���  0.�˳�\n");
		int ctr;
		scanf("%d",&ctr);
		switch(ctr){
			case 1:
				printf("ͼ�����Ϊ:%s\n���޸�:",p->book_id);
    			scanf("%s",p->book_id);
    			break;
    		case 2:
    			printf("����Ϊ:%s\n���޸�:",p->book);
    			scanf("%s",p->book);
    			break;
    		case 3:
    			printf("����:%s\n���޸�:",p->author);
    			scanf("%s",p->author);
    			break;
    		case 4:
    			printf("������:%s\n���޸�:",p->publisher);
    			scanf("%s",p->publisher);
    			break;
    		case 5:
    			printf("���:%d\n���޸�:",p->money);
    			scanf("%d",p->money);
    			break;
    		case 6:
    			printf("����:%d\n���޸�:",p->num);
    			scanf("%d",p->num);
    			break;
    		case 7:
				printf("���:%s\n���޸�:",p->introduction);
    			scanf("%s",p->introduction);
    			break; 
    		case 0:
    			return OK;
    		default:
    			printf("��Чָ�����������!\n");
    			break;
		} 	
	} 
}

//����
Status Save(){	
	fflush(stdout);
	printf("�����С���\n"); 
	FILE *f = fopen("data.txt", "w");
	LinkBook p=L->next;
	fprintf(f,"%d\n",L->num);
	while(p){
		fprintf(f,"%s\n%s\n%s\n%s\n%s\n",p->book_id,p->book,p->author,p->publisher,p->introduction);
		fprintf(f,"%d\n%d\n",p->num,p->money); 
		p=p->next;
	}
	fclose(f);
	system("cls");
	printf("������ɣ�\n");
	system("pause");
	return OK;
}

//���� 
Status Read(){
	fflush(stdin);
	printf("�����С���\n"); 
	FILE *f = fopen("data.txt", "r");
	int tmp;
	fscanf(f,"%d",&tmp);
	LBook *p;
	while(tmp--){
		int t1,t2;
		p=(LinkBook)malloc(sizeof(LBook));
		fscanf(f,"%s%s%s%s%s",p->book_id,p->book,p->author,p->publisher,p->introduction);
		fscanf(f,"%d%d",&t1,&t2);
		p->num=t1,p->money=t2;
		p->next=L->next;
        L->next=p;
        L->num++;		//��¼�� 
        int val=getHash(p->book_id,H);
    	H[val]=p;	
	} 
	fclose(f);
	system("cls");
	printf("������ɣ�\n");
	system("pause");
	return OK;
} 

void function(){//���ܲ˵� 
    printf("<------------------------------------------------>\n");
    printf("<-----------0-��ӭ����ͼ�����ϵͳ!-0------------>\n");
    printf("<------------------------------------------------>\n");
    printf("<--------------��ѡ�����¹���-------------------->\n");
    printf("<--------------1.�鿴����ͼ���¼---------------->\n");
    printf("<--------------2.���ͼ���¼-------------------->\n");
    printf("<--------------3.ɾ��ͼ���¼-------------------->\n");
    printf("<--------------4.�޸�ͼ���¼-------------------->\n");
    printf("<--------------5.����---------------------------->\n");
    printf("<--------------6.����---------------------------->\n");
    printf("<--------------7.��ſ���ͼ�����---------------->\n");
    printf("<--------------8.��ͨͼ�����-------------------->\n");
    printf("<--------------9.����ͼ��------------------------>\n");
    printf("<--------------0.�˳�---------------------------->\n");
} 
void tool(){//����ʵ�� 
    InitBook(L);
    InitHash(H);
    int i,choose;
    char n[MAXSIZE]; 
    ElemType e;
    while(true){
    	fflush(stdin);
    	system("cls");
		function();
        printf("��������Ҫѡ��Ĺ��ܣ�\n��ѡ��:");
        scanf("%d",&choose);
        system("cls");
        switch(choose){
        	case 1:			//�鿴����ͼ�� 
                DisBook(L);
                break;
            case 2:			//����ͼ���¼ 
                printf("���������ֲ�ͬ��ͼ��:\n");
                scanf("%d",&e);
                AddBook(L,e);
                break;
           	case 3:				//ɾ��ͼ�� 
                printf("������Ҫɾ����ͼ�����:\n");
                scanf("%s",n);
                if(DelBook(L,n)){
                    printf("ɾ���ɹ�!\n");
                }
                else{
                    printf("��ͼ�鲻���ڣ������Ƿ������ͼ���!\n");
                }
                system("pause");
                break;
            case 4:				//�޸�ͼ�� 
                printf("������Ҫ�޸ĵ�ͼ���:\n");
                scanf("%s",n);
                AlterBook(GetBook(L,n,H));
                break;
            case 5:				//����
            	if(!flag){
            		printf("���棡��ǰδ���̣����̽�����ԭ���ݣ�\n");
            		printf("�Ƿ������y/n��:");
            		char tmp;
            		fflush(stdin);
					scanf("%c",&tmp);
					system("pause");
					if(tmp!='y' && tmp!='Y') break; 
				}
            	Save();
				break; 
            case 6: 			//����
				if(Read())
					flag=1; 
				break;
            
            case 7:				//��ż��� 
            	printf("������Ҫ������ͼ�����:\n");
                scanf("%s",n);
                printBook(GetBook(L,n,H));
                system("pause");
				break; 
            case 8://��ͨ���� 
                Search();
                break;
            case 9://ͼ������ 
            	BubbleSort(cmp);
            	printf("����ɹ���\n");
				system("pause"); 
                break;
            case 0://�˳����� 
                printf("�ݰݣ�\n");
                exit(0);
            default:
                printf("��Ч���룬������ѡ��\n");
                system("pause");
                break;
        }
    }
}
int main()
{
	tool();
}
