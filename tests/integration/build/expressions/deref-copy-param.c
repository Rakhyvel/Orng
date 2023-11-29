/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _568_main(void);
void _572_f(int64_t* _572_y);

/* Function definitions */
int64_t _568_main(void) {
    int64_t _569_x;
    int64_t* _569_y;
    function0 _568_t2;
    int64_t _568_$retval;
    _569_x = 4;
    _569_y = &_569_x;
    _568_t2 = _572_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _568_t2(_569_y);
    $line_idx--;
    _568_$retval = *_569_y;
    return _568_$retval;
}

void _572_f(int64_t* _572_y) {
    int64_t* _574_z;
    _574_z = _572_y;
    *_574_z = 195;
}

int main(void) {
  printf("%ld",_568_main());
  return 0;
}
