#pragma once

#include "pch.h"
#include "Moon/Core.h"

namespace moon {

  enum class EventType
  {
    None = 0,
    WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
    AppTick, AppUpdate, AppRender,
    KeyPressed, KeyReleased, KeyTyped,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
  };

  class Event
  {
    template<typename T>
    using EventFn = std::function<bool(T&)>;
  public:
    bool Handled = false;

    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;

    virtual std::string ToString() const { return GetName(); }

    template<typename T>
    bool Dispatch(EventFn<T> func)
    {
      if (GetEventType() == T::GetStaticType())
      {
        Handled = func(*(T*)&this);
        return true;
      }
      return false;
    }
  };

  inline std::ostream& operator<<(std::ostream& os, const Event& e)
  {
    return os << e.ToString();
  }

}