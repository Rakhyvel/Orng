/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687129465
#define ORNG_1687129465

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Typedefs */
typedef struct {
	int64_t _0;
	int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _309_main();

/* Function definitions */
int64_t _309_main() {
	int64_t _309_t1;
	int64_t _309_t4;
	struct1 _310_x;
	struct1* _310_y;
	struct1 _309_t6;
	int64_t _309_t7;
	struct1 _309_t8;
	int64_t _309_t9;
	int64_t _309_$retval;
BB0:
	_309_t1 = 19;
	_309_t4 = 39;
	_310_x = (struct1) {_309_t1, _309_t4};
	_310_y = &_310_x;
	_309_t6 = *_310_y;
	_309_t7 = _309_t6._0;
	_309_t8 = *_310_y;
	_309_t9 = _309_t8._1;
	_309_$retval = _309_t7 + _309_t9;
	return _309_$retval;
}


int main()
{
  printf("%ld",_309_main());
  return 0;
}

#endif
