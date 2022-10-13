/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "DragItem.h"

#include <Scene/Scene.h>
#include <Spix/Events/Identifiers.h>
#include <sstream>

namespace spix {
namespace cmd {

DragItem::DragItem(ItemPath path, int x, int y)
: m_path(std::move(path))
, m_x(x), m_y(y)
{
}

void DragItem::execute(CommandEnvironment& env)
{
    auto item = env.scene().itemAtPath(m_path);

    if (!item) {
        env.state().reportError("DragBegin: Item not found: " + m_path.string());
        return;
    }

    auto size = item->size();
    Point midPoint(size.width / 2.0, size.height / 2.0);
    env.scene().events().mouseDown(item.get(), midPoint, spix::MouseButtons::Left);
    env.scene().events().mouseMove(item.get(), midPoint);

    Point nextPoint = midPoint;
    nextPoint.x += m_x;
    nextPoint.y += m_y;

    env.scene().events().mouseMove(item.get(), nextPoint);
    env.scene().events().mouseUp(item.get(), nextPoint, spix::MouseButtons::Left);
}

std::string DragItem::toString() const
{
    std::stringstream sstream;
    sstream << "DragItem: ";
    sstream << "path: {" << m_path.string() << "} ";
    sstream << "x: '" << m_x << "' ";
    sstream << "y: '" << m_y << "' ";

    return sstream.str();
}
} // namespace cmd
} // namespace spix
