# CrowdSim

# Phase 2: SDL Window and Game Loop

This document describes changes and lessons introduced during Phase 2.

For overall project goals and architecture, see:

- README.md
- README-Phase-01.md

---

# Phase Goals

Objectives for this phase:

- Integrate SDL3
- Create a native application window
- Implement SDL event processing
- Create a basic game loop
- Introduce RAII concepts
- Keep the application responsive

---

# What Changed

## SDL3 Integration

SDL3 was added as the project's first external dependency.

SDL provides:

- Window creation
- Event processing
- Input handling
- Rendering APIs (to be used later)

At this stage, SDL is only being used for window and event management.

---

## Window Class

Added:

```text
Engine/
└── Rendering/
    ├── Window.h
    └── Window.cpp
```

The Window class wraps SDL's native window object.

Responsibilities:

- Create application window
- Own SDL window resource
- Destroy SDL window during cleanup

This is the first example of resource ownership within the engine.

---

## Event Processing

The application now processes operating system events.

Example:

```cpp
SDL_Event event;

while (SDL_PollEvent(&event))
{
    if (event.type == SDL_EVENT_QUIT)
    {
        running = false;
    }
}
```

Without event processing:

```text
Window opens
→ Operating system sends messages
→ Application ignores messages
→ Window becomes "Not Responding"
```

This is a fundamental requirement of interactive applications.

---

## Game Loop

The application now executes continuously until the user closes the window.

Current structure:

```cpp
while (running)
{
    ProcessEvents();
}
```

This is the foundation of every future feature.

Future iterations will evolve into:

```cpp
while (running)
{
    ProcessEvents();
    Update();
    Render();
}
```

and eventually:

```cpp
while (running)
{
    ProcessEvents();

    RunSystems();

    DispatchJobs();

    Render();
}
```

---

# New Concepts Introduced

## RAII

Resource Acquisition Is Initialization (RAII) is one of the most important concepts in modern C++.

The idea:

```text
Object created
    ↓
Resource acquired

Object destroyed
    ↓
Resource released
```

Current example:

```cpp
Window::~Window()
{
    SDL_DestroyWindow(m_window);
}
```

The object is responsible for cleaning up the resource it owns.

Benefits:

- Fewer resource leaks
- Cleaner code
- Clear ownership rules

---

## Forward Declarations

Instead of including SDL headers in every file:

```cpp
#include <SDL3/SDL.h>
```

the Window header uses:

```cpp
struct SDL_Window;
```

This is called a forward declaration.

Benefits:

- Reduced compile times
- Reduced dependencies
- Cleaner interfaces

This becomes increasingly important as projects grow.

---

## Ownership

Phase 2 reinforced a central C++ design question:

> Who owns this object?

Current ownership:

```text
Application
    owns
        Window
```

represented as:

```cpp
Window m_window;
```

Rather than:

```cpp
Window* m_window;
```

Whenever possible, prefer direct ownership over raw pointers.

---

# New Gotchas Encountered

## Compiler-Generated Destructors

Attempting to define:

```cpp
Application::~Application()
{
    SDL_Quit();
}
```

produced:

```text
cannot define a compiler-generated special member function
```

Cause:

The destructor was not declared in the class definition.

Incorrect:

```cpp
class Application
{
public:
    bool Initialize();
    void Run();
};
```

Correct:

```cpp
class Application
{
public:
    ~Application();

    bool Initialize();
    void Run();
};
```

Takeaway:

If you provide an implementation for a special member function, declare it in the class first.

---

## SDL2 vs SDL3

Many examples found online use SDL2.

SDL3 changed:

- APIs
- Event constants
- Function signatures
- Return values

Verify documentation and examples are specifically for SDL3.

---

## Black Window Does Not Mean Failure

Current output:

```text
Black window
```

This is expected.

The objective of Phase 2 was:

```text
Window creation
Event processing
Application loop
```

Rendering will be introduced later.

A responsive black window is a successful result.

---

## Build Output Organization

During project reorganization, Visual Studio repeatedly recreated:

```text
x64/
Debug/
Release/
```

folders.

Cause:

Build output directories were still using Visual Studio defaults.

Solution:

Redirect build artifacts into:

```text
Build/
```

This keeps generated files separate from source code and simplifies source control.

---

## Visual Studio Filters vs Folders

Filters and folders are not the same thing.

Filters:

```text
Virtual organization
```

Folders:

```text
Physical file system structure
```

For this project, source organization is being managed through the actual folder structure rather than custom filters.

---

# Current Milestone

The application now:

✅ Initializes SDL

✅ Creates a native window

✅ Processes operating system events

✅ Remains responsive

✅ Shuts down correctly

✅ Runs a basic game loop

---

# Next Phase

## Phase 3: First Crowd Simulation

Goals:

- Create an Agent structure
- Store agents using `std::vector<Agent>`
- Render simple agents on screen
- Simulate movement
- Observe the limitations of an object-oriented data layout

Expected result:

```text
Hundreds of moving agents visible on screen.
```

This phase intentionally avoids ECS so that the motivation for data-oriented design becomes obvious through experience rather than theory.