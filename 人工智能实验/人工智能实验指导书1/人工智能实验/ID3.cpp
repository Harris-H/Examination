#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<set>
#include<cmath>
using namespace std;
const int maxn=3002;
set<int> se1,se2;
int IBV[8]={0,1,2,3,4,5,6,7};
int FPV[120],fnum;
int LPV[25],lnum;
struct Example{
    int IB;
    int FP;
    int LP;
    int res;
    Example(int IB=0,int FP=0,int LP=0,int res=0):
        IB(IB),FP(FP),LP(LP),res(res){}
}example[maxn];
int num;
struct Node{
    bool isleaf;  /**是否是叶子节点**/
    int responded; /**类别**/
    int property;  /**属性**/
    struct Node* son;  /**属性值对应的孩子节点**/
    int Size;   /**包含孩子节点数大小**/
};
class ID3{
private:
    Node *root;  /**根节点**/
    int record[maxn],vis[3]; /**record标记每条记录,vis标记每种属性**/
    int PE[120],NE[120]; /**PE记录正例个数,NE记录反例个数**/
public:
    ID3(){
        root=(Node *)malloc(sizeof(Node));
        root->son=NULL;
        root->Size=0;
        memset(record,0,sizeof(record));
        memset(vis,0,sizeof(vis));
    }
    void Destroy(Node* r){
        if(r->son!=NULL){
            for(int i=0;i<r->Size;i++) Destroy(&(r->son[i]));
            free(r->son);
        }
    }
    ~ID3(){
        Destroy(root);
        free(root);
    }
/**============================================**/
    /**计算正例和反例的个数**/
    void CalExample(int step,int& a,int& b){
        for(int i=0;i<num;i++){
            if(record[i]!=step) continue;
            if(example[i].res==0) a++;
            else b++;
        }
    }
    /**设置标记**/
    void SetRecord(int choose,int i,int d){
        for(int j=0;j<num;j++){
            if(choose==0&&example[j].IB==IBV[i]) record[j]+=d;
            else if(choose==1&&example[j].FP==FPV[i]) record[j]+=d;
            else if(choose==2&&example[j].LP==LPV[i]) record[j]+=d;
        }
    }
    /**计算熵值**/
    double CalQ(int p,int n){
        if(p==0||n==0) return 0;
        double a=p*1.0/(p+n);
        double b=n*1.0/(p+n);
        return -a*log2(a)-b*log2(b);
    }
    /**二分查找属性值对应的下标**/
    int BIS(int key,int *A,int n){
        int x=0,y=n-1,mid;
        while(x<=y){
            mid=(x+y)/2;
            if(key==A[mid]) return mid;
            else if(key<A[mid]) y=mid-1;
            else x=mid+1;
        }
        return -1;
    }
    /**计算E(pi,ni)之和**/
    double CalE(int choose,int step,int a,int b){
        memset(PE,0,sizeof(PE));
        memset(NE,0,sizeof(NE));
        for(int j=0;j<num;j++){
            if(record[j]!=step) continue;
            int pos;
            if(choose==0) pos=BIS(example[j].IB,IBV,8);
            else if(choose==1) pos=BIS(example[j].FP,FPV,fnum);
            else pos=BIS(example[j].LP,LPV,lnum);

            if(pos!=-1&&example[j].res==1) PE[pos]++;
            else if(pos!=-1&&example[j].res==0) NE[pos]++;
        }
        int Size;
        if(choose==0) Size=8;
        else if(choose==1) Size=fnum;
        else Size=lnum;

        double ret=0;
        for(int i=0;i<Size;i++){
            ret+=1.0*(PE[i]+NE[i])/(a+b)*CalQ(PE[i],NE[i]);
        }
        return ret;
    }
    void BuildTree(){tot=0; dfs(root,0); }
    int tot;
    void dfs(Node* x,int step){
        int a=0,b=0;
        CalExample(step,a,b); /**计算所有的正反例**/
        //printf("%d\n",++tot);
        if(a==0&&b==0){  /**未知**/
            x->isleaf=true;
            x->responded=-1;
            x->son=NULL;
            return;
        }
        else if(a==0){   /**全是1类**/
            x->isleaf=true;
            x->responded=1;
            x->son=NULL;
            return;
        }
        else if(b==0){   /**全是0类**/
            x->isleaf=true;
            x->responded=0;
            x->son=NULL;
            return;
        }
        if(vis[0]&&vis[1]&&vis[2]){ /**所有属性都被用完**/
            x->isleaf=true;
            x->responded=(a>b?0:1);
            x->son=NULL;
            return;
        }
        double maxq=-1.0;
        int choose=-1;
        for(int i=0;i<3;i++){
            if(vis[i]) continue;
            double I=CalQ(a,b);
            double E=CalE(i,step,a,b);

            double gain=I-E;
            if(maxq<gain){
                maxq=gain;
                choose=i;
            }
        }
        /**非叶子节点**/
        x->isleaf=false;
        x->property=choose;
        vis[choose]++;

        if(choose==0) x->Size=8;
        else if(choose==1) x->Size=fnum;
        else x->Size=lnum;
        x->son=(Node *)malloc(x->Size*sizeof(Node));

        for(int i=0;i<x->Size;i++){
            SetRecord(choose,i,1);
            dfs(&(x->son[i]),step+1);
            SetRecord(choose,i,-1);
        }
        vis[choose]--;
        return;
    }
    int GetResponded(Node* x,int IB,int FP,int LP){
        if(x->isleaf) return x->responded;
        int pos=-1;
        if(x->property==0) pos=BIS(IB,IBV,8);
        else if(x->property==1) pos=BIS(FP,FPV,fnum);
        else pos=BIS(LP,LPV,lnum);
        if(pos==-1) return -1;
        return GetResponded(&(x->son[pos]),IB,FP,LP);
    }
    int Query(int IB,int FP,int LP){
        return GetResponded(root,IB,FP,LP);
    }
};
int main(){
    FILE *fp=fopen("in.txt","r");
    int a,b,c,d;
    se1.clear();
    se2.clear();
    num=0;
    int input_k=0;
    printf("从文件中输入所有数据\n\n");
    while(fscanf(fp,"%d,%d,%d,%d",&a,&b,&c,&d)!=EOF){
        se1.insert(b);
        se2.insert(c);
        example[num++]=Example(a,b,c,d);
    }
    fnum=0;
    for(set<int>::iterator it=se1.begin();it!=se1.end();it++) FPV[fnum++]=*it;
    lnum=0;
    for(set<int>::iterator it=se2.begin();it!=se2.end();it++) LPV[lnum++]=*it;
    ID3 id3;
    printf("ID3算法建立决策树\n\n");
    id3.BuildTree();
    int IB,FP,LP;
    printf("输入数据判断是否是潜在客户:\n");
    while(scanf("%d%d%d",&IB,&FP,&LP)!=EOF){
        int res=id3.Query(IB,FP,LP);
        if(res==-1) printf("未知\n");
        else if(res==1) printf("潜在客户\n");
        else printf("非潜在客户\n");
    }
    return 0;
}
/*
4 200210 200601
5 200301 200601
6 200411 200601
5 199609 200603
6 200310 200512
4 200502 200601
5 200309 200602
6 200110 200603
6 199710 200603
5 200310 200601
*/
