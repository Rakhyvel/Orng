/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _766_main(void);
void _769_f(int64_t* _769_y);

/* Function definitions */
int64_t _766_main(void){
    int64_t _767_x;
    int64_t* _767_y;
    function0 _766_t2;
    int64_t _766_$retval;
    _767_x = 4;
    _767_y = &_767_x;
    _766_t2 = _769_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _766_t2(_767_y);
    $line_idx--;
    _766_$retval = *_767_y;
    return _766_$retval;
}

void _769_f(int64_t* _769_y){
    int64_t* _772_z;
    _772_z = _769_y;
    *_772_z = 195;
    return;
}

int main(void) {
  printf("%ld",_766_main());
  return 0;
}
