#pragma once

#include "Event.h"

namespace moon {

  class EngineEvent : public Event
  {
  public:
    EngineEvent(EventType type, Data&& data) : Event(type, std::move(data)) {}
  };
}

