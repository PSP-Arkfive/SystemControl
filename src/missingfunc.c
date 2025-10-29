/*
 * This file is part of PRO CFW.

 * PRO CFW is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * PRO CFW is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PRO CFW. If not, see <http://www.gnu.org/licenses/ .
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pspsdk.h>

// TODO: move this to libansic

/*
 * This file contains functions that Sony used to have in the Kernel,
 * but removed for whatever reason they had...
 *
 * To make life easier for developers, we reimplemented them and export
 * them via our NID Resolver.
 */

// Number Parser for Decimal Numbers
int strtol10(const char * str, int * res)
{
    // End Pointer
    char * endptr = NULL;
    
    // Forward Call (with Base 10)
    int result = strtol(str, &endptr, 10);
    
    // Return Result in Parameter
    if (res) *res = result;
    
    // Return Result
    return result;
}
