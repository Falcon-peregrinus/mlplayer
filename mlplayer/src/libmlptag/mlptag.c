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

#include <glib.h>

#include <libmlpcore/tuple.h>

#include "mlptag.h"
#include "config.h"
#include "tag_module.h"
#include "util.h"

bool_t tag_verbose = FALSE;

EXPORT void tag_set_verbose (bool_t verbose)
{
    tag_verbose = verbose;
}

/* The tuple's file-related attributes are already set */

EXPORT bool_t tag_tuple_read (Tuple * tuple, VFSFile * handle)
{
    tag_module_t * module = find_tag_module (handle, TAG_TYPE_NONE);

    if (module == NULL)
        return FALSE;

    return module->read_tag (tuple, handle);
}

EXPORT bool_t tag_image_read (VFSFile * handle, void * * data, int64_t * size)
{
    tag_module_t * module = find_tag_module (handle, TAG_TYPE_NONE);

    if (module == NULL || module->read_image == NULL)
        return FALSE;

    return module->read_image (handle, data, size);
}

EXPORT bool_t tag_tuple_write (const Tuple * tuple, VFSFile * handle, int new_type)
{
    tag_module_t * module = find_tag_module (handle, new_type);

    if (module == NULL)
        return FALSE;

    return module->write_tag (tuple, handle);
}

/* deprecated */
EXPORT bool_t tag_tuple_write_to_file (Tuple * tuple, VFSFile * handle)
{
    return tag_tuple_write (tuple, handle, TAG_TYPE_NONE);
}
