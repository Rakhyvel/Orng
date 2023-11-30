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
int64_t _849_main(void);
int64_t _851_add(int64_t _851_x,int64_t _851_y);

/* Function definitions */
int64_t _849_main(void) {
    function0 _849_t0;
    function0 _849_t2;
    int64_t _849_t4;
    int64_t _849_t5;
    int64_t _849_t3;
    function0 _849_t6;
    int64_t _849_t8;
    int64_t _849_t9;
    int64_t _849_t7;
    int64_t _849_t1;
    int64_t _849_$retval;
    _849_t0 = _851_add;
    _849_t2 = _851_add;
    _849_t4 = 47;
    _849_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _849_t3 = _849_t2(_849_t4, _849_t5);
    $line_idx--;
    _849_t6 = _851_add;
    _849_t8 = 1;
    _849_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _849_t7 = _849_t6(_849_t8, _849_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _849_t1 = _849_t0(_849_t3, _849_t7);
    $line_idx--;
    _849_$retval = _849_t1;
    return _849_$retval;
}

int64_t _851_add(int64_t _851_x,int64_t _851_y) {
    int64_t _851_$retval;
    _851_$retval = $add_int64_t(_851_x, _851_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _851_$retval;
}

int main(void) {
  printf("%ld",_849_main());
  return 0;
}
