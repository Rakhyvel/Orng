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
int64_t _70_main(void);
int64_t _72_add(int64_t _72_x,int64_t _72_y);

/* Function definitions */
int64_t _70_main(void) {
    function0 _71_f;
    int64_t _70_t2;
    int64_t _70_t3;
    int64_t _70_t1;
    int64_t _70_$retval;
    _71_f = _72_add;
    _70_t2 = 200;
    _70_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _70_t1 = _71_f(_70_t2, _70_t3);
    $line_idx--;
    _70_$retval = _70_t1;
    return _70_$retval;
}

int64_t _72_add(int64_t _72_x,int64_t _72_y) {
    int64_t _72_$retval;
    _72_$retval = $add_int64_t(_72_x, _72_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _72_$retval;
}

int main(void) {
  printf("%ld",_70_main());
  return 0;
}
