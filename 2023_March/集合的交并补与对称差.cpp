/*
第一个关卡是序列合并，首先将两个无序序列进行升序排序，然后调用合并函数完成两个升序序列的合并；
第二个关卡是判断一个序列是否被另一个序列包含；
第三个关卡是集合的并与交操作实例；
第四个关卡是集合的差集与对称差集应用；
第五个关卡是序列排列的问题。
最后在每个关卡都设置了实例，考察学员对所讲内容的理解和在线编程能力。
 

第1关：序列合并
任务描述
本关任务：给定两个无序数组arr1和arr2，编写一个程序实现这两个数组的升序合并。

相关知识
为了完成本关任务，你需要掌握：1.升序合并思路，2.Algorithm中的合并函数merge。

升序合并思路
要求解两个无序数组的升序合并，自然的，按照升序与合并位置关系，可分为先升序后合并和先合并后升序两种方式，假设数组一的个数为N，数组二的个数为M：

先升序后合并：分别对两个数组调用sort函数，完成升序的要求，然后调用merge合并函数，对两个有序数组合并。复杂度分析：两次排序操作复杂度为O(N×logN+M×logM)，最后合并的复杂度为O(N+M)。

先合并后升序：merge合并函数要求输入的两个数组是升序的，因此该方法无法调用merge函数，需要自己编写合并代码，然后调用sort函数对合并后的数组进行排序。复杂度分析：先合并的复杂度为O(N+M)，然后调用排序的复杂度为O((N+M)×logN+M)

Algorithm中的合并函数merge
合并数组是一个很常见的操作，例如在归并排序和快速排序的递归求解过程中，就需要将两个有序数组合并成一个。因此通过调用C++ Algorithm中模板函数merge，来快速实现这一操作是非常方便有效的。

合并函数的核心思想是设置两个头指针，分别指向两个升序数组首地址，通过比较两个头指针的大小，每次都将小的数值放入新的数组，然后小数值指针后移，最后新的数组也是有序的，从而完成合并过程，复杂度为O(N+M)。其函数原型和应用实例如下：

复制代码
 1 \\ 函数原型
 2 template <class InputIterator1, class InputIterator2, class OutputIterator>
 3 OutputIterator merge (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
 4 {
 5   while (true) {
 6     if (first1==last1) return std::copy(first2,last2,result);
 7     if (first2==last2) return std::copy(first1,last1,result);
 8     *result++ = (*first2<*first1)? *first2++ : *first1++;
 9   }
10 }
11 \\ 应用实例
12 int arr1[3] = {1,2,3};
13 int arr2[4] = {2,3,4,5};
14 int arr3[7];
15 merge(arr1, arr1+n1, arr2, arr2+n2, arr3);
16 \\ arr3结果为{1,2,2,3,3,4,5}
复制代码
编程要求
本关的编程任务是补全右侧代码片段Merge_Array中Begin至End中间的代码，具体要求如下：

在Merge_Array中，合并两个数组arr1和arr2，完成升序排序，最后返回排序后的合并数组。
测试说明
平台将自动编译补全后的代码，并生成若干组测试数据，接着根据程序的输出判断程序是否正确。

以下是平台的测试样例：

测试输入：
16

14 6 57 53 30 75 32 36 73 41 76 40 94 6 37 29

13

18 52 17 12 90 95 61 78 19 27 68 89 96

预期输出：
6 6 12 14 17 18 19 27 29 30 32 36 37 40 41 52 53 57 61 68 73 75 76 78 89 90 94 95 96

 

输入格式：
第一行整数N 第二行N个整数（无序） 第三行整数M 第四行M个整数（无序）

输出格式：
输出一行，包含N+M个升序整数，末尾换行！！！

开始你的任务吧，祝你成功！

 

 

 点击查看代码
 

 

第2关：序列包含
任务描述
本关任务：给定两个升序数组arr1和arr2，编写一个程序判定数组arr1是否包含数组arr2，例如arr1=[1,2,3,4]，arr2=[2,3]，则数组arr1包含数组arr2，若arr2=[2,5]，则数组arr1不包含数组arr2。

相关知识
为了完成本关任务，你需要掌握：1.有序数组包含，2.Algorithm中的包含函数includes。

有序数组包含
无序数组的包含问题就像是字符串应用中的最长公共子序列，解法是动态规划，而有序数组的包含则是简单的判断问题，解法类似有序数组的合并。

同样的，其核心思想也是设置两个头指针分别指向两个升序数组，若指针指向的元素相等，则两个指针都往后移动，否则指向数组arr1的指针往后移动，直到指针移向数组尾地址。

Algorithm中的包含函数includes
Algorithm中的包含函数includes是不常用但却又比较实用的函数，它避免了我们编写复杂的代码，同时，模板函数的优势可以让我们自定义数据类型，在数据库等查询任务中是非常方便有效的，其函数原型及应用实例如下：

复制代码
 1 \\ 函数原型
 2 template <class InputIterator1, class InputIterator2>
 3 bool includes ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2 )
 4 {
 5   while (first2!=last2) {
 6     if ( (first1==last1) || (*first2<*first1) ) return false;
 7     if (!(*first1<*first2)) ++first2;
 8     ++first1;
 9   }
10   return true;
11 }
12 \\ 应用实例
13 int arr1[4] = {1,2,3,4};
14 int arr2[2] = {2,3};
15 bool judge(arr1, arr1+4, arr2, arr2+2);
16 // judge结果为true
复制代码
编程要求
本关的编程任务是补全右侧代码片段Include_Array中Begin至End中间的代码，具体要求如下：

在Include_Array中，依据函数传入的参数，基于模板函数includes或自己编写具体代码，实现判定数组arr1是否包含arr2，并返回判定结果。
测试说明
平台将自动编译补全后的代码，并生成若干组测试数据，接着根据程序的输出判断程序是否正确。

以下是平台的测试样例：

测试输入：
11

6 15 25 26 40 43 54 62 70 78 81

6

6 25 40 54 70 81

预期输出：
array1 includes array2

输入格式：
第一行整数N 第二行N个整数（升序） 第三行整数M 第四行M个整数（升序）

输出格式：
若数组arr1包含数组arr2，则输出array1 includes array2，否则输出array1 not includes array2

开始你的任务吧，祝你成功！

 

 点击查看代码
 

 

第3关：集合并与交
任务描述
本关任务：给定两个集合A和B，编写一个程序实现这两个集合的并集与交集。

相关知识
为了完成本关任务，你需要掌握：1.集合，2.集合的并，3.集合的交。

集合
集合是由一个或多个确定的元素所构成的整体。集合中的元素有三个特征：

确定性（集合中的元素是确定的）；

互异性（集合中的元素是互不相同），例如：集合A=(1,a)，则a不能等于1；

无序性：集合中的元素没有先后之分，如集合(3,4,5)和(3,5,4)算作同一个集合，

但是本关卡为了在最后方便测试输出集合是否正确，对输出集合做了升序的要求。

集合的并
集合A和集合B的并是由所有属于集合A或属于集合B的元素所组成的集合，记作A⋃B 或者B⋃A，并集的一个重要属性就是越并越多。假定集合A=(1,2,3,4,5,6,7)，集合B=(6,7,8,9)，那么集合A和集合B的并集为A⋃B=(1,2,3,4,5,6,7,8,9)。

Algorithm算法模板中集成了集合的并操作，函数名称为set_union，其作用是将两个集合合并成一个集合，但是要求输入的两个集合必须是有序的，这看似违背了集合的定义，但是有序的目的是为了让求并的过程实现起来变得简单。 因此，在本关卡中，首先需要将两个集合排序，然后才调用set_union函数计算出并集。其函数原型及应用实例如下：输入参数是两个集合的首尾地址以及一个保存并集结果的数组的首地址，最后返回数组尾地址：

复制代码
 1 \\ 函数原型
 2 template <class InputIterator1, class InputIterator2, class OutputIterator>
 3 OutputIterator set_union (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
 4 {
 5   while (true)
 6   {
 7     if (first1==last1) return std::copy(first2,last2,result);
 8     if (first2==last2) return std::copy(first1,last1,result);
 9     if (*first1<*first2) { *result = *first1; ++first1; }
10     else if (*first2<*first1) { *result = *first2; ++first2; }
11     else { *result = *first1; ++first1; ++first2; }
12     ++result;
13   }
14 }
15 \\ 应用实例
16 int arr1[3]={1,2,3};
17 int arr2[3]={2,3,4};
18 int arr3[4];
19 int n = set_union(arr1, arr1+n1, arr2, arr2+n2, arr3)-arr3;
20 \\ arr3结果为{1,2,3,4}
21 \\ n结果为4
复制代码
集合的交
集合A和B的交是由所有属于集合A以及属于集合B的元素所组成的集合，记作A∩B或者B∩A，交集的一个重要属性就是越交越少。假定集合A=(1,2,3,4,5,6,7)，集合B=(6,7,8,9)，那么集合A和集合B的交集为A∩B=(6,7)。

Algorithm算法模板中集成了集合的交操作，函数名称为set_intersection，其作用是将两个集合交成一个集合，同样的要求输入的两个集合必须是有序的。因此，首先需要将两个集合排序，然后才调用set_intersection函数计算出交集。其函数原型及应用实例如下，输入参数是两个集合的首尾地址以及一个保存交集结果的数组的首地址，最后返回数组尾地址：

复制代码
 1 \\ 函数原型
 2 template <class InputIterator1, class InputIterator2, class OutputIterator>
 3   OutputIterator set_intersection (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
 4 {
 5   while (true)
 6   {
 7     if (first1==last1) return std::copy(first2,last2,result);
 8     if (first2==last2) return std::copy(first1,last1,result);
 9     if (*first1<*first2) { *result = *first1; ++first1; }
10     else if (*first2<*first1) { *result = *first2; ++first2; }
11     else { *result = *first1; ++first1; ++first2; }
12     ++result;
13   }
14 }
15 \\ 应用实例
16 int arr1[3]={1,2,3};
17 int arr2[3]={2,3,4};
18 int arr3[2];
19 int n = set_intersection(arr1, arr1+n1, arr2, arr2+n2, arr3)-arr3;
20 \\ arr3结果为{2,3}
21 \\ n结果为2
复制代码
编程要求
本关的编程任务是补全右侧代码片段Set_Union和Set_Intersection中Begin至End中间的代码，具体要求如下：

在Set_Union中，依据函数传入的参数，实现函数的功能：计算出输入的两个集合的并集，首先对两个集合排序，然后调用set_union或自己实现集合并操作，最后返回并集大小。
在Set_Intersection中，依据函数传入的参数，实现函数的功能：计算出输入的两个集合的交集，首先对两个集合排序，然后调用set_intersection或自己实现集合交操作，最后返回交集大小。
测试说明
平台将自动编译补全后的代码，并生成若干组测试数据，接着根据程序的输出判断程序是否正确。

以下是平台的测试样例：

测试输入：

7

1 2 3 4 5 6 7

4

6 7 8 9

预期输出：

Union:9

{1,2,3,4,5,6,7,8,9}

Intersection:2

{6,7}

开始你的任务吧，祝你成功！

 

 点击查看代码
 

 


第4关：集合“差集”与“对称差集”
任务描述
本关任务：给定两个集合A和B，编写一个程序实现集合B关于集合A的相对差集A−B，集合A相对集合B的相对差集B−A，以及集合A与集合B的对称差集。

相关知识
为了完成本关任务，你需要掌握：1.集合相对差集，2.集合对称差集。

集合相对差集
集合差集也叫集合补集，是一个相对的定义：由属于A而不属于B的元素组成的集合，称为B关于A的相对补集，记作A−B。例如集合A=(1,2,3,4)，集合B=(3,4,5,6)，那么集合A−B=(1,2)。

Algorithm算法模板中集成了集合的差操作，函数名称为set_difference，其作用是计算出两个集合的差集，与上个关卡集合的相关操作一样，要求输入的两个集合必须是有序的。其函数原型及应用实例如下：

复制代码
 1 \\ 函数原型
 2 template <class InputIterator1, class InputIterator2, class OutputIterator>
 3 OutputIterator set_difference (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
 4 {
 5   while (first1!=last1 && first2!=last2)
 6   {
 7     if (*first1<*first2) {*result = *first1; ++result; ++first1; }
 8     else if (*first2<*first1) ++first2;
 9     else { ++first1; ++first2; }
10   }
11   return std::copy(first1,last1,result);
12 }
13 \\ 应用实例
14 int arr1[4]={1,2,3,4};
15 int arr2[4]={3,4,5,6};
16 int arr3[4];
17 int n = set_difference(arr1, arr1+n1, arr2, arr2+n2, arr3)-arr3;
18 \\ arr3结果为{1,2}
19 \\ n结果为2
复制代码
集合对称差集
集合A与集合B的对称差集定义为属于集合A与集合B，但不属于它们交集A∩B的元素集合，记为A△B。也就是说A△B=x∣x∈A∪B且x∈/​A∩B，即A△B=(A∪B)—(A∩B)。同样也可以用相对差集的并来表示A△B=(A—B)∪(B—A)。例如上述的两个集合，他们的对称差集为A△B=(1,2,5,6)。

Algorithm算法模板中集成了集合对称差集的操作，函数名称为set_symmetric_difference，其作用是计算出两个集合的对称差集，同样的，要求输入的两个集合必须是有序的。其函数原型及应用实例如下：

复制代码
 1 \\ 函数原型
 2 template <class InputIterator1, class InputIterator2, class OutputIterator>
 3 OutputIterator set_symmetric_difference (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
 4 {
 5   while (true)
 6   {
 7     if (first1==last1) return std::copy(first2,last2,result);
 8     if (first2==last2) return std::copy(first1,last1,result);
 9     if (*first1<*first2) { *result=*first1; ++result; ++first1; }
10     else if (*first2<*first1) { *result = *first2; ++result; ++first2; }
11     else { ++first1; ++first2; }
12   }
13 }
14 \\ 应用实例
15 int arr1[4]={1,2,3,4};
16 int arr2[4]={3,4,5,6};
17 int arr3[8];
18 int n = set_symmetric_difference(arr1, arr1+n1, arr2, arr2+n2, arr3)-arr3;
19 \\ arr3结果为{1,2,5,6}
20 \\ n结果为4
复制代码
编程要求
本关的编程任务是补全右侧代码片段Set_Difference和Set_Symmetric_Difference中Begin至End中间的代码，具体要求如下：

在Set_Difference中，实现函数的功能：参数arr1和n1是集合A的首地址和集合个数，同理，参数arr2和n2是集合B的首地址和集合个数，计算出集合B关于集合A的相对差集A−B，存入首地址为arr3的存储空间，并返回相对差集的个数。

在Set_Symmetric_Difference中，实现集合对称差集的计算，学员可以利用set_symmetric_difference来实现这一功能，也可以调用基本的集合操作函数来实现，例如集合差集和集合并集操作。

测试说明
平台将自动编译补全后的代码，并生成若干组测试数据，接着根据程序的输出判断程序是否正确。

以下是平台的测试样例：

测试输入：

7

1 2 3 4 5 6 7

4

6 7 8 9

预期输出：

A-B:5

{1,2,3,4,5}

B-A:2

{8,9}

(A-B)U(B-A):7

{1,2,3,4,5,8,9}

开始你的任务吧，祝你成功！

 

 点击查看代码
 

 

第5关：序列排列问题
任务描述
本关任务：给定排列的大小n，计算出从1,2,3,..,n开始的下m个排列，以及从n,..,3,2,1开始的上m个排列，并输出结果。

例如n=3,m=4，那么从1,2,3开始的下4个排列为:1,2,3; 1,3,2; 2,1,3; 2,3,1，从3,2,1开始的上4个排列为:3,2,1; 3,1,2; 2,3,1; 2,1,3。

相关知识
为了完成本关任务，你需要掌握：1.序列排列，2.Algorithm中下一个排列模板函数，3.Algorithm中上一个排列模板函数。

序列排列
一般地，从n个不同元素中取出m个元素，按照一定的顺序排成一列，叫做从n个元素中取出m个元素的一个排列permutation。特别地，当m=n时，这个排列被称作全排列all permutation，本关卡就是关于n的全排列问题。

Algorithm中下一个排列模板函数
给定一个排列序列，Algorithm中的模板函数next_permutation可以产生该排列的下一个序列，输入参数为序列的首地址和尾地址，其函数模板及应用实例如下：

复制代码
 1 \\ 函数模板
 2 template <class BidirectionalIterator>
 3 bool next_permutation (BidirectionalIterator first,   BidirectionalIterator last);
 4 \\ 应用实例
 5 int myints[] = {1,2,3};
 6 do {
 7     std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
 8 } while ( std::next_permutation(myints,myints+3) );
 9 输出结果为：
10 1 2 3
11 1 3 2
12 2 1 3
13 2 3 1
14 3 1 2
15 3 2 1
复制代码
Algorithm中上一个排列模板函数
给定一个排列序列，Algorithm中的模板函数prev_permutation可以产生该排列的上一个序列，输入参数为序列的首地址和尾地址，其函数模板及应用实例如下：

复制代码
 1 \\ 函数模板
 2 template <class BidirectionalIterator>
 3 bool prev_permutation (BidirectionalIterator first,   BidirectionalIterator last);
 4 \\ 应用实例
 5 int myints[] = {3,2,1};
 6 do {
 7     std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
 8 } while ( std::prev_permutation(myints,myints+3) );
 9 输出结果为：
10 3 2 1
11 3 1 2
12 2 3 1
13 2 1 3
14 1 3 2
15 1 2 3
复制代码
编程要求
本关的编程任务是补全右侧代码片段Next_Permutation和Prev_Permutation中Begin至End中间的代码，具体要求如下：

在Next_Permutation中，依据传入的排列序列首地址arr及其个数n，输出1,2,..,n的下m个排列序列。

在Prev_Permutation中，依据传入的排列序列首地址arr及其个数n，输出n,..,2,1的上m个排列序列。

测试说明
平台将自动编译补全后的代码，并生成若干组测试数据，接着根据程序的输出判断程序是否正确。

以下是平台的测试样例：

测试输入：

3 4

预期输出：

Next_Permutation:

1 2 3

1 3 2

2 1 3

2 3 1

Prev_Permutation:

3 2 1

3 1 2

2 3 1

2 1 3

开始你的任务吧，祝你成功！

 

*/