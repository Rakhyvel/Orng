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
int64_t _965_main(void);
void _967_change_x(int64_t* _967_x);


/* Function definitions */
int64_t _965_main(void){
    int64_t _966_x;
    function0 _965_t2;
    int64_t* _965_t4;
    int64_t _965_$retval;
    _966_x = 40;
    _965_t2 = (function0) _967_change_x;
    _965_t4 = &_966_x;
    $lines[$line_idx++] = "tests/integration/functions/immutable-param-mut-addr.orng:4:14:\n    change_x(&mut x)\n            ^";
    (void) _965_t2(_965_t4);
    $line_idx--;
    _965_$retval = _966_x;
    return _965_$retval;
}

void _967_change_x(int64_t* _967_x){
    *_967_x = 288;
    return;
}


int main(void) {
  printf("%ld",_965_main());
  return 0;
}
