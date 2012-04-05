#ifndef __ALGO__COMMON__
#define __ALGO__COMMON__

/* misc. */
#define ARRAY_SIZE(a) ((sizeof (a)) / (sizeof (a)[0] ))
#define STATIC_ASSERT(cond) do { switch (1) {case 0: case !!(cond): ;} } while (0)

/* generic element type, use it in *all* collections */
typedef int elem_t;

/* the following type denotes the prototype of all sorting functions */
typedef void (*sort_t)(elem_t *arr, size_t length);

/* dummy time eater */
static inline void eat(void)
{
	static volatile int eater; /*noopt*/
	/* int eater; /\* try this with -O3 *\/ */
	for (eater = 0; eater < 1000; eater++)
		;
}

#endif /* __ALGO__COMMON__  */
