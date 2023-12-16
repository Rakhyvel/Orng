/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _674_main(void);
void _677_f(int64_t* _677_y);

/* Function definitions */
int64_t _674_main(void){
    int64_t _675_x;
    int64_t* _675_y;
    function0 _674_t2;
    int64_t _674_$retval;
    _675_x = 4;
    _675_y = &_675_x;
    _674_t2 = _677_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _674_t2(_675_y);
    $line_idx--;
    _674_$retval = *_675_y;
    return _674_$retval;
}

void _677_f(int64_t* _677_y){
    int64_t* _680_z;
    _680_z = _677_y;
    *_680_z = 195;
    return;
}

int main(void) {
  printf("%ld",_674_main());
  return 0;
}
