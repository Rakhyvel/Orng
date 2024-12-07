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
int64_t _971_main(void);
void _973_change_x(int64_t* _973_x);


/* Function definitions */
int64_t _971_main(void){
    int64_t _972_x;
    function0 _971_t2;
    int64_t* _971_t4;
    int64_t _971_$retval;
    _972_x = 40;
    _971_t2 = (function0) _973_change_x;
    _971_t4 = &_972_x;
    $lines[$line_idx++] = "tests/integration/functions/immutable-param-mut-addr.orng:4:14:\n    change_x(&mut x)\n            ^";
    (void) _971_t2(_971_t4);
    $line_idx--;
    _971_$retval = _972_x;
    return _971_$retval;
}

void _973_change_x(int64_t* _973_x){
    *_973_x = 288;
    return;
}


int main(void) {
  printf("%ld",_971_main());
  return 0;
}
