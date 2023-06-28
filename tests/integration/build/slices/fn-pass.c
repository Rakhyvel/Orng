/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687738458023072984
#define ORNG_1687738458023072984

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
typedef struct {
	int64_t* _0;
	int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _423_main();
int64_t _425_f(struct3 _425_x);

/* Function definitions */
int64_t _423_main() {
	int64_t _423_t1;
	int64_t _423_t2;
	int64_t _423_t3;
	int64_t _423_t4;
	struct1 _424_x;
	int64_t _423_t6;
	int64_t _423_t7;
	int64_t* _423_t8;
	int64_t _423_t9;
	struct3 _424_y;
	int64_t _423_t10;
	int64_t _423_$retval;
BB0:
	_423_t1 = 1;
	_423_t2 = 2;
	_423_t3 = 3;
	_423_t4 = 4;
	_424_x = (struct1) {_423_t1, _423_t2, _423_t3, _423_t4};
	_423_t6 = 0;
	_423_t7 = *(((int64_t*)(&_424_x))+_423_t6);
	_423_t8 = (((int64_t*)(&_424_x))+_423_t6);
	_423_t9 = 4;
	_424_y = (struct3) {_423_t8, _423_t9};
	_423_t10 = _425_f(_424_y);
	_423_$retval = _423_t10;
	return _423_$retval;
}

int64_t _425_f(struct3 _425_x) {
	int64_t _425_t0;
	int64_t _425_t1;
	int64_t _425_t2;
	int64_t _425_$retval;
BB0:
	_425_t0 = 1;
	_425_t1 = *(((int64_t*)((&_425_x)->_0))+_425_t0);
	_425_t2 = 80;
	_425_$retval = _425_t1 + _425_t2;
	return _425_$retval;
}


int main()
{
  printf("%ld",_423_main());
  return 0;
}

#endif
