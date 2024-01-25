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
int64_t _991_main(void);
void _993_change_x(int64_t* _993_x);


/* Function definitions */
int64_t _991_main(void){
    int64_t _992_x;
    function0 _991_t1;
    int64_t* _991_t3;
    int64_t _991_$retval;
    _992_x = 40;
    _991_t1 = _993_change_x;
    _991_t3 = &_992_x;
    $lines[$line_idx++] = "tests/integration/functions/immutable-param-mut-addr.orng:4:14:\n    change_x(&mut x)\n            ^";
    (void) _991_t1(_991_t3);
    $line_idx--;
    _991_$retval = _992_x;
    return _991_$retval;
}

void _993_change_x(int64_t* _993_x){
    *_993_x = 288;
    return;
}


int main(void) {
  printf("%ld",_991_main());
  return 0;
}
