/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct1;

/* Typedefs */
struct struct1 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function0)(int64_t, int64_t);

/* Function forward definitions */
int64_t _954_main(void);
int64_t _956_add(int64_t _956_x, int64_t _956_y);

/* Function definitions */
int64_t _954_main(void){
    function0 _954_t0;
    function0 _954_t2;
    int64_t _954_t4;
    int64_t _954_t5;
    int64_t _954_t3;
    function0 _954_t6;
    int64_t _954_t8;
    int64_t _954_t9;
    int64_t _954_t7;
    int64_t _954_t1;
    int64_t _954_$retval;
    _954_t0 = _956_add;
    _954_t2 = _956_add;
    _954_t4 = 47;
    _954_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _954_t3 = _954_t2(_954_t4, _954_t5);
    $line_idx--;
    _954_t6 = _956_add;
    _954_t8 = 1;
    _954_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _954_t7 = _954_t6(_954_t8, _954_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _954_t1 = _954_t0(_954_t3, _954_t7);
    $line_idx--;
    _954_$retval = _954_t1;
    return _954_$retval;
}

int64_t _956_add(int64_t _956_x, int64_t _956_y){
    int64_t _956_$retval;
    _956_$retval = $add_int64_t(_956_x, _956_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _956_$retval;
}

int main(void) {
  printf("%ld",_954_main());
  return 0;
}
