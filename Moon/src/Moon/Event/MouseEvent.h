#pragma once

#include "Event.h"

namespace moon {

  class MouseEvent : public Event
  {
  public:
    MouseEvent(EventType type, Data&& data) : Event(type, std::move(data)) {}
  };

}

