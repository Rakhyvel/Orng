/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _852_main(void);
uint8_t _857_f(int64_t _857_x);

/* Function definitions */
int64_t _852_main(void){
    function0 _852_t1;
    int64_t _852_t3;
    uint8_t _852_t2;
    int64_t _852_t0;
    int64_t _852_$retval;
    _852_t1 = _857_f;
    _852_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/mod-0.orng:3:10:\n    if f(4) {\n        ^";
    _852_t2 = _852_t1(_852_t3);
    $line_idx--;
    if (_852_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _852_t0 = 191;
    goto BB4;
BB5:
    _852_t0 = 4;
    goto BB4;
BB4:
    _852_$retval = _852_t0;
    return _852_$retval;
}

uint8_t _857_f(int64_t _857_x){
    uint8_t _857_$retval;
    (void)_857_x;
    _857_$retval = 1;
    return _857_$retval;
}

int main(void) {
  printf("%ld",_852_main());
  return 0;
}
