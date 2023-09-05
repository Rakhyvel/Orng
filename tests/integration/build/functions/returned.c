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
typedef int64_t(*function0)(int64_t);

/* Interned Strings */

/* Function forward definitions */
int64_t _2_main();
function0 _4_f();
int64_t _6_addFour(int64_t _6_x);

/* Function definitions */
int64_t _2_main() {
    function0 _2_t0;
    int64_t _2_t2;
    int64_t _2_t1;
    int64_t _2_$retval;
BB0:
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:7:\n    f()(45)\n     ^";
    _2_t0 = _4_f();
    $line_idx--;
    _2_t2 = 45;
    $lines[$line_idx++] = "tests/integration/functions/returned.orng:3:9:\n    f()(45)\n       ^";
    _2_t1 = _2_t0(_2_t2);
    $line_idx--;
    _2_$retval = _2_t1;
    return _2_$retval;
}

function0 _4_f() {
    function0 _4_$retval;
BB1:
    _4_$retval = _6_addFour;
    return _4_$retval;
}

int64_t _6_addFour(int64_t _6_x) {
    int64_t _6_t0;
    int64_t _6_$retval;
BB0:
    _6_t0 = 4;
    _6_$retval = _6_x + _6_t0;
    return _6_$retval;
}


int main()
{
  printf("%ld",_2_main());
  return 0;
}

#endif
