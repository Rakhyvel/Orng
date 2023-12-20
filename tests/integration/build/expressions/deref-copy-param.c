/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _647_main(void);
void _649_f(int64_t* _649_y);

/* Function definitions */
int64_t _647_main(void){
    int64_t _648_x;
    int64_t* _648_y;
    function0 _647_t2;
    int64_t _647_$retval;
    _648_x = 4;
    _648_y = &_648_x;
    _647_t2 = _649_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _647_t2(_648_y);
    $line_idx--;
    _647_$retval = *_648_y;
    return _647_$retval;
}

void _649_f(int64_t* _649_y){
    int64_t* _650_z;
    _650_z = _649_y;
    *_650_z = 195;
    return;
}

int main(void) {
  printf("%ld",_647_main());
  return 0;
}
