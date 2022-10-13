/***
 * Copyright (C) Falko Axmann. All rights reserved.
 * Licensed under the MIT license.
 * See LICENSE.txt file in the project root for full license information.
 ****/

#include "CommandExecuter.h"
#include "CommandEnvironment.h"
#include <Spix/Logging.h>

#include <cassert>

namespace spix {

CommandExecuter::CommandExecuter()
: m_mainThreadId(std::this_thread::get_id())
, m_commandQueue()
{
}

ExecuterState& CommandExecuter::state()
{
    // main thread access only
    assert(m_mainThreadId == std::this_thread::get_id());
    return m_state;
}

void CommandExecuter::enqueueCommand(std::unique_ptr<cmd::Command> command)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_commandQueue.emplace(std::move(command));
}

void CommandExecuter::processCommands(Scene& scene)
{
    // main thread access only
    assert(m_mainThreadId == std::this_thread::get_id());

    std::unique_lock<std::mutex> lock(m_mutex, std::try_to_lock);
    if (!lock) {
        return;
    }

    CommandEnvironment env(scene, m_state);

    while (!m_commandQueue.empty()) {
        auto& queuedCmd = m_commandQueue.front();
        logging::log("Picked new command from queue: " + queuedCmd->toString());

        if (!queuedCmd->canExecuteNow())
        {
            logging::log("Cannot execute picked command now, exiting queue loop");
            break;
        }

        // We can execute the command now.
        // Remove from queue and execute.
        std::unique_ptr<cmd::Command> localCmd = std::move(queuedCmd);
        m_commandQueue.pop();

        lock.unlock();

        logging::log("Executing command: " + localCmd->toString());
        localCmd->execute(env);
        logging::log("Done executing command: " + localCmd->toString());
        if (!lock.try_lock()) {
            return;
        }
    }
}

} // namespace spix
