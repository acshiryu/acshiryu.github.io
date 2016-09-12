/*
AC�Զ���ģ�棻
Insert()������
build_ac_automation()����ʧ��ָ�룻
query()��ѯ��
*/

#include<stdio.h>
#include<string.h>

const int kind = 26; //�ַ����� 

struct node{ //Tire���ڵ�ṹ 
    node *fail; //ʧ��ָ�� 
    node *next[kind]; //Tireÿ���ڵ���ӽڵ� 
    int count; //�ѵ�ǰ�ڵ�Ϊ���ʽ�β�ĸ��� 
    node(){ //���캯�� 
        fail = NULL;
        count = 0;
        memset(next, 0, sizeof(next));
    }
}*que[1000000]; //���� 

char key_word[100]; //Ŀ�Ĵ� 
char str[10000000]; //ģʽ�� 

int front, rear; //���е�ͷβ 

void  insert(char *str, node *root){ //�ѵ��ʼ���Tire�� 
    node *p = root;
    int i = 0;
    int index;

    while(str[i]){ //��ÿ����ĸ���뵽Tire���� 
        index = str[i] - 'a';
        if(p->next[index] == NULL){
            p->next[index] = new node();
        }
        p = p->next[index];
        i++;
    }
    p->count++; //�ڵ��ʵ����һ���ڵ�count++������һ������
}

/*������ڵ��ϵ���ĸΪC�����������׵�ʧ��ָ���ߣ�ֱ���ߵ�һ���ڵ㣬���Ķ�����Ҳ����ĸΪC�Ľڵ㡣Ȼ��ѵ�ǰ�ڵ��ʧ��ָ��ָ���Ǹ���ĸҲΪC�Ķ��ӡ����һֱ�ߵ���root��û�ҵ����ǾͰ�ʧ��ָ��ָ��root��*/
void build_ac_automation(node *root){ //����ʧ��ָ�� 
    int i;

    root->fail = NULL;
    que[rear++] = root;
    while(front < rear){//���� 
        node *temp = que[front];
        node *p = NULL;
        for(i = 0; i < 26; ++i){
            if(temp->next[i] != NULL){
                if(temp == root){
                    temp->next[i]->fail = root;
                }else{
                    p = temp->fail;
                    while(p != NULL){
                        if(p->next[i] != NULL){
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL)
                        temp->next[i]->fail = root;
                }
                que[rear++] = temp->next[i];
            }
        }
        front++;
    }
}

//���ݾ�����Ŀ����д��ѯ����
int query(node *root, char *str){
    int i = 0, cnt = 0;
    int index;
    int len = strlen(str);
    node *p = root;

    while(str[i]){
        index = str[i] - 'a';
        while(p->next[index] == NULL && p != root){
            p = p->fail;
        }
        p = p->next[index];
        if(p == NULL) p = root;
        node *temp = p;
        while(temp != root && temp->count != -1){
            cnt += temp->count;
            temp->count = -1;
            temp = temp->fail;
        }
        i++;
    }
    return cnt;
}

//Ӧ�þ�����hdu2222
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
        int n;
        scanf("%d",&n);
        node *root=new node;
        while(n--)
        {
            scanf("%s",key_word);
            insert(key_word,root);
        }
        build_ac_automation(root); 
        scanf("%s",str);
        printf("%d\n",query(root,str));
    }
    return 0;
}