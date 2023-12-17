/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _954_main(void);
uint8_t _959_f(int64_t _959_x);

/* Function definitions */
int64_t _954_main(void){
    function0 _954_t1;
    int64_t _954_t3;
    uint8_t _954_t2;
    int64_t _954_t0;
    int64_t _954_$retval;
    _954_t1 = _959_f;
    _954_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/self-lesser-equal.orng:3:10:\n    if f(4) {\n        ^";
    _954_t2 = _954_t1(_954_t3);
    $line_idx--;
    if (_954_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _954_t0 = 228;
    goto BB4;
BB5:
    _954_t0 = 0;
    goto BB4;
BB4:
    _954_$retval = _954_t0;
    return _954_$retval;
}

uint8_t _959_f(int64_t _959_x){
    uint8_t _959_$retval;
    (void)_959_x;
    _959_$retval = 1;
    return _959_$retval;
}

int main(void) {
  printf("%ld",_954_main());
  return 0;
}
