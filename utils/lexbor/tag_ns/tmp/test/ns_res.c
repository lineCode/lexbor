/*
 * Copyright (C) 2018 Alexander Borisov
 *
 * Author: Alexander Borisov <lex.borisov@gmail.com>
 */

/*
 * Caution!!! Important!!!
 * This file is generated by the script "utils/lexbor/tag_ns/tags.py"!
 * Do not change this file!
 */


#include <unit/test.h>

#include <lexbor/ns/ns.h>


TEST_BEGIN(names)
{
    const lxb_ns_data_t *entry;
    lxb_ns_heap_t *ns_heap;

    ns_heap = lxb_ns_heap_create();
    test_eq(lxb_ns_heap_init(ns_heap, 32), LXB_STATUS_OK);

%%TEST_NAMES%%

    lxb_ns_heap_destroy(ns_heap);
}
TEST_END

int
main(int argc, const char * argv[])
{
    TEST_INIT();

    TEST_ADD(names);

    TEST_RUN("lexbor/ns/res");
    TEST_RELEASE();
}


