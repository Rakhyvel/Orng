/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687738073
#define ORNG_1687738073

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
	int64_t _2;
	int64_t _3;
} struct1;

/* Function forward definitions */
int64_t _380_main();

/* Function definitions */
int64_t _380_main() {
	int64_t _380_t1;
	int64_t _380_t2;
	int64_t _380_t3;
	int64_t _380_t4;
	struct1 _381_x;
	int64_t _380_t5;
	int64_t _380_t6;
	int64_t* _380_t7;
	int64_t _380_t8;
	int64_t _380_t9;
	int64_t _380_t10;
	int64_t _380_$retval;
BB0:
	_380_t1 = 1;
	_380_t2 = 2;
	_380_t3 = 3;
	_380_t4 = 4;
	_381_x = (struct1) {_380_t1, _380_t2, _380_t3, _380_t4};
	_380_t5 = 0;
	_380_t6 = *(((int64_t*)(&_381_x))+_380_t5);
	_380_t7 = (((int64_t*)(&_381_x))+_380_t5);
	_380_t8 = 63;
	**&_380_t7 = _380_t8;
	_380_t9 = 0;
	_380_t10 = *(((int64_t*)(&_381_x))+_380_t9);
	_380_$retval = _380_t10;
	return _380_$retval;
}


int main()
{
  printf("%ld",_380_main());
  return 0;
}

#endif
