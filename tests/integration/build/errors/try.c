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
    uint64_t tag;
    union {
        int64_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _1_main();
struct0 _3_f(uint8_t _3_fail);
struct0 _8_g();

/* Function definitions */
int64_t _1_main() {
    struct0 _1_t1;
    int64_t _1_t0;
    struct0 _1_t7;
    int64_t _1_t6;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:8:\n    (f(true) catch 122) + (f(false) catch 122)\n      ^";
    _1_t1 = _3_f(1);
    $line_idx--;
    if (_1_t1.tag) {
        goto BB1;
    } else {
        goto BB7;
    }
BB1:
    _1_t0 = _1_t1._1;
    goto BB2;
BB7:
    _1_t0 = 122;
BB2:
    $lines[$line_idx++] = "tests/integration/errors/try.orng:3:30:\n    (f(true) catch 122) + (f(false) catch 122)\n                            ^";
    _1_t7 = _3_f(0);
    $line_idx--;
    if (_1_t7.tag) {
        goto BB3;
    } else {
        goto BB6;
    }
BB3:
    _1_t6 = _1_t7._1;
    goto BB4;
BB6:
    _1_t6 = 122;
BB4:
    _1_$retval = _1_t0 + _1_t6;
    return _1_$retval;
}

struct0 _3_f(uint8_t _3_fail) {
    struct0 _3_t1;
    int64_t _3_t3;
    struct0 _3_t0;
    struct0 _3_$retval;
    if (_3_fail) {
        goto BB1;
    } else {
        goto BB8;
    }
BB1:
    $lines[$line_idx++] = "tests/integration/errors/try.orng:8:23:\n        let x = try g()\n                     ^";
    _3_t1 = _8_g();
    $line_idx--;
    if (_3_t1.tag) {
        goto BB2;
    } else {
        goto BB7;
    }
BB8:
    _3_t0 = (struct0) {.tag=1, ._1=0};
    goto BB6;
BB2:
    _3_t3 = _3_t1._1;
    _3_t0 = (struct0) {.tag=1, ._1=_3_t3};
    goto BB6;
BB7:
    _3_$retval = _3_t1;
    return _3_$retval;
BB6:
    _3_$retval = _3_t0;
    return _3_$retval;
}

struct0 _8_g() {
    struct0 _8_$retval;
    _8_$retval = (struct0) {.tag=0};
    return _8_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
