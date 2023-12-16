/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _614_main(void);
void _617_f(int64_t* _617_y);

/* Function definitions */
int64_t _614_main(void){
    int64_t _615_x;
    int64_t* _615_y;
    function0 _614_t2;
    int64_t _614_$retval;
    _615_x = 4;
    _615_y = &_615_x;
    _614_t2 = _617_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _614_t2(_615_y);
    $line_idx--;
    _614_$retval = *_615_y;
    return _614_$retval;
}

void _617_f(int64_t* _617_y){
    int64_t* _620_z;
    _620_z = _617_y;
    *_620_z = 195;
    return;
}

int main(void) {
  printf("%ld",_614_main());
  return 0;
}
