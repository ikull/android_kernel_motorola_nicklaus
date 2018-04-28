/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2013, 2017 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

/**
 * @file mali_timeline_sync_fence.h
 *
 * This file contains code related to creating sync fences from timeline fences.
 */

#ifndef __MALI_TIMELINE_SYNC_FENCE_H__
#define __MALI_TIMELINE_SYNC_FENCE_H__

#include "mali_timeline.h"

#if defined(CONFIG_SYNC) || defined(CONFIG_SYNC_FILE)

/**
 * Sync fence tracker.
 */
struct mali_timeline_sync_fence_tracker {
	struct mali_sync_flag        *flag;    /**< Sync flag used to connect tracker and sync fence. */
	struct mali_timeline_tracker  tracker; /**< Timeline tracker. */
};

/**
 * Create a sync fence that will be signaled when @ref fence is signaled.
 *
 * @param system Timeline system.
 * @param fence Fence to create sync fence from.
 * @return File descriptor for new sync fence, or -1 on error.
 */
s32 mali_timeline_sync_fence_create(struct mali_timeline_system *system, struct mali_timeline_fence *fence);

/**
 * Used by the Timeline system to activate a sync fence tracker.
 *
 * @param sync_fence_tracker Sync fence tracker.
 *
 */
void mali_timeline_sync_fence_activate(struct mali_timeline_sync_fence_tracker *sync_fence_tracker);

#endif /* defined(CONFIG_SYNC) || defined(CONFIG_SYNC_FILE) */

#endif /* __MALI_TIMELINE_SYNC_FENCE_H__ */
