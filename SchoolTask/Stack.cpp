#define St Stack

#include <cstdlib>
#include <iostream>

#include "Stack.h"
#include "RealNumber.h"

St::Stack() {
	count = 0;
	head = new RealNumber();
}

St::Stack(Stack& stack) {
	count = stack.Count();
	head = stack.First();
}

St::~Stack() {
	Clear();
	delete head;
}

void St::Add_Item(double value) {
	RealNumber* temp = new RealNumber(value);

	temp->SetNext(head->Next());
	head->SetNext(temp);

	count++;
}

void St::Add_Two_Items(double first, double second) {
	Add_Item(first);
	Add_Item(second);
}

void St::Extract_Item() {
	if (count != 0) {
		RealNumber* toDelete = head->Next();
		head->SetNext(toDelete->Next());

		delete toDelete;
		count--;
	}
}

void St::Extract_Two_Items() {
	Extract_Item();
	Extract_Item();
}

RealNumber* St::First() {
	return head->Next();
}

RealNumber* St::Second() {
	return count > 1 ? head->Next()->Next() : NULL;
}

long long St::Count() {
	return count;
}

void St::Clear() {
	while (count > 0) {
		Extract_Item();
	}
}

void St::Print() {
	for (RealNumber* rn = head->Next(); rn != NULL; rn = rn->Next()) {
		std::cout << rn->Value() << " ";
	}
	std::cout << '\n';
}