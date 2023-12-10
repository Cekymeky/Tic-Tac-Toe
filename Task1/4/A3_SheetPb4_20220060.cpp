// File name: A3_SheetPb4_20220060
// Purpose: Set using template
// Author(s): Islam Yasser Zakaria
// ID(s): 20220060
// Section: 13
// Date: 9/12/2023

#include <bits/stdc++.h>

using namespace std;

template <typename T>

class Set
{
private:
    vector<T> v;

public:
    Set() {}
    Set(int x) { v.push_back(x); }

    template <typename... Args>
    Set(Args... args) : v{args...} {}

    void add(const T &x)
    {
        if (find(v.begin(), v.end(), x) == v.end())
        {
            v.push_back(x);
        }
    }

    void remove(const T &x)
    {
        auto it = find(v.begin(), v.end(), x);

        if (it != v.end())
        {
            v.erase(it);
        }
    }

    size_t size()
    {
        cout << v.size();
        return true;
    }

    void isMember(const T &x)
    {
        if (find(v.begin(), v.end(), x) != v.end())
        {
            cout << x << " is member of the set." << endl;
        }
        else
        {
            cout << x << " isn't a member of the set." << endl;
        }
    }
    T *toArray()
    {
        T *array = new T[size()];
        copy(v.begin(), v.end(), array);
        return array;
    }
    void print()
    {
        for (T i : v)
        {
            cout << i << " ";
        }
    }
    bool operator==(const Set &other) const
    {
        return v == other.v;
    }
    bool operator!=(const Set &other) const
    {
        return v != other.v;
    }
    typename vector<T>::iterator begin() { return v.begin(); }
    typename vector<T>::iterator end() { return v.end(); }
};

int main()
{
    Set<int> integer(1, 2, 3);
    Set<int> integer2(1, 2, 3, 4);
    integer.add(6);
    integer.remove(3);
    integer.size();
    cout << endl;
    integer.isMember(3);
    cout << endl;
    integer.print();

    if (integer2 == integer)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    // Set<Set<int>> obj;
    // obj.add(Set<int>(10));
    // obj.add(Set<int>(10));
    // obj.add(Set<int>(5));
    // obj.size();
}