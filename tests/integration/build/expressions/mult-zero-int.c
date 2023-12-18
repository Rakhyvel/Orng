/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _897_main(void);
uint8_t _902_f(int64_t _902_x);

/* Function definitions */
int64_t _897_main(void){
    function0 _897_t1;
    int64_t _897_t3;
    uint8_t _897_t2;
    int64_t _897_t0;
    int64_t _897_$retval;
    _897_t1 = _902_f;
    _897_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mult-zero-int.orng:3:10:\n    if f(4) {\n        ^";
    _897_t2 = _897_t1(_897_t3);
    $line_idx--;
    if (_897_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _897_t0 = 187;
    goto BB4;
BB5:
    _897_t0 = 4;
    goto BB4;
BB4:
    _897_$retval = _897_t0;
    return _897_$retval;
}

uint8_t _902_f(int64_t _902_x){
    uint8_t _902_$retval;
    (void)_902_x;
    _902_$retval = 1;
    return _902_$retval;
}

int main(void) {
  printf("%ld",_897_main());
  return 0;
}
