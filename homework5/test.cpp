#pragma once
#include "test.h"
bool test() {
	testMatrix* test1 = new testMatrix();
	testReadMatrix* test2 = new testReadMatrix();
	return test1->test() && test2->test();
}
