/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _624_main(void);
uint8_t _629_f(int64_t _629_x);


/* Function definitions */
int64_t _624_main(void){
    function0 _624_t1;
    int64_t _624_t3;
    uint8_t _624_t2;
    int64_t _624_t0;
    int64_t _624_$retval;
    _624_t1 = (function0) _629_f;
    _624_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/add-zero.orng:3:10:\n    if f(4) {\n        ^";
    _624_t2 = _624_t1(_624_t3);
    $line_idx--;
    if (_624_t2) {
        goto BB736;
    } else {
        goto BB740;
    }
BB736:
    _624_t0 = 182;
    goto BB739;
BB740:
    _624_t0 = 4;
    goto BB739;
BB739:
    _624_$retval = _624_t0;
    return _624_$retval;
}

uint8_t _629_f(int64_t _629_x){
    uint8_t _629_$retval;
    (void)_629_x;
    goto BB731;
BB731:
    _629_$retval = 1;
    return _629_$retval;
}


int main(void) {
  printf("%ld",_624_main());
  return 0;
}
