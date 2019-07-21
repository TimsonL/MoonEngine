#pragma once

namespace moon {

  enum class EventType
  {
    None = 0,

    // System Events

    // Window Events
    WindowClosed,
    WindowResized,
    WindowFocused,
    WindowLostFocus,
    WindowMoved,

    // Key Events
    KeyPressed,
    KeyReleased,

    // Mouse Events
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled

    // Engine Events

    // Game Events
  };

  class Event {
  public:
    using Data = std::unordered_map<std::string, boost::any>;

    Event(EventType type, Data&& data) : m_type(type), m_data(data) {}
    Event(const Event&) = delete;

    EventType GetType() { return m_type; }
    Data& GetData() { return m_data; }

    boost::any& operator[](const std::string& key) { 
      auto it = m_data.find(key);
      if (it != m_data.end()) return it->second;
      MOON_CORE_ERROR("Event does not have the requested attribute");
      assert(0);
    }
    const boost::any& operator[](const std::string& key) const { return operator[](key); }
  private:
    EventType m_type;
  protected:
    Data m_data;
  };

  template<typename EventCategory>
  class EventDispatcher {
  public:
    class EventListener;

    void AddListener(EventType, EventListener* listener);
    void RemoveListener(EventType, EventListener* listener);

    void dispatch(const EventCategory& e);
  private:
    std::unordered_map<EventType, std::vector<EventListener*>> m_listeners;
  };

  class EventListener {
  public:
    void subscribe(EventType type);
    void unsubscribe(EventType type);

    virtual void OnEvent(EventType type, const Event::Data& data) const = 0;
  private:
    std::unordered_set<EventType> m_subscriptions;
  };

}
                        