/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _550_main(void);
int64_t _552_f(int64_t _552_x);

/* Function definitions */
int64_t _550_main(void) {
    function0 _550_t0;
    int64_t _550_t2;
    int64_t _550_t1;
    int64_t _550_$retval;
    _550_t0 = _552_f;
    _550_t2 = 1;
    $lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";
    _550_t1 = _550_t0(_550_t2);
    $line_idx--;
    _550_$retval = _550_t1;
    return _550_$retval;
}

int64_t _552_f(int64_t _552_x) {
    int64_t _552_t1;
    uint8_t _552_t2;
    int64_t _552_t0;
    int64_t _552_$retval;
    _552_t1 = 0;
    _552_t2 = _552_x != _552_t1;
    if (_552_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _552_t0 = 173;
    goto BB4;
BB5:
    _552_t0 = 3;
    goto BB4;
BB4:
    _552_$retval = _552_t0;
    return _552_$retval;
}

int main(void) {
  printf("%ld",_550_main());
  return 0;
}
