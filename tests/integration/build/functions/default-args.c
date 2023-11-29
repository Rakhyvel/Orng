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
int64_t _870_main(void);
int64_t _872_add(int64_t _872_x,int64_t _872_y);

/* Function definitions */
int64_t _870_main(void) {
    function0 _870_t0;
    function0 _870_t2;
    int64_t _870_t4;
    int64_t _870_t5;
    int64_t _870_t3;
    function0 _870_t6;
    int64_t _870_t8;
    int64_t _870_t9;
    int64_t _870_t7;
    int64_t _870_t1;
    int64_t _870_$retval;
    _870_t0 = _872_add;
    _870_t2 = _872_add;
    _870_t4 = 47;
    _870_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _870_t3 = _870_t2(_870_t4, _870_t5);
    $line_idx--;
    _870_t6 = _872_add;
    _870_t8 = 1;
    _870_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _870_t7 = _870_t6(_870_t8, _870_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _870_t1 = _870_t0(_870_t3, _870_t7);
    $line_idx--;
    _870_$retval = _870_t1;
    return _870_$retval;
}

int64_t _872_add(int64_t _872_x,int64_t _872_y) {
    int64_t _872_$retval;
    _872_$retval = $add_int64_t(_872_x, _872_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _872_$retval;
}

int main(void) {
  printf("%ld",_870_main());
  return 0;
}
