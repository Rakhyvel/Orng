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
int64_t _718_main(void);
int64_t _720_add(int64_t _720_x,int64_t _720_y);

/* Function definitions */
int64_t _718_main(void) {
    function0 _718_t0;
    int64_t _718_t2;
    int64_t _718_t3;
    int64_t _718_t1;
    int64_t _718_$retval;
    _718_t0 = _720_add;
    _718_t2 = 4;
    _718_t3 = 50;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    _718_t1 = _718_t0(_718_t2, _718_t3);
    $line_idx--;
    _718_$retval = _718_t1;
    return _718_$retval;
}

int64_t _720_add(int64_t _720_x,int64_t _720_y) {
    int64_t _720_$retval;
    _720_$retval = $add_int64_t(_720_x, _720_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _720_$retval;
}

int main(void) {
  printf("%ld",_718_main());
  return 0;
}
