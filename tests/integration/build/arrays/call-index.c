/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687314590
#define ORNG_1687314590

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
int64_t _20_main();
struct1* _22_f(struct1* _22_x);

/* Function definitions */
int64_t _20_main() {
	int64_t _20_t1;
	int64_t _20_t2;
	int64_t _20_t3;
	int64_t _20_t4;
	struct1 _21_x;
	struct1* _20_t6;
	struct1* _20_t5;
	struct1 _20_t7;
	int64_t _20_t8;
	int64_t _20_t9;
	int64_t _20_$retval;
BB0:
	_20_t1 = 1;
	_20_t2 = 2;
	_20_t3 = 3;
	_20_t4 = 4;
	_21_x = (struct1) {_20_t1, _20_t2, _20_t3, _20_t4};
	_20_t6 = &_21_x;
	_20_t5 = _22_f(_20_t6);
	_20_t7 = *_20_t5;
	_20_t8 = 3;
	_20_t9 = *(((int64_t*)(_20_t5))+_20_t8);
	_20_$retval = _20_t9;
	return _20_$retval;
}

struct1* _22_f(struct1* _22_x) {
	struct1 _22_t0;
	int64_t _22_t1;
	int64_t _22_t2;
	struct1* _22_$retval;
BB0:
	_22_t0 = *_22_x;
	_22_t1 = 3;
	_22_t2 = 78;
	*(((int64_t*)(_22_x))+_22_t1) = _22_t2;
	_22_$retval = _22_x;
	return _22_$retval;
}


int main()
{
  printf("%ld",_20_main());
  return 0;
}

#endif
