/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _405_main(void);
void _407_f(int64_t* _407_y);

/* Function definitions */
int64_t _405_main(void) {
    int64_t _406_x;
    int64_t* _406_y;
    function0 _405_t2;
    int64_t _405_$retval;
    _406_x = 4;
    _406_y = &_406_x;
    _405_t2 = _407_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _405_t2(_406_y);
    $line_idx--;
    _405_$retval = *_406_y;
    return _405_$retval;
}

void _407_f(int64_t* _407_y) {
    int64_t* _408_z;
    _408_z = _407_y;
    *_408_z = 195;
    return;
}

int main(void) {
  printf("%ld",_405_main());
  return 0;
}
