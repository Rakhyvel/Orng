/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
} struct0;
typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;
typedef struct {
    struct1 _0;
    struct1 _1;
    struct1 _2;
} struct2;
typedef struct {
    struct1* _0;
    int64_t _1;
} struct3;

/* Function forward definitions */
int64_t _2_main();

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    int64_t* _2_t12;
    struct1 _2_t5;
    int64_t* _2_t21;
    struct1 _2_t14;
    int64_t* _2_t30;
    struct1 _2_t23;
    struct2 _3_y;
    struct1* _2_t39;
    struct3 _3_z;
    int64_t _2_t42;
    struct1 _2_t43;
    int64_t _2_t48;
    int64_t _2_t53;
    struct1 _2_t54;
    int64_t _2_t59;
    int64_t _2_$retval;
    _3_x = (struct0) {1, 2, 3};
    _2_t12 = (int64_t*)&_3_x;
    _2_t5 = (struct1) {_2_t12, 3};
    _2_t21 = (int64_t*)&_3_x;
    _2_t14 = (struct1) {_2_t21, 3};
    _2_t30 = (int64_t*)&_3_x;
    _2_t23 = (struct1) {_2_t30, 3};
    _3_y = (struct2) {_2_t5, _2_t14, _2_t23};
    _2_t39 = (struct1*)&_3_y;
    _3_z = (struct3) {_2_t39, 3};
    _2_t42 = 1;
    if (_2_t42 >= _3_z._1) {
        goto BB19;
    } else {
        goto BB20;
    }
BB20:
    _2_t43 = *((struct1*)_3_z._0 + _2_t42);
    _2_t48 = 2;
    if (_2_t48 >= ((struct1*)_3_z._0 + _2_t42)->_1) {
        goto BB23;
    } else {
        goto BB24;
    }
BB24:
    *((int64_t*)_2_t43._0 + _2_t48) = 82;
    _2_t53 = 1;
    if (_2_t53 >= _3_z._1) {
        goto BB27;
    } else {
        goto BB28;
    }
BB28:
    _2_t54 = *((struct1*)_3_z._0 + _2_t53);
    _2_t59 = 2;
    if (_2_t59 >= ((struct1*)_3_z._0 + _2_t53)->_1) {
        goto BB31;
    } else {
        goto BB32;
    }
BB32:
    _2_$retval = *((int64_t*)_2_t54._0 + _2_t59);
    return _2_$retval;
BB31:
    $lines[$line_idx++] = "tests/integration/slices/multi-dim.orng:7:10:\n    z[1][2]\n        ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB27:
    $lines[$line_idx++] = "tests/integration/slices/multi-dim.orng:7:7:\n    z[1][2]\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB23:
    $lines[$line_idx++] = "tests/integration/slices/multi-dim.orng:6:10:\n    z[1][2] = 82\n        ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
BB19:
    $lines[$line_idx++] = "tests/integration/slices/multi-dim.orng:6:7:\n    z[1][2] = 82\n     ^";
    fprintf(stderr, "panic: index is greater than length\n");
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
