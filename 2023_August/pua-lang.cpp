#include <iostream>
using namespace std;

#define 细分 if				// "specialization"
#define 路径 else			// "pathway"
#define 闭环 while			// "closed loop"
#define 三七五 true			// "3.75", a passing performance evalulation result
#define 三二五 false			// "3.25", a failing performance evalulation result
#define 赋能 int			// "empower"
#define 抓手 fn				// "handle", as in getting a handle on things
#define 反哺 return			// "repay", used in Alibaba as a general term for feedback in systems
#define 组合拳 Array			// "combo move"; not yet a word in the language
#define 载体 Hash 			// "carrier"; not yet a word in the language
#define 对齐 ==				// "align"
#define 联动 +				// "linkage"
#define 差异 -				// "difference"
#define 倾斜 /				// "tilt"
#define 输出 cout			// "output"
#define 淘汰 exit			// "eliminate"
#define 量化 atoi			// "quantify"

#define 布局 main
#define 规整 int

typedef int (*fn) (int);

规整 fib(规整 n)
{
    细分(n 对齐 0) {
        反哺 0;
    } 路径 细分(n 对齐 1) {
        反哺 1;
    } 路径{
        反哺 fib(n 差异 1) 联动 fib(n 差异 2);
    }
}

抓手 迭代 = fib;

规整 布局()
{
    输出 << 迭代(19) << '\n';
    反哺 0;
}