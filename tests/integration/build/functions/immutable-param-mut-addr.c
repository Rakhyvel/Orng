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
int64_t _957_main(void);
void _959_change_x(int64_t* _959_x);


/* Function definitions */
int64_t _957_main(void){
    int64_t _958_x;
    function0 _957_t2;
    int64_t* _957_t4;
    int64_t _957_$retval;
    _958_x = 40;
    _957_t2 = (function0) _959_change_x;
    _957_t4 = &_958_x;
    $lines[$line_idx++] = "tests/integration/functions/immutable-param-mut-addr.orng:4:14:\n    change_x(&mut x)\n            ^";
    (void) _957_t2(_957_t4);
    $line_idx--;
    _957_$retval = _958_x;
    return _957_$retval;
}

void _959_change_x(int64_t* _959_x){
    *_959_x = 288;
    return;
}


int main(void) {
  printf("%ld",_957_main());
  return 0;
}
