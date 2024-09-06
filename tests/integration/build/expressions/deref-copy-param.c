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
int64_t _660_main(void);
void _662_f(int64_t* _662_y);


/* Function definitions */
int64_t _660_main(void){
    int64_t _661_x;
    int64_t* _661_y;
    function0 _660_t4;
    int64_t _660_$retval;
    _661_x = 4;
    _661_y = &_661_x;
    _660_t4 = (function0) _662_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    (void) _660_t4(_661_y);
    $line_idx--;
    _660_$retval = *_661_y;
    return _660_$retval;
}

void _662_f(int64_t* _662_y){
    int64_t* _663_z;
    _663_z = _662_y;
    *_663_z = 195;
    return;
}


int main(void) {
  printf("%ld",_660_main());
  return 0;
}
