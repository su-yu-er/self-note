



![image-20230510171754608](D:\Users\suyu\Pictures\Typora-picture\image-20230510171754608.png)

# 一、冒泡排序函数



冒泡排序的原理是：从左到右，相邻元素进行比较。每次比较一轮，就会找到序列中最大的一个或最小的一个。这个数就会从序列的最右边冒出来。

以从小到大排序为例，第一轮比较后，所有数中最大的那个数就会浮到最右边；第二轮比较后，所有数中第二大的那个数就会浮到倒数第二个位置……就这样一轮一轮地比较，最后实现从小到大排序。



## A - 进阶模拟qsort

```c
#include<stdio.h>
#include<stdlib.h>

//交换函数（通过交换每一个字节达到对不同类型数据的交换）
void swap(char* x, char* y, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char c = *x;
		*x = *y;
		*y = c;
		x++;
		y++;
	}
}

/*
  width=sizeof(arr[0]),代表一个数据的字节数。
  sz，代表数据的个数。
*/
//实现bobble排序程序员不一定知道未来排序的数据类型
void bobble_sort(void* base, int sz, int width, int(*cmp)(void* a, void* b))
{
	int i = 0, j = 0;
	//趟数
	for (i = 0; i < sz - 1; i++)
2	{
		//每趟比较的对数
		for (j = 0; j < sz - 1 - i; j++)
		{
			//两个元素比较
			if (cmp((char*)base + j * width, (char*)base + (j+1) * width) > 0)
				//交换
				swap((char*)base + j * width, (char*)base + (j+1) * width, width);
		}		
	}
}

int cmp(const void* x, const void* y)
{
	int* a = (int*)x;
	int* b = (int*)y;
	return *a - *b;
}

int main()
{
	int i = 0;
	int arr[5] = { 2,5,1,6,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	//qsort(arr,5, sizeof(arr[0]), cmp);
	bobble_sort(arr, sz, sizeof(arr[0]),cmp);

	for (i = 0; i < 5;i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
```





# 二、dfs与bfs

#### 1、什么是搜索

**dfs(暴力搜索)**  

**bfs?（搜索最小，最少**）

连通块

常见 染色法

A* 

#### 2、dfs和bfs模板



dfs一定需要传入参数，来转移状态，

```c
void dfs(参数)//一般都是层数
{
    if (不合法状态)
        return;
    if (当前为终点/边界)
    {
        进行或计数统计答案等操作
        return;//终止当前函数}
    }//终止条件的
    for (枚举当前的所有方案)
    {
        if(当前方案合法/当前方案没有被标记过)
        {
            记录当前方案
            标记当前方案
            dfs(下一位置)
            还原标记
        }
    }
}
```



bfs看心情

![img](https://img-blog.csdnimg.cn/20210217121643395.gif)

```c
void bfs(起始点) 
{
    将起始点放入队列中;
    标记起始点访问;
	while (如果队列不为空)
    {
		访问队列首元素;
		删除队列首元素;
		for (x 所有相邻的点)
        {
			if (该点未访问且合法)
            {
				将该点加入队列末尾; 
			}
		} 
	} 
	队列为空，BFS结束; 
}
```





## 案列

## dfs（深度搜索）

### [A - 全排列问题](https://vjudge.csgrandeur.cn/contest/541415#problem/A)

```C++
#include<iostream>
#include<iomanip>

using namespace std;
const int N=100;
int n,ans[N];
bool vis[N];

void print()
{
	for(int i=1;i<=n;i++)
        cout<<setw(5)<<ans[i];
	cout<<endl;
}

bool rule(int x)
{
	return !vis[x];
}

void dfs(int cnt)
{
    //cnt是层数
	if(cnt==n+1)
    {
		print();//打印ans数组
		return ;
	}
	for(int i=1;i<=n;i++)
    {
		if(rule(i))
        {
			ans[cnt]=i;
			vis[i]=1;
			dfs(cnt+1);
			vis[i]=0;
		}
	}
}

int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
```



### [B - Lake Counting S](https://vjudge.csgrandeur.cn/contest/541415#problem/B)

```C++
#include<iostream>
#include<iomanip>

using namespace std;
const int N=105;
int n,ans[N],m;
bool vis[N][N];
char s[N][N];
int dis[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};



bool rule(int x,int y)
{
    //是否走过，是否越界，是否能够走
	return !vis[x][y]&&x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='W';
}

void dfs(int x,int y)
{
    //x,y下标
	for(int i=0;i<8;i++)
    {
		int dx=x+dis[i][0];
		int dy=y+dis[i][1];
		if(rule(dx,dy))
        {
			vis[dx][dy]=1;
			s[dx][dy]='.';
			dfs(dx,dy);
		}
	}
}

int main()
{
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='W')
				dfs(i,j),s[i][j]='.',ans++;
	cout<<ans<<endl;
	return 0;
}
```





### C - 全组合

题目：

实质上就是N个数字遍历 例如N = 3 分别遍历出：
1
2
3
1 2
1 3
2 3
1 2 3
遍历以上的饲料是否符合条件
核心程序就是

```c++
#include <iostream>
#include <cstdio>
#define MAX 22
using namespace std;
int n,r,x; 
int a[MAX] = {1};
bool visited[MAX];

void Dfs(int k)
{
	int i;
	if(k == x + 1)
	{
		for(i = 1;i <= x;i++)
		{
			printf("%3d",a[i]);
		}
		return 0;
	}
	for(i = a[k - 1];i <= n;i++)
	{
		if(visited[i] == 0)
		{
			visited[i] = 1;
			a[k] = i;
			Dfs(k + 1);
			visited[i] = 0;
		}
	}
}
int main()
{
    //n为排列组合的最大范围数。
    //r为排列组合的长度。
    //x为当前dfs的层数。
	cin >> n >> r;
	for(x = 1;x <= r;x++)
	{
		Dfs(1);
	}
	return 0;
}

```





## bfs（广度搜索）



### 小鳄鱼游泳

Description



小鳄鱼在泳池里洗完澡后，打算离开泳池，它在x11，y11处。出口在x22，y22处。现在给出一个 n×n 的地图，0表示可以通过，1表示不能通过，小鳄鱼只能垂直或水平行进。小鳄鱼要求出最短到达出口的距离（每两个相邻坐标间距离为1）。如果无论如何都不能到达出口，请输出-1。你能帮它解决吗？



Input

第1行包含一个数 n。

第2行到第 n+1行：整个地图描述（0表示可以通过，1表示不能通过，注意两个数之间没有空格）。

第 n+2行：四个数x11，y11，x22，y22。



Output

只有1行，即最短到达出口的距离。



Sample Input 1 

```
3
001
101
100
1 1 3 3
```

Sample Output 1

```
4
```

Hint

对于 20%数据，满足 1≤n≤100。

对于 100%数据，满足 1≤n≤1000。

```cpp
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1005;
char s[N][N];
int ans = 2147483647;
int n = 0;

bool rule(int x, int y) {
	bool ru = (x < n && x >= 0 && y < n && y >= 0 && s[y][x] == '0');
	return ru;
}
//BFS广度优先搜索（由于求最小值）
void Bfs(int x1, int y1, int x2, int y2) {
	queue<pair<int,int>>cque;
	cque.push({ x1, y1 });
	pair<int,int> cur;
	int roll = 0;
	char a = '1';
	s[y1][x1] = a;
	//队列不为空
	++a;
	while (!cque.empty()) {
		int count = 0;
		int len = cque.size();
		for (int i = 0; i < len; ++i) {
			cur = cque.front();	//获取队列首元素
			cque.pop();

			if (cur.first == x2 && cur.second == y2) {
				ans = min(ans, roll);
				return;
			}
			//上下左右四种分支
			if (rule(cur.first + 1, cur.second)) {
				x1 = cur.first + 1;
				cque.push({ x1,cur.second });
				s[cur.second][x1] = a; ++count;
			}
			if (rule(cur.first - 1, cur.second)) {
				x1 = cur.first - 1;
				cque.push({ x1,cur.second });
				s[cur.second][x1] = a; ++count;
			}
			if (rule(cur.first, cur.second + 1)) {
				y1 = cur.second + 1;
				cque.push({ cur.first,y1 });
				s[y1][cur.first] = a; ++count;
			}
			if (rule(cur.first, cur.second - 1)) {
				y1 = cur.second - 1;
				cque.push({ cur.first,y1 });
				s[y1][cur.first] = a; ++count;
			}
			if (count <= 0)
				continue;
		}
		++roll;	//步数加一
		a += 1;
	}	
	if (ans == 2147483647) {
		ans = -1;
		return;
	}
}


int main() {
	int x1, y1, x2, y2;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin>>s[i];
	cin >> x1 >> y1 >> x2 >> y2;
	//
	if (s[x1 - 1][y1 - 1] == '1')
		cout << -1;
	else {
		Bfs(x1 - 1, y1 - 1, x2 - 1, y2 - 1);
		cout << ans;
	}

	//cout << '\n';
	//for (int i = 0; i < n; ++i)
	//	cout << s[i] << '\n';
	return 0;
}
```



### A - 抓住那头牛

题目：农夫约翰被告知一头逃跑的奶牛的位置，想立即抓住她。他从数字线上的*点 N*（0 ≤ *N* ≤ 100，000）开始，母牛在同一数字线上的点 K （0 ≤ *K* ≤ 100，000）。 农夫约翰有两种交通工具：步行和传送。

*步行：FJ可以在一分钟内
从任何点X移动到*点X-1*或X + 1*传送：FJ可以在一分钟内从任何点X移动到2× *X*点。

如果这头牛不知道它的追逐，根本不动，农夫约翰需要多长时间才能取回它？

输入

第 1 行：两个空格分隔的整数：*N* 和 *K*

输出

第 1 行：农夫约翰抓住逃跑的牛所需的时间最短，以分钟为单位。

样本

| 输入复制 | 输出复制 |
| -------- | -------- |
| `5 17`   | `4`      |

提示

农夫约翰到达逃逸牛的最快方法是沿着以下路径移动：5-10-9-18-17，需要 4 分钟。

```c
#include<iostream>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
int n, m;
bool vis[N];

//判断函数，检查数据是否合理、位置是否被标记
bool rule(int x)
{
    return x >= 0 && x <= 100000 && !vis[x];
}

//结构体node创建
struct node 
{
    //step为步数
    int x, step;//x为数字线上的位置		
};

//bfs函数
void bfs() 
{
    queue<node>st;//建立一个node类型的对列
    node cur, temp;//定义两个node变量
    temp.x = n, temp.step = 0;
    st.push(temp);//入队
    vis[n] = 1;//标记搜索过的位置
    
    while (!st.empty()) 
    {
        cur = st.front();//获得st队列的首元素
        st.pop();//出队
        if (cur.x == m) //判断是否到达目标位置
        {
            cout << cur.step << endl;
            return;
        }
        temp.step = cur.step + 1;//步数加一
        
        //每一次搜索的三种分支
        if (rule(cur.x + 1))
            temp.x = cur.x + 1, st.push(temp), vis[temp.x] = 1;
        if (rule(cur.x - 1))
            temp.x = cur.x - 1, st.push(temp), vis[temp.x] = 1;
        if (rule(cur.x * 2))
            temp.x = cur.x * 2, st.push(temp), vis[temp.x] = 1;
    }
}

int main() 
{
    cin >> n >> m;
    bfs();
    return 0;
}
```





# 三、博弈

## 1、理论铺垫

1、定义P-position和N-position：其中P代表Previous，N代表Next。直观的说，上一次move的人有必胜策略的局面是P-position，也就是“先手必败”，现在轮到move的人有必胜策略的局面是N-position，也就是“先手可保证必胜”。

（1）.无法进行任何移动的局面（也就是terminal position）是P-position；

（2）.可以移动到P-position的局面是N-position；

（3）.所有移动都导致N-position的局面是P-position。

2、P/N状态有如下性质：

（1）、若面临末状态者为获胜则末状态为胜态否则末状态为必败态。
（2）、一个局面是胜态的充要条件是该局面进行某种决策后会成为必败态。
（3）、一个局面是必败态的充要条件是该局面无论进行何种决策均会成为胜态
3、P点： 即必败点，某玩家位于此点，只要对方无失误，则必败；

   N点： 即必胜点，某玩家位于此点，只要自己无失误，则必胜。

4、取石子游戏算法实现

步骤1:将所有终结位置标记为必败点（P点）；

步骤2: 将所有一步操作能进入必败点（P点）的位置标记为必胜点（N点）

步骤3:如果从某个点开始的所有一步操作都只能进入必胜点（N点） ，则将该点标记为必败点（P点） ；

步骤4: 如果在步骤3未能找到新的必败（P点），则算法终止；否则，返回到步骤2

/*

a.如果当前是P点，那么一步（向前）可以走到的都是N点

b.如果当前点未标明P/N属性，那么看看该点向后走是不是都只能到达N点，如果是，那么该点是P点。

c.如果该点是N点，倒无法确定什么。

如果没办法标一个点，那么异常结束。

*/

## 2、常见的博弈类别

### A、威佐夫博弈

### 博弈条件：

威佐夫博弈（Wythoff's game）：有两堆各若干个物品，两个人轮流从任一堆取至少一个或同时从两堆中取同样多的物品，规定每次至少取一个，多者不限，最后取光者得胜。



#### 结论：

两个人如果都采用正确操作，那么面对非奇异局势，先拿者必胜；反之，则后拿者取胜。那么任给一个局势（a，b），怎样判断它是不是奇异局势呢？我们有如下公式：

ak =[k（1+√5）/2]，bk= ak + k （k=0，1，2，...n 方括号表示取整函数)



奇妙的是其中出现了[黄金分割数](https://baike.baidu.com/item/黄金分割数/10996195?fromModule=lemma_inlink)（1+√5）/2 = 1.618...因此，由ak，bk组成的矩形近似为黄金矩形，由于2/（1+√5）=（√5-1）/2，可以先求出j=[a（√5-1）/2]，若a=[j（1+√5）/2]，那么a = aj，bj = aj + j，若不等于，那么a = aj+1，b = aj + j + 1，若都不是，那么就不是奇异局势。然后再按照上述法则进行，一定会遇到奇异局势。



#### 证明

**定理 0**：一个状态是必败态，当且仅当它的所有后继状态都是必胜态；而一个状态是必胜态，只要它的后继状态有一个以上的必败态即可。

证明略去。

容易发现下面的定理：

**定理 1**：(a，b) 和 (b, a) 的胜负性是相同的（a <> b）。

证明：如果 (a, b) 是必胜态，那么将必胜策略中所有的操作，对第一堆的变为第二堆，对第二堆的变为第一堆，就构成 (b, a) 的必胜策略

**定理 2**：若 (a, b) 是必败态，则对于所有的 x <> a 和 y <> b，(x, b) 和 (a, y) 是必胜态。

证明：

对于 x > a 和 y > b，不管是哪一种情况，总可以从 x 堆或 y 堆中取出一定量的石子使当前状态变为必败态 (a, b)，由定理 1，(x, b) 和 (a, y) 为必胜态。

对于 x < a 和 y < b，不管是哪一种情况，如果 (x, b) 或 (a, y) 是必败态的话，由上述可得 (a, b) 是必胜态，矛盾。故 (x, b) 和 (a, y) 均为为必胜态。

**定理 3**: 若 (a, b) 是必败态，则对于所有的 d > 0，(a + d, b + d) 是必胜态。

证明：

与定理 2 类似。

**定理 4**：在所有的必败态中，每个数字恰巧出现一次。

证明：

有了定理 1，对于对称的状态我们只需要处理其中一个，而两个数不会相同（相同的状态必然是必胜态），于是我们把每个状态中较小的数字放在前面，每行写一个状态，去掉括号并按照升序排列每行的第一个数，就构成了如下的矩阵：

1 2

3 5

4 7

6 10

……

假设数字k在矩阵中出现两次或两次以上，则有(k,a)，(k,b)都为必败态，与定理2矛盾。

假设数字k为序列中没有出现且值最小的数字，则有 (k,k+i)为必胜态(i>0)，则对任意i，必然存在j(0<j<k)使得(k-j,k+i-j)或(k,k+i-j)或(k-j,k+i)为必败态 (若不如此，则无论如何取石子，对方必胜)，根据假设，显然(k,k+i-j)必胜，因此，对任意i，必有(k-j,k+i-j)或(k-j,k+i)=0, (0<j<k) 必败

根据[鸽巢原理](https://baike.baidu.com/item/鸽巢原理/731656?fromModule=lemma_inlink)，必然存在3个i的取值(其实是无穷多个，j只有k-1种取值，而i有无数种)记为i1, i2, i3使得j1=j2=j3=m。对这3个i，同样必然存在一对i，不妨为(i1,i2)，使(k-m,k+i1-m)且(k-m,k+i2-m)必败或f(k-m,k+i1)且f(k-m,k+i2)必败。显然与定理2矛盾，因此不存在这样的数k。

观察这个矩阵，我们又可以得到新的定理：

**定理 5**：矩阵中每行第一个数恰巧是前面每一行中没有出现过的最小正整数。

证明：

由定理 4，矩阵中每个数字恰巧出现一次，而按照这个矩阵的定义，第二列的数总比同行第一列大，第一列又按照升序排列，所以每一行的第一个数正好为前面每一行中没有出现过的最小正整数。

**定理 6**：矩阵第 i 行的第二个数正好为第一个数加上 i

证明：

用[数学归纳法](https://baike.baidu.com/item/数学归纳法/5155524?fromModule=lemma_inlink)。

\1) 对于第一行显然成立

\2) 若对于前 i - 1 行均成立，则所有的 (a[p], a[p] + p) (a[p] 为第 p 行第一个数，p < i) 均为必败态，那么考察第 i 行的状态 (a[i], a[i] + delta)。容易看出 delta >= i，因为如果 delta < i，一定可以通过一次操作变为前面出现过的必败态，那么这个状态就是必胜态。下面由 delta >= i，我们来说明 delta = i。

首先，我们考虑从第一堆中取出 p 个石子，得到状态 (a[i] - p, a[i] - p + delta)，由定理 5，比 a[i] 小的数都在之前出现过，若 a[i] - p 出现在某一行的第一列，由于存在必败态 (a[i] - p, a[i] - p + d) (d < delta)，故 (a[i] - p, a[i] - p + delta) 一定为必胜态（定理 2）；若 a[i] - p 出现

![img](https://bkimg.cdn.bcebos.com/formula/f30b7a1b850897cc537ad0496a0fe0d2.svg)

在某一行的第二列，由于第一列是单增的，因而其对应的第一列数必小于 a[i] + delta，故而也可推出其状态为必胜态。

对于从两堆石子中取出相同数目的情况与之类似，容易看出一定为必胜态。

于是，(a[i], a[i] + delta) 状态的胜负性只与状态 (a[i], a[i] + d) (d < delta) 有关。不难看出，delta = i 时恰为必败态，因为不论从第二堆中取出多少个石子，作为另一堆的第一堆石子并没有在之前出现过，所以得到的一定是一个必胜态，因而 (a[i], a[i] + delta) 为必败态，由定理 2 及定理 4 可得，原命题成立。即矩阵中第 i 行第二列的数等于同行第一列的数加上 i。

这时，我们所有的问题都转化到了矩阵上，只要能通过合适的方法表示出这个矩阵，我们就可以很好地解决原问题。

下面的过程可能需要比较高的数学技巧，首先给出我们需要的一个重要定理（[x] 表示 x 的整数部分，{x} 表示 x 的小数部分，即 {x} = x - [x]）：

**定理 7**（Beatty 定理）：如果存在正无理数 A, B 满足 1/A + 1/B = 1，那么集合 P = { [At], t

证明：详见Beatty定理。

考虑到 Beatty 定理中“恰为 Z

于是我们得到每一行第二列的数为 [

我们的目的是要让 Z

于是应用 Beatty 定理，我们得到最终我们需要的定理：

**定理 8**：上述矩阵中每一行第一列的数为 [

证明：由 Beatty 定理显然得证。

设a、b是正[无理数](https://baike.baidu.com/item/无理数?fromModule=lemma_inlink)且 1/a +1/b =1。记P={ 【na】 | n为任意的[正整数](https://baike.baidu.com/item/正整数?fromModule=lemma_inlink)}，Q={ 【nb】 | n 为任意的正整数}，则P与Q是Z+的一个划分，即P∩Q为空集且P∪Q为正整数集合Z+。

证明：因为a、b为正且1/a +1/b=1，则a、b>1，所以对于不同的整数n，【na】各不相同，类似对b有相同的结果。因此任一个整数至多在集合P或Q中出现一次。

\* 现证明P∩Q为空集；([反证法](https://baike.baidu.com/item/反证法?fromModule=lemma_inlink))假设k为P∩Q的一个整数，则存在正整数m、n使得【ma】=【nb】=k。即k < ma、nb<k+1，等价地改写不等式为

\* m/(k+1)< 1/a < m/k及n/(k+1)< 1/b < n/k。相加起来得 (m+n)/(k+1) < 1 < (m+n)/k，即 k < m+n < k+1。这与m、n为整数有[矛盾](https://baike.baidu.com/item/矛盾?fromModule=lemma_inlink)，所以P∩Q为空集。现证明Z+=P∪Q；已知P∪Q是Z+的[子集](https://baike.baidu.com/item/子集?fromModule=lemma_inlink)，剩下来只要证明Z+是P∪Q的子集。(反证法)假设Z+\(P∪Q)有一个元素k，则存在正整数m、n使得【ma】< k <【(m+1)a】、【nb】< k <【(n+1)b】。 由此得ma < k ≦【 (m+1)a】-1<(m+1)a -1，类似地有nb < k ≦【 (n+1)b】-1<(n+1)b -1。等价地改写为 m/k < 1/a < (m+1)/(k+1)及n/k < 1/b < (n+1)/(k+1)。两式加起来，得

(m+n)/k < 1 < (m+n+2)/(k+1)，即m+n < k < k+1 < m+n+2。这与m, n, k皆为正整数矛盾。所以Z+=P∪Q。

![img](https://bkimg.cdn.bcebos.com/pic/0b46f21fbe096b635593ca130e338744eaf8acef?x-bce-process=image/watermark,image_d2F0ZXIvYmFpa2UxMTY=,g_7,xp_5,yp_5)

### B、巴什博弈

#### 问题模型：

只有一堆n个物品，两个人轮流从这堆物品中取物，规定每次至少取一个，最多取m个，最后取光者得胜。

#### 解决思路：

当n=m+1时，由于一次最多只能取m个，所以无论先取者拿走多少个，后取者都能够一次拿走剩余的物品，后者取胜，所以当一方面对的局势是n%(m+1)=0时，其面临的是必败的局势。所以当n=（m+1)*r+s，（r为任意自然数，s≤m)时,如果先取者要拿走s个物品，如果后取者拿走x（≤m)个，那么先取者再拿走m+1-k个，结果剩下（m+1）（r-1）个，以后保持这样的取法，那么先取者肯定获胜。总之，要保持给对手留下（m+1）的倍数，就能最后获胜。

3、变形：条件不变，改为最后取光的人输。

结论：当（n-1）%（m+1）==0时后手胜利。

### C、Fibonacci博弈

#### 1、问题模型：

 有一堆个数为n的石子，游戏双方轮流取石子，满足： 

（1）先手不能在第一次把所有的石子取完； 

（2）之后每次可以取的石子数介于1到对手刚取的石子数的2倍之间（包含1和对手刚取的石子数的2倍）。 约定取走最后一个石子的人为赢家。

#### 2、解决思路：

  当n为Fibonacci数时，先手必败。即存在先手的必败态当且仅当石头个数为Fibonacci数。 

##### 证明：

根据“Zeckendorf定理”（齐肯多夫定理）：任何正整数可以表示为若干个不连续的Fibonacci数之和。如n=83 = 55+21+5+2，我们看看这个分解有什么指导意义：假如先手取2颗，那么后手无法取5颗或更多，而5是一个Fibonacci数，那么一定是先手取走这5颗石子中的最后一颗，同理，接下去先手取走接下来的后21颗中的最后一颗，再取走后55颗中的最后一颗，那么先手赢。

反证：如果n是Fibonacci数，如n=89：记先手一开始所取的石子数为y

（1）若y>=34颗（也就是89的向前两项），那么一定后手赢，因为89-34=55=34+21<2*34。

（2）y<34时剩下的石子数x介于55到89之间，它一定不是一个Fibonacci数，把x分解成Fibonacci数：x=55+f[i]+…+f[j]，若，如果f[j]<=2y，那么对B就是面临x局面的先手，所以根据之前的分析，后手只要先取f[j]个即可，以后再按之前的分析就可保证必胜。

### D、尼姆博弈

#### 1、问题模型：

有三堆各若干个物品，两个人轮流从某一堆取任意多的物品，规定每次至少取一个，多者不限，最后取光者得胜。

#### 2、解决思路：

用（a，b，c）表示某种局势，显证（0，0，0）是第一种奇异局势，无论谁面对奇异局势，都必然失败。第二种奇异局势是（0，n，n），只要与对手拿走一样多的物品，最后都将导致（0，0，0）。

  搞定这个问题需要把必败态的规律找出：(a,b,c)是必败态等价于a^b^c=0(^表示异或运算）。

  证明:(1)任何p(a,b,c)=0的局面出发的任意局面(a,b,c’);一定有p(a,b,c’)不等于0。否则可以得到c=c’。

（2）任何p(a,b,c)不等于0的局面都可以走向 p(a,b,c)=0的局面

（3）对于 (4,9,13) 这个容易验证是奇异局势           

   其中有两个8，两个4，两个1，非零项成对出现，这就是尼姆和为  零的本质。别人要是拿掉13里的8或者1，那你就拿掉对应的9  中的那个8或者1；别人要是拿        掉13里的4，你就拿掉4里的4；  别人如果拿掉13里的3，就把10作分解，然后想办法满 足非零项成对即可。

3、推广一：如果我们面对的是一个非奇异局势（a，b，c），要如何变为奇异局势呢？假设 a < b< c,我们只要将 c 变为 a^b,即可,因为有如下的运算结果: a^b^(a^b)=(a^a)^(b^b)=0^0=0。要将c 变为a^b，只从 c中减去 c-（a^b）

4、推广二：当石子堆数为n堆时，则推广为当对每堆的数目进行亦或之后值为零是必败态。

 



# 四、快速幂

## 1、什么是快速幂算法

首先，我们先来看一道ACM程序设计题，这道题是杭电OJ中序号为2035的题目，没做过这道题目的同学可以跟着一起做一下，题目如下：

问题描述：

![img](https://img-blog.csdnimg.cn/20190102161125415.png)

这道题目乍一看会觉得并不难啊，题目短短一行而已，而且思路也很容易，求幂这种算法一般在初学程序设计语言的时候应该都有联系过，只要写一个简单的循环就能够搞定。

 * ```c++
 /**
     * 普通的求幂函数
     * @param base 底数
     * @param power  指数
     * @return  求幂结果的最后3位数表示的整数
    **/
    long long normalPower(long long base,long long power)
    {
        long long result=1;
    	for(int i=1;i<=power;i++)
    	{
        	result=result*base;
    	}
    	return result%1000;
    }
 ```c++

这道题不是分分钟解决吗？接下来，让我们来写一个主函数测试一下：

c++
int main()
{
    long long base,power;
    cin>>base>>power;
 
    cout<<"base="<<base<<" power="<<power<<" "<<normalPower(base,power)<<endl;
 
    return 0;
}
 ```

然后，让我们愉快的来求一下2^100的结果的后三位数表示的整数是什么吧！输出结果如下：

![img](https://img-blog.csdnimg.cn/20190102164900548.png)

​		为什么答案会是0呢？明明没有错误的啊！~ 

​		先不急，我们再来考虑一下，这道题其实出的很有意思，题目要求你输出结果的后三位，为什么不让你直接输出结果呢？难道仅仅只是为了增大题目的难度吗？当然不是，我们在初中就学过“指数爆炸”，下面我们在来回顾一下“指数”的概念：

​		**~指数：在乘方a中，其中的a叫做底数，n叫做指数，结果叫幂。**

​		**~f(x)=a^x ， 随着x单位长度的递增，f(x)会呈“爆炸性”增长。**

​        一张纸对折一次，厚度变成原来的2倍。再对折第二次，变为原来的2的2次方倍即4倍。以此类推，假设纸的厚度为0.1mm，则对折24次以后，长度超过1千米；对折39次达55000千米，超过地球赤道长度；对折42次达44万千米，超过地球至月球的距离；对折51次达22亿千米，超过地球至太阳的距离；对折82次为51113光年，超过银河系半径的长度。

​		因此，如果题目让你求2的100次方，貌似我们程序设计语言中最大的long lnog类型也无法承载这么大的数值，所以题目才不会要求你输出结果，因为结果可能会非常的大，大到没有任何类型可以承载。所以我们会发现上面的结果为什么是0，因为已经发生溢出了。

​		那为什么题目要求输出结果的最后三位数表示的整数呢？有的同学可能会问：求一个数的最后三位数表示的整数好办，只要用这个结果进行“取模”运算，让其对1000取模，得到的数就是这个数最后三位数表示的整数。（例如：12345的最后三位数表示的整数是：12345%1000=345）。但是，你这结果都无法求出来，让我怎么进行“取模”运算呢？你这不是瞎闹吗？

​		别急，我们首先来了解一下“取模”运算的运算法则：（具体的证明感兴趣的同学可以问度娘）

```c
 1、(a + b) % p = (a % p + b % p) % p （1） 
 2、(a - b) % p = (a % p - b % p) % p （2） 
 3、(a * b) % p = (a % p * b % p) % p （3）
```

​		其中我们只要关注第“3”条法则即可：(a * b) % p = (a % p * b % p) % p ，我们仔细研究一下这个运算法则，会发现多个因子连续的乘积取模的结果等于每个因子取模后的乘积再取模的结果。也就是说，我们如果要求：

​								**(a*b*c)%d=(a%d·b%d·c%d)%d;**

​		因此，我们可以借助这个法则，只需要在循环乘积的每一步都提前进行“取模”运算，而不是等到最后直接对结果“取模”，也能达到同样的效果。

​		所以，我们的代码可以变成这个样子：

```c
/** 
 * 普通的求幂函数
 * @param base 底数
 * @param power  指数
 * @return  求幂结果的最后3位数表示的整数
   */
long long normalPower(long long base,long long power)
{
    long long result=1;
	for(int i=1;i<=power;i++)
	{
    	result=result*base;
    	result=result%1000;
	}
	return result%1000;
}
```

 ```c
 
 我们再来测试一下，这样又能不能输出结果呢？我们仍然来求一下2^100的后三位是什么：
     
​		这一次完美的得到了我们想要的结果。2^100的幂结果的后三位整数位376。

​		为了打消一些同学对这个运算法则的怀疑，我们再用一个结果比较小的式子来验证一下：我们知道2^10为1024,按理来说，最后输出的结果的后三位数表示的整数应该是24，那么是不是这样呢？我们来试一试：
     
最后的结果果然是24，所以这个法则是没有问题的。我们把下面的代码提交给OJ看一下是否能通过：

//c++
#include <iostream>
#include <cmath>

using namespace std;

/*
 * 普通的求幂函数
 * @param base 底数
 * @param power  指数
 * @return  求幂结果的最后3位数表示的整数
 */
long long normalPower(long long base, long long power)
{
    long long result = 1;
   for (int i = 1; i <= power; i++) 
   {
       result = result * base;
       result = result % 1000;
   }
   return result % 1000;
}
int main()
{
    long long base, power;
    while (true) 
    {
        cin >> base >> power;
        if (base == 0 && power == 0) break;
        cout << normalPower(base, power) << endl;
    }
    return 0;

}
 ```

​						最后的结果是成功Accept了。

## 2、再次思考

​		虽然这个求幂的方法很有用，并且提交给OJ也直接Accept了，但是我们来考虑一下这个算法的时间复杂度，假设我们求2的100次方，那么将会执行100次循环。如果我们分析一下这个算法，就会发现这个算法的时间复杂度为O(N),其中N为指数。求一下小的结果还好，那如果我们要求2的1000000000次方呢？这个程序可能会运行很久很久，具体会多久呢，让我们来测试一下，测试代码如下：

```c++
#include <iostream>
#include <cmath>
#include <time.h>

using namespace std;

/**

 * 普通的求幂函数
 * @param base 底数
 * @param power  指数
 * @return  求幂结果的最后3位数表示的整数
   */
   long long normalPower(long long base, long long power) {
   long long result = 1;
   for (int i = 1; i <= power; i++) {
       result = result * base;
       result = result % 1000;
   }
   return result % 1000;
   }

int main() {
    clock_t start, finish;
    //clock_t为CPU时钟计时单元数
    long long base, power;
    cin >> base >> power;
    start = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout << normalPower(base, power) << endl;
    finish = clock();
    //clock()函数返回此时CPU时钟计时单元数
    cout << "the time cost is" << double(finish - start) / CLOCKS_PER_SEC;
    //finish与start的差值即为程序运行花费的CPU时钟单元数量，再除每秒CPU有多少个时钟单元，即为程序耗时
    return 0;

}
```

​		结果如图所示：

![img](https://img-blog.csdnimg.cn/20190102173019265.png)

​		我们发现，虽然结果是成功求出来了，但是用了将近18秒的时间才求出最后的答案。这效率当然是非常的低下的，更谈不上实际的生产应用了。那么有没有什么好的办法能够对其进行优化呢？接下来就是我们本次的主题了：快速幂算法。

## 3、快速幂算法初步入门

​		快速幂算法能帮我们算出指数非常大的幂，传统的求幂算法之所以时间复杂度非常高（为O(指数n)），就是因为当指数n非常大的时候，需要执行的循环操作次数也非常大。所以我们快速幂算法的核心思想就是每一步都把指数分成两半，而相应的底数做平方运算。这样不仅能把非常大的指数给不断变小，所需要执行的循环次数也变小，而最后表示的结果却一直不会变。让我们先来看一个简单的例子：

```c
3^10=3*3*3*3*3*3*3*3*3*3

//尽量想办法把指数变小来，这里的指数为10

3^10=(3*3)*(3*3)*(3*3)*(3*3)*(3*3)

3^10=(3*3)^5

3^10=9^5

//此时指数由10缩减一半变成了5，而底数变成了原来的平方，求3^10原本需要执行10次循环操作，求9^5却只需要执行5次循环操作，但是3^10却等于9^5,我们用一次（底数做平方操作）的操作减少了原本一半的循环量，特别是在幂特别大的时候效果非常好，例如2^10000=4^5000,底数只是做了一个小小的平方操作，而指数就从10000变成了5000，减少了5000次的循环操作。

//现在我们的问题是如何把指数5变成原来的一半，5是一个奇数，5的一半是2.5，但是我们知道，指数不能为小数，因此我们不能这么简单粗暴的直接执行5/2，然而，这里还有另一种方法能表示9^5

9^5=（9^4）*（9^1）

//此时我们抽出了一个底数的一次方，这里即为9^1，这个9^1我们先单独移出来,剩下的9^4又能够在执行“缩指数”操作了，把指数缩小一半，底数执行平方操作

9^5=（81^2）*(9^1)

//把指数缩小一半，底数执行平方操作

9^5=（6561^1）*(9^1)

//此时，我们发现指数又变成了一个奇数1，按照上面对指数为奇数的操作方法，应该抽出了一个底数的一次方，这里即为6561^1，这个6561^1我们先单独移出来，但是此时指数却变成了0，也就意味着我们无法再进行“缩指数”操作了。

9^5=（6561^0）*(9^1)*(6561^1)=1*(9^1)*(6561^1)=(9^1)*(6561^1)=9*6561=59049

我们能够发现，最后的结果是9*6561，而9是怎么产生的？是不是当指数为奇数5时，此时底数为9。那6561又是怎么产生的呢？是不是当指数为奇数1时，此时的底数为6561。所以我们能发现一个规律：最后求出的幂结果实际上就是在变化过程中所有当指数为奇数时底数的乘积。
```

​		让我们来看一段简单的动画演示（点击放大）：

![img](https://img-blog.csdnimg.cn/20190103145233776.gif)

​		接下来，再让我们用代码来演示一下上面的算法：

```c++
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 0) {
            //如果指数为偶数
            power = power / 2;//把指数缩小为一半
            base = base * base % 1000;//底数变大成原来的平方
        } else {
            //如果指数为奇数
            power = power - 1;//把指数减去1，使其变成一个偶数
            result = result * base % 1000;//此时记得要把指数为奇数时分离出来的底数的一次方收集好
            power = power / 2;//此时指数为偶数，可以继续执行操作
            base = base * base % 1000;
        }
    }
    return result;
}
```

​		我们再来测试一下此时的快速幂算法和普通的求幂算法的效率，我们仍然来求2的1000000000次方，看一看用时又会是多少：

![img](https://img-blog.csdnimg.cn/20190103140313548.png)

​		真让人简直不可思议，竟然只花了0.002秒就求出了结果，而且结果也是376，然而普通的算法却用了将近18秒的时间才求出最后的结果。

## 4、压榨性能再优化

虽然上面的快速幂算法效率已经很高了，但是我们仍然能够再一次的对其进行“压榨级别”的优化。我们上面的代码看起来仍然有些地方可以再进一步地进行简化，例如在if和else代码块中仍然有重复性的代码：

```c
        power = power / 2;
        base = base * base % 1000;
```
​												**而**

```c
        power = power - 1;//把指数减去1，使其变成一个偶数
        power = power / 2;
```
```
可以压缩成一句：
            power = power / 2;
```

因为power是一个整数，例如当power是奇数5时,power-1=4,power/2=2；而如果我们直接用power/2=5/2=2。在整型运算中得到的结果是一样的，因此，我们的代码可以压缩成下面这样：

```c++
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base % 1000;
        }
        power = power / 2;
        base = (base * base) % 1000;
    }
    return result;
}
```

接下来，我们来测试一下优化后的性能如何，仍然是求2的1000000000次方：

![img](https://img-blog.csdnimg.cn/20190103142357532.png)

结果仍然是正确的376，但时间上的花费从0.002减少成了0.001。

 

## 5、终极优化

​		在C语言中，power%2==1可以用更快的“位运算”来代替，例如：power&1。因为如果power为偶数，则其二进制表示的最后一位一定是0；如果power是奇数，则其二进制表示的最后一位一定是1。将他们分别与1的二进制做“与”运算，得到的就是power二进制最后一位的数字了，是0则为偶数，是1则为奇数。例如5是奇数，则5&1=1；而6是偶数，则6&1=0；因此奇偶数的判断就可以用“位运算”来替换了。

![img](https://img-blog.csdnimg.cn/20190103143841293.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzE5NzgyMDE5,size_16,color_FFFFFF,t_70)

​		同样，对于power=power/2来说，也可以用更快的“位运算”进行替代，我们只要把power的二进制表示向右移动1位就能变成原来的一半了。

![img](https://img-blog.csdnimg.cn/20190103144259337.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzE5NzgyMDE5,size_16,color_FFFFFF,t_70)

​		最后，我们的代码就能优化成下面这样：

```c++
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {//此处等价于if(power%2==1)
            result = result * base % 1000;
        }
        power >>= 1;//此处等价于power=power/2
        base = (base * base) % 1000;
    }
    return result;
}
```

我们仍然测试一下求2的1000000000次方，看看终极优化后的代码的性能是怎样的：

![img](https://img-blog.csdnimg.cn/20190103144956564.png)

简直可怕，时间花费竟然接近于0秒，我们从最开始的18秒最后压缩到接近0秒，真的是感慨算法的威力！如果同样两家公司，采用不同的算法，给用户带来的体验区别是非常大的，这无不让我们感受到算法的威力。



# 五、矩阵快速幂

### 1、矩阵乘法

想要做矩阵快速幂，先要了解矩阵乘法。（考虑到我数学水平有限，这里不展开讲）

先定义矩阵A（n×k）、B（k×m）。

图片来自百度：

![img](https://img-blog.csdnimg.cn/2d39fd62b3f54e7db366507d103cd9a5.png)

#### 矩阵乘法的定义如下：

（1）A（左矩阵）的列数必须与 B（右矩阵）的行数相同，这也是矩阵乘方要求是正方形矩阵的原因，即矩阵自乘要求行和列数相等。

（2） C 的行数与 A（左矩阵）相同，列数与B（右矩阵）相同，即C（n×m）

（3） C 的第 i 行第 j 列的元素 C（ij）由 A 的第 i 行元素与 B的第 j 列元素对应相乘，再取乘积之和。

用一个公式来说就是：

图片来自百度：

![img](https://img-blog.csdnimg.cn/8743932f06574fc7b3e53d62bc73466b.png)

列子：

图片来自百度：

![img](https://img-blog.csdnimg.cn/img_convert/cbfbb81cc866ecf5243051736195b7aa.jpeg)

A出行，B出列，对应相乘再相加。

### 2、关于单位矩阵：

单位矩阵是一个左上到右下对角线的元素都为11，其余元素为00的矩阵，一个矩阵乘以单位矩阵（在行列数允许的情况下），根据矩阵乘法的定义，得到的结果是这个矩阵本身。

OK，了解到这里已经足够我们做矩阵快速幂了。

 矩阵快速幂代码实现
对指数k的操作同上，这里不再复述。

重要的是，重载乘法运算符，使得我们在上面的式子对于矩阵也适用。

代码实现：

```c++
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
 
struct no 
{
	long long a[5][5];
	no() 
    {
		memset(a,0,sizeof(a));
	}
};
 
int p,q,a1,a2;
long long n,Mod;
 
no X(no a,no b) 
{
	no c;
	for(int i=1; i<=2; i++)
		for(int j=1; j<=2; j++)
			for(int k=1; k<=2; k++)
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%Mod;
	return c;
}
 
no ksm(no a,long long k)
{
	no ans=a;
	for(k--; k; k>>=1,a=X(a,a))
		if(k&1)
			ans=X(ans,a);
	return ans;
}
 
int main() {
	scanf("%d%d%d%d%lld%lld",&p,&q,&a1,&a2,&n,&Mod);
	a1%=Mod;
	a2%=Mod;
	q%=Mod;
	p%=Mod;
	if(n<3) {
		if(n==1)
			printf("%d\n",a1);
		else
			printf("%d\n",a2);
		return 0;
	}
	no a;
	a.a[1][1]=p;
	a.a[1][2]=q;
	a.a[2][1]=1;
	a=ksm(a,n-2);
	printf("%lld\n",(a.a[1][1]*a2+a.a[1][2]*a1)%Mod);
	return 0;
}
```

# 六、STL

![image-20230305194651036](D:\Users\suyu\Pictures\Typora-picture\image-20230305194651036.png)

## 1、vector

### **A、什么是vector？**

**向量（vector）**是一个封装了动态大小数组的顺序容器（Sequence Container）。
跟任意其它类型容器一样，它能够存放各种类型的对象。
可以简单的认为，向量是一个能够存放任意类型的动态数组。

### B、vector用法：

(1)#include<vector>//头文件
(2)vector<int> vec//创建vector对象
(3)vec.push_back(a)//尾部插入数字
	vec.pop_back() //弹出元素。 

(4)cout<<vec[0]<<endl//使用下标访问元素，下标是从0开始的 

(5)vector<int>::iterator it;
	for(it=vec.begin();it!=vec.end();it++)
	cout<<*it<<endl;//使用迭代器访问元素.

(6)vec.insert(vec.begin()+i,a)// 插入元素：在第i个元素后面插入a;

(7)vec.erase(vec.begin()+i)// 删除元素：删除第i个元素

vec.erase(vec.begin()+i,vec.end()+j)//删除区间[ i,j-1] 区间从0开始

(8)vec.size()//数组的大小
	 vec.empty()//判断数组是否为空，是返回1，不是返回0 

(9)vec.clear()//清空数组 

(11)vector<int>a//  建一个动态数组a，a的默认初值为0

(12)vector<int >b(a)// 将a中的元素复制到b中

(13)vetcor<int>a(100)//  将数组a的元素定义为100个，默认初始值为0

(14)vector<int>a(100,6)//  定义100个值为6的元素

(15)vector<string>a(10,"null")// 定义10个值为null的元素

(16)vector<string>a(10,"hello")//  定义10个值为hello的元素

(17)vector<string>b(a.begin(),a.end())// 将动态数组a的元素值复	   制到b中



#  七、并查集（Disjoint Set）

## 1、引入

**并查集是用于检查图中是否存在环状结构的。**

例：<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314194842473.png" alt="image-20230314194842473" style="zoom:50%;" />

通过并查集检测上诉图中是否有环

（1）、先将六个顶点平铺开来

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314195147519.png" alt="image-20230314195147519" style="zoom:50%;" />

（2）、 将两边相连的顶点放入一个结合中

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314195525754.png" alt="image-20230314195525754" style="zoom:50%;" />

​		此时的集合将有两个性质：
​			①集合中的每一个顶点都可以通向另一个顶点

​			②如果从此集合中任选两个顶点就会构成一个环

（3）、用一维数组构成树

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314204716437.png" alt="image-20230314204716437" style="zoom:50%;" />

①0的父节点是1：parent[0]=1;

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314204911872.png" alt="image-20230314204911872" style="zoom:50%;" />

②2的父节点是1：parent[2]=1;

得到：<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314205310060.png" alt="image-20230314205310060" style="zoom:50%;" />



<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314205115447.png" alt="image-20230314205115447" style="zoom:50%;" />

③3的父节点是4：parent[3]=4;

得到：<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314205422154.png" alt="image-20230314205422154" style="zoom:50%;" />

（4）、合并父节点

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314205521594.png" alt="image-20230314205521594" style="zoom:50%;" />

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314205538697.png" alt="image-20230314205538697" style="zoom:50%;" />

（5）、寻找其中两个顶点的根

如果两个顶点的根相同，则可得到一个环。



## 2、实现

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314194842473.png" alt="image-20230314194842473" style="zoom:50%;" />

```c
#define Vertices 6

//初始化数组
void initialise(int parent[])
{
    int i;
    for(i=0;i<Vertices;i++)
    {
        parent[i]=-1; 
    }
}

//寻找根节点
int find_root(int x,int parent[])
{
    //先假设一个根结点x_root
    int x_root=x;	
    //如果parent[x_root]为-1代表找到根结点
    while(parent[x_root]!=-1)
    {
        //不然就找向上一个顶点
        x_root=parent[x_root];
    }
    return x_root;
}

//合并两个树
//如果return 1则合并成功，如果return 0则合并失败
int union_vertices(int x,int y,int parent[])
{
    //寻找x和y两棵树的根结点
    int x_root=find_root(x,parent);
    int y_root=find_root(x,parent);
    //如果两棵树的根结点相同则合并失败
    if(x_root==y_root)
    {
        return 0;
    }
    else
    {
        //把x的根结点连接向y的根节点
     	parent[x_root]=y_root;
        return 1;
    }
}

int mian()
{
    int parent[Vertices]={0};
    initialise(parent);
    int edges[6][2]={
        {0,1},{1,2},{1,3},
        {2,4},{3,4},{2,5}
    }
    int i=0;
    for(i=0;i<6;i++)
    {
        int x=edges[i][0];
        int y=edges[i][1];
        if(union_vertices(x,y,parent)==0)
        {
            printf("图中有环\n");
            exit(0);
        }
    }
    printf("图中没有环!\n");
    return 0;
}
```

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230314194842473.png" alt="image-20230314194842473" style="zoom:50%;" />





### a、压缩路径

**（1）、查找压缩**

```c
//未压缩
int find(int x)
{
	if (x==parent[x])return x;
	return find(parent[x]);
}
//压缩后
int find(int x)
{
    if(x==parent[x]) return x;
    //每次都将对应的根存储在对应的叶上
    else parent[x]=find(parent[x]);
    return parent[x];
}
```





**（2）、秩序合并**

通常将较短的树合并到较长的树上，从而不改变树的长度。

```c
void union(int lx,int ly)//传入x、y
{
    x_root=find(x);						//寻找 x的代表元
    y_root=find(y);						//寻找 y的代表元
    if(x_root==y_root) return ;			//如果 x和 y的代表元一致，说明他们共属同一集合，则不需要合并，直接返回；否则，执行下面的逻辑
    if(rank[x]>rank[y]) pre[y]=x;		//如果 x的高度大于 y，则令 y的上级为 x
    else								//否则
    {
        if(rank[x]==rank[y]) rank[y]++;	//如果 x的高度和 y的高度相同，则令 y的高度加1
        pre[x]=y;						//让 x的上级为 y
    }
}

```





# 八、埃氏筛法，欧拉筛法

**合数：合数指自然数中除了能被1和本身整除外，还能被其他数（0除外）整除的数。**



**质数（素数）：一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数。**



## 问题：

判断素数

```c
#include<stdio.h>
#include<math.h>
bool isprime(int x)
{
    int i=0;
    x=sqrt(x);	//取根号x
    for(i=2;i<=x+1;++i)
    {
        if(x%i==0) return 0;
        return 1;
    }
}
int mian()
{
    int N;int i=0;
    scanf("%d",&n);
    long long sum=0;
    for(i=2;i<=n;++i)
    {
        if(isprime(i)) sum+=1;
    }
    printf("%lld\n",sum);
    return 0;
}
```

但是时间复杂度较高



## 优化：

### 1、朴素筛法（近埃氏筛法）

```c
#include<stdio.h>
#include<math.h>
typedef MAX 1e7
//一个合数一定可以写成某个质数的n倍
bool isprime(int x)
{
    int i=0;
    x=sqrt(x);	//取根号x
    for(i=2;i<=x+1;++i)
    {
        if(x%i==0) return 0;
        return 1;
    }
}

bool pri[MAX]={0};	//0为素数，1为合数
int mian()
{
    int N=MAX;
    int i=0,cnt=0;
    //N=sqrt(N); 可以通过取N的根号提高效率
    for(i=2;i<=N;++i)
    {
        //if(isprime(i))
        //因为一个合数一定会被2、3、5、7、11等质数筛去
        if(!pir[i]) //如果这个数字未被筛去
        {
            int j=0;
            for(j=2*i;j<=N;j+=i)
                pri[j]=1;
        }   
    }
    for(i=2;i<=N;++i)
    {
        if(!pri[i])
            ++cnt;
    }
    printf("%lld\n",cnt);
    return 0;
}
```

### 2、埃氏筛法

```c
#include<stdio.h>
#include<math.h>
typedef MAX 1e7
//一个合数一定可以写成某个质数的n倍

bool pri[MAX]={0};	//0为素数，1为合数
int mian()
{
    int N=MAX;
    int i=0,cnt=0;
    N=sqrt(N);	//取N的根号
    for(i=2;i<=N;++i)
    {
        //if(isprime(i))
        //因为一个合数一定会被2、3、5、7、11等质数筛去
        if(!pir[i]) //如果这个数字未被筛去
        {
            int j=0;
            //筛去i的n倍的数
            for(j=i*i;j<=N;j+=i)//将j改为i*i提升效率
                pri[j]=1;
        }   
    }
    for(i=2;i<=N;++i)
    {
        if(!pri[i])
            ++cnt;
    }
    printf("%lld\n",cnt);
    return 0;
}
```

### 3、欧拉筛法

```c
120=2*2*2*3*5;
/*
由于埃氏筛法会对一个合数进行重复的筛选，如120就会进行3次筛选，2筛一次、3筛一次、5筛一次
*/
```

2、3、4、5、6、7、8、9、10

```c
#include<stdio.h>
#include<math.h>
typedef MAX 1e7;

int primes[MAX],pp=0;
bool pri[MAX]={0};	//一个标记，0为素数，1为合数
int mian()
{
    int N=MAX;
    int i=0,j=0;
    int cnt=0;
   
    for(i=2;i<=N;++i)
    {
        //++pp是从1开始的
        if(!pri[i]) primes[++pp]=i;
        for(j=1;j<=pp;++j)
        {
            pri[primes[j]*i]==1;
            if(i%primes[j]==0) break;
        }
    }
    for(i=2;i<=N;++i)
    {
        if(!pri[i])
            ++cnt;
    }
    printf("%lld\n",cnt);
    return 0;
}
```





# 九、动态规划

## 数字三角形：

首先，我们看一下这道题（此题目来源于北大POJ）：

数字三角形(POJ1163)

在上面的数字三角形中寻找一条从顶部到底边的路径，使得路径上所经过的数字之和最大。路径上的每一步都只能往左下或 右下走。只需要求出这个最大和即可，不必给出具体路径。 三角形的行数大于1小于等于100，数字为 0 - 99

输入格式：

5      //表示三角形的行数    接下来输入三角形

7

3   8

8   1   0

2   7   4   4

4   5   2   6   5

要求输出最大和

接下来，我们来分析一下解题思路：

首先，肯定得用二维数组来存放数字三角形

然后我们用D( r, j) 来表示第r行第 j 个数字(r,j从1开始算)

我们用MaxSum(r, j)表示从D(r,j)到底边的各条路径中，最佳路径的数字之和。

因此，此题的最终问题就变成了求 MaxSum(1,1)

当我们看到这个题目的时候，首先想到的就是可以用简单的递归来解题：

D(r, j)出发，下一步只能走D(r+1,j)或者D(r+1, j+1)。故对于N行的三角形，我们可以写出如下的递归式：   

**if ( r == N)                
	  MaxSum(r,j) = D(r,j)  
else**      
	MaxSum( r, j) = Max{ MaxSum(r＋1,j), MaxSum(r+1,j+1) } + D(r,j) 
    根据上面这个简单的递归式，我们就可以很轻松地写出完整的递归代码： 

### 1、递归实现

```c++
#include <iostream>  
#include <algorithm> 
#define MAX 101  
using namespace std; 
int D[MAX][MAX];  
int n;
int MaxSum(int i, int j)
{
	if(i==n)
		return D[i][j];
	int x = MaxSum(i+1,j);    
	int y = MaxSum(i+1,j+1);    
	return max(x,y)+D[i][j];  
}
int main()
{
	int i,j;    
	cin >> n;    
	for(i=1;i<=n;i++)   
		for(j=1;j<=i;j++)        
			cin >> D[i][j];    
	cout << MaxSum(1,1) << endl;  
}      
```

对于如上这段递归的代码，当我提交到OJ时，会显示如下结果：

<img src="https://img-blog.csdn.net/20150811140540144?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom: 67%;" />

对的，代码运行超时了，为什么会超时呢？

答案很简单，因为我们重复计算了，当我们在进行递归时，计算机帮我们计算的过程如下图：


​    <img src="https://img-blog.csdn.net/20150811140840233?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom:50%;" />

就拿第三行数字1来说，当我们计算从第2行的数字3开始的MaxSum时会计算出从1开始的MaxSum，当我们计算从第二行的数字8开始的MaxSum的时候又会计算一次从1开始的MaxSum，也就是说有重复计算。这样就浪费了大量的时间。也就是说如果采用递规的方法，深度遍历每条路径，存在大量重复计算。则时间复杂度为 2的n次方,对于 n = 100 行，肯定超时。 

接下来，我们就要考虑如何进行改进，我们自然而然就可以想到如果每算出一个MaxSum(r,j)就保存起来，下次用到其值的时候直接取用，则可免去重复计算。那么可以用n方的时间复杂度完成计算。因为三角形的数字总数是 n(n+1)/2

根据这个思路，我们就可以将上面的代码进行改进，使之成为记忆递归型的动态规划程序： 

### 2、记录簿优化

​    当我们提交如上代码时，结果就是一次AC

虽然在短时间内就AC了。但是，我们并不能满足于这样的代码，因为递归总是需要使用大量堆栈上的空间，很容易造成栈溢出，我们现在就要考虑如何把递归转换为递推，让我们一步一步来完成这个过程。

我们首先需要计算的是最后一行，因此可以把最后一行直接写出，如下图：


​    <img src="https://img-blog.csdn.net/20150811152746815?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom: 67%;" />

现在开始分析倒数第二行的每一个数，现分析数字2，2可以和最后一行4相加，也可以和最后一行的5相加，但是很显然和5相加要更大一点，结果为7，我们此时就可以将7保存起来，然后分析数字7，7可以和最后一行的5相加，也可以和最后一行的2相加，很显然和5相加更大，结果为12，因此我们将12保存起来。以此类推。。我们可以得到下面这张图：


​    <img src="https://img-blog.csdn.net/20150811153237686?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom: 67%;" />

然后按同样的道理分析倒数第三行和倒数第四行，最后分析第一行，我们可以依次得到如下结果：


 <img src="https://img-blog.csdn.net/20150811153534629?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom: 67%;" />   

​    

上面的推导过程相信大家不难理解，理解之后我们就可以写出如下的递推型动态规划程序： 

```c++
#include <iostream>  
#include <algorithm> 
using namespace std;

#define MAX 101

int D[MAX][MAX];    
int n;  
int maxSum[MAX][MAX];

int MaxSum(int i, int j){      
	if( maxSum[i][j] != -1 )         
		return maxSum[i][j];      
	if(i==n)   
		maxSum[i][j] = D[i][j];     
	else
    {    
		int x = MaxSum(i+1,j);       
		int y = MaxSum(i+1,j+1);       
		maxSum[i][j] = max(x,y)+ D[i][j];     
	}     
	return maxSum[i][j]; 
} 
int main(){    
	int i,j;    
	cin >> n;    
	for(i=1;i<=n;i++)   
		for(j=1;j<=i;j++) {       
			cin >> D[i][j];       
			maxSum[i][j] = -1;   
		}    
	cout << MaxSum(1,1) << endl; 
} 
```



### 3、存储优化

我们的代码仅仅是这样就够了吗？当然不是，我们仍然可以继续优化，而这个优化当然是对于空间进行优化，其实完全没必要用二维maxSum数组存储每一个MaxSum(r,j),只要从底层一行行向上递推，那么只要一维数组maxSum[100]即可,即只要存储一行的MaxSum值就可以。

 对于空间优化后的具体递推过程如下：

<img src="https://img-blog.csdn.net/20150811155011262?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom:67%;" />



<img src="https://img-blog.csdn.net/20150811155028144?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom:67%;" />

<img src="https://img-blog.csdn.net/20150811155119121?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom:67%;" />

<img src="https://img-blog.csdn.net/20150811155136507?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom:67%;" /><img src="https://img-blog.csdn.net/20150811155255355?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom:67%;" /><img src="https://img-blog.csdn.net/20150811155311499?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom:67%;" />



接下里的步骤就按上图的过程一步一步推导就可以了。进一步考虑，我们甚至可以连maxSum数组都可以不要，直接用D的第n行直接替代maxSum即可。但是这里需要强调的是：虽然节省空间，但是时间复杂度还是不变的。

依照上面的方式，我们可以写出如下代码：    

```c++
#include <iostream>  
#include <algorithm> 
using namespace std; 

#define MAX 101  

int D[MAX][MAX];  
int n; 
int * maxSum; 

int main(){    
	int i,j;    
	cin >> n;    
	for(i=1;i<=n;i++)   
		for(j=1;j<=i;j++)        
			cin >> D[i][j];   
	maxSum = D[n]; //maxSum指向第n行    
	for( int i = n-1; i>= 1;  --i )     
		for( int j = 1; j <= i; ++j )       
			maxSum[j] = max(maxSum[j],maxSum[j+1]) + D[i][j];
	cout << maxSum[1] << endl;  
}
```

接下来，我们就进行一下总结：

递归到动规的一般转化方法

递归函数有n个参数，就定义一个n维的数组，数组的下标是递归函数参数的取值范围，数组元素的值是递归函数的返回值，这样就可以从边界值开始， 逐步填充数组，相当于计算递归函数值的逆过程。

动规解题的一般思路

1. 将原问题分解为子问题

把原问题分解为若干个子问题，子问题和原问题形式相同或类似，只不过规模变小了。子问题都解决，原问题即解决(数字三角形例）。
子问题的解一旦求出就会被保存，所以每个子问题只需求 解一次。
2.确定状态

在用动态规划解题时，我们往往将和子问题相关的各个变量的一组取值，称之为一个“状 态”。一个“状态”对应于一个或多个子问题， 所谓某个“状态”下的“值”，就是这个“状 态”所对应的子问题的解。
所有“状态”的集合，构成问题的“状态空间”。“状态空间”的大小，与用动态规划解决问题的时间复杂度直接相关。 在数字三角形的例子里，一共有N×(N+1)/2个数字，所以这个问题的状态空间里一共就有N×(N+1)/2个状态。
整个问题的时间复杂度是状态数目乘以计算每个状态所需时间。在数字三角形里每个“状态”只需要经过一次，且在每个状态上作计算所花的时间都是和N无关的常数。

3.确定一些初始状态（边界状态）的值

以“数字三角形”为例，初始状态就是底边数字，值就是底边数字值。

4. 确定状态转移方程

 定义出什么是“状态”，以及在该“状态”下的“值”后，就要找出不同的状态之间如何迁移――即如何从一个或多个“值”已知的 “状态”，求出另一个“状态”的“值”(递推型)。状态的迁移可以用递推公式表示，此递推公式也可被称作“状态转移方程”。

数字三角形的状态转移方程:


​    <img src="https://img-blog.csdn.net/20150811160833998?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/Center" alt="img" style="zoom:50%;" />

能用动规解决的问题的特点

1) 问题具有最优子结构性质。如果问题的最优解所包含的 子问题的解也是最优的，我们就称该问题具有最优子结 构性质。

2) 无后效性。当前的若干个状态值一旦确定，则此后过程的演变就只和这若干个状态的值有关，和之前是采取哪种手段或经过哪条路径演变到当前的这若干个状态，没有关系。





## 过河卒：

棋盘上 A AA点有一个过河卒，需要走到目标B BB点。卒行走的规则：可以向下、或者向右。同时在棋盘上C CC点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。

棋盘用坐标表示，A AA 点 (0,0)(0, 0)(0,0)、B BB点 (n,m)(n, m)(n,m)，同样马的位置坐标是需要给出的。

<img src="https://img-blog.csdnimg.cn/img_convert/fc521162ebc6e6aabb0cf0a71e964219.png" alt="img" style="zoom: 80%;" />

现在要求你计算出卒从 A  点能够到达 B 点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。

输入格式
一行四个正整数，分别表示 B 点坐标和马的坐标。

输出格式
一个整数，表示所有的路径条数。

输入输出样例
输入 #1

6 6 3 3

输出 #1

6

说明/提示
对于100 100%100的数据，1 ⩽ m , n ⩾ 20 

**分析棋盘上到每个点的路径数目，如下图所示：**

<img src="https://img-blog.csdnimg.cn/20210710211847481.jpg" alt="img" style="zoom: 50%;" />

### **1、原理解释：**

每一个卒可以去到的格子的路数**等于可以去到上一个格子和可以去到左一个格子的路数和。**

**据此，我们可以得出一个迭代式的(x,y)=(x-1,y)+(x,y-1)**

```c++
#include<iostream>
#include<queue>
#include<cstring>
#include<iomanip>
#include<map>
using namespace std;
long long dp[30][30];
int m_x[8]={-2,-2,-1,-1,1,1,2,2},m_y[8]={1,-1,2,-2,2,-2,1,-1};//马跳的坐标变化

int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    n+=1;m+=1;x+=1;y+=1;//整体空出一行一列，便于边界检查
    for(int i=0;i<8;i++)
    {
        //检查标记是否越界（标记为马锁定的位置）
        if(x+m_x[i]>=1&&x+m_x[i]<=n&&y+m_y[i]>=1&&y+m_y[i]<=m)
            dp[x+m_x[i]][y+m_y[i]]=-1;	//标记为-1
    }
    dp[1][0]=1;		//起始点标位1（可以举例推一下就知道为啥不是0了）
    dp[x][y]=-1;	//马所在的点也不能走
    //双重循环遍历每一个点
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //马锁死的位置标记为0
            if(dp[i][j]==-1)
                dp[i][j]=0;
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }

    cout<<dp[n][m];
    return 0;
}
```



## 最长升子序：

### 1、通常做法：

**LIS定义**

**LIS**（Longest Increasing Subsequence）最长上升子序列 
一个数的序列bi，当b1 < b2 < … < bS的时候，我们称这个序列是上升的。

对于给定的一个序列(a1, a2, …, aN)，我们可以得到一些上升的子序列(ai1, ai2, …, aiK)，

这里1 <= i1 < i2 < … < iK <= N。 
比如，对于序列(1, 7, 3, 5, 9, 4, 8)，有它的一些上升子序列，如(1, 7), (3, 4, 8)等等。

这些子序列中最长的长度是4，比如子序列(1, 3, 5, 8). 
你的任务，就是对于给定的序列，求出**最长上升子序列的长度**。

**两种做法**

**O(N^2)做法：dp动态规划**

状态设计：dp[i]代表以a[i]结尾的LIS的长度 
状态转移：dp[i]=max(dp[i], dp[j]+1) (0<=j< i, a[j]< a[i]) 
边界处理：dp[i]=1 (0<=j< n) 
时间复杂度：O(N^2) 
举例： 对于序列(1, 7, 3, 5, 9, 4, 8)，dp的变化过程如下

| dp[i] | 初始值 | j=0  | j=1  | j=2  | j=3  | j=4  | j=5  |
| :---- | :----- | :--- | :--- | :--- | :--- | :--- | :--- |
| dp[0] | 1      |      |      |      |      |      |      |
| dp[1] | 1      | 2    |      |      |      |      |      |
| dp[2] | 1      | 2    | 2    |      |      |      |      |
| dp[3] | 1      | 2    | 2    | 3    |      |      |      |
| dp[4] | 1      | 2    | 3    | 3    | 4    |      |      |
| dp[5] | 1      | 2    | 2    | 3    | 3    | 3    |      |
| dp[6] | 1      | 2    | 3    | 3    | 4    | 4    | 4    |

求完dp数组后，取**其中的最大值**就是LIS的长度。【注意答案不是dp[n-1]，这个样例只是巧合】

```c
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
#include<map>
#include<stack>
#define eps 1e-6
using namespace std;
typedef long long ll;
using namespace std;
const int MAXX=10000+5;

// 1 6 2 7 3 8 4 9
int a[MAXX],dp[MAXX];
// a数组为数据，dp[i]表示以a[i]结尾的最长递增子序列长度
int n;
int LIS()
{
    int ans=1;
    for(int i=1; i<=n; i++)//枚举子序列的终点
    {
        dp[i]=1;// 初始化为1，长度最短为自身
        for(int j=1; j<i; j++)//从头向终点检查每一个元素
        {
            if(a[i]>a[j])
            {
                dp[i]=max(dp[i],dp[j]+1);  // 状态转移
            }
        }
        ans=max(ans,dp[i]);  // 比较每一个dp[i],最大值为答案
    }
    return ans;
}
int main()
{
    while(cin>>n)
    {
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        int ans=LIS();
        cout<<ans<<endl;
    }
    return 0;
}
```

**O(NlogN)做法：贪心+二分**

a[i]表示第i个数据。 
dp[i]表示表示长度为i+1的LIS结尾元素的最小值。 
**利用贪心的思想，对于一个上升子序列，显然当前最后一个元素越小，越有利于添加新的元素，这样LIS长度自然更长。** 
因此，我们只需要维护dp数组，其表示的就是长度为i+1的LIS结尾元素的最小值，保证每一位都是最小值，

**这样子dp数组的长度就是LIS的长度。**

dp数组具体维护过程同样举例讲解更为清晰。 
同样对于序列 a(1, 7, 3, 5, 9, 4, 8)，dp的变化过程如下：

- dp[0] = a[0] = 1，长度为1的LIS结尾元素的最小值自然没得挑，就是第一个数。 （dp = {1}）
- 对于a[1]=7，a[1]>dp[0]，因此直接添加到dp尾，dp[1]=a[1]。（dp = {1, 7}）
- 对于a[2]=3，dp[0]< a[2]< dp[1]，因此a[2]替换dp[1]，令dp[1]=a[2]，因为长度为2的LIS，结尾元素自然是3好过于7，因为越小这样有利于后续添加新元素。 （dp = {1, 3}）
- 对于a[3]=5，a[3]>dp[1]，因此直接添加到dp尾，dp[2]=a[3]。 （dp = {1, 3, 5}）
- 对于a[4]=9，a[4]>dp[2]，因此同样直接添加到dp尾，dp[3]=a[9]。 （dp = {1, 3, 5, 9}）
- 对于a[5]=4，dp[1]< a[5]< dp[2]，因此a[5]替换值为5的dp[2]，因此长度为3的LIS，结尾元素为4会比5好，越小越好嘛。（dp = {1, 3, 4, 9}）
- 对于a[6]=8，dp[2]< a[6]< dp[3]，同理a[6]替换值为9的dp[3]，道理你懂。 （dp = {1, 3, 5, 8}）

这样子dp数组就维护完毕，所求LIS长度就是dp数组长度4。 
通过上述求解，可以发现dp数组是单调递增的，因此对于每一个a[i]，先判断是否可以直接插入到dp数组尾部，

即比较其与dp数组的最大值即最后一位；如果不可以，则找出dp中第一个大于等于a[i]的位置，用a[i]替换之。 
这个过程可以利用**二分查找**，因此查找时间复杂度为O(logN)，所以总的时间复杂度为O(N*logN)

```c
#include <bits/stdc++.h>
using namespace std;
const int MAXX=100000+5;
const int INF=INT_MAX;
 
int a[MAXX],dp[MAXX]; // a数组为数据，dp[i]表示长度为i+1的LIS结尾元素的最小值
 
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            dp[i]=INF; // 初始化为无限大
        }
        int pos=0;    // 记录dp当前最后一位的下标
        dp[0]=a[0];   // dp[0]值显然为a[0]
        for(int i=1; i<n; i++)
        {
            if(a[i]>dp[pos])    // 若a[i]大于dp数组最大值，则直接添加
                dp[++pos] = a[i];
            else    // 否则找到dp中第一个大于等于a[i]的位置，用a[i]替换之。
                dp[lower_bound(dp,dp+pos+1,a[i])-dp]=a[i];  // 二分查找
        }
        cout<<pos+1<<endl;
    }
    return 0;
}
```



### 2、我的做法：

**通过树去维护数组，以树的形式表示最长子序，而树的深度就是最长升子序。**

用查并集的思想去做。

例如：a(3，5，4，1，2，9，6，7，8) 的最长升子序。

<img src="D:\Users\suyu\Pictures\Typora-picture\image-20230412215621612.png" alt="image-20230412215621612" style="zoom:67%;" />



```c

int a[]={3,5,4,1,2,9,6,7,8};
len=strlen(a);
int su[len][len]={0};
for(i=0;i<len;++i)
{
    if(i==0)
        su[0][0]=a[i]
    else
    {
        if(a[i]>a[i-1])
    }
}
```





# 十、二分查找

## 1、简介

故事分享🏬：

```c
//有一天小明到图书馆借了 N 本书，出图书馆的时候，警报响了，于是保安把小明拦下，要检查一下哪本书没有登记出借。小明正准备把每一本书在报警器下过一下，以找出引发警报的书，但是保安露出不屑的眼神：你连二分查找都不会吗？于是保安把书分成两堆，让第一堆过一下报警器，报警器响；于是再把这堆书分成两堆…… 最终，检测了 logN 次之后，保安成功的找到了那本引起警报的书，露出了得意和嘲讽的笑容。于是小明背着剩下的书走了。 从此，图书馆丢了 N - 1 本书。
```

保安怎么知道只有一本书📖没有登记出借，万一全部都没有登记呢？

这个故事其实说出了二分查找**需要的条件**

①用于查找的内容逻辑上来说是需要有序的
②查找的数量只能是一个，而不是多个

比如在一个有序的数组并且无重复元素的数组中，例如[1, 2, 3, 4, 5, 6]，需要查找3的位置就可以使用二分查找。

```c
//在二分查找中，目标元素的查找区间的定义十分重要，不同的区间的定义写法不一样
```

因为查找的区间是不断迭代的，所以确定查找的范围十分重要，主要就是左右区间的开和闭的问题，开闭不一样，对应的迭代方式也不一样，有以下两种方式：

——左闭右闭[left, right]

——左闭右开[left, right)

**2、例子**
这是一个使用二分查找的例题

题目如下：

```c
//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
```

示例一：

```c
//输入: nums = [-1,0,3,5,9,12], target = 9
//输出: 4
//解释: 9 出现在 nums 中并且下标为 4
```

示例二：

```c
//输入: nums = [-1,0,3,5,9,12], target = 2
//输出: -1
//解释: 2 不存在 nums 中因此返回 -1
```

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。

出自704. 二分查找 - [力扣 (leetcode.cn)](https://leetcode.cn/problems/binary-search/)

二分法的思想很简单，**因为整个数组是有序的**，数组默认是递增的。

①首先选择数组中间的数字和需要查找的目标值比较
②如果相等最好，就可以直接返回答案了
③如果不相等
	>>>如果中间的数字大于目标值，则中间数字向右的所有数字都大于目标值，全部排除

​	>>>如果中间的数字小于目标值，则中间数字向左的所有数字都小于目标值，全部排除

二分法就是按照这种方式进行快速排除查找的

```c
tips:
不用去纠结数组的长度是奇数或者偶数的时候，怎么取长度的一半，以下说明，可以跳过。
```

当数组的长度为奇数的时候：

<img src="https://img-blog.csdnimg.cn/20210424160141149.png" alt="img" style="zoom: 67%;" />


是奇数的情况很简单，指向中间的数字很容易理解，如果需要查找的数字为29

因为29大于中间的数字大于11，所以左边的所有数字全部排除

<img src="https://img-blog.csdnimg.cn/20210424160241753.png" alt="img" style="zoom:67%;" />

**当数组的长度为偶数的时候：**

<img src="https://img-blog.csdnimg.cn/20210424160301212.png" alt="img" style="zoom:67%;" />


这个时候中间的数字两边的数字数量就不一样了（刚开始学习二分法的时候我经常纠结这个问题，和另外一个长度除2得到的是最中间的数吗的问题，我相信不止我一个人纠结过……但其实这是同一个问题，每次长度除2，如果长度为奇数，得到的中间的数字两边数字数量相同，如果长度为偶数就为上图中间的数字两边的相差为 1）

但是千万不要一直纠结中间的数字两边的数字数量不一样这个问题，因为：

两边数量不一样是一定会出现的情况
但是这种情况并不影响我们对中间数字和目标数字大小关系的判断
只要中间数字大于目标数字，就排除右边的
只要中间数字小于目标数字，就排除左边的
所以数组长度是偶数还是奇数这个真的不重要，不影响怎么排除的问题，无非是多排除一个数字或者少排除一个数字

**真正影响的是中间那个数字到底该不该加入下一次的查找中，也就是*边界问题***



## 2、第一种写法（左闭右闭）

**二分法最重要的两个点：**

①while循环中 left 和 right 的关系，到底是 left <= right 还是 left < right
②迭代过程中 middle 和 right 的关系，到底是 right = middle - 1 还是 right = middle

**2.1 正向写法（正确演示）**

​		第一种写法：每次查找的区间在[left, right]（左闭右闭区间），根据查找区间的定义（左闭右闭区间），就决定了后续的代码应该怎么写才能对。因为定义 target 在[left, right]区间，所以有如下两点：

循环条件要使用while(left <= right)，因为当(left == right)这种情况发生的时候，得到的结果是有意义的
if(nums[middle] > target) ， right 要赋值为 middle - 1， 因为当前的 nums[middle] 一定不是 target ，需要把这个 middle 位置上面的数字丢弃，那么接下来需要查找范围就是[left, middle - 1]
代码如下：

```c
//nums是数组，size是数组的大小，target是需要查找的值
int search(int nums[], int size, int target) 
{
    int left = 0;
    // 定义了target在左闭右闭的区间内，[left, right]
    int right = size - 1;	
    //当left == right时，区间[left, right]仍然有效
    while (left <= right) 
    {	
        //等同于 (left + right) / 2，防止溢出
        int middle = left + ((right - left) / 2);
        if (nums[middle] > target)
        {
            right = middle - 1;	//target在左区间，所以[left, middle - 1]
        } 
        else if (nums[middle] < target) 
        {
            left = middle + 1;	//target在右区间，所以[middle + 1, right]
        } 
        else 
        {	//既不在左边，也不在右边，那就是找到答案了
            return middle;
        }
    }
    //没有找到目标值
    return -1;
}
```



首先看一个数组，需要对这个数组进行操作。需要对33进行查找的操作，那么**target 的值就是33**

<img src="https://img-blog.csdnimg.cn/20210424160758343.png" alt="img" style="zoom:67%;" />

首先，对 left 的值和 right 的值进行初始化，然后计算 middle 的值

```c
left = 0, right = size - 1
middle = (left + (right - left) / 2 )
```

<img src="https://img-blog.csdnimg.cn/20210424160823492.png" alt="img" style="zoom:67%;" />

比较 nums[middle] 的值和 target 的值大小关系

```c
if (nums[middle] > target)，代表middle向右所有的数字大于target
if (nums[middle] < target)，代表middle向左所有的数字小于target
//既不大于也不小于就是找到了相等的值
```

**nums[middle] = 13 < target = 33，left = middle + 1**

见下图：

<img src="https://img-blog.csdnimg.cn/2021042416084724.png" alt="img" style="zoom:67%;" />

```c
循环条件为 while (left <= right)

此时，left = 6 <= right = 11，则继续进行循环

当前，middle = left + ((right - left) / 2)，计算出 middle 的值
```


计算出 middle 的值后，比较 nums[middle] 和 target 的值，发现：

**nums[middle] = 33 == target = 33，找到目标**



**2.2 反向写法(错误演示)**

对应第一种正向的写法，我们把循环条件修改看看会发生什么事

​	原查找区间 [left, right]
​	原循环条件是 while (left <= right)

修改后题目对应的条件：

​	查找区间不变，仍然是[left, right]
​	查找数字为27 (target = 27)
​	循环条件修改为while (left < right)

代码：

```c
int search(int nums[], int size, int target) 
{
    int left = 0;
    int right = size - 1;	
    while (left < right) {	//left <= right 修改为 left < right,其他不变
        int middle = left + ((right - left) / 2);
        if (nums[middle] > target) {
            right = middle - 1;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else {	
            return middle;
        }
    }
    //没有找到目标值
    return -1;
}
```




好了，现在开始用图片模拟过程

​	初始化一个数组，计算 middle 的值

![img](https://img-blog.csdnimg.cn/20210424161148136.png)

根据计算的 middle 值确定 nums[middle]

![img](https://img-blog.csdnimg.cn/20210424161214479.png)

因为nums[middle] = 13 < target = 27，所以left = middle + 1

![img](https://img-blog.csdnimg.cn/20210424161238873.png)

继续计算 middle 的值

![img](https://img-blog.csdnimg.cn/20210424161339460.png)

因为 nums[middle] = 33 > target = 27，所以 right = middle - 1

![img](https://img-blog.csdnimg.cn/20210424161355107.png)

接着计算 middle 的值

![img](https://img-blog.csdnimg.cn/20210424161422235.png)

因为 nums[middle] = 22 < target = 27，此时 left = middle + 1，此时 left = right，而循环条件为while (left < right)，所以还未找到27 的情况下算法就跳出了循环，返回 -1

![img](https://img-blog.csdnimg.cn/20210424161440637.png)

## 3、第二种写法（左闭右开）

**3.1 正向写法（正确演示）**

第二种写法：每次查找的区间在 [left, right)，（左闭右开区间）， 根据区间的定义，条件控制应该如下：

​	循环条件使用while (left < right)
​	if (nums[middle] > target)， right = middle，因为当前的 nums[middle] 是大于 target 的，不符合条件,不能取到 middle，并且区间	的定义是 [left, right)，刚好区间上的定义就取不到 right, 所以 right 赋值为 middle。

代码如下：

```c
int search(int nums[], int size, int target)
{
	int left = 0;
	int right = size; //定义target在左闭右开的区间里，即[left, right)
	while (left < right) {	//因为left = right的时候，在[left, right)区间上无意义
		int middle = left + ((right - left) / 2);
		if (nums[middle] > target) {
			right = middle; //target 在左区间，在[left, middle)中 
		} else if (nums[middle] < target) {
			left = middle + 1;
		} else {
			return middle;
		}
	} 
    // 没找到就返回-1
	return -1;
}
```



**需要查找的值为3*

第一步是初始化 left 和 right 的值，然后计算 middle 的值

​	left = 0, right = size
​	循环条件while (left < right)

因为是左闭右开区间，所以数组定义如下：

![img](https://img-blog.csdnimg.cn/20210424161720534.png)

计算 middle 的值

![img](https://img-blog.csdnimg.cn/2021042416174072.png)

比较 nums[middle] 和 target 的大小：因为 nums[middle] = 22 > target = 3
所以 right = middle

![img](https://img-blog.csdnimg.cn/20210424161805761.png)

符合循环的条件，接着计算 middle 的值

![img](https://img-blog.csdnimg.cn/20210424161816659.png)

比较 nums[middle] 和 target 的大小：因为 nums[middle] = 9 > target = 3
所以 right = middle

![img](https://img-blog.csdnimg.cn/20210424161836963.png)

符合循环的条件，继续计算 middle 的值

![img](https://img-blog.csdnimg.cn/20210424161848640.png)

比较 nums[middle] 和 target 的大小关系：因为nums[middle] = 0 < target = 3
所以 left = middle + 1

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210424161903340.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ1OTc4ODkw,size_16,color_FFFFFF,t_70#pic_center)

符合循环条件，接着计算 middle 的值

![img](https://img-blog.csdnimg.cn/20210424161919407.png)

比较 nums[middle] 和 target 的关系：nums[middle] = 3 == target = 3
成功找到 target



**3.2 反向写法（错误演示）**

对应第二种正确的写法，照样把循环条件修改，看会发生什么事

正确的写法中条件为：

​	查找原区间 [left, right)
​	循环条件为 while (left < right)

修改后题目对应的条件：

​	查找区间不变，仍然是 [left, right)

​	循环条件修改为：while (left <= right)

​	查找的数字为26（数组中不存在这个数字！！！）

代码：

```c
int search(int nums[], int size, int target)
{
	int left = 0;
	int right = size; 
	while (left <= right) {	//条件left < right 修改为 left <= right
		int middle = left + ((right - left) / 2);
		if (nums[middle] > target) {
			right = middle; 
		} else if (nums[middle] < target) {
			left = middle + 1;
		} else {
			return middle;
		}
	} 
    // 没找到就返回-1
	return -1;
}
```




以下是演示全过程：

同样，开始初始化一个数组

![img](https://img-blog.csdnimg.cn/20210424162039656.png)

先计算 middle 的值

![img](https://img-blog.csdnimg.cn/20210424162054302.png)

判断 nums[middle] 和 target 的大小关系：nums[middle] = 22 < target = 26
left = middle + 1 （其实这里nums[left] 已经等于27，26不可能找到，接下去就看算法是否能够知道数组中不存在26并且返回-1 了）

![img](https://img-blog.csdnimg.cn/20210424162108630.png)

符合循环条件，计算 middle 的值

![img](https://img-blog.csdnimg.cn/20210424162119840.png)

判断 nums[middle] 和 target 的大小关系：nums[middle] = 57 > target = 26
right = middle

![img](https://img-blog.csdnimg.cn/20210424162137619.png)

满足循环条件，接着计算 middle 的值

![img](https://img-blog.csdnimg.cn/20210424162154499.png)

比较 nums[middle] 和 target 的大小关系：nums[middle] = 33 > target = 26
right = middle

![img](https://img-blog.csdnimg.cn/20210424162207609.png)

符合循环条件，继续计算 middle 的值

![img](https://img-blog.csdnimg.cn/20210424162223901.png)

比较 nums[middle] 和 target 大小关系，因为 nums[middle] = 27 > target = 26，
所以 right = middle，自此，left 和 right 相遇，但是循环条件被我们修改成 while (left <= right) 会接着做循环

![img](https://img-blog.csdnimg.cn/20210424162235639.png)

接下来就是死循环

因为 middle = left + ((right - left) / 2)，当 left = right 的时候，middle 的值不会继续改变

middle 不继续改变，由于right = middle，right 也不会改变，所以三个数字自此开始不会继续改变

循环条件 while (left <= right) 却仍然满足，不会跳出循环

死循环……

## 5、总结

二分法最重要的两个点，就是循环条件和后续的区间赋值问题

![img](https://img-blog.csdnimg.cn/20210424162256792.png)


因为两者是相互联系，相互影响的，所以就需要两者统一，如果两者不统一，就会出现问题

所以循环条件和赋值问题必须统一，也就是循环不变量。



# 十一、字典树

## 1、什么是字典树？

**叫前缀树更容易理解**
**字典树的样子**

<img src="https://img-blog.csdn.net/20180823221048359?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTc3ODU3MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70" alt="这里写图片描述" style="zoom:50%;" />

Trie又被称为前缀树、字典树，所以当然是一棵树。上面这棵Trie树包含的字符串集合是{in, inn, int, tea, ten, to}。每个节点的编号是我们为了描述方便加上去的。树中的每一条边上都标识有一个字符。这些字符可以是任意一个字符集中的字符。比如对于都是小写字母的字符串，字符集就是’a’-‘z’；对于都是数字的字符串，字符集就是’0’-‘9’；对于二进制字符串，字符集就是0和1。

比如上图中3号节点对应的路径0123上的字符串是inn，8号节点对应的路径0568上的字符串是ten。终结点与集合中的字符串是一一对应的。

## 2、原理

下面我们来讲一下对于给定的字符串集合{W1, W2, W3, … WN}如何创建对应的Trie树。其实上Trie树的创建是从只有根节点开始，通过依次将W1, W2, W3, … WN插入Trie中实现的。所以关键就是之前提到的Trie的插入操作。
具体来说，Trie一般支持两个操作：

1. Trie.insert(W)：第一个操作是插入操作，就是将一个字符串W加入到集合中。
2. Trie.search(S)：第二个操作是查询操作，就是查询一个字符串S是不是在集合中。

假设我们要插入字符串”in”。我们一开始位于根，也就是0号节点，我们用P=0表示。我们先看P是不是有一条标识着i的连向子节点的边。没有这条边，于是我们就新建一个节点，也就是1号节点，然后把1号节点设置为P也就是0号节点的子节点，并且将边标识为i。最后我们移动到1号节点，也就是令P=1。

<img src="https://img-blog.csdn.net/20180823221726242?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTc3ODU3MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70" alt="这里写图片描述" style="zoom: 80%;" />

这样我们就把”in”的i字符插入到Trie中了。然后我们再插入字符n，也是先找P也就是1号节点有没有标记为n的边。还是没有，于是再新建一个节点2，设置为P也就是1号节点的子节点，并且把边标识为n。最后再移动到P=2。这样我们就把n也插入了。由于n是”in”的最后一个字符，所以我们还需要将P=2这个节点标记为终结点。

<img src="https://img-blog.csdn.net/20180823221834440?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTc3ODU3MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70" alt="这里写图片描述" style="zoom:67%;" />

现在我们再插入字符串”inn”。过程也是一样的，从P=0开始找标识为i的边，这次找到1号节点。于是我们就不用创建新节点了，直接移动到1号节点，也就是令P=1。再插入字符n，也是有2号节点存在，所以移动到2号节点，P=2。最后再插入字符n这时P没有标识为n的边了，所以新建3号节点作为2号节点的子节点，边标识为n，同时将3号节点标记为终结点：

<img src="https://img-blog.csdn.net/20180823221923252?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTc3ODU3MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70" alt="这里写图片描述" style="zoom:67%;" />

将后面的字符串int tea ten to都插入之后，就得到了我们一开始给出的Trie：

<img src="https://img-blog.csdn.net/20180823221955893?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTc3ODU3MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70" alt="这里写图片描述" style="zoom:50%;" />



下面我们再讲一下如何查询Trie树中是不是包含字符串S，也就是之前提到的查找操作。查找其实比较简单。我们只要从根节点开始，沿着标识着S[1] -> S[2] -> S[3] … -> S[S.len]的边移动，如果最后成功到达一个终结点，就说明S在Trie树中；如果最后无路可走，或者到达一个不是终结点的节点，就说明S不在Trie树中。

![这里写图片描述](https://img-blog.csdn.net/20180823222102694?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl8zOTc3ODU3MA==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

如果是查找”te”，就会从0开始经过5最后到达6。但是6不是终结点，所以te没在Trie树中。如果查找的是”too”，就会从0开始经过5和9，然后发现之后无路可走：9号节点没有标记为o的边连出去。所以too也不在Trie中。

## 3、代码实现

数组方式实现
要写代码实现一个Trie首先就要确定如何存储一个Trie结构。这里用一个二维数组来存储：

int trie [MAX_NODE] [CHARSET];
int k;
其中MAX_NODE是trie中最大能存储的节点数目，CHARSET是字符集的大小，k是当前trie中包含有多少个节点。Trie[i][j]的值是0表示trie树中i号节点，并没有一条连出去的边，满足边上的字符标识是字符集中第j个字符（从0开始）；trie[i][j]的值是正整数x表示trie树中i号节点，有一条连出去的边，满足边上的字符标识是字符集中第j个字符，并且这条边的终点是x号节点。

**简单实现**

```c++
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAX_NODE = 1000000 + 10;
const int CHARSET = 26;
//MAX_NODE层，每层有26个结点的树
/*
a b c d e f g h i j k  l  ……
0 1 2 3 4 5 6 7 8 9 10 11 ……
0
1
2
3
~
*/
int trie[MAX_NODE][CHARSET] = {0};
int color[MAX_NODE] = {0};
int k = 1;

void insert(char *w)
{
    int len = strlen(w);
    int p = 0;
    for(int i=0; i<len; i++)
    {
        //映射目标字符的纵坐标a->0,b->1,c->2……
        int c = w[i] - 'a';
        //如果没有目标字符的边
        if(trie[p][c]==0)
        {
            //创建一个边
            trie[p][c] = k;
            //k记录结点序数
            k++;
        }
        //p记录层数
        p = trie[p][c];
        
      //记录从根节点至该节点字符串重复的次数
      //color[p]+=1
    }
    //记录字符串终止结点位置
    color[p] = 1;
}

int search(char *s)
{
    int len = strlen(s);
    int p = 0;
    for(int i=0; i<len; i++)
    {
        int c = s[i] - 'a';
        if(!trie[p][c]) 
            return 0;
        p = trie[p][c];
    }
    return color[p] == 1;
}

int main()
{
    int t,q;
    char s[20];
    scanf("%d%d", &t,&q);
    while(t--)
    {
        scanf("%s", s);
        insert(s);
    }
    while(q--)
    {
        scanf("%s", s);
        if(search(s))
            printf("YES\n");
        else 
            printf("NO\n");
    }
    return 0;
}
```

## 4、最大异或对

给定*N*个整数*A*1、*A*2、*A*3……*A**N*；从中选出两个数进行异或运算，得到结果的最大值是多少？

数据范围：

1≤N≤10^5

1≤A(i)≤10^8;

Input

第一行输入一个数*N*；

第二行输入*N*个数表示：*A1、A2……A(N)*。

Output

输出一个数，表示答案。



Sample Input 1 

```
3
1 2 3
```

Sample Output 1

```
3
```

Source

```c
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<math.h>
#include<string.h>
int son[100010][2] = { 0 };
int idx = 1;
int a[100010] = { 0 };

int max(a, b)
{
	if (a > b)
		return a;
	else
		return b;
}

void insert(int x)
{
	int p = 0;
	int i = 0;
	for (i = 30; i >= 0; --i)
	{
        //取出x的二进制最高位
		int u = x >> i & 1;
		if (son[p][u] == 0)
		{
			son[p][u] = idx;
			++idx;
		}
		p = son[p][u];
	}
}

//用于找寻某个数在已建字典树中
//对应最大异或数是多少
int find(int x)
{
	int p = 0, res = 0;
	int i = 0;
	for (i = 30; i >= 0; --i)
	{
		int u = x >> i & 1;
		//检查对应层有无不同的数
		if (son[p][!u])	//有不同数
		{
			p = son[p][!u];	//p就指到不同数的地址
            //res=res+(1<<i);
            //还原某数最大异或数对应二进制数字为十进制
            //原理：难以理解┭┮﹏┭┮（原理见下图）
            
            //原理：补充，二进制本质为某个数进行短除法的余数
            //而res = (res * 2) + !u是对短除的逆过程
			res = (res * 2) + !u;
		}
		else  //没有不同数
		{
			p = son[p][u];
			res = (res * 2) + u;
		}
	}
	return res;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)  
		scanf("%d", &a[i]);

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		insert(a[i]);
		int t = find(a[i]);
		res = max(res, a[i] ^ t);
	}
	printf("%d\n", res);
	return 0;
}
```







# 十二、打表

**通过数据的有限和特殊性，将有限结果制作成表。**



### 数学难题

Description



已知有一个仅由00和11组成的字符串s，且这个字符串中的每一个字符每过一秒就会发生改变：

```
1. 0会变成01
2. 1会变成10
```

在第00秒时s="0"，请问在经过m秒之后s的前n个字符是及s*1,*s*2,*s*3……*s**n*是什么。



Input



第一行输入一个数t，表示有t组输入（1≤t≤10001≤*t*≤1000）；

接下来的每一组输入两个数n*,*m*（1≤*n*≤1000,1≤*m*≤200000）；

保证所有的m的和不超过200000200000 。



Output



每组输出一段字符串表示答案，并且每一组之间用换行隔开。



Sample Input 1 

```
2
1 3
10 10
```

Sample Output 1

```
0
0110100110
```

Hint

第0秒时：0

第1秒时：01

第2秒时：0110

第3秒时：01101001

```cpp

#include<iostream>
#include<list>
#include<string>
#include<bitset>
using namespace std;
//由于数据只需要求n<=1000的前n个数，所以先通过暴力求出前1000位数，然后直接遍历前n位即可
string str = { "01101001100101101001011001101001100101100110100101101001100101101001011001\
101001011010011001011001101001100101101001011001101001100101100110100101101001100101100110\
100110010110100101100110100101101001100101101001011001101001100101100110100101101001100101\
101001011001101001011010011001011001101001100101101001011001101001011010011001011010010110\
011010011001011001101001011010011001011001101001100101101001011001101001100101100110100101\
101001100101101001011001101001011010011001011001101001100101101001011001101001100101100110\
100101101001100101100110100110010110100101100110100101101001100101101001011001101001100101\
100110100101101001100101100110100110010110100101100110100110010110011010010110100110010110\
100101100110100101101001100101100110100110010110100101100110100101101001100101101001011001\
101001100101100110100101101001100101101001011001101001011010011001011001101001100101101001\
011001101001100101100110100101101001100101100110100110010110100101100110100101101001100101\
101001011001101001100101100110100101101001100101100" };

int main() {
	int cen = 0;
	int n = 0, m = 0;
	//list<int>bit1{ 0 };
	cin >> cen;
	
	for (int i = 0; i < cen; ++i) {
		string ans = "";
		cin >> n >> m;
		for (int j = 0; j < n; ++j) {
			ans += str[j];
		}
		cout <<ans<<'\n';
	}
	return 0;
}
```

