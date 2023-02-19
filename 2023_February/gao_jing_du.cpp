#include<bits/stdc++.h>
using namespace std;

const int max_Num_length = 1000;
class Num
{
public:
    Num()
    {
        this->length = 0;
        memset(this->data, 0, sizeof(this->data));
    }
    
    Num(const Num& a)
    {
        strcpy(this->data, a.data);
        this->length = a.length;
    }
    
    ~Num()
    {
        
    }
    
    void print()
    {
        reverse(this->data, this->data + this->length);
        cout << this->data << endl;
        reverse(this->data, this->data + this->length);
    }

    void insert()
    {
        cin >> this->data;
        this->length = strlen(data);
        reverse(this->data, this->data + this->length);
    }

    size_t size()
    {
        return this->length;
    }

    void minus_48()
    {
        for (size_t i = 0; i < this->length; i++)
        {
            this->data[i] -= '0';
        }
    }

    void add_48()
    {
        for (size_t i = 0; i < this->length; i++)
        {
            this->data[i] += '0';
        }
    }

    Num operator+(Num& tmp)
    {
        size_t max_len = max(tmp.length, this->length) + 1;
        Num ans;
        tmp.minus_48();
        this->minus_48();
        for (size_t i = 0; i < max_len; i++)
        {
            ans.data[i] += tmp.data[i] + this->data[i];
            ans.data[i + 1] = ans.data[i] / 10;
            ans.data[i] %= 10;
        }
        tmp.add_48();
        this->add_48();
        max_len--;
        for (size_t i = 0; i < max_len; i++)
        {
            if (ans.data[max_len] == 0 && max_len < max_Num_length + 100)
            {
                max_len--;
                if (max_len == 0)
                {
                    break;
                }
            }
        }
        
        ans.length = ++max_len;
        ans.add_48();
        return ans;
    }

    Num& operator=(const Num& a)
    {
        strcpy(this->data, a.data);
        this->length = a.length;
        return *this;
    }

    char data[max_Num_length];
    size_t length;
};

int main()
{
    Num a;
    Num b;
    a.insert();
    b.insert();
    Num c;
    c = a + b;
    c.print();
    Num d(a + c);
    d.print();

    system("pause");
    return 0;
}