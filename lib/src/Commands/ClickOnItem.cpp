/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "ClickOnItem.h"

#include <Scene/Scene.h>
#include <sstream>

namespace spix {
namespace cmd {

ClickOnItem::ClickOnItem(ItemPosition path, MouseButton mouseButton)
: m_position(std::move(path))
, m_mouseButton(mouseButton)
, m_eventToItem(false)
{
}

ClickOnItem::ClickOnItem(ItemPosition path, bool eventToItem)
: m_position(std::move(path))
, m_mouseButton(spix::MouseButtons::Left)
, m_eventToItem(eventToItem)
{
}

void ClickOnItem::execute(CommandEnvironment& env)
{
    auto path = m_position.itemPath();
    auto item = env.scene().itemAtPath(path);

    if (!item) {
        env.state().reportError("ClickOnItem: Item not found: " + path.string());
        return;
    }

    auto size = item->size();
    auto mousePoint = m_position.positionForItemSize(size);
    env.scene().events().mouseDown(item.get(), mousePoint, m_mouseButton, m_eventToItem);
    env.scene().events().mouseUp(item.get(), mousePoint, m_mouseButton, m_eventToItem);
}

std::string ClickOnItem::toString() const
{
    std::stringstream sstream;
    sstream << "ClickOnItem: ";
    sstream << "position: {" << m_position.toString() << "} ";
    sstream << "mouseButton: '" << spix::toStringMouseButton(m_mouseButton) << "' ";
    sstream << "eventToItem: '" << m_eventToItem << "' ";

    return sstream.str();
}

} // namespace cmd
} // namespace spix
