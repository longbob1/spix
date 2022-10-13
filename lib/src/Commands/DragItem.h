/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#pragma once

#include "Command.h"
#include <Spix/Data/ItemPath.h>

namespace spix {
namespace cmd {

class DragItem : public Command {
public:
    DragItem(ItemPath path, int x, int y);

    void execute(CommandEnvironment& env) override;
    std::string toString() const override;

private:
    ItemPath m_path;
    int m_x;
    int m_y;
};

} // namespace cmd
} // namespace spix
