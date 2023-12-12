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
int64_t _87_main(void);
int64_t _89_add(int64_t _89_x,int64_t _89_y);

/* Function definitions */
int64_t _87_main(void) {
    function0 _88_f;
    int64_t _87_t2;
    int64_t _87_t3;
    int64_t _87_t1;
    int64_t _87_$retval;
    _88_f = _89_add;
    _87_t2 = 200;
    _87_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _87_t1 = _88_f(_87_t2, _87_t3);
    $line_idx--;
    _87_$retval = _87_t1;
    return _87_$retval;
}

int64_t _89_add(int64_t _89_x,int64_t _89_y) {
    int64_t _89_$retval;
    _89_$retval = $add_int64_t(_89_x, _89_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _89_$retval;
}

int main(void) {
  printf("%ld",_87_main());
  return 0;
}
