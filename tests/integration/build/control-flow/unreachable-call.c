/* Code generated using the Orng compiler https://ornglang.org */
#ifndef ORNG_1692153173557914945
#define ORNG_1692153173557914945

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
int64_t _4_f();
int64_t _6_g();

/* Function definitions */
int64_t _2_main() {
	int64_t _2_t0;
	int64_t _2_$retval;
BB0:
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:3:7:\n    f()\n       ^";
	_2_t0 = _4_f();
	_2_$retval = _2_t0;
	return _2_$retval;
}

int64_t _4_f() {
	int64_t _4_t0;
	int64_t _4_$retval;
BB0:
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:6:7:\n    g()\n       ^";
	_4_t0 = _6_g();
	_4_$retval = _4_t0;
	return _4_$retval;
}

int64_t _6_g() {
BB0:
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable-call.orng:9:16:\n    unreachable\n                ^";
    fprintf(stderr, "panic: reached unreachable code\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
