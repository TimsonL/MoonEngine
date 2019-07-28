#pragma once

#include "Event.h"

namespace moon {

  class AppEvent : public Event
  {
  public:
    AppEvent() : Event() {}
    AppEvent(Data&& data) : Event(std::move(data)) {}
  };

}

