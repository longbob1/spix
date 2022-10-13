/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include <Spix/Data/Geometry.h>

namespace spix {

Size::Size()
: width(0.0)
, height(0.0)
{
}

Size::Size(Real width, Real height)
: width(width)
, height(height)
{
}

std::string Size::toString() const 
{
    return "width: '" + std::to_string(width) + "' height: '" + std::to_string(height) + "'";
}

Point::Point()
: x(0.0)
, y(0.0)
{
}

Point::Point(Real x, Real y)
: x(x)
, y(y)
{
}

std::string Point::toString() const 
{
    return "x: '" + std::to_string(x) + "' y: '" + std::to_string(y) + "'";
}

Rect::Rect()
{
}

Rect::Rect(Real x, Real y, Real width, Real height)
: topLeft(x, y)
, size(width, height)
{
}

std::string Rect::toString() const 
{
    return "topLeft: {" + topLeft.toString() +  "} size: {" + size.toString() + "}";
}

Color::Color(int r, int g, int b)
: r(r)
, g(g)
, b(b)
{
}

std::string Color::toString() const 
{
    return "r: '" + std::to_string(r) + "' g: '" + std::to_string(g) + "' b: '" + std::to_string(b) + "'";
}
} // namespace spix
