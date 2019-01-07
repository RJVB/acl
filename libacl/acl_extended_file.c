/*
  File: acl_extended_file.c

  Copyright (C) 2011
  Andreas Gruenbacher, <a.gruenbacher@bestbits.at>

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include "config.h"
#include <unistd.h>
#include <sys/xattr.h>
#include "libacl.h"

#include "__acl_extended_file.h"


#ifdef __APPLE__
    static ssize_t _getxattr(const char *path, const char *name, void *value, size_t size)
    {
        return getxattr(path, name, value, size, 0, 0);
    }
    #define getxattr(p,n,v,s)       _getxattr((p),(n),(v),(s))
#else
    #define _getxattr getxattr
#endif

int
acl_extended_file(const char *path_p)
{
	return __acl_extended_file(path_p, _getxattr);
}

