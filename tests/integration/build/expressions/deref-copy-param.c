/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef void(*function0)(int64_t*);

/* Function forward definitions */
int64_t _547_main(void);
void _551_f(int64_t* _551_y);

/* Function definitions */
int64_t _547_main(void) {
    int64_t _548_x;
    int64_t* _548_y;
    function0 _547_t2;
    int64_t _547_$retval;
    _548_x = 4;
    _548_y = &_548_x;
    _547_t2 = _551_f;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _547_t2(_548_y);
    $line_idx--;
    _547_$retval = *_548_y;
    return _547_$retval;
}

void _551_f(int64_t* _551_y) {
    int64_t* _553_z;
    _553_z = _551_y;
    *_553_z = 195;
}

int main(void) {
  printf("%ld",_547_main());
  return 0;
}
