/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Debug information */
static const char* $lines[1024];
static uint16_t $line_idx = 0;

inline static void $panic(const char *restrict msg) {
    fprintf(stderr, "panic: %s\n", msg);
    for(uint16_t $i = 0; $i < $line_idx; $i++) {
        fprintf(stderr, "%s\n", $lines[$line_idx - $i - 1]);
    }
    exit(1);
}

inline static void $bounds_check(const int64_t idx, const int64_t length, const char *restrict line) {
    if (0 > idx || idx >= length) {
        $lines[$line_idx++] = line;
        $panic("bounds check failed");
    }
}

inline static void $tag_check(const int64_t tag, const int64_t sel, const char *restrict line) {
    if (tag != sel) {
        $lines[$line_idx++] = line;
        $panic("inactive field");
    }
}
/* Typedefs */
typedef struct {
    int64_t _0;
    int64_t _1;
    int64_t _2;
    int64_t _3;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _1_main();
int64_t _3_f();

/* Function definitions */
int64_t _1_main() {
    struct0 _2_x;
    int64_t* _1_t9;
    struct1 _2_y;
    int64_t _1_t12;
    int64_t _1_$retval;
    _2_x = (struct0) {0, 0, 0, 0};
    _1_t9 = (int64_t*)&_2_x;
    _2_y = (struct1) {_1_t9, 4};
    $lines[$line_idx++] = "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:9:\n    y[f()] = 0\n       ^";
    _1_t12 = _3_f();
    $line_idx--;
    $bounds_check(_1_t12, 4, "tests/integration/lint/slice-copy-neg-bounds-check.orng:5:7:\n    y[f()] = 0\n     ^");
    *((int64_t*)_2_y._0 + _1_t12) = 0;
    _1_$retval = 0;
    return _1_$retval;
}

int64_t _3_f() {
    int64_t _3_$retval;
    _3_$retval = -100;
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
