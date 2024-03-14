/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _1825_main(void);
int64_t _1827_a(int64_t _1827_n);
int64_t _1829_b(int64_t _1829_n);
int64_t _1831_c(int64_t _1831_n);


/* Function definitions */
int64_t _1825_main(void){
    function0 _1825_t0;
    int64_t _1825_t2;
    int64_t _1825_t1;
    int64_t _1825_$retval;
    _1825_t0 = (function0) _1827_a;
    _1825_t2 = 47;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:2:21:\nfn main() -> Int {a(47)}\n                   ^";
    _1825_t1 = _1825_t0(_1825_t2);
    $line_idx--;
    _1825_$retval = _1825_t1;
    return _1825_$retval;
}

int64_t _1827_a(int64_t _1827_n){
    function0 _1827_t0;
    int64_t _1827_t1;
    int64_t _1827_$retval;
    _1827_t0 = (function0) _1829_b;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:4:24:\nfn a(n: Int) -> Int {b(n)}\n                      ^";
    _1827_t1 = _1827_t0(_1827_n);
    $line_idx--;
    _1827_$retval = _1827_t1;
    return _1827_$retval;
}

int64_t _1829_b(int64_t _1829_n){
    function0 _1829_t0;
    int64_t _1829_t1;
    int64_t _1829_$retval;
    _1829_t0 = (function0) _1831_c;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:6:24:\nfn b(n: Int) -> Int {c(n)}\n                      ^";
    _1829_t1 = _1829_t0(_1829_n);
    $line_idx--;
    _1829_$retval = _1829_t1;
    return _1829_$retval;
}

int64_t _1831_c(int64_t _1831_n){
    int64_t _1831_t1;
    uint8_t _1831_t3;
    function0 _1831_t5;
    int64_t _1831_t6;
    int64_t _1831_t0;
    int64_t _1831_$retval;
    _1831_t1 = 47;
    _1831_t3 = _1831_n==_1831_t1;
    if (_1831_t3) {
        goto BB2068;
    } else {
        goto BB2072;
    }
BB2068:
    _1831_t0 = 47;
    goto BB2071;
BB2072:
    _1831_t5 = (function0) _1827_a;
    $lines[$line_idx++] = "tests/integration/whitebox/function-cycle.orng:12:11:\n        a(n)\n         ^";
    _1831_t6 = _1831_t5(_1831_n);
    $line_idx--;
    _1831_t0 = _1831_t6;
    goto BB2071;
BB2071:
    _1831_$retval = _1831_t0;
    return _1831_$retval;
}


int main(void) {
  printf("%ld",_1825_main());
  return 0;
}
