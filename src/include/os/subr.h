/*
 *
 * contributeur : Sachin Bhamare   sbhamare@panasas.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 3 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 * ---------------------------------------
 */

/**
 * @file subr.h
 * @author Sachin Bhamare <sbhamare@panasas.com>
 * @brief platform dependant subroutine type definitions
 */

#ifndef SUBR_OS_H
#define SUBR_OS_H

#include <stdbool.h>
#include <extended_types.h>

#ifndef UTIME_NOW
#define UTIME_NOW	-1
#define UTIME_OMIT	-2
#endif

int vfs_utimesat(int fd, const char *path, const struct timespec times[2],
		 int flags);
int vfs_utimes(int fd, const struct timespec *times);

struct vfs_dirent {
	uint64_t vd_ino;
	uint32_t vd_reclen;
	uint32_t vd_type;
	off_t vd_offset;
	char *vd_name;
};

struct seekloc {
#if defined(__APPLE__)
	long loc;
#else
	off_t loc;
#endif
};

int vfs_readents(int fd, char *buf, unsigned int bcount, struct seekloc *);
bool to_vfs_dirent(char *buf, int bpos, struct vfs_dirent *vd, off_t base);
void setuser(uid_t uid);
void setgroup(gid_t gid);
uid_t getuser(void);
gid_t getgroup(void);
int set_threadgroups(size_t size, const gid_t *list);

#endif/* SUBR_OS_H */
