/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687316164
#define ORNG_1687316164

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
int64_t _384_main();
struct1* _386_f(struct1* _386_x);

/* Function definitions */
int64_t _384_main() {
	int64_t _384_t1;
	int64_t _384_t2;
	int64_t _384_t3;
	int64_t _384_t4;
	struct1 _385_x;
	struct1* _384_t6;
	struct1* _384_t5;
	struct1 _384_t7;
	int64_t _384_t8;
	int64_t _384_t9;
	int64_t _384_$retval;
BB0:
	_384_t1 = 1;
	_384_t2 = 2;
	_384_t3 = 3;
	_384_t4 = 4;
	_385_x = (struct1) {_384_t1, _384_t2, _384_t3, _384_t4};
	_384_t6 = &_385_x;
	_384_t5 = _386_f(_384_t6);
	_384_t8 = 3;
	_384_t9 = *(((int64_t*)(_384_t5))+_384_t8);
	_384_$retval = _384_t9;
	return _384_$retval;
}

struct1* _386_f(struct1* _386_x) {
	struct1 _386_t0;
	int64_t _386_t1;
	int64_t _386_t2;
	struct1* _386_$retval;
BB0:
	_386_t1 = 3;
	_386_t2 = 78;
	*(((int64_t*)(_386_x))+_386_t1) = _386_t2;
	_386_$retval = _386_x;
	return _386_$retval;
}


int main()
{
  printf("%ld",_384_main());
  return 0;
}

#endif
