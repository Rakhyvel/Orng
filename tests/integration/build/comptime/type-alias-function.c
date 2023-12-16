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
int64_t _300_main(void);
int64_t _302_add(int64_t _302_x,int64_t _302_y);

/* Function definitions */
int64_t _300_main(void){
    function0 _301_f;
    int64_t _300_t2;
    int64_t _300_t3;
    int64_t _300_t1;
    int64_t _300_$retval;
    _301_f = _302_add;
    _300_t2 = 200;
    _300_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _300_t1 = _301_f(_300_t2, _300_t3);
    $line_idx--;
    _300_$retval = _300_t1;
    return _300_$retval;
}

int64_t _302_add(int64_t _302_x,int64_t _302_y){
    int64_t _302_$retval;
    _302_$retval = $add_int64_t(_302_x, _302_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _302_$retval;
}

int main(void) {
  printf("%ld",_300_main());
  return 0;
}
