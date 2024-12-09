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
int64_t _976_main(void);
void _978_change_x(int64_t* _978_x);


/* Function definitions */
int64_t _976_main(void){
    int64_t _977_x;
    function0 _976_t2;
    int64_t* _976_t4;
    int64_t _976_$retval;
    _977_x = 40;
    _976_t2 = (function0) _978_change_x;
    _976_t4 = &_977_x;
    $lines[$line_idx++] = "tests/integration/functions/immutable-param-mut-addr.orng:4:14:\n    change_x(&mut x)\n            ^";
    (void) _976_t2(_976_t4);
    $line_idx--;
    _976_$retval = _977_x;
    return _976_$retval;
}

void _978_change_x(int64_t* _978_x){
    *_978_x = 288;
    return;
}


int main(void) {
  printf("%ld",_976_main());
  return 0;
}
