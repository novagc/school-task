#pragma once
#include <stdio.h>
#include "RealNumber.h"

using namespace std;

struct Stack
{
private:
    long long count;
    RealNumber* first;

public:
    Stack ();
    Stack (Stack* stack);

    ~Stack ();

    void Add_Item      (double value);
    void Add_Two_Items (double first, double second);

    void Extract_Item      ();
    void Extract_Two_Items ();

    RealNumber* First  ();
    RealNumber* Second ();

    long long Count ();

    void Clear ();
    void Print ();
};