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
int64_t _360_main(void);
int64_t _362_add(int64_t _362_x,int64_t _362_y);

/* Function definitions */
int64_t _360_main(void){
    function0 _361_f;
    int64_t _360_t2;
    int64_t _360_t3;
    int64_t _360_t1;
    int64_t _360_$retval;
    _361_f = _362_add;
    _360_t2 = 200;
    _360_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _360_t1 = _361_f(_360_t2, _360_t3);
    $line_idx--;
    _360_$retval = _360_t1;
    return _360_$retval;
}

int64_t _362_add(int64_t _362_x,int64_t _362_y){
    int64_t _362_$retval;
    _362_$retval = $add_int64_t(_362_x, _362_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _362_$retval;
}

int main(void) {
  printf("%ld",_360_main());
  return 0;
}
