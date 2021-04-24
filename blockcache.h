/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2014-2021 Paul Cercueil <paul@crapouillou.net>
 */

#ifndef __BLOCKCACHE_H__
#define __BLOCKCACHE_H__

#include "lightrec.h"

struct blockcache;

struct block * lightrec_find_block(struct blockcache *cache, u32 pc);
void lightrec_register_block(struct blockcache *cache, struct block *block);
void lightrec_unregister_block(struct blockcache *cache, struct block *block);

struct blockcache * lightrec_blockcache_init(struct lightrec_state *state);
void lightrec_free_block_cache(struct blockcache *cache);

u32 lightrec_calculate_block_hash(const struct block *block);
_Bool lightrec_block_is_outdated(struct block *block);

#endif /* __BLOCKCACHE_H__ */
