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
int64_t _445_main(void);
int64_t _447_add(int64_t _447_x,int64_t _447_y);

/* Function definitions */
int64_t _445_main(void){
    function0 _446_f;
    int64_t _445_t2;
    int64_t _445_t3;
    int64_t _445_t1;
    int64_t _445_$retval;
    _446_f = _447_add;
    _445_t2 = 200;
    _445_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _445_t1 = _446_f(_445_t2, _445_t3);
    $line_idx--;
    _445_$retval = _445_t1;
    return _445_$retval;
}

int64_t _447_add(int64_t _447_x,int64_t _447_y){
    int64_t _447_$retval;
    _447_$retval = $add_int64_t(_447_x, _447_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _447_$retval;
}

int main(void) {
  printf("%ld",_445_main());
  return 0;
}
