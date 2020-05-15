#define RN RealNumber

#include<cstdlib>

#include "RealNumber.h"

RN::RealNumber() {
	value = 0;
	next = NULL;
}

RN::RealNumber(double num) {
	value = 0;
	next = NULL;
}

RN::RealNumber(RealNumber& num) {
	value = num.Value();
	next = num.Next();
}

RN::~RealNumber() {
	value = 0;
	next = NULL;
}

RealNumber* RN::Sum(RealNumber& b) {
	return new RealNumber(value + b.Value());
}

RealNumber* RN::Subtraction(RealNumber& b) {
	return new RealNumber(value - b.Value());
}
RealNumber* RN::Divide(RealNumber& b) {
	return new RealNumber(value / b.Value());
}
RealNumber* RN::Multiply(RealNumber& b) {
	return new RealNumber(value * b.Value());
}

void RN::Assing(RealNumber& b) {
	value = b.Value();
}

void RN::SetNext(RealNumber* b) {
	next = b;
}
void RN::SetValue(double& num) {
	value = num;
}

RealNumber* RN::Next() {
	return next;
}

double RN::Value() {
	return value;
}