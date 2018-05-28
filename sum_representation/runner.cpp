// Author: Matvei Zhukov (matzhukov2000@gmail.com)
#include "sum_representation.h"

int main()
{
	CombinatorialObject * calculator = new SumRepresentation();
	calculator->interact();
	delete calculator;
	return 0;
}