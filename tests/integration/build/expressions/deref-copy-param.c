/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _652_main(void);
void _654_f(int64_t* _654_y);


/* Function definitions */
int64_t _652_main(void){
    int64_t _653_x;
    int64_t* _653_y;
    function0 _652_t4;
    int64_t _652_$retval;
    _653_x = 4;
    _653_y = &_653_x;
    _652_t4 = (function0) _654_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    (void) _652_t4(_653_y);
    $line_idx--;
    _652_$retval = *_653_y;
    return _652_$retval;
}

void _654_f(int64_t* _654_y){
    int64_t* _655_z;
    _655_z = _654_y;
    *_655_z = 195;
    return;
}


int main(void) {
  printf("%ld",_652_main());
  return 0;
}
