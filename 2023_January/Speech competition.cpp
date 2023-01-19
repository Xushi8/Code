#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<ctime>
#include<queue>
#include<functional>
using namespace std;

class Person
{
public:
    Person(int id)
    {
        this->id = 10000 + id;
    }

    int id;
    double score;
};

void shuffle_person(vector<Person>& vp);

//生成十二个人
void create_person(vector<Person>& vp, int n)
{
    for (int i = 1 + n; i <= 12 + n; i++)
    {
        vp.push_back(Person(i));
    }
    shuffle_person(vp);
}

//打二十次分, 返回分数去除最高和最低的平均值
double grade(void)
{
    deque<int>score;
    for (int i = 0; i < 20; i++)
    {
        score.push_back(rand() % 41 + 60);
    }
    sort(score.begin(), score.end());
    score.pop_back(), score.pop_front();
    int sum = 0;
    for (deque<int>::iterator it = score.begin(); it != score.end(); it++)
    {
        sum += *it;
    }

    return (double)sum / 18.0;
}

void print_person(const vector<Person>& vp)
{
    for (vector<Person>::const_iterator it = vp.begin(); it != vp.end(); it++)
    {
        cout << "序号: " << it->id << " 分数: " << it->score << '\n';
    }
    cout << endl;
}

class cmp_by_score
{
public:
    bool operator()(const Person& a, const Person& b)
    {
        return a.score > b.score;
    }
};

//n是此次容器中的总人数,本函数删除后一半的人
void delete_person(vector<Person>& vp, int n)
{
    n /= 2;
    for (int tmp = 0; tmp < n; tmp++)
    {
        vp.pop_back();
    }
}

void shuffle_person(vector<Person>& vp)
{
    random_shuffle(vp.begin(), vp.end());
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<Person> person;
    int match_num = 0;//经历的比赛次数
    int n = 12;

    create_person(person, match_num);
    print_person(person);
    system("pause");
    //上半场
    cout << "上半场开始\n";
    int index = 0;
    for (vector<Person>::iterator it = person.begin(); index<n/2; it++, index++)
    {
        it->score = grade();
    }

    // print_person(person);

    // sort(person.begin(), person.end(), cmp_by_score());
    // print_person(person);
    // print_person(person);
    // //delete_person(person, 12);
    // //print_person(person);


    return 0;
}