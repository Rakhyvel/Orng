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
int64_t _963_main(void);
void _965_change_x(int64_t* _965_x);


/* Function definitions */
int64_t _963_main(void){
    int64_t _964_x;
    function0 _963_t2;
    int64_t* _963_t4;
    int64_t _963_$retval;
    _964_x = 40;
    _963_t2 = (function0) _965_change_x;
    _963_t4 = &_964_x;
    $lines[$line_idx++] = "tests/integration/functions/immutable-param-mut-addr.orng:4:14:\n    change_x(&mut x)\n            ^";
    (void) _963_t2(_963_t4);
    $line_idx--;
    _963_$retval = _964_x;
    return _963_$retval;
}

void _965_change_x(int64_t* _965_x){
    *_965_x = 288;
    return;
}


int main(void) {
  printf("%ld",_963_main());
  return 0;
}
