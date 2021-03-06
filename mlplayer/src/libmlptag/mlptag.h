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

/* External Interface of the tagging library */

#ifndef AUDTAG_H
#define AUDTAG_H

#include <libmlpcore/tuple.h>
#include <libmlpcore/vfs.h>

enum
{
    TAG_TYPE_NONE = 0,
    TAG_TYPE_APE,
};

void tag_set_verbose (bool_t verbose);

bool_t tag_tuple_read (Tuple * tuple, VFSFile *fd);
bool_t tag_image_read (VFSFile * handle, void * * data, int64_t * size);

/* new_type specifies the type of tag (see the TAG_TYPE_* enum) that should be
 * written if the file does not have any existing tag. */
bool_t tag_tuple_write (const Tuple * tuple, VFSFile * handle, int new_type);

/* deprecated, use tag_tuple_write */
bool_t tag_tuple_write_to_file (Tuple * tuple, VFSFile * handle);

#endif /* AUDTAG_H */
