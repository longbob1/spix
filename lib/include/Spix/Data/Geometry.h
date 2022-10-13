/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#pragma once

#include <Spix/spix_export.h>
#include <string>

namespace spix {

using Real = double;

struct SPIX_EXPORT Size {
    Size();
    Size(Real width, Real height);

    std::string toString() const;

    Real width;
    Real height;
};

struct SPIX_EXPORT Point {
    Point();
    Point(Real x, Real y);

    std::string toString() const;

    Real x;
    Real y;
};

struct SPIX_EXPORT Rect {
    Rect();
    Rect(Real x, Real y, Real width, Real height);

    std::string toString() const;

    Point topLeft;
    Size size;
};

struct Color {
    Color(int r, int g, int b);

    std::string toString() const;

    int r;
    int g;
    int b;
};

} // namespace spix
