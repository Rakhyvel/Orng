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
int64_t _978_main(void);
int64_t _980_add(int64_t _980_x,int64_t _980_y);

/* Function definitions */
int64_t _978_main(void){
    function0 _978_t0;
    int64_t _978_t2;
    int64_t _978_t3;
    int64_t _978_t1;
    int64_t _978_$retval;
    _978_t0 = _980_add;
    _978_t2 = 4;
    _978_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _978_t1 = _978_t0(_978_t2, _978_t3);
    $line_idx--;
    _978_$retval = _978_t1;
    return _978_$retval;
}

int64_t _980_add(int64_t _980_x,int64_t _980_y){
    int64_t _980_$retval;
    _980_$retval = $add_int64_t(_980_x, _980_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _980_$retval;
}

int main(void) {
  printf("%ld",_978_main());
  return 0;
}
