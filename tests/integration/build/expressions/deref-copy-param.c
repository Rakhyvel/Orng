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
int64_t _686_main(void);
void _688_f(int64_t* _688_y);


/* Function definitions */
int64_t _686_main(void){
    int64_t _687_x;
    int64_t* _687_y;
    function0 _686_t2;
    int64_t _686_$retval;
    _687_x = 4;
    _687_y = &_687_x;
    _686_t2 = (function0) _688_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    (void) _686_t2(_687_y);
    $line_idx--;
    _686_$retval = *_687_y;
    return _686_$retval;
}

void _688_f(int64_t* _688_y){
    int64_t* _689_z;
    _689_z = _688_y;
    *_689_z = 195;
    return;
}


int main(void) {
  printf("%ld",_686_main());
  return 0;
}
