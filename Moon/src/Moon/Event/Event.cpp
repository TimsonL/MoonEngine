#include "pch.h"
#include "Event.h"

namespace moon {

  template<typename EventCategory>
  void EventDispatcher<EventCategory>::AddListener(EventType type, EventListener* listener)
  {
    auto it = m_listeners.find(type);
    if (it != m_listeners.end()) {
      auto& listeners = *it;
      for (auto l : listeners) {
        if (listener == l) {
          MOON_CORE_WARN("EventListener already registered");
          return;
        }
      }
      listeners.push_back(listener);
      listener->subscribe();
    }
  }
  
  template<typename EventCategory>
  void EventDispatcher<EventCategory>::RemoveListener(EventType type, EventListener* listener)
  {
    auto it = m_listeners.find(type);
    if (it != m_listeners.end()) {
      auto& listeners = *it;
      for (auto it = listeners.begin(); it != listeners.end(); ++it) {
        if (listener == *it) {
          listener->unsubscribe();
          listeners.erase(it);
          return;
        }
      }
      MOON_CORE_WARN("EventListener already removed");
    }
  }

  template<typename EventCategory>
  void EventDispatcher<EventCategory>::dispatch(const EventCategory& e)
  {
    auto type = e.GetType();
    auto& listeners = m_listeners[type];
    for (auto l : listeners) {
      l->OnEvent(type, e.GetData());
    }
  }

  void EventListener::subscribe(EventType type)
  {
    m_subscriptions.emplace(type);
  }

  void EventListener::unsubscribe(EventType type)
  {
    m_subscriptions.erase(type);
  }

}
