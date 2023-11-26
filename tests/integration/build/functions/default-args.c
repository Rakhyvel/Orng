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
int64_t _610_main(void);
int64_t _612_add(int64_t _612_x,int64_t _612_y);

/* Function definitions */
int64_t _610_main(void) {
    function0 _610_t0;
    function0 _610_t2;
    int64_t _610_t4;
    int64_t _610_t5;
    int64_t _610_t3;
    function0 _610_t6;
    int64_t _610_t8;
    int64_t _610_t9;
    int64_t _610_t7;
    int64_t _610_t1;
    int64_t _610_$retval;
    _610_t0 = _612_add;
    _610_t2 = _612_add;
    _610_t4 = 47;
    _610_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _610_t3 = _610_t2(_610_t4, _610_t5);
    $line_idx--;
    _610_t6 = _612_add;
    _610_t8 = 1;
    _610_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _610_t7 = _610_t6(_610_t8, _610_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _610_t1 = _610_t0(_610_t3, _610_t7);
    $line_idx--;
    _610_$retval = _610_t1;
    return _610_$retval;
}

int64_t _612_add(int64_t _612_x,int64_t _612_y) {
    int64_t _612_$retval;
    _612_$retval = $add_int64_t(_612_x, _612_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _612_$retval;
}

int main(void) {
  printf("%ld",_610_main());
  return 0;
}
