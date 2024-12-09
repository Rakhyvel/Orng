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
int64_t _657_main(void);
void _659_f(int64_t* _659_y);


/* Function definitions */
int64_t _657_main(void){
    int64_t _658_x;
    int64_t* _658_y;
    function0 _657_t4;
    int64_t _657_$retval;
    _658_x = 4;
    _658_y = &_658_x;
    _657_t4 = (function0) _659_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    (void) _657_t4(_658_y);
    $line_idx--;
    _657_$retval = *_658_y;
    return _657_$retval;
}

void _659_f(int64_t* _659_y){
    int64_t* _660_z;
    _660_z = _659_y;
    *_660_z = 195;
    return;
}


int main(void) {
  printf("%ld",_657_main());
  return 0;
}
