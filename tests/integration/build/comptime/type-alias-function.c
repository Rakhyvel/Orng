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
int64_t _289_main(void);
int64_t _291_add(int64_t _291_x,int64_t _291_y);

/* Function definitions */
int64_t _289_main(void){
    function0 _290_f;
    int64_t _289_t2;
    int64_t _289_t3;
    int64_t _289_t1;
    int64_t _289_$retval;
    _290_f = _291_add;
    _289_t2 = 200;
    _289_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _289_t1 = _290_f(_289_t2, _289_t3);
    $line_idx--;
    _289_$retval = _289_t1;
    return _289_$retval;
}

int64_t _291_add(int64_t _291_x,int64_t _291_y){
    int64_t _291_$retval;
    _291_$retval = $add_int64_t(_291_x, _291_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _291_$retval;
}

int main(void) {
  printf("%ld",_289_main());
  return 0;
}
