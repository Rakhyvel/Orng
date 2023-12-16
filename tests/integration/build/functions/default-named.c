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
int64_t _918_main(void);
int64_t _920_add(int64_t _920_x,int64_t _920_y);

/* Function definitions */
int64_t _918_main(void){
    function0 _918_t0;
    int64_t _918_t2;
    int64_t _918_t3;
    int64_t _918_t1;
    int64_t _918_$retval;
    _918_t0 = _920_add;
    _918_t2 = 4;
    _918_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _918_t1 = _918_t0(_918_t2, _918_t3);
    $line_idx--;
    _918_$retval = _918_t1;
    return _918_$retval;
}

int64_t _920_add(int64_t _920_x,int64_t _920_y){
    int64_t _920_$retval;
    _920_$retval = $add_int64_t(_920_x, _920_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _920_$retval;
}

int main(void) {
  printf("%ld",_918_main());
  return 0;
}
