/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1691899681449729182
#define ORNG_1691899681449729182

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
	uint8_t* _0;
	int64_t _1;
} struct0;

/* Interned Strings */
char* string_0 = "\x0A\x0D\x09\x27\x22";

/* Function forward definitions */
uint8_t _2_main();

/* Function definitions */
uint8_t _2_main() {
	struct0 _3_x;
	int64_t _2_t1;
	int64_t _2_t5;
	uint8_t _2_t6;
	uint8_t _2_t2;
	uint8_t _2_$retval;
BB0:
	_3_x = (struct0) {string_0, 11};
	_2_t1 = 0;
	_2_t5 = (&_3_x)->_1;
	_2_t6 = _2_t1 >= _2_t5;
	if (_2_t6) {
		goto BB3;
	} else {
		goto BB4;
	}
BB4:
	_2_t2 = *(((uint8_t*)((&_3_x)->_0))+_2_t1);
	_2_$retval = _2_t2;
	return _2_$retval;
BB3:
    $lines[$line_idx++] = "tests/integration/strings/string-newline.orng:4:7:\n    x[0]\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
	goto BB4;
}


int main()
{
  printf("%d",_2_main());
  return 0;
}

#endif
