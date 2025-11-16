#ifndef MYASSERT_H
#define MYASSERT_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>

#define FATAL(msg)                                        \
  do {                                                    \
    fprintf(stderr,                                       \
            "Fatal error in %s on line %d: %s\n",         \
            __FILE__,                                     \
            __LINE__,                                     \
            msg);                                         \
    fflush(stderr);                                       \
    abort();                                              \
  } while (0)

#define ASSERT(expr)                                      \
 do {                                                     \
  if (!(expr)) {                                          \
    fprintf(stderr,                                       \
            "Assertion failed in %s on line %d: %s\n",    \
            __FILE__,                                     \
            __LINE__,                                     \
            #expr);                                       \
    abort();                                              \
  }                                                       \
 } while (0)

#define ASSERT_BASE(a, operator, b, type, conv)              \
 do {                                                        \
  type const eval_a = (a);                                   \
  type const eval_b = (b);                                   \
  if (!(eval_a operator eval_b)) {                           \
    fprintf(stderr,                                          \
            "Assertion failed in %s on line %d: `%s %s %s` " \
            "(%"conv" %s %"conv")\n",                        \
            __FILE__,                                        \
            __LINE__,                                        \
            #a,                                              \
            #operator,                                       \
            #b,                                              \
            eval_a,                                          \
            #operator,                                       \
            eval_b);                                         \
    abort();                                                 \
  }                                                          \
 } while (0)

#define ASSERT_OK(a)                                         \
 do {                                                        \
  int64_t const eval_a = (a);                                \
  if (eval_a) {                                              \
    fprintf(stderr,                                          \
            "Assertion failed in %s on line %d: `%s` okay "  \
            "(error: %"PRId64")\n",                          \
            __FILE__,                                        \
            __LINE__,                                        \
            #a,                                              \
            eval_a);                                         \
    abort();                                                 \
  }                                                          \
 } while (0)

#define ASSERT_BASE_STR(expr, a, operator, b, type, conv)      \
 do {                                                          \
  if (!(expr)) {                                               \
    fprintf(stderr,                                            \
            "Assertion failed in %s on line %d: `%s %s %s` "   \
            "(%"conv" %s %"conv")\n",                          \
            __FILE__,                                          \
            __LINE__,                                          \
            #a,                                                \
            #operator,                                         \
            #b,                                                \
            (type)a,                                           \
            #operator,                                         \
            (type)b);                                          \
    abort();                                                   \
  }                                                            \
 } while (0)

#define ASSERT_BASE_LEN(expr, a, operator, b, conv, len)     \
 do {                                                        \
  if (!(expr)) {                                             \
    fprintf(stderr,                                          \
            "Assertion failed in %s on line %d: `%s %s %s` " \
            "(%.*"#conv" %s %.*"#conv")\n",                  \
            __FILE__,                                        \
            __LINE__,                                        \
            #a,                                              \
            #operator,                                       \
            #b,                                              \
            (int)len,                                        \
            a,                                               \
            #operator,                                       \
            (int)len,                                        \
            b);                                              \
    abort();                                                 \
  }                                                          \
 } while (0)

#define ASSERT_EQ_INT(a, b) ASSERT_BASE(a, ==, b, int, "d")
#define ASSERT_GE_INT(a, b) ASSERT_BASE(a, >=, b, int, "d")
#define ASSERT_GT_INT(a, b) ASSERT_BASE(a, >, b, int, "d")
#define ASSERT_LE_INT(a, b) ASSERT_BASE(a, <=, b, int, "d")
#define ASSERT_LT_INT(a, b) ASSERT_BASE(a, <, b, int, "d")
#define ASSERT_NE_INT(a, b) ASSERT_BASE(a, !=, b, int, "d")

#define ASSERT_EQ_UINT(a, b) ASSERT_BASE(a, ==, b, unsigned int, "u")
#define ASSERT_GE_UINT(a, b) ASSERT_BASE(a, >=, b, unsigned int, "u")
#define ASSERT_GT_UINT(a, b) ASSERT_BASE(a, >, b, unsigned int, "u")
#define ASSERT_LE_UINT(a, b) ASSERT_BASE(a, <=, b, unsigned int, "u")
#define ASSERT_LT_UINT(a, b) ASSERT_BASE(a, <, b, unsigned int, "u")
#define ASSERT_NE_UINT(a, b) ASSERT_BASE(a, !=, b, unsigned int, "u")

#define ASSERT_EQ_INT64(a, b) ASSERT_BASE(a, ==, b, int64_t, PRId64)
#define ASSERT_GE_INT64(a, b) ASSERT_BASE(a, >=, b, int64_t, PRId64)
#define ASSERT_GT_INT64(a, b) ASSERT_BASE(a, >, b, int64_t, PRId64)
#define ASSERT_LE_INT64(a, b) ASSERT_BASE(a, <=, b, int64_t, PRId64)
#define ASSERT_LT_INT64(a, b) ASSERT_BASE(a, <, b, int64_t, PRId64)
#define ASSERT_NE_INT64(a, b) ASSERT_BASE(a, !=, b, int64_t, PRId64)

#define ASSERT_EQ_UINT64(a, b) ASSERT_BASE(a, ==, b, uint64_t, PRIu64)
#define ASSERT_GE_UINT64(a, b) ASSERT_BASE(a, >=, b, uint64_t, PRIu64)
#define ASSERT_GT_UINT64(a, b) ASSERT_BASE(a, >, b, uint64_t, PRIu64)
#define ASSERT_LE_UINT64(a, b) ASSERT_BASE(a, <=, b, uint64_t, PRIu64)
#define ASSERT_LT_UINT64(a, b) ASSERT_BASE(a, <, b, uint64_t, PRIu64)
#define ASSERT_NE_UINT64(a, b) ASSERT_BASE(a, !=, b, uint64_t, PRIu64)

#define ASSERT_EQ_INT32(a, b) ASSERT_BASE(a, ==, b, int32_t, PRId32)
#define ASSERT_GE_INT32(a, b) ASSERT_BASE(a, >=, b, int32_t, PRId32)
#define ASSERT_GT_INT32(a, b) ASSERT_BASE(a, >, b, int32_t, PRId32)
#define ASSERT_LE_INT32(a, b) ASSERT_BASE(a, <=, b, int32_t, PRId32)
#define ASSERT_LT_INT32(a, b) ASSERT_BASE(a, <, b, int32_t, PRId32)
#define ASSERT_NE_INT32(a, b) ASSERT_BASE(a, !=, b, int32_t, PRId32)

#define ASSERT_EQ_UINT32(a, b) ASSERT_BASE(a, ==, b, uint32_t, PRIu32)
#define ASSERT_GE_UINT32(a, b) ASSERT_BASE(a, >=, b, uint32_t, PRIu32)
#define ASSERT_GT_UINT32(a, b) ASSERT_BASE(a, >, b, uint32_t, PRIu32)
#define ASSERT_LE_UINT32(a, b) ASSERT_BASE(a, <=, b, uint32_t, PRIu32)
#define ASSERT_LT_UINT32(a, b) ASSERT_BASE(a, <, b, uint32_t, PRIu32)
#define ASSERT_NE_UINT32(a, b) ASSERT_BASE(a, !=, b, uint32_t, PRIu32)

#define ASSERT_EQ_INT16(a, b) ASSERT_BASE(a, ==, b, int16_t, PRId16)
#define ASSERT_GE_INT16(a, b) ASSERT_BASE(a, >=, b, int16_t, PRId16)
#define ASSERT_GT_INT16(a, b) ASSERT_BASE(a, >, b, int16_t, PRId16)
#define ASSERT_LE_INT16(a, b) ASSERT_BASE(a, <=, b, int16_t, PRId16)
#define ASSERT_LT_INT16(a, b) ASSERT_BASE(a, <, b, int16_t, PRId16)
#define ASSERT_NE_INT16(a, b) ASSERT_BASE(a, !=, b, int16_t, PRId16)

#define ASSERT_EQ_UINT16(a, b) ASSERT_BASE(a, ==, b, uint16_t, PRIu16)
#define ASSERT_GE_UINT16(a, b) ASSERT_BASE(a, >=, b, uint16_t, PRIu16)
#define ASSERT_GT_UINT16(a, b) ASSERT_BASE(a, >, b, uint16_t, PRIu16)
#define ASSERT_LE_UINT16(a, b) ASSERT_BASE(a, <=, b, uint16_t, PRIu16)
#define ASSERT_LT_UINT16(a, b) ASSERT_BASE(a, <, b, uint16_t, PRIu16)
#define ASSERT_NE_UINT16(a, b) ASSERT_BASE(a, !=, b, uint16_t, PRIu16)

#define ASSERT_EQ_INT8(a, b) ASSERT_BASE(a, ==, b, int8_t, PRId8)
#define ASSERT_GE_INT8(a, b) ASSERT_BASE(a, >=, b, int8_t, PRId8)
#define ASSERT_GT_INT8(a, b) ASSERT_BASE(a, >, b, int8_t, PRId8)
#define ASSERT_LE_INT8(a, b) ASSERT_BASE(a, <=, b, int8_t, PRId8)
#define ASSERT_LT_INT8(a, b) ASSERT_BASE(a, <, b, int8_t, PRId8)
#define ASSERT_NE_INT8(a, b) ASSERT_BASE(a, !=, b, int8_t, PRId8)

#define ASSERT_EQ_UINT8(a, b) ASSERT_BASE(a, ==, b, uint8_t, PRIu8)
#define ASSERT_GE_UINT8(a, b) ASSERT_BASE(a, >=, b, uint8_t, PRIu8)
#define ASSERT_GT_UINT8(a, b) ASSERT_BASE(a, >, b, uint8_t, PRIu8)
#define ASSERT_LE_UINT8(a, b) ASSERT_BASE(a, <=, b, uint8_t, PRIu8)
#define ASSERT_LT_UINT8(a, b) ASSERT_BASE(a, <, b, uint8_t, PRIu8)
#define ASSERT_NE_UINT8(a, b) ASSERT_BASE(a, !=, b, uint8_t, PRIu8)

#define ASSERT_EQ_FLOAT(a, b) ASSERT_BASE(a, ==, b, float, "f")
#define ASSERT_GE_FLOAT(a, b) ASSERT_BASE(a, >=, b, float, "f")
#define ASSERT_GT_FLOAT(a, b) ASSERT_BASE(a, >, b, float, "f")
#define ASSERT_LE_FLOAT(a, b) ASSERT_BASE(a, <=, b, float, "f")
#define ASSERT_LT_FLOAT(a, b) ASSERT_BASE(a, <, b, float, "f")
#define ASSERT_NE_FLOAT(a, b) ASSERT_BASE(a, !=, b, float, "f")

#define ASSERT_EQ_DOUBLE(a, b) ASSERT_BASE(a, ==, b, double, "lf")
#define ASSERT_GE_DOUBLE(a, b) ASSERT_BASE(a, >=, b, double, "lf")
#define ASSERT_GT_DOUBLE(a, b) ASSERT_BASE(a, >, b, double, "lf")
#define ASSERT_LE_DOUBLE(a, b) ASSERT_BASE(a, <=, b, double, "lf")
#define ASSERT_LT_DOUBLE(a, b) ASSERT_BASE(a, <, b, double, "lf")
#define ASSERT_NE_DOUBLE(a, b) ASSERT_BASE(a, !=, b, double, "lf")

#define ASSERT_EQ_SIZE(a, b) ASSERT_BASE(a, ==, b, size_t, "zu")
#define ASSERT_GE_SIZE(a, b) ASSERT_BASE(a, >=, b, size_t, "zu")
#define ASSERT_GT_SIZE(a, b) ASSERT_BASE(a, >, b, size_t, "zu")
#define ASSERT_LE_SIZE(a, b) ASSERT_BASE(a, <=, b, size_t, "zu")
#define ASSERT_LT_SIZE(a, b) ASSERT_BASE(a, <, b, size_t, "zu")
#define ASSERT_NE_SIZE(a, b) ASSERT_BASE(a, !=, b, size_t, "zu")

#define ASSERT_TRUE(a) \
  ASSERT_BASE(a, ==, true, bool, "d")

#define ASSERT_FALSE(a) \
  ASSERT_BASE(a, ==, false, bool, "d")

#define ASSERT_NULL(a) \
  ASSERT_BASE(a, ==, NULL, const void*, "p")

#define ASSERT_NOT_NULL(a) \
  ASSERT_BASE(a, !=, NULL, const void*, "p")

#define ASSERT_MEM_EQ(a, b, len) \
  ASSERT_BASE_LEN(memcmp(a, b, len) == 0, a, ==, b, "p", len)

#define ASSERT_MEM_NE(a, b, len) \
  ASSERT_BASE_LEN(memcmp(a, b, len) != 0, a, !=, b, "p", len)

#define ASSERT_STR_EQ(a, b) \
  ASSERT_BASE_STR(strcmp(a, b) == 0, a, == , b, char*, "s")

#define ASSERT_STR_NE(a, b) \
  ASSERT_BASE_STR(strcmp(a, b) != 0, a, !=, b, char*, "s")

#define ASSERT_STR_EQ_LEN(a, b, len) \
  ASSERT_BASE_LEN(strncmp(a, b, len) == 0, a, ==, b, "s", len)

#define ASSERT_STR_NE_LEN(a, b, len) \
  ASSERT_BASE_LEN(strncmp(a, b, len) != 0, a, !=, b, "s", len)

enum test_status {
  TEST_OK = 0,
  TEST_SKIP = 7
};

#define RETURN_OK()                                                           \
  do {                                                                        \
    return TEST_OK;                                                           \
  } while (0)

#define RETURN_SKIP(explanation)                                              \
  do {                                                                        \
    fprintf(stderr, "%s\n", explanation);                                     \
    fflush(stderr);                                                           \
    return TEST_SKIP;                                                         \
  } while (0)

#define RUN_TEST(test_func)                                                   \
  do {                                                                        \
    printf("Running %s... ", #test_func);                                     \
    fflush(stdout);                                                           \
    int result = test_func();                                                 \
    if (result == TEST_OK) {                                                  \
      printf("PASSED\n");                                                     \
    } else if (result == TEST_SKIP) {                                         \
      printf("SKIPPED\n");                                                    \
    } else {                                                                  \
      printf("FAILED\n");                                                     \
    }                                                                         \
  } while (0)

#endif
