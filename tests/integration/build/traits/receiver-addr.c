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
int64_t _139_main(void);
void _137_c(void* _137_self, int64_t _137_x);
int64_t _135_b(void* _135_self, int64_t _135_x);

/* Trait vtable implementations */

/* Function definitions */
int64_t _139_main(void){
    int64_t _139_t1;
    int64_t _139_t2;
    struct struct3 _140_my_val;
    struct struct3* _139_t5;
    int64_t _139_t6;
    function4 _139_t7;
    struct struct3* _139_t9;
    int64_t _139_t10;
    function6 _139_t11;
    int64_t _139_t8;
    int64_t _139_$retval;
    _139_t1 = 100;
    _139_t2 = 45;
    _140_my_val = (struct struct3) {_139_t1, _139_t2};
    _139_t5 = &_140_my_val;
    _139_t6 = 2;
    _139_t7 = (function4) _137_c;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:18:13:\n    my_val.>c(2)\n           ^";
    (void) _139_t7(_139_t5, _139_t6);
    $line_idx--;
    _139_t9 = &_140_my_val;
    _139_t10 = 2;
    _139_t11 = (function6) _135_b;
    $lines[$line_idx++] = "tests/integration/traits/receiver-addr.orng:19:13:\n    my_val.>b(2)\n           ^";
    _139_t8 = _139_t11(_139_t9, _139_t10);
    $line_idx--;
    _139_$retval = _139_t8;
    return _139_$retval;
}

void _137_c(void* _137_self, int64_t _137_x){
    (*(struct struct3*)_137_self)._0 = $mult_int64_t((*(struct struct3*)_137_self)._0, _137_x, "tests/integration/traits/receiver-addr.orng:13:46:\n    fn c(&mut self, x: Int) -> () { self.x *= x }\n                                            ^");
    return;
}

int64_t _135_b(void* _135_self, int64_t _135_x){
    int64_t _135_t0;
    int64_t _135_$retval;
    _135_t0 = $mult_int64_t((*(struct struct3*)_135_self)._1, _135_x, "tests/integration/traits/receiver-addr.orng:11:51:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                                 ^");
    _135_$retval = $add_int64_t((*(struct struct3*)_135_self)._0, _135_t0, "tests/integration/traits/receiver-addr.orng:11:42:\n    fn b(&self, x: Int) -> Int { self.x + self.y * x }\n                                        ^");
    return _135_$retval;
}


int main(void) {
  printf("%ld",_139_main());
  return 0;
}
