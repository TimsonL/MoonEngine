#pragma once

#include "Event.h"

namespace moon {

  class AppEvent : public Event
  {
  public:
    AppEvent(EventType type, Data&& data) : Event(type, std::move(data)) {}
  };

}

