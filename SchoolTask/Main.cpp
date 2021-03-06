#include <iostream>

#include "RealNumber.h"
#include "Stack.h"

using namespace std;

void TestOne  ();
void TestTwo  ();
void TestThree();

void Add_Item(Stack& a, double value) {
	a.Add_Item(value);
}

void Add_Two_Items(Stack& a, double first, double second) {
	a.Add_Two_Items(first, second);
}

void Extract_Item(Stack& a) {
	a.Extract_Item();
}

RealNumber* Sum(RealNumber* a, RealNumber* b) {
	return new RealNumber(a->value + b->value);
}
RealNumber* Multiply(RealNumber* a, RealNumber* b) {
	return new RealNumber(a->value * b->value);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int temp;

	cout << "�������� ����: ";
	cin  >> temp;

	switch (temp)
	{
	case 1:
		TestOne();
		break;
	case 2:
		TestTwo();
		break;
	case 3:
		TestThree();
		break;
	default:
		break;
	}

	return 0;
}

void TestOne() {
	Stack stack;
	RealNumber* temp;
	double _, __;

	cout << "������� 2 �����: ";

	cin >> _ >> __;
	stack.Add_Two_Items(_, __);

	temp = stack.First()->Sum(stack.Second());

	if (temp->Value() == 0) {
		stack.Extract_Two_Items();
	}
	else {
		stack.Add_Item(temp);
	}

	cout << "����: ";
	stack.Print();
}

void TestTwo() {
	RealNumber* temp1;
	Stack stack;
	double _, __;

	cout << "������� 2 �����: ";

	cin >> _ >> __;

	stack.Add_Two_Items(_, __);

	temp1 = stack.First()->Sum(stack.Second());
	stack.First()->Assing(temp1);

	delete temp1;

	if (stack.First()->Value() == 0) {
		RealNumber* temp2;
		int ___;

		stack.First()->Assing(stack.Second());

		cout << "������� �����: ";
		cin >> _;
		temp1 = new RealNumber(_);

		cout << "�������� ��������:\n1) �������\n2) ���������\n> ";
		cin >> ___;

		switch (___)
		{
		case 1:
			temp2 = stack.First()->Subtraction(temp1);
			stack.First()->Assing(temp2);
			break;
		case 2:
			temp2 = stack.First()->Divide(temp1);
			stack.First()->Assing(temp2);
			break;
		default:
			temp2 = stack.First()->Divide(temp1);
			stack.First()->Assing(temp2);
			break;
		}

		delete temp1;
		delete temp2;
	}

	cout << "����: ";
	stack.Print();
}

void TestThree() {
	RealNumber* f;

	Stack stack;
	double _;
	int n;

	cout << "������� ���������� �����: ";
	cin >> n;

	cout << "������� " << n << " �����: ";

	for (int i = 0; i < n; i++) {
		cin >> _;
		stack.Add_Item(_);
	}

	f = new RealNumber(1);

	for (RealNumber* s = stack.First(), *t = NULL; s != NULL; s = s->Next()) {
		t = f->Multiply(s);
		f->Assing(t);

		delete t;
	}

	stack.Add_Item(f);

	if (stack.First()->Value() < 0) {
		stack.Extract_Item();
	}

	cout << "����: ";
	stack.Print();
}