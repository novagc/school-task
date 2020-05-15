#pragma once
#include <stdio.h>
#include "RealNumber.h"

using namespace std;

struct Stack
{
private:
    long long count;
    RealNumber* head;

public:
    friend void Add_Item(Stack &a, double value);
    friend void Add_Two_Items(Stack& a, double first, double second);
    friend void Extract_Item(Stack& a);

    Stack ();
    Stack (Stack& stack);

    ~Stack ();

    void Add_Item (double value);
    void Add_Item (RealNumber* num);

    void Add_Two_Items (double first, double second);
    void Add_Two_Items (RealNumber* first, RealNumber* second);

    void Extract_Item      ();
    void Extract_Two_Items ();

    RealNumber* First  ();
    RealNumber* Second ();

    long long Count ();

    void Clear ();
    void Print ();
};