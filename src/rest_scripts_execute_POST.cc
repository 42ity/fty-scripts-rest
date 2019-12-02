/*  =========================================================================
    rest_scripts_execute_post - class description

    Copyright (C) 2014 - 2018 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

/*
@header
    rest_scripts_execute_post -
@discuss
@end
*/

#include "fty_scripts_rest_classes.h"

//  Structure of our class

struct _rest_scripts_execute_post_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new rest_scripts_execute_post

rest_scripts_execute_post_t *
rest_scripts_execute_post_new (void)
{
    rest_scripts_execute_post_t *self = (rest_scripts_execute_post_t *) zmalloc (sizeof (rest_scripts_execute_post_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the rest_scripts_execute_post

void
rest_scripts_execute_post_destroy (rest_scripts_execute_post_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        rest_scripts_execute_post_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

