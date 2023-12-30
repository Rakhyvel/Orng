/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _659_main(void);
void _661_f(int64_t* _661_y);

/* Function definitions */
int64_t _659_main(void){
    int64_t _660_x;
    int64_t* _660_y;
    function0 _659_t2;
    int64_t _659_$retval;
    _660_x = 4;
    _660_y = &_660_x;
    _659_t2 = _661_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _659_t2(_660_y);
    $line_idx--;
    _659_$retval = *_660_y;
    return _659_$retval;
}

void _661_f(int64_t* _661_y){
    int64_t* _662_z;
    _662_z = _661_y;
    *_662_z = 195;
    return;
}

int main(void) {
  printf("%ld",_659_main());
  return 0;
}
