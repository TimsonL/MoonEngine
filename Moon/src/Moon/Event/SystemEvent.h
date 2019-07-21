#pragma once

#include "Event.h"

namespace moon {

  class SystemEvent : public Event
  {
  public:
    SystemEvent(EventType type, Data&& data) : Event(type, std::move(data)) {}
  };

}

