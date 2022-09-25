
#include<vector>
#include<iostream>
using namespace std;

class UF
{
private:
    vector<int> s;
public:
    int find(int x);
    void unionUF(int root1, int root2);
    UF(int n) :s(n, -1) {};
};
//ʹ��·��ѹ��
int UF::find(int x) {
    if (s[x] < 0)
        return x;
    else
        return s[x] = find(s[x]);
}
//���Ⱥϲ�
void UF::unionUF(int root1, int root2) {
    if (s[root2] < s[root1])  //��Ϊ�Ǹ�ֵ��˵��root2����
        s[root1] = root2;
    else {
        if (s[root1] == s[root2])
            --s[root1];  //�߶ȼ�1
        s[root2] = root1;
    }
}
 
int main() {
    int N, M, total;
    int x, y; //��ǰ�����·�������˵�
    cout << "�����������ĿN,�������·��ĿM��MΪ0�������" << endl;
    while (scanf_s("%d%d", &N, &M) && N)         //����n�����nΪ0������
    {

        total = N - 1; //�տ�ʼ��ʱ����n������һ��·��û��,��ôҪ��n-1��·���ܰ�����������
        UF uf(N);
        while (M--) {
            scanf_s("%d%d", &x, &y);
            while (x<1 || y<1 || x>N || y> N) {
                cout << "x,y�������1��С��N" << endl;
                scanf_s("%d%d", &x, &y);
            }
            //�������ı߻�û����ͨ����ô������������,��ʱ��Ҫ�޵�·Ҳ����һ��
            if (uf.find(x - 1) != uf.find(y - 1)) {
                uf.unionUF(x - 1, y - 1);
                total--;
            }
        }
        printf("%d\n", total);
    }
}