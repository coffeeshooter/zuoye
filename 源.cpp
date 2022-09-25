
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
//使用路径压缩
int UF::find(int x) {
    if (s[x] < 0)
        return x;
    else
        return s[x] = find(s[x]);
}
//按秩合并
void UF::unionUF(int root1, int root2) {
    if (s[root2] < s[root1])  //因为是负值，说明root2更深
        s[root1] = root2;
    else {
        if (s[root1] == s[root2])
            --s[root1];  //高度加1
        s[root2] = root1;
    }
}
 
int main() {
    int N, M, total;
    int x, y; //当前读入的路的两个端点
    cout << "请输入城镇数目N,及城镇道路数目M，M为0程序结束" << endl;
    while (scanf_s("%d%d", &N, &M) && N)         //读入n，如果n为0，结束
    {

        total = N - 1; //刚开始的时候，有n个城镇，一条路都没有,那么要修n-1条路才能把它们连起来
        UF uf(N);
        while (M--) {
            scanf_s("%d%d", &x, &y);
            while (x<1 || y<1 || x>N || y> N) {
                cout << "x,y必须大于1，小于N" << endl;
                scanf_s("%d%d", &x, &y);
            }
            //如果输入的边还没有连通，那么把他们连起来,此时需要修的路也少了一条
            if (uf.find(x - 1) != uf.find(y - 1)) {
                uf.unionUF(x - 1, y - 1);
                total--;
            }
        }
        printf("%d\n", total);
    }
}