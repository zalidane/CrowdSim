# CrowdSim

A learning project focused on modern C++ and game engine architecture.

The long-term goal is to build a small data-oriented Entity Component System (ECS) engine capable of simulating thousands of moving entities while teaching:

- Modern C++20
- Data-oriented design
- Entity Component Systems (ECS)
- Asset loading
- Serialization
- Memory pools
- Job systems
- Basic rendering

The project will evolve incrementally, with each phase introducing one new concept while keeping the simulation functional.

---

# Current Phase

**Phase 1: Project Setup and Application Skeleton**

Current milestone:

✅ Solution structure established

✅ Engine/Game separation

✅ Application startup and shutdown

✅ Successful build and execution

Future milestones:

⬜ SDL window

⬜ Game loop

⬜ Crowd simulation

⬜ ECS architecture

⬜ Serialization

⬜ Job system

---

# Project Structure

```text
CrowdSim/
│
├── Assets/
│
├── Build/
│   ├── Intermediate/
│   └── x64/
│
├── External/
│
├── Source/
│   │
│   ├── Engine/
│   │   ├── Assets/
│   │   ├── Core/
│   │   ├── ECS/
│   │   ├── Jobs/
│   │   ├── Memory/
│   │   ├── Rendering/
│   │   ├── Serialization/
│   │   └── Utils/
│   │
│   └── Game/
│       ├── Components/
│       ├── Scenes/
│       ├── Systems/
│       └── Main.cpp
│
├── CrowdSim.vcxproj
└── CrowdSim.slnx
```

---

# Architecture

The project is organized into two major areas.

## Engine

The reusable engine code.

Examples:

- ECS implementation
- Rendering systems
- Asset management
- Job system
- Memory allocators

The engine should eventually become independent of the crowd simulation itself.

---

## Game

The simulation-specific code.

Examples:

- Components
- Systems
- Spawn logic
- Crowd behaviors

The Game layer should use the Engine layer rather than implementing low-level infrastructure itself.

---

# Current Code

## Main.cpp

Current entry point.

```cpp
int main()
{
    Application app;

    if (!app.Initialize())
    {
        return -1;
    }

    app.Run();
    app.Shutdown();

    return 0;
}
```

Responsibilities:

- Create application
- Initialize application
- Execute main loop
- Shutdown application

This pattern mirrors many professional engines.

```text
main()
    ↓
Application
    ↓
Engine Systems
```

---

## Application

Current implementation:

```cpp
Application::Initialize()
Application::Run()
Application::Shutdown()
```

At the moment these methods only write diagnostic messages.

Example output:

```text
Application initialized.
```

The Application class will eventually own:

- Window
- Renderer
- ECS World
- Asset Manager
- Job System

Application will become the root object of the engine.

---

## Position Component

Current component:

```cpp
struct Position
{
    float x;
    float y;
};
```

Purpose:

Represents a 2D position.

This is intentionally a simple data structure.

Future ECS components should mostly resemble this style.

---

## Velocity Component

Current component:

```cpp
struct Velocity
{
    float x;
    float y;
};
```

Purpose:

Represents movement direction and speed.

This component will eventually be used by a MovementSystem.

---

# ECS Placeholder Files

The ECS folder currently contains placeholder files:

```text
ComponentPool.h
Entity.h
SparseSet.h
System.h
World.h
```

These files do not yet contain implementations.

Their purpose is to reserve the architectural layout that will be built in later phases.

Planned responsibilities:

### Entity.h

Entity identifiers.

### World.h

ECS world management.

### ComponentPool.h

Component storage.

### SparseSet.h

Fast entity lookups.

### System.h

System interfaces and shared functionality.

---

# Modern C++ Concepts Introduced

## Classes

Current example:

```cpp
class Application
{
};
```

Used to group behavior and state.

---

## Structs

Current examples:

```cpp
struct Position
{
};
```

```cpp
struct Velocity
{
};
```

In modern C++, the primary difference between `struct` and `class` is the default visibility.

For ECS components, `struct` is usually preferred because components are primarily data containers.

---

## Stack Allocation

Current example:

```cpp
Application app;
```

This object is created on the stack.

Advantages:

- Automatic cleanup
- No manual memory management
- Faster and safer

Prefer this whenever practical.

---

# C++ Gotchas

## Do Not Reach For `new`

Older C++ tutorials often encourage code like:

```cpp
Application* app = new Application();
```

Avoid this unless dynamic allocation is genuinely required.

Prefer:

```cpp
Application app;
```

or

```cpp
std::unique_ptr<Application>
```

when an object's lifetime must be controlled dynamically.

---

## Header Files Are Not Imports

This is one of the biggest differences from languages like:

- C#
- Java
- TypeScript

When you write:

```cpp
#include "Application.h"
```

the preprocessor literally copies the contents of the header into the translation unit before compilation.

Poor include hygiene can significantly slow compile times.

---

## Use `#pragma once`

Every project header should begin with:

```cpp
#pragma once
```

This prevents multiple inclusion of the same header.

Example:

```cpp
#pragma once

class Application
{
};
```

---

## Keep Headers Small

Avoid including large headers unnecessarily.

Bad:

```cpp
#include <filesystem>
#include <map>
#include <thread>
#include <vector>
```

everywhere.

Better:

```cpp
class Window;
```

Forward declare types when possible.

Benefits:

- Faster compilation
- Reduced coupling
- Cleaner dependencies

---

## Prefer Values

Modern C++ tends to favor value semantics.

Good:

```cpp
Position position;
```

Avoid:

```cpp
Position* position = new Position();
```

unless ownership requirements make it necessary.

Data-oriented design relies heavily on value-based data structures.

---

## Source Files and Header Files Serve Different Purposes

Headers describe interfaces.

Example:

```cpp
class Application
{
public:
    bool Initialize();
    void Run();
    void Shutdown();
};
```

Source files contain implementation details.

Example:

```cpp
bool Application::Initialize()
{
    return true;
}
```

Keep implementation details inside `.cpp` files whenever possible.

---

# What We Learned

This phase introduced:

- Visual Studio project organization
- Modern source layout
- Engine/Game separation
- Basic application architecture
- C++ classes
- C++ structs
- Stack allocation
- Program startup and shutdown
- Preparing for ECS development

---

# Lessons Learned During Setup

## Visual Studio Filters Are Not Folders

Visual Studio filters are purely organizational.

They do not represent the actual file system.

For this project, we chose to organize the physical folder structure directly and largely ignore filter management.

---

## Build Output Should Be Isolated

Generated files should not mix with source code.

Build artifacts now live under:

```text
Build/
```

This keeps the project root clean and makes source control management easier.

---

## Organize Code Before Writing Features

The current layout was intentionally created before implementing functionality.

Benefits:

- Easier navigation
- Clear ownership boundaries
- Less refactoring later

---

# Next Phase

## Phase 2: SDL Window and Game Loop

Goals:

- Install SDL3
- Create a native window
- Process user input events
- Implement a game loop
- Introduce RAII concepts
- Keep the application responsive

Expected result:

```text
A window opens and remains responsive until closed.
```

This window will become the foundation for all rendering and simulation code that follows.