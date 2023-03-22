/*
1.子类继承父类的所有成员变量及方法
2.不继承父类的构造方法
3.子类构造函数第一行必须调用父类构造方法且只能第一行
4.如果显式调用父类构造, 则不默认调用父类无参构造函数
5.只支持单继承, 不支持多重继承,但支持多层继承
6.子类可以定义与父类句柄相同的代码(覆盖), 之后如果用子类对象调用该方法, 则执行的是子类的方法
7.


多态:
1.父类的引用可以无条件的指向子类的对象, 用父类的引用调用的是子类的代码
2.调用者和被调用者必须共同遵守某一限定, 调用者按照该限定进行方法调用,
被调用者按照该限定进行方法实现
*/


import java.util.Vector;

public class Bank
{
    public static void main(String[] args)
    {
        Student s = new Student(15);
        s.print();
        Vector<Person> v = new Vector<Person>();
        v.add(new Person(34));
        v.add(new Student(8));
        System.out.println(v.get(0).age);
        System.out.println(v.get(1).age);
    }
}

class Person
{
    int age;

    Person()
    {
        this.age++;
    }

    Person(int age)
    {
        this.age = age;
    }
    void print()
    {
        System.out.println(this.age);
    }
}

class Student extends Person
{
    Student(int age)
    {
        super(age);
        this.age = age;
    }
}
















