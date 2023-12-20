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
int64_t _359_main(void);
int64_t _361_add(int64_t _361_x,int64_t _361_y);

/* Function definitions */
int64_t _359_main(void){
    function0 _360_f;
    int64_t _359_t2;
    int64_t _359_t3;
    int64_t _359_t1;
    int64_t _359_$retval;
    _360_f = _361_add;
    _359_t2 = 200;
    _359_t3 = 43;
    $lines[$line_idx++] = "tests/integration/comptime/type-alias-function.orng:6:7:\n    f(200, 43)\n     ^";
    _359_t1 = _360_f(_359_t2, _359_t3);
    $line_idx--;
    _359_$retval = _359_t1;
    return _359_$retval;
}

int64_t _361_add(int64_t _361_x,int64_t _361_y){
    int64_t _361_$retval;
    _361_$retval = $add_int64_t(_361_x, _361_y, "tests/integration/comptime/type-alias-function.orng:9:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _361_$retval;
}

int main(void) {
  printf("%ld",_359_main());
  return 0;
}
