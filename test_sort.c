#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> /* memset */
#include <assert.h> /* assert */
#include <sys/time.h> /* gettimeofday */
#include <sys/types.h>
#include <errno.h>
#include "algo_common.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "shell_sort.h"
#include "insert_sort.h"
#include "cocktail_sort.h"
#include "bubble_sort.h"

/* include other sorts here */

#define AVAIL_TEST_NR_MAX (10)

struct test_detail {
	sort_t		 td_func;
	const char	*td_name;
};

struct test {
	struct test_detail	st_test[AVAIL_TEST_NR_MAX];
	/* start position of the test */
	size_t			st_start;
	/* end position of the test */
	size_t			st_end;
};

#define AVAIL_PROFILE_NR_MAX (20)

struct run_profile_detail {
	size_t	pd_length;
	size_t	pd_run_time;
};

struct run_profile {
	struct run_profile_detail	rp_profile[AVAIL_PROFILE_NR_MAX];
	/* start position of the test */
	size_t				rp_start;
	/* end position of the test */
	size_t				rp_end;
};

/**
 * Allocates an array of given @length with randomly set elements
 */
int init_array(elem_t **out, size_t length)
{
	size_t i;
	*out = (elem_t*)malloc(sizeof(elem_t)*length);
	if (*out == 0)
		return -ENOMEM;
	else
		for (i = 0; i < length; ++i)
			(*out)[i] = rand();
	return 0;
}

/**
 * Deallocates given array
 */
void fini_array(elem_t *out)
{
	free(out);
}


/**
 * Checks if an array of a given length is sorted in asscending order
 * @return 0 if success, -1 if failure
 */
int check_sorted_array(elem_t *arr, size_t length)
{
	size_t i, j;

	for (i = 0, j = 1; i < length-1; ++i, ++j)
		if (arr[i] > arr[j])
			return -1;

	return 0;
}

/**
 *  @return time in **microseconds**
 */
size_t checkpoint(void)
{
	struct timeval  tv;
	int		rc;

	rc = gettimeofday(&tv, NULL);
	assert(rc == 0); /* XXX: provide more correct solution */
	return 1000000*tv.tv_sec + tv.tv_usec;
}

/**
 * @TODO: define this function...
 * Reports time and algorithm profile params
 */
void report(size_t elapsed, struct run_profile_detail prf,
	    struct test_detail tst)
{
	const size_t tm = prf.pd_run_time;
	/* printf("test: %s, arr_len: %lu, test_times: %lu // elapsed time: %lu || avg time: %5.5f\n", */
	/* 	 tst.td_name, prf.pd_length, tm, elapsed, ((float)elapsed)/tm); */
	printf("%s:\tsize=%lu\ttime=%5.5f\n", tst.td_name, prf.pd_length, ((float)elapsed)/tm);
}

/**
 * Tests algorithms, reports execution time
 */
void test(size_t profile_start, size_t profile_end,
	  size_t test_start, size_t test_end)
{
	const struct run_profile prof = {
		.rp_profile = {
			[0] =  {.pd_length = 10, .pd_run_time = 10000},
			[1] =  {.pd_length = 20, .pd_run_time = 10000},
			[2] =  {.pd_length = 50, .pd_run_time = 10000},
			[3] =  {.pd_length = 100, .pd_run_time = 1000},
			[4] =  {.pd_length = 200, .pd_run_time = 1000},
			[5] =  {.pd_length = 500, .pd_run_time = 1000},
			[6] =  {.pd_length = 1000, .pd_run_time = 100},
			[7] =  {.pd_length = 5000, .pd_run_time = 100},
			[8] =  {.pd_length = 10000, .pd_run_time = 10},
			[9] =  {.pd_length = 15000, .pd_run_time = 5},
			[10] = {.pd_length = 20000, .pd_run_time = 3},
			[11] = {.pd_length = 50000, .pd_run_time = 2},
			[12] = {.pd_length = 70000, .pd_run_time = 2},
			[13] = {.pd_length = 80000, .pd_run_time = 2},
			[14] = {.pd_length = 100000, .pd_run_time = 2},
			[15] = {0, 0}  /* end */
		},
		.rp_start = profile_start,
		.rp_end   = profile_end
	};
	const struct test rtst = {
		.st_test = {
			[0] = {quick_sort, "quick_sort"},
			[1] = {shell_sort, "shell_sort"},
			[2] = {bubble_sort, "bubble_sort"},
			[3] = {cocktail_sort, "cocktail_sort"},
			[4] = {insert_sort, "insert_sort"},
			[5] = {NULL, NULL} /* end */
		},
		.st_start = test_start,
		.st_end   = test_end
	};
	size_t tst, prf, len, tim, times;
	size_t start_time, end_time;
	elem_t *array;
	sort_t func;
	int rc;

	assert(prof.rp_start >= 0);
	assert(rtst.st_start >= 0);

	for (tst = rtst.st_start; tst < rtst.st_end; ++tst) {
		for (prf = prof.rp_start; prf < prof.rp_end; ++prf) {
			len = prof.rp_profile[prf].pd_length;
			times = prof.rp_profile[prf].pd_run_time;
			assert(len != 0 && times != 0);

			func = rtst.st_test[tst].td_func;
			assert(func != NULL);

			rc = init_array(&array, len);
			assert(rc == 0);

			start_time = checkpoint();

			for (tim = 0; tim < times; ++tim) {
				func(array, len);
			}

			end_time = checkpoint();

			rc = check_sorted_array(array, len);
			assert(rc == 0);

			fini_array(array);
			report(end_time - start_time,
			       prof.rp_profile[prf],
			       rtst.st_test[tst]);
		}
	}
}

int main(int argc, char **argv)
{
	printf("init\n");
	checkpoint();
	srand(0xCAFEBABE);

	printf("test\n");
	test(0, 15, 1, 5);
	return 0;
}
