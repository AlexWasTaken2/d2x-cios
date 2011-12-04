/*
 * DIP plugin for Custom IOS.
 *
 * Copyright (C) 2008-2010 Waninkoko, WiiGator.
 * Copyright (C) 2011 davebaol.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "plugin.h"
#include "syscalls.h"
#include "tools.h"


/* Addresses */
u32 addr_initStage2  = 0;
u32 addr_handleIoctl = 0;
u32 addr_handleCmd   = 0;
u32 addr_alloc       = 0;
u32 addr_free        = 0;
u32 addr_readHash    = 0;
u32 addr_printf      = 0;
u8 *dip_readctrl     = 0;


void Patch_DipModule(u32 version)
{
	switch (version) {
	/** 07/11/08 14:34:26 **/
	case 0x48776F72:        // IOS: 53v5662, 55v5662
		/* Patch DVD driver init stage 2 */
		DCWrite32(0x20200074, 0x4B004718);
		DCWrite32(0x20200078, (u32)DI_EmulateInitStage2);

		/* Patch IOCTL handler */
		DCWrite32(0x20200400, 0x4B004718);
		DCWrite32(0x20200404, (u32)DI_EmulateIoctl);
		
		/* Patch command handler */
		DCWrite32(0x20200EF8, 0x4B004718);
		DCWrite32(0x20200EFC, (u32)DI_EmulateCmd);

		/* Set addresses */
		addr_initStage2  = 0x2020007C + 1;
		addr_readHash    = 0x20202A70 + 1;
		addr_handleIoctl = 0x2020040C + 1;
		addr_handleCmd   = 0x20200F04 + 1;
		addr_alloc       = 0x2020096C + 1;
		addr_free        = 0x2020093C + 1;
		addr_printf      = 0x2020387C + 1;
		dip_readctrl     = (u8 *)0x2022DD60;

		break;

	/** 07/24/08 20:08:44 **/
	case 0x4888E14C:        // IOS: 36v3607, 38v4123
		/* Patch DVD driver init stage 2 */
		DCWrite32(0x20200068, 0x4B004718);
		DCWrite32(0x2020006C, (u32)DI_EmulateInitStage2);

		/* Patch IOCTL handler */
		DCWrite32(0x202003B8, 0x4B004718);
		DCWrite32(0x202003BC, (u32)DI_EmulateIoctl);
		
		/* Patch command handler */
		DCWrite32(0x20200D2C, 0x4B004718);
		DCWrite32(0x20200D30, (u32)DI_EmulateCmd);

		/* Set addresses */
		addr_initStage2  = 0x20200070 + 1;
		addr_readHash    = 0x20202874 + 1;
		addr_handleIoctl = 0x202003C4 + 1;
		addr_handleCmd   = 0x20200D38 + 1;
		addr_alloc       = 0x202008C4 + 1;
		addr_free        = 0x20200898 + 1;
		addr_printf      = 0x2020365C + 1;
		dip_readctrl     = (u8 *)0x2022CDAC;

		break;

	/** 11/24/08 15:39:09 **/
	/** 06/03/09 07:49:09 **/
	case 0x492ACA9D:
	case 0x4A262AF5:        // IOS: 37v5662, 56v5661, 57v5918, 58v6175, 60v6174, 61v5661, 70v6687, 80v6943
		/* Patch DVD driver init stage 2 */
		DCWrite32(0x20200074, 0x4B004718);
		DCWrite32(0x20200078, (u32)DI_EmulateInitStage2);

		/* Patch IOCTL handler */
		DCWrite32(0x20200400, 0x4B004718);
		DCWrite32(0x20200404, (u32)DI_EmulateIoctl);
		
		/* Patch command handler */
		DCWrite32(0x20200EF8, 0x4B004718);
		DCWrite32(0x20200EFC, (u32)DI_EmulateCmd);

		/* Set addresses */
		addr_initStage2  = 0x2020007C + 1;
		addr_readHash    = 0x20202944 + 1;
		addr_handleIoctl = 0x2020040C + 1;
		addr_handleCmd   = 0x20200F04 + 1;
		addr_alloc       = 0x2020096C + 1;
		addr_free        = 0x2020093C + 1;
		addr_printf      = 0x20203750 + 1;
		dip_readctrl     = (u8 *)0x2022CD60;

		break;

	default:
		svc_write("DIPP: Error -> Can't patch DI module (unknown version)\n");

		break;
	}
}