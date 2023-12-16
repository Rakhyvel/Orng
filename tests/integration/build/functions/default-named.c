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
int64_t _907_main(void);
int64_t _909_add(int64_t _909_x,int64_t _909_y);

/* Function definitions */
int64_t _907_main(void){
    function0 _907_t0;
    int64_t _907_t2;
    int64_t _907_t3;
    int64_t _907_t1;
    int64_t _907_$retval;
    _907_t0 = _909_add;
    _907_t2 = 4;
    _907_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _907_t1 = _907_t0(_907_t2, _907_t3);
    $line_idx--;
    _907_$retval = _907_t1;
    return _907_$retval;
}

int64_t _909_add(int64_t _909_x,int64_t _909_y){
    int64_t _909_$retval;
    _909_$retval = $add_int64_t(_909_x, _909_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _909_$retval;
}

int main(void) {
  printf("%ld",_907_main());
  return 0;
}
