/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1686104538
#define ORNG_1686104538

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Function Definitions */
int64_t _92_main();
int64_t _93_a(int64_t n);
int64_t _94_b(int64_t n);
int64_t _95_c(int64_t n);

int64_t _92_main() {
	int64_t (*_92_t0)(int64_t n);
	int64_t _92_t2;
	int64_t _92_$retval;
BB0:
	_92_t0 = _93_a;
	_92_t2 = 47;
	_92_$retval = _92_t0(_92_t2);
	return _92_$retval;
}

int64_t _93_a(int64_t n) {
	int64_t (*_93_t0)(int64_t n);
	int64_t _93_$retval;
BB0:
	_93_t0 = _94_b;
	_93_$retval = _93_t0(n);
	return _93_$retval;
}

int64_t _94_b(int64_t n) {
	int64_t (*_94_t0)(int64_t n);
	int64_t _94_$retval;
BB0:
	_94_t0 = _95_c;
	_94_$retval = _94_t0(n);
	return _94_$retval;
}

int64_t _95_c(int64_t n) {
	int64_t _95_t3;
	uint8_t _95_t1;
	int64_t _95_t0;
	int64_t _95_$retval;
	int64_t (*_95_t5)(int64_t n);
BB0:
	_95_t3 = 47;
	_95_t1 = n == _95_t3;
	if (!_95_t1) {
		goto BB9;
	} else {
		goto BB1;
	}
BB1:
	_95_t0 = 47;
	goto BB6;
BB6:
	_95_$retval = _95_t0;
	return _95_$retval;
BB9:
	_95_t5 = _93_a;
	_95_t0 = _95_t5(n);
	goto BB6;
}


int main()
{
  printf("%ld",_92_main());
  return 0;
}

#endif
