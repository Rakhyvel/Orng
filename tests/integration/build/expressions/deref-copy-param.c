/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _372_main(void);
void _374_f(int64_t* _374_y);

/* Function definitions */
int64_t _372_main(void) {
    int64_t _373_x;
    int64_t* _373_y;
    function0 _372_t2;
    int64_t _372_$retval;
    _373_x = 4;
    _373_y = &_373_x;
    _372_t2 = _374_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _372_t2(_373_y);
    $line_idx--;
    _372_$retval = *_373_y;
    return _372_$retval;
}

void _374_f(int64_t* _374_y) {
    int64_t* _375_z;
    _375_z = _374_y;
    *_375_z = 195;
}

int main(void) {
  printf("%ld",_372_main());
  return 0;
}
