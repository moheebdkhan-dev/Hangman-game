#pragma once
#include <cstdlib>

using namespace std;


namespace myRandomLib {
	int RandomNumber(int from, int to) {
		return rand() % (to - from + 1) + from;
	}
}