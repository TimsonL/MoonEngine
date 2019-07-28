#pragma once

#include "Event.h"

namespace moon {

  class SystemEvent : public Event
  {
  public:
    SystemEvent() : Event() {}
    SystemEvent(Data&& data) : Event(std::move(data)) {}
  };

}

