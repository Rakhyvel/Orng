/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687129465
#define ORNG_1687129465

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t* _0;
	int64_t* _1;
} struct2;

/* Function forward definitions */
int64_t _337_main();

/* Function definitions */
int64_t _337_main() {
	int64_t _338_x;
	int64_t _338_y;
	int64_t* _337_t3;
	int64_t* _337_t4;
	struct2 _338_z;
	int64_t* _337_t5;
	int64_t _337_t6;
	int64_t* _337_t7;
	int64_t _337_t8;
	int64_t _337_$retval;
BB0:
	_338_x = 30;
	_338_y = 29;
	_337_t3 = &_338_x;
	_337_t4 = &_338_y;
	_338_z = (struct2) {_337_t3, _337_t4};
	_337_t5 = _338_z._0;
	_337_t6 = *_337_t5;
	_337_t7 = _338_z._1;
	_337_t8 = *_337_t7;
	_337_$retval = _337_t6 + _337_t8;
	return _337_$retval;
}


int main()
{
  printf("%ld",_337_main());
  return 0;
}

#endif
