/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _631_main(void);
uint8_t _636_f(int64_t _636_x);

/* Function definitions */
int64_t _631_main(void){
    function0 _631_t1;
    int64_t _631_t3;
    uint8_t _631_t2;
    int64_t _631_t0;
    int64_t _631_$retval;
    _631_t1 = _636_f;
    _631_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _631_t2 = _631_t1(_631_t3);
    $line_idx--;
    if (_631_t2) {
        goto BB774;
    } else {
        goto BB778;
    }
BB774:
    _631_t0 = 182;
    goto BB777;
BB778:
    _631_t0 = 4;
    goto BB777;
BB777:
    _631_$retval = _631_t0;
    return _631_$retval;
}

uint8_t _636_f(int64_t _636_x){
    uint8_t _636_$retval;
    (void)_636_x;
    _636_$retval = 1;
    return _636_$retval;
}

int main(void) {
  printf("%ld",_631_main());
  return 0;
}
