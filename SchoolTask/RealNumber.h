#pragma once

class RealNumber {
private:
	double value;
	RealNumber* next;

public:
	RealNumber ();
	RealNumber (double num);
	RealNumber (RealNumber* num);

	~RealNumber();

	RealNumber* Sum         (RealNumber* b);
	RealNumber* Subtraction (RealNumber* b);
	RealNumber* Divide      (RealNumber* b);
	RealNumber* Multiply    (RealNumber* b);
	
	friend RealNumber* Sum(RealNumber* a, RealNumber* b);
	friend RealNumber* Multiply(RealNumber* a, RealNumber* b);

	void Assing (RealNumber* b);

	void SetNext  (RealNumber* b);
	void SetValue (double value);

	RealNumber* Next();

	double Value();
};