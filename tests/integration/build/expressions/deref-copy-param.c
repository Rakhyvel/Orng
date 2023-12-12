/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _413_main(void);
void _415_f(int64_t* _415_y);

/* Function definitions */
int64_t _413_main(void) {
    int64_t _414_x;
    int64_t* _414_y;
    function0 _413_t2;
    int64_t _413_$retval;
    _414_x = 4;
    _414_y = &_414_x;
    _413_t2 = _415_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _413_t2(_414_y);
    $line_idx--;
    _413_$retval = *_414_y;
    return _413_$retval;
}

void _415_f(int64_t* _415_y) {
    int64_t* _416_z;
    _416_z = _415_y;
    *_416_z = 195;
    return;
}

int main(void) {
  printf("%ld",_413_main());
  return 0;
}
