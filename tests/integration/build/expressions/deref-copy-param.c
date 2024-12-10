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
int64_t _672_main(void);
void _674_f(int64_t* _674_y);


/* Function definitions */
int64_t _672_main(void){
    int64_t _673_x;
    int64_t* _673_y;
    function0 _672_t4;
    int64_t _672_$retval;
    _673_x = 4;
    _673_y = &_673_x;
    _672_t4 = (function0) _674_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    (void) _672_t4(_673_y);
    $line_idx--;
    _672_$retval = *_673_y;
    return _672_$retval;
}

void _674_f(int64_t* _674_y){
    int64_t* _675_z;
    _675_z = _674_y;
    *_675_z = 195;
    return;
}


int main(void) {
  printf("%ld",_672_main());
  return 0;
}
