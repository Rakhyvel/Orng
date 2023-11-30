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
int64_t _113_main(void);
int64_t _116_add(int64_t _116_x,int64_t _116_y);

/* Function definitions */
int64_t _113_main(void) {
    function0 _114_f;
    int64_t _113_t2;
    int64_t _113_t3;
    int64_t _113_t1;
    int64_t _113_$retval;
    _114_f = _116_add;
    _113_t2 = 200;
    _113_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _113_t1 = _114_f(_113_t2, _113_t3);
    $line_idx--;
    _113_$retval = _113_t1;
    return _113_$retval;
}

int64_t _116_add(int64_t _116_x,int64_t _116_y) {
    int64_t _116_$retval;
    _116_$retval = $add_int64_t(_116_x, _116_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _116_$retval;
}

int main(void) {
  printf("%ld",_113_main());
  return 0;
}
