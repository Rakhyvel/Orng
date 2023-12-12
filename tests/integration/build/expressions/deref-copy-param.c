/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _432_main(void);
void _434_f(int64_t* _434_y);

/* Function definitions */
int64_t _432_main(void) {
    int64_t _433_x;
    int64_t* _433_y;
    function0 _432_t2;
    int64_t _432_$retval;
    _433_x = 4;
    _433_y = &_433_x;
    _432_t2 = _434_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _432_t2(_433_y);
    $line_idx--;
    _432_$retval = *_433_y;
    return _432_$retval;
}

void _434_f(int64_t* _434_y) {
    int64_t* _435_z;
    _435_z = _434_y;
    *_435_z = 195;
    return;
}

int main(void) {
  printf("%ld",_432_main());
  return 0;
}
