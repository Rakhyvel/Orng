/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _341_main(void);
void _343_f(int64_t* _343_y);

/* Function definitions */
int64_t _341_main(void) {
    int64_t _342_x;
    int64_t* _342_y;
    function0 _341_t2;
    int64_t _341_$retval;
    _342_x = 4;
    _342_y = &_342_x;
    _341_t2 = _343_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _341_t2(_342_y);
    $line_idx--;
    _341_$retval = *_342_y;
    return _341_$retval;
}

void _343_f(int64_t* _343_y) {
    int64_t* _344_z;
    _344_z = _343_y;
    *_344_z = 195;
}

int main(void) {
  printf("%ld",_341_main());
  return 0;
}
