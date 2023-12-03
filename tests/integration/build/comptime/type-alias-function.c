/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
} struct1;

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _143_main(void);
int64_t _145_add(int64_t _145_x,int64_t _145_y);

/* Function definitions */
int64_t _143_main(void) {
    function0 _144_f;
    int64_t _143_t2;
    int64_t _143_t3;
    int64_t _143_t1;
    int64_t _143_$retval;
    _144_f = _145_add;
    _143_t2 = 200;
    _143_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _143_t1 = _144_f(_143_t2, _143_t3);
    $line_idx--;
    _143_$retval = _143_t1;
    return _143_$retval;
}

int64_t _145_add(int64_t _145_x,int64_t _145_y) {
    int64_t _145_$retval;
    _145_$retval = $add_int64_t(_145_x, _145_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _145_$retval;
}

int main(void) {
  printf("%ld",_143_main());
  return 0;
}
