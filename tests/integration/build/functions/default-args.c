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
int64_t _872_main(void);
int64_t _874_add(int64_t _874_x,int64_t _874_y);

/* Function definitions */
int64_t _872_main(void) {
    function0 _872_t0;
    function0 _872_t2;
    int64_t _872_t4;
    int64_t _872_t5;
    int64_t _872_t3;
    function0 _872_t6;
    int64_t _872_t8;
    int64_t _872_t9;
    int64_t _872_t7;
    int64_t _872_t1;
    int64_t _872_$retval;
    _872_t0 = _874_add;
    _872_t2 = _874_add;
    _872_t4 = 47;
    _872_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _872_t3 = _872_t2(_872_t4, _872_t5);
    $line_idx--;
    _872_t6 = _874_add;
    _872_t8 = 1;
    _872_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _872_t7 = _872_t6(_872_t8, _872_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _872_t1 = _872_t0(_872_t3, _872_t7);
    $line_idx--;
    _872_$retval = _872_t1;
    return _872_$retval;
}

int64_t _874_add(int64_t _874_x,int64_t _874_y) {
    int64_t _874_$retval;
    _874_$retval = $add_int64_t(_874_x, _874_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _874_$retval;
}

int main(void) {
  printf("%ld",_872_main());
  return 0;
}
