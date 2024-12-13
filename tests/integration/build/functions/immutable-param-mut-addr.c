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
int64_t _993_main(void);
void _995_change_x(int64_t* _995_x);


/* Function definitions */
int64_t _993_main(void){
    int64_t _994_x;
    function0 _993_t2;
    int64_t* _993_t4;
    int64_t _993_$retval;
    _994_x = 40;
    _993_t2 = (function0) _995_change_x;
    _993_t4 = &_994_x;
    $lines[$line_idx++] = "tests/integration/functions/immutable-param-mut-addr.orng:4:14:\n    change_x(&mut x)\n            ^";
    (void) _993_t2(_993_t4);
    $line_idx--;
    _993_$retval = _994_x;
    return _993_$retval;
}

void _995_change_x(int64_t* _995_x){
    *_995_x = 288;
    return;
}


int main(void) {
  printf("%ld",_993_main());
  return 0;
}
