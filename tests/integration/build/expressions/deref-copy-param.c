/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _570_main(void);
void _574_f(int64_t* _574_y);

/* Function definitions */
int64_t _570_main(void) {
    int64_t _571_x;
    int64_t* _571_y;
    function0 _570_t2;
    int64_t _570_$retval;
    _571_x = 4;
    _571_y = &_571_x;
    _570_t2 = _574_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _570_t2(_571_y);
    $line_idx--;
    _570_$retval = *_571_y;
    return _570_$retval;
}

void _574_f(int64_t* _574_y) {
    int64_t* _576_z;
    _576_z = _574_y;
    *_576_z = 195;
}

int main(void) {
  printf("%ld",_570_main());
  return 0;
}
