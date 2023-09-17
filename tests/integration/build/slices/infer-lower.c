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
    int64_t _4;
    int64_t _5;
} struct0;

typedef struct {
    int64_t* _0;
    int64_t _1;
} struct1;

/* Function forward definitions */
int64_t _2_main();
int64_t _4_sum_up(struct1 _4_xs);

/* Function definitions */
int64_t _2_main() {
    struct0 _3_x;
    int64_t* _2_t18;
    struct1 _3_z;
    int64_t _2_t20;
    int64_t _2_$retval;
    _3_x = (struct0) {100, 8, 2, 4, 35, 6};
    _2_t18 = (int64_t*)&_3_x;
    _3_z = (struct1) {_2_t18, 3};
    $lines[$line_idx++] = "tests/integration/slices/infer-lower.orng:6:12:\n    sum_up(z)\n          ^";
    _2_t20 = _4_sum_up(_3_z);
    $line_idx--;
    _2_$retval = _2_t20;
    return _2_$retval;
}

int64_t _4_sum_up(struct1 _4_xs) {
    int64_t _5_sum;
    int64_t _6_i;
    int64_t _4_$retval;
    _5_sum = 0;
    _6_i = 0;
BB1:
    if (_6_i < _4_xs._1) {
        goto BB4;
    } else {
        goto BB9;
    }
BB4:
    $bounds_check(_6_i, _4_xs._1, "tests/integration/slices/infer-lower.orng:12:19:\n        sum += xs[i]\n                 ^");
    _5_sum = _5_sum + *((int64_t*)_4_xs._0 + _6_i);
    _6_i = _6_i + 1;
    goto BB1;
BB9:
    _4_$retval = _5_sum;
    return _4_$retval;
}

int main()
{
  printf("%ld",_2_main());
  return 0;
}
