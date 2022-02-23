#include <iostream>
using namespace std;

class Date
{
public:
    friend ostream &operator<<(ostream &out, const Date &d);
    friend istream &operator>>(istream &in, Date &d);
    Date(int year = 0, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    bool operator==(const Date &d) const
    //==> bool operator==(const Date* this, const Date &d)
    //ȷ��thisָ������ݲ����޸ģ������ź���д��const
    //��������в�С���޸��˳�Ա����������ʱ���ܼ�����
    {
        if (_year == d._year && _month == d._month && _day == d._day)
        {
            return true;
        }
        return false;
    }
    void Print() const
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
    //��Ա�����У������������Ժ��ڳ�Ա����Ա����/��Ա������ǰ�����this->
    void Fun1()
    {
        Print(); // this->Print();
    }

    Date *operator&()
    {
        return this;
    }

    const Date *operator&() const
    {
        return this;
    }

    // //d1 << cout; �������ò��У��ǳ���ֱ��
    // //��һ������������������ڶ����������Ҳ�����
    // void operator<<(ostream& out)//void operator<<(Date* this, ostream& out)
    // {
    //     //cout��������out����cout����
    //     //�������Ϳ���ֱ����cout���
    //     out << _year << "-" << _month << "-" << _day << endl;
    // }

private:
    int _year;
    int _month;
    int _day;
};

ostream &operator<<(ostream &out, const Date &d)
{
    out << d._year << "-" << d._month << "-" << d._day << endl;
    return out;
}
istream &operator>>(istream &in, Date &d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}
int main(int argc, char const *argv[])
{
    Date d1(2022, 2, 22);
    Date d2(2022, 2, 22);
    // cout << (d1 == d2) << endl;
    // d1.Fun1();
    // cout << &d1 << endl;
    // &d2;
    cin >> d1 >> d2;
    cout << d1 << endl
         << d2 << endl;
    system("pause");
    return 0;
}

// int main(int argc, char const *argv[])
// {
//     int x = 5, y = 7;
//     cout << (true ? (++x, ++y) : (--x, --y)) << endl;
//     system("pause");
//     return 0;
// }
