/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1689219200972419442
#define ORNG_1689219200972419442

#include <math.h>
#include <stdio.h>
#include <stdint.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
	uint64_t tag;
} struct0;

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
struct0 _4_f(int64_t* _4_x,uint8_t _4_fail);

/* Function definitions */
int64_t _2_main() {
	int64_t _3_x;
	int64_t _3_y;
	int64_t* _2_t3;
	uint8_t _2_t4;
	struct0 _2_t2;
	int64_t* _2_t6;
	uint8_t _2_t7;
	struct0 _2_t5;
	int64_t _2_$retval;
BB0:
	_3_x = 10;
	_3_y = 10;
	_2_t3 = &_3_x;
	_2_t4 = 1;
    $lines[$line_idx++] = "    f(&mut x, true)";
	_2_t2 = _4_f(_2_t3, _2_t4);
	_2_t6 = &_3_y;
	_2_t7 = 0;
    $lines[$line_idx++] = "    f(&mut y, false)";
	_2_t5 = _4_f(_2_t6, _2_t7);
	_2_$retval = _3_x + _3_y;
	return _2_$retval;
}

struct0 _4_f(int64_t* _4_x,uint8_t _4_fail) {
	int64_t _4_t0;
	int64_t _4_t4;
	int64_t _4_t5;
	int64_t _4_t6;
	int64_t _4_t10;
	int64_t _4_t11;
	int64_t _4_t12;
	struct0 _4_$retval;
BB0:
	_4_t0 = 6;
	**&_4_x = _4_t0;
	if (_4_fail) {
		goto BB1;
	} else {
		goto BB9;
	}
BB9:
	_4_$retval = (struct0) {.tag=1};
	return _4_$retval;
BB1:
	_4_t4 = *_4_x;
	_4_t5 = 100;
	_4_t6 = _4_t4 + _4_t5;
	**&_4_x = _4_t6;
	_4_t10 = *_4_x;
	_4_t11 = 9;
	_4_t12 = _4_t10 + _4_t11;
	**&_4_x = _4_t12;
	return _4_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
