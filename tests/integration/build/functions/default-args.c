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
int64_t _724_main(void);
int64_t _726_add(int64_t _726_x,int64_t _726_y);

/* Function definitions */
int64_t _724_main(void) {
    function0 _724_t0;
    function0 _724_t2;
    int64_t _724_t4;
    int64_t _724_t5;
    int64_t _724_t3;
    function0 _724_t6;
    int64_t _724_t8;
    int64_t _724_t9;
    int64_t _724_t7;
    int64_t _724_t1;
    int64_t _724_$retval;
    _724_t0 = _726_add;
    _724_t2 = _726_add;
    _724_t4 = 47;
    _724_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _724_t3 = _724_t2(_724_t4, _724_t5);
    $line_idx--;
    _724_t6 = _726_add;
    _724_t8 = 1;
    _724_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _724_t7 = _724_t6(_724_t8, _724_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _724_t1 = _724_t0(_724_t3, _724_t7);
    $line_idx--;
    _724_$retval = _724_t1;
    return _724_$retval;
}

int64_t _726_add(int64_t _726_x,int64_t _726_y) {
    int64_t _726_$retval;
    _726_$retval = $add_int64_t(_726_x, _726_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _726_$retval;
}

int main(void) {
  printf("%ld",_724_main());
  return 0;
}
