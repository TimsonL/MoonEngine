#pragma once

#include "Event.h"

namespace moon {

  class WindowEvent : public Event
  {
  public:
    WindowEvent() : Event() {}
    WindowEvent(Data&& data) : Event(std::move(data)) {}
  };

}

