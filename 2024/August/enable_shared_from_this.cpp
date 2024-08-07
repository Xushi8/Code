#include <memory>

using namespace std;

template <typename T>
struct A : public enable_shared_from_this<A<T>>
{
    A() :
        m_val() {}
    A(T val) :
        m_val(val) {}
    T m_val;

    void func()
    {
        auto self = this->shared_from_this();
    }
};