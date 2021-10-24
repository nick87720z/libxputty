/*
 *                           0BSD 
 * 
 *                    BSD Zero Clause License
 * 
 *  Copyright (c) 2019 Hermann Meyer
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.

 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 */


#include "xdrawing_area_private.h"


void _draw_image(void *w_, void* user_data) {
    Widget_t *w = (Widget_t*)w_;
    XWindowAttributes attrs;
    XGetWindowAttributes(w->app->dpy, (Window)w->widget, &attrs);
    int width_t = attrs.width;
    int height_t = attrs.height;

    if (!w->image) {
         widget_get_png(w, LDVAR(warning_png));
    }

    if (w->image) {
        int width = cairo_xlib_surface_get_width(w->image);
        int height = cairo_xlib_surface_get_height(w->image);
        double x = (double)width_t/(double)(width);
        double y = (double)height_t/(double)height;
        double x1 = (double)(width)/(double)width_t;
        double y1 = (double)height/(double)height_t;
        cairo_scale(w->crb, x,y);
        cairo_set_source_surface (w->crb, w->image, 0, 0);
        cairo_paint (w->crb);
        cairo_scale(w->crb, x1,y1);
    } 
}
