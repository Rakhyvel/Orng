/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _444_main(void);
void _446_f(int64_t* _446_y);

/* Function definitions */
int64_t _444_main(void) {
    int64_t _445_x;
    int64_t* _445_y;
    function0 _444_t2;
    int64_t _444_$retval;
    _445_x = 4;
    _445_y = &_445_x;
    _444_t2 = _446_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _444_t2(_445_y);
    $line_idx--;
    _444_$retval = *_445_y;
    return _444_$retval;
}

void _446_f(int64_t* _446_y) {
    int64_t* _447_z;
    _447_z = _446_y;
    *_447_z = 195;
}

int main(void) {
  printf("%ld",_444_main());
  return 0;
}
