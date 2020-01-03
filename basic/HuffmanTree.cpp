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
	if(s2<s1) { //��֤s1���±�ֵС��s2ʵ�����������Ĵ�С�Գ�
		s1=s1+s2;
		s2=s1-s2;
		s1=s1-s2;
	}
}

void CreateHuffmanTree(HuffmanTree &HT,int n) {
	int i,m,s1,s2;
	if(n<=1) return;
	m=2*n-1;
	HT=new HTNode[m+1]; //0�ŵ�Ԫδ�ã�HT[m]��ʾ���ڵ�
	for(i=1; i<=m; ++i) {
		HT[i].lch=0;	//��2n-1��Ԫ�ص�lch��rch��parent��Ϊ0
		HT[i].rch=0;
		HT[i].parent=0;
	}
	for(i=1; i<=n; ++i)
		cin>>HT[i].data>>HT[i].weight; //����ǰn��Ԫ�ص�weightֵ
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
	HC=new char*[n+1];	//����n���ַ������ͷָ��ʸ��
	char *cd=new char[n];	//������ʱ��ű���Ķ�̬����
	cd[n-1]='\0';	//���������
	for(i=1; i<=n; i++) {	//����ַ������������
		start=n-1;
		c=i;
		f=HT[i].parent;
		while(f!=0) {	//��Ҷ�ӽڵ㿪ʼ���ϻ��ݣ�ֱ�����ڵ�
			--start;	//����һ��start��ǰָһ��λ��
			if(HT[f].lch==c) cd[start]='0';	//���c��f�����ӣ������ɴ���0
			else			 cd[start]='1';	//���c��f���Һ��ӣ������ɴ���1
			c=f;
			f=HT[f].parent;	//�������ϻ���
		}		//�����i���ַ��ı���
		HC[i]=new char[n-start];	//Ϊ��i���ַ����������ռ�
		strcpy(HC[i],&cd[start]);	//����õı������ʱ�ռ�cd���Ƶ�HC��ǰ����
	}
	delete cd;	 //�ͷ���ʱ�ռ�
}

void PrintHT(HuffmanTree HT,int n){
	cout <<"�±�\t"<<"����\t"<<"Ȩֵ\t"<< "˫��\t" << "����\t" << "�Һ���" << endl;
	for (int i = 1;i<=2*n-1;i++)
	{
		cout <<i<< "\t"<<HT[i].data<<"\t"<<HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lch << "\t" << HT[i].rch << endl;
	}
}

void PrintHC(HuffmanCode HC,HuffmanTree HT,int n){
	for(int i=1; i<=n; i++)
		cout<<"��"<<i<<"���ַ��ı���->"<<HT[i].data<<":"<<HC[i]<<endl;
}

void Encode(HuffmanTree HT) 
{
	string s;
	int root=1;//��¼���ڵ���±�
	cout << "������01�ַ���:" << endl;
	cin >> s;
	while (HT[root].parent != 0) root++;
	int j = root;
	for (int i=0;i<s.length();i++)//���������01��
	{
		if ('0' == s[i])
		{
			j = HT[j].lch;
		}
		else
		{
			j = HT[j].rch;
		}
		if (HT[j].lch == 0 && HT[j].rch == 0)//����Ҷ�ڵ�
		{
			cout << HT[j].data;
			j = root;//���ظ��ڵ����
		}
	}
	cout << endl;
}

void WPL(HuffmanTree HT,HuffmanCode HC){
	double WPL=0;
	for (int i = 1;;i++)
	{
		if (HT[i].lch != 0 || HT[i].rch != 0)break;
		WPL += HT[i].weight*strlen(HC[i]);//Ȩֵ��·�����ȣ����볤�ȣ�	
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







