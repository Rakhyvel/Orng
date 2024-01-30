/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */
struct struct1;
struct struct3;
struct struct5;

/* Struct, union, and function definitions */
struct struct1 {
    void* _0;
    int64_t _1;
};

typedef int64_t(*function0)(void*, int64_t);

typedef void(*function2)(void*, int64_t);

struct struct3 {
    int64_t _0;
    int64_t _1;
};

struct struct5 {
    struct struct3* _0;
    int64_t _1;
};

typedef void(*function4)(struct struct3*, int64_t);

typedef int64_t(*function6)(struct struct3*, int64_t);

/* Trait vtable type definitions */
/* Function forward definitions */
int64_t _57_main(void);
void _55_c(void* _55_self, int64_t _55_x);
int64_t _53_b(void* _53_self, int64_t _53_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _57_main(void){
    int64_t _57_t1;
    int64_t _57_t2;
    struct struct3 _58_my_val;
    struct struct3* _57_t4;
    int64_t _57_t5;
    function4 _57_t6;
    struct struct3* _57_t8;
    int64_t _57_t9;
    function6 _57_t10;
    int64_t _57_t7;
    int64_t _57_$retval;
    _57_t1 = 100;
    _57_t2 = 45;
    _58_my_val = (struct struct3) {_57_t1, _57_t2};
    _57_t4 = &_58_my_val;
    _57_t5 = 2;
    _57_t6 = (function4) _55_c;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _57_t6(_57_t4, _57_t5);
    $line_idx--;
    _57_t8 = &_58_my_val;
    _57_t9 = 2;
    _57_t10 = (function6) _53_b;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _57_t7 = _57_t10(_57_t8, _57_t9);
    $line_idx--;
    _57_$retval = _57_t7;
    return _57_$retval;
}

void _55_c(void* _55_self, int64_t _55_x){
    (*(struct struct3*)_55_self)._0 = $mult_int64_t((*(struct struct3*)_55_self)._0, _55_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _53_b(void* _53_self, int64_t _53_x){
    int64_t _53_t0;
    int64_t _53_$retval;
    _53_t0 = $mult_int64_t((*(struct struct3*)_53_self)._1, _53_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _53_$retval = $add_int64_t((*(struct struct3*)_53_self)._0, _53_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _53_$retval;
}


int main(void) {
  printf("%ld",_57_main());
  return 0;
}
