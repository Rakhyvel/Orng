/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _36_main(void);
void _38_f(int64_t* _38_y);

/* Function definitions */
int64_t _36_main(void) {
    int64_t _37_x;
    int64_t* _37_y;
    function0 _36_t2;
    int64_t _36_$retval;
    _37_x = 4;
    _37_y = &_37_x;
    _36_t2 = _38_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _36_t2(_37_y);
    $line_idx--;
    _36_$retval = *_37_y;
    return _36_$retval;
}

void _38_f(int64_t* _38_y) {
    int64_t* _39_z;
    _39_z = _38_y;
    *_39_z = 195;
}

int main(void) {
  printf("%ld",_36_main());
  return 0;
}
