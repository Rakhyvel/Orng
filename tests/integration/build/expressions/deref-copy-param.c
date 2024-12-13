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
int64_t _674_main(void);
void _676_f(int64_t* _676_y);


/* Function definitions */
int64_t _674_main(void){
    int64_t _675_x;
    int64_t* _675_y;
    function0 _674_t4;
    int64_t _674_$retval;
    _675_x = 4;
    _675_y = &_675_x;
    _674_t4 = (function0) _676_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    (void) _674_t4(_675_y);
    $line_idx--;
    _674_$retval = *_675_y;
    return _674_$retval;
}

void _676_f(int64_t* _676_y){
    int64_t* _677_z;
    _677_z = _676_y;
    *_677_z = 195;
    return;
}


int main(void) {
  printf("%ld",_674_main());
  return 0;
}
