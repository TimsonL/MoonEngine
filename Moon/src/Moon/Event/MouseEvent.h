#pragma once

#include "Event.h"

namespace moon {

  class MouseEvent : public Event
  {
  public:
    MouseEvent() : Event() {}
    MouseEvent(Data&& data) : Event(std::move(data)) {}
  };

}

