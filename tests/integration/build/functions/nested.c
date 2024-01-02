/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */
struct struct2;

/* Typedefs */
typedef int64_t(*function0)(int64_t);

struct struct2 {
    int64_t _0;
    int64_t _1;
};

typedef int64_t(*function1)(int64_t, int64_t);

/* Function forward definitions */
int64_t _982_main(void);
int64_t _984_fib(int64_t _984_n);
int64_t _990_add(int64_t _990_x, int64_t _990_y);

/* Function definitions */
int64_t _982_main(void){
    function0 _982_t0;
    int64_t _982_t2;
    int64_t _982_t1;
    int64_t _982_t3;
    int64_t _982_$retval;
    _982_t0 = _984_fib;
    _982_t2 = 10;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:3:17:\n    let n = fib(10) - 10\n               ^";
    _982_t1 = _982_t0(_982_t2);
    $line_idx--;
    _982_t3 = 10;
    _982_$retval = $sub_int64_t(_982_t1, _982_t3, "tests/integration/functions/nested.orng:3:22:\n    let n = fib(10) - 10\n                    ^");
    return _982_$retval;
}

int64_t _984_fib(int64_t _984_n){
    function1 _984_t7;
    function0 _984_t9;
    int64_t _984_t11;
    int64_t _984_t12;
    int64_t _984_t10;
    function0 _984_t13;
    int64_t _984_t15;
    int64_t _984_t16;
    int64_t _984_t14;
    int64_t _984_t8;
    int64_t _984_t0;
    int64_t _984_t1;
    uint8_t _984_t2;
    int64_t _984_t3;
    uint8_t _984_t4;
    int64_t _984_$retval;
    _984_t1 = 0;
    _984_t2 = _984_n==_984_t1;
    if (_984_t2) {
        goto BB1189;
    } else {
        goto BB1192;
    }
BB1189:
    _984_t0 = 0;
    goto BB1191;
BB1192:
    _984_t3 = 1;
    _984_t4 = _984_n==_984_t3;
    if (_984_t4) {
        goto BB1194;
    } else {
        goto BB1196;
    }
BB1191:
    _984_$retval = _984_t0;
    return _984_$retval;
BB1194:
    _984_t0 = 1;
    goto BB1191;
BB1196:
    _984_t7 = _990_add;
    _984_t9 = _984_fib;
    _984_t11 = 1;
    _984_t12 = $sub_int64_t(_984_n, _984_t11, "tests/integration/functions/nested.orng:8:29:\n            _ => add(fib(n - 1), fib(n - 2))\n                           ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:26:\n            _ => add(fib(n - 1), fib(n - 2))\n                        ^";
    _984_t10 = _984_t9(_984_t12);
    $line_idx--;
    _984_t13 = _984_fib;
    _984_t15 = 2;
    _984_t16 = $sub_int64_t(_984_n, _984_t15, "tests/integration/functions/nested.orng:8:41:\n            _ => add(fib(n - 1), fib(n - 2))\n                                       ^");
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:38:\n            _ => add(fib(n - 1), fib(n - 2))\n                                    ^";
    _984_t14 = _984_t13(_984_t16);
    $line_idx--;
    $lines[$line_idx++] = "tests/integration/functions/nested.orng:8:22:\n            _ => add(fib(n - 1), fib(n - 2))\n                    ^";
    _984_t8 = _984_t7(_984_t10, _984_t14);
    $line_idx--;
    _984_t0 = _984_t8;
    goto BB1191;
}

int64_t _990_add(int64_t _990_x, int64_t _990_y){
    int64_t _990_$retval;
    _990_$retval = $add_int64_t(_990_x, _990_y, "tests/integration/functions/nested.orng:14:33:\nfn add(x: Int, y: Int)->Int {x + y}\n                               ^");
    return _990_$retval;
}

int main(void) {
  printf("%ld",_982_main());
  return 0;
}
