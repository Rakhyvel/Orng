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
int64_t _615_main(void);
int64_t _617_add(int64_t _617_x,int64_t _617_y);

/* Function definitions */
int64_t _615_main(void) {
    function0 _615_t0;
    int64_t _615_t2;
    int64_t _615_t3;
    int64_t _615_t1;
    int64_t _615_$retval;
    _615_t0 = _617_add;
    _615_t2 = 4;
    _615_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _615_t1 = _615_t0(_615_t2, _615_t3);
    $line_idx--;
    _615_$retval = _615_t1;
    return _615_$retval;
}

int64_t _617_add(int64_t _617_x,int64_t _617_y) {
    int64_t _617_$retval;
    _617_$retval = $add_int64_t(_617_x, _617_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _617_$retval;
}

int main(void) {
  printf("%ld",_615_main());
  return 0;
}
