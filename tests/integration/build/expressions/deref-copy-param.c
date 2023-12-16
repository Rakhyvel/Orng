/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _603_main(void);
void _606_f(int64_t* _606_y);

/* Function definitions */
int64_t _603_main(void){
    int64_t _604_x;
    int64_t* _604_y;
    function0 _603_t2;
    int64_t _603_$retval;
    _604_x = 4;
    _604_y = &_604_x;
    _603_t2 = _606_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _603_t2(_604_y);
    $line_idx--;
    _603_$retval = *_604_y;
    return _603_$retval;
}

void _606_f(int64_t* _606_y){
    int64_t* _609_z;
    _609_z = _606_y;
    *_609_z = 195;
    return;
}

int main(void) {
  printf("%ld",_603_main());
  return 0;
}
