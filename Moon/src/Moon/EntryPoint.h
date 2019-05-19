#pragma once

#ifdef MOON_PLATFORM_WIN

extern moon::Application* moon::CreateApplication();

int main(int argc, char** argv)
{
  auto app = moon::CreateApplication();
  app->Run();
  delete app;
}

#endif // MOON_PLATFORM_WIN

