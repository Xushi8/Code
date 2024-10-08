使用邻项交换排序需要注意的问题
另一道例题
题目来源
洛谷P2123 皇后游戏

题目描述
皇后有 $n$ 位大臣，每位大臣的左右手上面分别写上了一个正整数。恰逢国庆节来临，皇后决定为 $n$ 位大臣颁发奖金，其中第 $i$ 位大臣所获得的奖金数目为第 $i－1$ 位大臣所获得奖金数目与前 $i$ 位大臣左手上的数的和的较大值再加上第 $i$ 位大臣右手上的数。

形式化地讲：我们设第 $i$ 位大臣左手上的正整数为 $a_i$ ，右手上的正整数为 $b_i$ ，

则第 $i$ 位大臣获得的奖金数目为 $c_i$ 可以表达为：

$$c_i=\begin{cases}a_1+b_1 & i=1\\\max(c_{i-1},\sum\limits_{j=1}^ia_j)+b_i & 2\le i\le n\end{cases}$$

当然，吝啬的皇后并不希望太多的奖金被发给大臣，所以她想请你来重新安排一下队伍的顺序，使得获得奖金最多的大臣，所获奖金数目尽可能的少。

注意：重新安排队伍并不意味着一定要打乱顺序，我们允许不改变任何一位大臣的位置。

输入格式
第一行包含一个正整数 $T$ ，表示测试数据的组数。

接下来 $T$ 个部分，每个部分的第一行包含一个正整数 $n$ ，表示大臣的数目。

每个部分接下来 $n$ 行中，每行两个正整数，分别为 $a_i$ 和 $b_i$ ，含义如上文所述。

输出格式
共 $T$ 行，每行包含一个整数，表示获得奖金最多的大臣所获得的奖金数目。

数据范围
对于全部测试数据满足：$T\le10,1\le n\le20000,1\le a_i,b_i\le10^9$ 。

尝试用邻项交换排序解决问题
还是选取相邻的两个大臣 $i$ 和 $j$ （$j$ 此时在 $i$ 后一个），交换 $i$ 和 $j$ 对前面的大臣无影响，对后面的大臣的影响在于排在后面的那个大臣获得的奖金，需要使之尽量小。

设这两个大臣前面的所有大臣左手上的数之和为 $\rm sum$ ，这两个大臣的再往前一个大臣得到的奖金是 $\rm pre$ 。

当 $i$ 在前 $j$ 在后时，这个值为 $\max(\max(\mathrm{pre},\mathrm{sum}+a_i)+b_i,\mathrm{sum}+a_i+a_j)+b_j$ 。

当 $j$ 在前 $i$ 在后时，这个值为 $\max(\max(\mathrm{pre},\mathrm{sum}+a_j)+b_j,\mathrm{sum}+a_j+a_i)+b_i$ 。

由于 $\max(x,y)+z=\max(x+z,y+z)$ ，需要比较的就是 $\max(\mathrm{pre}+b_i+b_j,\mathrm{sum}+a_i+b_i+b_j,\mathrm{sum}+a_i+a_j+b_j)$ 和 $\max(\mathrm{pre}+b_j+b_i,\mathrm{sum}+a_j+b_j+b_i,\mathrm{sum}+a_j+a_i+b_i)$ ，其中 $\mathrm{pre}+b_i+b_j=\mathrm{pre}+b_j+b_i$ ，需要比较的就是 $\max(\mathrm{sum}+a_i+b_i+b_j,\mathrm{sum}+a_i+a_j+b_j)$ 和 $\max(\mathrm{sum}+a_j+b_j+b_i,\mathrm{sum}+a_j+a_i+b_i)$ ，再用 $\mathrm{sum}+a_i+b_i+a_j+b_j$ 减去两边并变号，即：当 $\min(a_i,b_j)>\min(a_j,b_i)$ 时，需要交换 $i$ 和 $j$。

于是，可以写出以下代码，并在洛谷上AC此题：
```
#include <iostream>
#include <algorithm>

using namespace std;

const int N=20010;

struct Node
{
    int a,b;
    bool operator<(Node& y)
    {
        return min(a,y.b)<min(b,y.a);
    }
} dc[N];

long long ans,sum,t,n;

int main()
{
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;++i)
        {
            cin>>dc[i].a>>dc[i].b;
        }
        sort(dc+1,dc+n+1);
        ans=sum=0;
        for (int i=1;i<=n;++i)
        {
            sum+=dc[i].a;
            ans=max(ans,sum)+dc[i].b;
        }
        cout<<ans<<endl;
    }
    return 0;
}
```
hack数据
事实上，上面的做法是错误的，无法通过下面这组数据：

2
4
1 1
1 1
3 5
2 7
4
1 1
3 5
1 1
2 7
这两组数据只有大臣给出的顺序不同，但上面的代码输出为：

16
17
输出中间结果，可以发现，排列后的最终结果分别为：

1 1
1 1
2 7
3 5
和

1 1
3 5
1 1
2 7
这两种排列方式都满足 $\forall i\in [1,n),\min(a_i,b_{i+1})\le\min(a_{i+1},b_i)$，但第二种方式并不是最优解。具体原因将在下文分析。

严格弱序
严格弱序简介
要知道为什么这种做法是错误的，首先需要了解严格弱序（strict weak ordering）。

对于一个比较运算符（用“$<$”表示此运算符，用“$\not<$”表示不满足此运算符），若满足以下四个条件，则称其是满足严格弱序的：

$x\not<x$ （非自反性）
若 $x<y$，则 $y\not<x$ （非对称性）
若 $x<y,y<z$，则 $x<z$ （传递性）
若 $x\not<y,y\not<x,y\not<z,z\not<y$，则 $x\not<z,z\not<x$ （不可比性的传递性）
而 C++ 标准库要求用于排序的运算符必须满足严格弱序：

It has to be antisymmetric.

This means that for operator $<$: If $x < y$ is true, then $y < x$ is false.

This means that for a predicate op(): If op(x,y) is true, then op(y,x) is false.

It has to be transitive.

This means that for operator $<$: If $x < y$ is true and $y < z$ is true, then $x < z$ is true.

This means that for a predicate op(): If op(x,y) is true and op(y,z) is true, then op(x,z)

is true.

It has to be irreflexive.

This means that for operator $<$: $x < x$ is always false.

This means that for a predicate op(): op(x,x) is always false.

It has to have transitivity of equivalence, which means roughly: If a is equivalent to b and b is

equivalent to c, then a is equivalent to c.

This means that for operator $<$: If $!(a<b) \&\& !(b<a)$ is true and $!(b<c) \&\& !(c<b)$ is true

then $!(a<c) \&\& !(c<a)$ is true.

This means that for a predicate op(): If op(a,b), op(b,a), op(b,c), and op(c,b) all yield

false, then op(a,c) and op(c,a) yield false.

上述做法的判断条件满足传递性，但不满足不可比性的传递性。

满足传递性的证明
命题：$\forall \begin{cases}\min(a_i,b_j)<\min(a_j,b_i)\\\min(a_j,b_k)<\min(a_k,b_j)\end{cases}$，有 $\min(a_i,b_k)<\min(a_k,b_i)$。

将上式拆解成逻辑式，即证：

$\forall \begin{cases}(a_i<a_j\lor b_j<a_j)\land(a_i<b_i\lor b_j<b_i) \\(a_j<a_k\lor b_k<a_k)\land(a_j<b_j\lor b_k<b_j)\end{cases}$，有 $(a_i<a_k\lor b_k<a_k)\land(a_i<b_i\lor b_k<b_i)$。

假设原命题不成立，即 $\exists\begin{cases}(a_i<a_j\lor b_j<a_j)\land(a_i<b_i\lor b_j<b_i)&(1) \\(a_j<a_k\lor b_k<a_k)\land(a_j<b_j\lor b_k<b_j)&(2) \\(a_i\ge a_k\land b_k\ge a_k)\lor(a_i\ge b_i\land b_k\ge b_i)&(3)\end{cases}$

分别讨论 $(3)$ 式成立的两种情况：

若 $a_i\ge a_k\land b_k\ge a_k$，由 $(2)$ 式得 $a_j<a_k$，进而推出 $a_j<a_i$，再由 $(1)$ 式得 $b_j<a_j$，再由 $(2)$ 式得到 $b_k<b_j$，所以 $b_k<b_j<a_j<a_k$，与 $b_k\ge a_k$ 矛盾，不成立。

若 $a_i\ge b_i\land b_k\ge b_i$，与上面类似，由 $(1)$ 式得 $b_j<b_i$，进而推出 $b_j<b_k$，再由 $(2)$ 式得到 $a_j<b_j$，再由 $(1)$ 式得到 $a_i<a_j$，所以 $a_i<a_j<b_j<b_i$，与 $a_i\ge b_i$ 矛盾，不成立。

综上所述，假设不成立。

所以，$P_{i,j}=\min(a_i,b_j)<\min(a_j,b_i)$ 具有传递性。

不具有不可比性的传递性的证明
命题：$\forall \begin{cases}\min(a_i,b_j)=\min(a_j,b_i)\\\min(a_j,b_k)=\min(a_k,b_j)\end{cases}$，有 $\min(a_i,b_k)=\min(a_k,b_i)$。

很明显，当 $a_j=b_j$ 且都很小时存在反例，如：

$$\begin{array}{c|c|c}&a&b\\i&3&5\\j&1&1\\k&2&7\end{array}$$

$\begin{cases}\min(3,1)=\min(1,5)\\\min(1,7)=\min(2,1)\end{cases}$，但 $\min(3,7)\ne \min(2,5)$。

这样的反例还有很多，所以，$P_{i,j}=\min(a_i,b_j)<\min(a_j,b_i)$ 不具有不可比性的传递性。

为何会错
简单地说，$P_{i,j}=\min(a_i,b_j)<\min(a_j,b_i)$ 不满足严格弱序，不能作为 std::sort 的比较函数。

究其原因，“不具有不可比性的传递性”意味着：将序列中若干个不可比的相邻元素对（在这种比较方式下即 $\min(a_i,b_{i+1})=\min(a_{i+1},b_i)$ 的 $i$ 和 $i+1$）互换后，可能会出现前面的元素“大于”后面的元素（在这种比较方式下即出现 $\min(a_i,b_{i+1})>\min(a_{i+1},b_i)$），从而使得原先的排列方式不是最优的。

正确解法
更加完善的贪心解法
比较相邻两项时，若 $\min(a_i,b_j)=\min(a_j,b_i)$ ，从全局来看，由于 $a$ 的前缀和对答案有一定的影响，把 $a$ 更小的放前面是更优的。从而可以得到这样一个解法：

#include <iostream>
#include <algorithm>

using namespace std;

const int N=20010;

struct Node
{
    int a,b;
    bool operator<(Node& y)
    {
        return min(a,y.b)==min(b,y.a)?a<y.a:min(a,y.b)<min(b,y.a);
    }
} dc[N];

long long ans,sum,t,n;

int main()
{
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;++i)
        {
            cin>>dc[i].a>>dc[i].b;
        }
        sort(dc+1,dc+n+1);
        ans=sum=0;
        for (int i=1;i<=n;++i)
        {
            sum+=dc[i].a;
            ans=max(ans,sum)+dc[i].b;
        }
        cout<<ans<<endl;
    }
    return 0;
}
这个解法的正确性将在下文证明。

一个解法是否正确的判断方式
由上文的讨论可以得知，一个排序方式 $P_{i,j}$ 要是正解，需要满足两个条件：

满足严格弱序。

$\forall P_{i,j}=true$，$\min(a_i,b_j)\le\min(a_j,b_i)$ 。

即，可以作为比较函数，且排序完成后任意交换相邻元素均不会使答案更优。

从而可以写出下面的正解判断器：

```
#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int i,int j);

int a[10],b[10];

int main()
{
    for (a[0]=1;a[0]<=6;++a[0])
    {
        for (b[0]=1;b[0]<=6;++b[0])
        {
            if (cmp(0,0))
            {
                printf("No irreflexivity:%d %d\n",a[0],b[0]);
            }
            for (a[1]=1;a[1]<=6;++a[1])
            {
                for (b[1]=1;b[1]<=6;++b[1])
                {
                    if (cmp(0,1)&&min(a[0],b[1])>min(a[1],b[0]))
                    {
                        printf("Not the best:%d %d %d %d\n",a[0],b[0],a[1],b[1]);
                    }
                    for (a[2]=1;a[2]<=6;++a[2])
                    {
                        for (b[2]=1;b[2]<=6;++b[2])
                        {
                            if (cmp(0,1)&&cmp(1,2)&&!cmp(0,2))
                            {
                                printf("No transitivity:%d %d %d %d %d %d\n",a[0],b[0],a[1],b[1],a[2],b[2]);
                            }
                            if (!cmp(0,1)&&!cmp(1,0)&&!cmp(1,2)&&!cmp(2,1)&&(cmp(0,2)||cmp(2,0)))
                            {
                                printf("No transitivity of incomparability:%d %d %d %d %d %d\n",a[0],b[0],a[1],b[1],a[2],b[2]);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

bool cmp(int i,int j)
{
    return min(a[i],b[j])==min(a[j],b[i])?a[i]<a[j]:min(a[i],b[j])<min(a[j],b[i]);
}
```
运行程序，没有任何输出，说明上文所述的排序方式是一个正解。

用其它排序方式替换 cmp，若没有任何输出即可作为本题的正确排序方式。

下面是几种排序方式的例子：
```
bool cmp(int i,int j)
{
    return min(a[i],b[j])==min(a[j],b[i])?b[i]>b[j]:min(a[i],b[j])<min(a[j],b[i]);
}
```
输出为空，是正解。
```
bool cmp(int i,int j)
{
    return min(a[i],b[j])<min(a[j],b[i]);
}
```
共输出1694行，前10行如下：

No transitivity of incomparability:1 2 1 1 2 1
No transitivity of incomparability:1 2 1 1 2 2
No transitivity of incomparability:1 2 1 1 2 3
No transitivity of incomparability:1 2 1 1 2 4
No transitivity of incomparability:1 2 1 1 2 5
No transitivity of incomparability:1 2 1 1 2 6
No transitivity of incomparability:1 2 1 1 3 1
No transitivity of incomparability:1 2 1 1 3 2
No transitivity of incomparability:1 2 1 1 3 3
No transitivity of incomparability:1 2 1 1 3 4
bool cmp(int i,int j)
{
	return min(a[i],b[j])==min(a[j],b[i])?a[i]>a[j]:min(a[i],b[j])<min(a[j],b[i]);
}
共输出280行，前10行如下：

No transitivity:1 2 2 1 1 1
No transitivity:1 2 2 2 1 1
No transitivity:1 2 2 3 1 1
No transitivity:1 2 2 4 1 1
No transitivity:1 2 2 5 1 1
No transitivity:1 2 2 6 1 1
No transitivity:1 2 3 1 1 1
No transitivity:1 2 3 2 1 1
No transitivity:1 2 3 3 1 1
No transitivity:1 2 3 4 1 1
bool cmp(int i,int j)
{
    return min(a[i],b[j])<=min(a[j],b[i]);
}
共输出883行，前10行如下：

No irreflexivity:1 1
No irreflexivity:1 2
No irreflexivity:1 3
No irreflexivity:1 4
No irreflexivity:1 5
No irreflexivity:1 6
No irreflexivity:2 1
No transitivity:2 1 1 1 1 2
No transitivity:2 1 1 1 1 3
No transitivity:2 1 1 1 1 4
总结
在可以通过比较相邻两项得出交换或不交换一定不会更差时，可以通过邻项交换排序的方式来得到最优解。

邻项交换排序的比较函数需要满足严格弱序，并且排序完成后任意交换相邻元素都不会更优。

使用这种算法时，一定要注意以上两点，才能得到真正正确的算法。

最后再把我去雅礼集训的时候水题选讲的 slide 放上来好了..（还附赠一道由乃题）