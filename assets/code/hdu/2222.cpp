#include<stdio.h>
#include<string.h>

const int kind = 26; //字符种类 

struct node{ //Tire树节点结构 
    node *fail; //失败指针 
    node *next[kind]; //Tire每个节点的子节点 
    int count; //已当前节点为单词结尾的个数 
    node(){ //构造函数 
        fail = NULL;
        count = 0;
        memset(next, NULL, sizeof(next));
    }
}*que[1000000]; //队列 

char key_word[100]; //目的串 
char str[10000000]; //模式串 

int front, rear; //队列的头尾 

void  insert(char *str, node *root){ //把单词加入Tire中 
    node *p = root;
    int i = 0;
    int index;

    while(str[i]){ //将每个字母加入到Tire树中 
        index = str[i] - 'a';
        if(p->next[index] == NULL){
            p->next[index] = new node();
        }
        p = p->next[index];
        i++;
    }
    p->count++; //在单词的最后一个节点count++，代表一个单词
}

/*设这个节点上的字母为C，沿着他父亲的失败指针走，直到走到一个节点，他的儿子中也有字母为C的节点。然后把当前节点的失败指针指向那个字母也为C的儿子。如果一直走到了root都没找到，那就把失败指针指向root。*/
void build_ac_automation(node *root){ //构造失败指针 
    int i;

    root->fail = NULL;
    que[rear++] = root;
    while(front < rear){//队列 
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

//根据具体题目，重写查询方法
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

//应用举例，hdu2222
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