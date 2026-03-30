/* SPDX-License-Identifier: LGPL-2.1+ WITH Linux-syscall-note */
/*
 * neumodmx.h
 * (c) Deep Thought <deeptho@gmail.com> 2025
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#ifndef _UAPI_NEUMODVBDMX_H_
#define _UAPI_NEUMODVBDMX_H_

#include <linux/types.h>
#ifndef __KERNEL__
#include <time.h>
#endif

#define DMX_SET_STID_STREAM      _IOW('o', 53, struct dmx_stid_stream_params)
#define DMX_SET_T2MI_STREAM      _IOW('o', 54, struct dmx_t2mi_stream_params)

/**
 * struct dmx_stid_stream_params - Specifies BBFrames embedded in dvb ts stream
 *	filter parameters.
 *
 * @embedding_pid:	PID in which bbframes are embedded
 * @isi:	stream to be extracted from the bbframes or -1
 */
struct dmx_stid_stream_params {
	__u16           embedding_pid; //PID of pes stream containing the bbframes
	__s16           isi; //id of the stream to extract
};

/**
 * struct dmx_t2mi_stream_params - Specifies filter parameters for t2mi transport stream embedded in dvb ts stream
 *
 * @embedding_pid:	PID in which bbframes are embedded
 * @isi:	stream to be extracted from the bbframes or -1
 */
struct dmx_t2mi_stream_params {
	__u16           embedding_pid; //PID of pes stream containing the bbframes
	__s16           plp; //plp of the stream to extract
};


#endif /* _NEUMODVBDMX_H_ */
