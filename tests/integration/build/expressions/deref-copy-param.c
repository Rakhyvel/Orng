/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _595_main(void);
void _598_f(int64_t* _598_y);

/* Function definitions */
int64_t _595_main(void) {
    int64_t _596_x;
    int64_t* _596_y;
    function0 _595_t2;
    int64_t _595_$retval;
    _596_x = 4;
    _596_y = &_596_x;
    _595_t2 = _598_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _595_t2(_596_y);
    $line_idx--;
    _595_$retval = *_596_y;
    return _595_$retval;
}

void _598_f(int64_t* _598_y) {
    int64_t* _601_z;
    _601_z = _598_y;
    *_601_z = 195;
    return;
}

int main(void) {
  printf("%ld",_595_main());
  return 0;
}
