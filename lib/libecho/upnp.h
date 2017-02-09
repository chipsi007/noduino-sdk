/*
 *  Copyright (c) 2016 - 2025 MaiKe Labs
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
*/
#ifndef __UPNP_H__
#define __UPNP_H__

#include "ssdp.h"

typedef void (*on_fn_t)(void);
typedef void (*off_fn_t)(void);

typedef struct upnp_dev {
	struct espconn *esp_conn;
	uint32_t port;
	char dev_upnp_uuid[64];
	char dev_voice_name[32];
	on_fn_t way_on;
	off_fn_t way_off;
} upnp_dev_t;

int upnp_start(upnp_dev_t *devs, int ways);
void upnp_stop(upnp_dev_t *devs, int ways);
#endif