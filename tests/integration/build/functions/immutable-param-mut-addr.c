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
int64_t _964_main(void);
void _966_change_x(int64_t* _966_x);


/* Function definitions */
int64_t _964_main(void){
    int64_t _965_x;
    function0 _964_t1;
    int64_t* _964_t3;
    int64_t _964_$retval;
    _965_x = 40;
    _964_t1 = _966_change_x;
    _964_t3 = &_965_x;
    $lines[$line_idx++] = "tests/integration/functions/immutable-param-mut-addr.orng:4:14:\n    change_x(&mut x)\n            ^";
    (void) _964_t1(_964_t3);
    $line_idx--;
    _964_$retval = _965_x;
    return _964_$retval;
}

void _966_change_x(int64_t* _966_x){
    *_966_x = 288;
    return;
}


int main(void) {
  printf("%ld",_964_main());
  return 0;
}
