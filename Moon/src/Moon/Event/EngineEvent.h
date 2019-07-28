#pragma once

#include "Event.h"

namespace moon {

  class EngineEvent : public Event
  {
  public:
    EngineEvent() : Event() {}
    EngineEvent(Data&& data) : Event(std::move(data)) {}
  };
}

