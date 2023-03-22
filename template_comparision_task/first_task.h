#include <iostream>

template <class Base1>
class Base {
public:
    template<class T>
    
    bool operator==(const T& other) {
        Base1* there = static_cast<Base1*>(this);
        return !((*there != other));
    }

    template<class T>
    bool operator>=(const T& other) {
        Base1* there = static_cast<Base1*>(this);
        return !(*there < other);
    }

    template<class T>
    bool operator<=(const T& other) {
        Base1* there = static_cast<Base1*>(this);
        return !(*there > other);
    }

    template<class T>
    bool operator!=(const T& other) {
        Base1* there = static_cast<Base1*>(this);
        return ((*there > other) || (*there < other));
    }
   
};

class NewA : public Base<NewA>
{
public:
    NewA(int a, int b) : m_a(a), m_b(b){}

    // Операторы сравнения с NewA
    bool operator<(const NewA& other) const
    {
        return (m_a < other.m_a) && (m_b < other.m_b);
    }

    bool operator>(const NewA& other) const
    {
        return (m_a > other.m_a) && (m_b > other.m_b);
    }

    // Операторы сравнения с int
    bool operator<(const int other) const
    {
        return m_a < other;
    }

    bool operator>(const int other) const
    {
        return m_a > other;
    }

private:
    int m_a = 0;
    int m_b = 0;
};


  int main()
{
    NewA a1(1, 2);
    NewA a2(1, 2);
    std::cout << (a1 == a2) << "\n";
    std::cout << "Boris, das ist meine erste Probe" << "\n";

    NewA a3(3, 1);
    NewA a4(5, 2);
    std::cout << (a3 <= a4) << "\n";
    std::cout << "Boris, das ist meine zweite Probe" << "\n";

    return 0;
}


