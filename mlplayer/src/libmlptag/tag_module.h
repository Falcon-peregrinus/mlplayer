/*
 * Copyright 2009 Paula Stanciu
 *
 * This file is part of MLPlayer.
 *
 * MLPlayer is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3 of the License.
 *
 * MLPlayer is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * MLPlayer. If not, see <http://www.gnu.org/licenses/>.
 *
 * The MLPlayer team does not consider modular code linking to MLPlayer or
 * using our public API to be a derived work.
 */

/* Interface of the tagging library */

#ifndef TAG_MODULE_H
#define TAG_MODULE_H

#include "libmlpcore/tuple.h"
#include "libmlpcore/vfs.h"

typedef Tuple* pTuple;

typedef struct _module {
    char *name;
    int type; /* set to TAG_TYPE_NONE if the module cannot create new tags */
    bool_t(*can_handle_file) (VFSFile *fd);
    bool_t (* read_tag) (Tuple * tuple, VFSFile * handle);
    bool_t (* read_image) (VFSFile * handle, void * * data, int64_t * size);
    bool_t (* write_tag) (const Tuple * tuple, VFSFile * handle);
} tag_module_t;

tag_module_t * find_tag_module (VFSFile * handle, int new_type);

#endif /* TAG_MODULE_H */
