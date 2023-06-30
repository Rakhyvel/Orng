/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1687313805274392075
#define ORNG_1687313805274392075

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
int64_t _388_main();
struct1* _390_f(struct1* _390_x);

/* Function definitions */
int64_t _388_main() {
	int64_t _388_t1;
	int64_t _388_t2;
	int64_t _388_t3;
	int64_t _388_t4;
	struct1 _389_x;
	struct1* _388_t6;
	struct1* _388_t5;
	struct1 _388_t7;
	int64_t _388_t8;
	int64_t _388_t9;
	int64_t _388_$retval;
BB0:
	_388_t1 = 1;
	_388_t2 = 2;
	_388_t3 = 3;
	_388_t4 = 4;
	_389_x = (struct1) {_388_t1, _388_t2, _388_t3, _388_t4};
	_388_t6 = &_389_x;
	_388_t5 = _390_f(_388_t6);
	_388_t8 = 3;
	_388_t9 = *(((int64_t*)(_388_t5))+_388_t8);
	_388_$retval = _388_t9;
	return _388_$retval;
}

struct1* _390_f(struct1* _390_x) {
	struct1 _390_t0;
	int64_t _390_t1;
	int64_t _390_t2;
	struct1* _390_$retval;
BB0:
	_390_t1 = 3;
	_390_t2 = 78;
	*(((int64_t*)(_390_x))+_390_t1) = _390_t2;
	_390_$retval = _390_x;
	return _390_$retval;
}


int main()
{
  printf("%ld",_388_main());
  return 0;
}

#endif
