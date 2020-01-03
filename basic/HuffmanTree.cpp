#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
typedef char **HuffmanCode;
using namespace std;
typedef struct {
	int weight;
	int parent,lch,rch;
	char data;
} HTNode,*HuffmanTree;


void Select(HuffmanTree &HT,int n,int &s1,int &s2) {
	int i;
	int min=0;
	for(i=1; i<=n; ++i) {
		if(HT[i].parent==0) {
			if(min==0) {
				min=HT[i].weight;
				min++;
				s1=i;
			}
			if(HT[i].weight<min) {
				min=HT[i].weight;
				s1=i;
			}
		}
	}
	min=0;
	for(i=1; i<=n; ++i) {
		if((HT[i].parent==0)&&(i!=s1)) {
			if(min==0) {
				min=HT[i].weight;
				min++;
				s2=i;
			}
			if(HT[i].weight<min) {
				min=HT[i].weight;
				s2=i;
			}
		}
	}
	if(s2<s1) { //保证s1的下标值小与s2实现左右子树的大小对称
		s1=s1+s2;
		s2=s1-s2;
		s1=s1-s2;
	}
}

void CreateHuffmanTree(HuffmanTree &HT,int n) {
	int i,m,s1,s2;
	if(n<=1) return;
	m=2*n-1;
	HT=new HTNode[m+1]; //0号单元未用，HT[m]表示根节点
	for(i=1; i<=m; ++i) {
		HT[i].lch=0;	//将2n-1个元素的lch，rch，parent置为0
		HT[i].rch=0;
		HT[i].parent=0;
	}
	for(i=1; i<=n; ++i)
		cin>>HT[i].data>>HT[i].weight; //输入前n个元素的weight值
	for(i=n+1; i<=m; i++) {
		Select(HT,i-1,s1,s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lch=s1;
		HT[i].rch=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		HT[i].data = ' ';
	}
}

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n) {
	int start,i,c,f;
	HC=new char*[n+1];	//分配n个字符编码的头指针矢量
	char *cd=new char[n];	//分配临时存放编码的动态数组
	cd[n-1]='\0';	//编码结束符
	for(i=1; i<=n; i++) {	//逐个字符求哈夫曼编码
		start=n-1;
		c=i;
		f=HT[i].parent;
		while(f!=0) {	//从叶子节点开始向上回溯，直到根节点
			--start;	//回溯一次start向前指一个位置
			if(HT[f].lch==c) cd[start]='0';	//结点c是f的左孩子，则生成代码0
			else			 cd[start]='1';	//结点c是f的右孩子，则生成代码1
			c=f;
			f=HT[f].parent;	//继续向上回溯
		}		//求出第i个字符的编码
		HC[i]=new char[n-start];	//为第i个字符串编码分配空间
		strcpy(HC[i],&cd[start]);	//将求得的编码从临时空间cd复制到HC当前行中
	}
	delete cd;	 //释放临时空间
}

void PrintHT(HuffmanTree HT,int n){
	cout <<"下标\t"<<"数据\t"<<"权值\t"<< "双亲\t" << "左孩子\t" << "右孩子" << endl;
	for (int i = 1;i<=2*n-1;i++)
	{
		cout <<i<< "\t"<<HT[i].data<<"\t"<<HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lch << "\t" << HT[i].rch << endl;
	}
}

void PrintHC(HuffmanCode HC,HuffmanTree HT,int n){
	for(int i=1; i<=n; i++)
		cout<<"第"<<i<<"个字符的编码->"<<HT[i].data<<":"<<HC[i]<<endl;
}

void Encode(HuffmanTree HT) 
{
	string s;
	int root=1;//记录根节点的下标
	cout << "请输入01字符串:" << endl;
	cin >> s;
	while (HT[root].parent != 0) root++;
	int j = root;
	for (int i=0;i<s.length();i++)//遍历输入的01串
	{
		if ('0' == s[i])
		{
			j = HT[j].lch;
		}
		else
		{
			j = HT[j].rch;
		}
		if (HT[j].lch == 0 && HT[j].rch == 0)//到达叶节点
		{
			cout << HT[j].data;
			j = root;//返回根节点继续
		}
	}
	cout << endl;
}

void WPL(HuffmanTree HT,HuffmanCode HC){
	double WPL=0;
	for (int i = 1;;i++)
	{
		if (HT[i].lch != 0 || HT[i].rch != 0)break;
		WPL += HT[i].weight*strlen(HC[i]);//权值×路径长度（编码长度）	
	}
	cout << "WPL:" << WPL << endl;
}
int main() {
	HuffmanTree HT;
	HuffmanCode HC;
	int i,n=8;
	CreateHuffmanTree(HT,n);
	PrintHT(HT,n);
	CreateHuffmanCode(HT,HC,n);
	PrintHC(HC,HT,n);
	//Encode(HT);
	WPL(HT,HC);
	return 0;
}







