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
int64_t _973_main(void);
int64_t _975_add(int64_t _975_x,int64_t _975_y);

/* Function definitions */
int64_t _973_main(void){
    function0 _973_t0;
    function0 _973_t2;
    int64_t _973_t4;
    int64_t _973_t5;
    int64_t _973_t3;
    function0 _973_t6;
    int64_t _973_t8;
    int64_t _973_t9;
    int64_t _973_t7;
    int64_t _973_t1;
    int64_t _973_$retval;
    _973_t0 = _975_add;
    _973_t2 = _975_add;
    _973_t4 = 47;
    _973_t5 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:27:\nfn main() -> Int {add(add(47), add())}\n                         ^";
    _973_t3 = _973_t2(_973_t4, _973_t5);
    $line_idx--;
    _973_t6 = _975_add;
    _973_t8 = 1;
    _973_t9 = 1;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:36:\nfn main() -> Int {add(add(47), add())}\n                                  ^";
    _973_t7 = _973_t6(_973_t8, _973_t9);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/default-args.orng:2:23:\nfn main() -> Int {add(add(47), add())}\n                     ^";
    _973_t1 = _973_t0(_973_t3, _973_t7);
    $line_idx--;
    _973_$retval = _973_t1;
    return _973_$retval;
}

int64_t _975_add(int64_t _975_x,int64_t _975_y){
    int64_t _975_$retval;
    _975_$retval = $add_int64_t(_975_x, _975_y, "tests/integration/functions/default-args.orng:4:43:\nfn add(x: Int = 1, y: Int = 1) -> Int {x + y}\n                                         ^");
    return _975_$retval;
}

int main(void) {
  printf("%ld",_973_main());
  return 0;
}
