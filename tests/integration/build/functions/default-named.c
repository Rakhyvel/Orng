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
int64_t _1070_main(void);
int64_t _1072_add(int64_t _1072_x,int64_t _1072_y);

/* Function definitions */
int64_t _1070_main(void){
    function0 _1070_t0;
    int64_t _1070_t2;
    int64_t _1070_t3;
    int64_t _1070_t1;
    int64_t _1070_$retval;
    _1070_t0 = _1072_add;
    _1070_t2 = 4;
    _1070_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _1070_t1 = _1070_t0(_1070_t2, _1070_t3);
    $line_idx--;
    _1070_$retval = _1070_t1;
    return _1070_$retval;
}

int64_t _1072_add(int64_t _1072_x,int64_t _1072_y){
    int64_t _1072_$retval;
    _1072_$retval = $add_int64_t(_1072_x, _1072_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _1072_$retval;
}

int main(void) {
  printf("%ld",_1070_main());
  return 0;
}
