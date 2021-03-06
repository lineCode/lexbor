/*
 * Copyright (C) 2018 Alexander Borisov
 *
 * Author: Alexander Borisov <lex.borisov@gmail.com>
 */

#ifndef LEXBOR_DOM_NODE_H
#define LEXBOR_DOM_NODE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lexbor/dom/interface.h"
#include "lexbor/dom/interfaces/event_target.h"


typedef lexbor_action_t
(*lxb_dom_node_simple_walker_f)(lxb_dom_node_t *node, void *ctx);


typedef enum {
    LXB_DOM_NODE_TYPE_UNDEF                  = 0x00,
    LXB_DOM_NODE_TYPE_ELEMENT                = 0x01,
    LXB_DOM_NODE_TYPE_ATTRIBUTE              = 0x02,
    LXB_DOM_NODE_TYPE_TEXT                   = 0x03,
    LXB_DOM_NODE_TYPE_CDATA_SECTION          = 0x04,
    LXB_DOM_NODE_TYPE_ENTITY_REFERENCE       = 0x05, // historical
    LXB_DOM_NODE_TYPE_ENTITY                 = 0x06, // historical
    LXB_DOM_NODE_TYPE_PROCESSING_INSTRUCTION = 0x07,
    LXB_DOM_NODE_TYPE_COMMENT                = 0x08,
    LXB_DOM_NODE_TYPE_DOCUMENT               = 0x09,
    LXB_DOM_NODE_TYPE_DOCUMENT_TYPE          = 0x0A,
    LXB_DOM_NODE_TYPE_DOCUMENT_FRAGMENT      = 0x0B,
    LXB_DOM_NODE_TYPE_NOTATION               = 0x0C, // historical
    LXB_DOM_NODE_TYPE_LAST_ENTRY             = 0x0D
}
lxb_dom_node_type_t;

struct lxb_dom_node {
    lxb_dom_event_target_t event_target;

    lxb_dom_document_t     *owner_document;

    lxb_dom_node_t         *next;
    lxb_dom_node_t         *prev;
    lxb_dom_node_t         *parent;
    lxb_dom_node_t         *first_child;
    lxb_dom_node_t         *last_child;

    unsigned int           ns;
    unsigned int           tag_id;

    lxb_dom_node_type_t    type;

#ifdef LXB_DOM_NODE_USER_VARIABLES
    LXB_DOM_NODE_USER_VARIABLES
#endif /* LXB_DOM_NODE_USER_VARIABLES */
};


LXB_API lxb_dom_node_t *
lxb_dom_node_interface_create(lxb_dom_document_t *document);

LXB_API lxb_dom_node_t *
lxb_dom_node_interface_destroy(lxb_dom_node_t *node);

LXB_API const lxb_char_t *
lxb_dom_node_name(lxb_dom_node_t *node, size_t *len);

LXB_API void
lxb_dom_node_insert_child(lxb_dom_node_t *to, lxb_dom_node_t *node);

LXB_API void
lxb_dom_node_insert_before(lxb_dom_node_t *to, lxb_dom_node_t *node);

LXB_API void
lxb_dom_node_insert_after(lxb_dom_node_t *to, lxb_dom_node_t *node);

LXB_API void
lxb_dom_node_remove(lxb_dom_node_t *node);

LXB_API void
lxb_dom_node_simple_walk(lxb_dom_node_t *root,
                         lxb_dom_node_simple_walker_f walker_cb, void *ctx);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LEXBOR_DOM_NODE_H */
