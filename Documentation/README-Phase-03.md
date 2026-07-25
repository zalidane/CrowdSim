# CrowdSim

# Phase 3: First Simulation and Rendering

This document describes changes and lessons introduced during Phase 3.

For previous work, see:

- README.md
- README-Phase-01.md
- README-Phase-02.md

---

# Phase Goals

Objectives for this phase:

- Create the first simulation object
- Introduce agent data structures
- Implement update logic
- Render objects to the screen
- Introduce delta time
- Separate simulation updates from rendering

---

# What Changed

## Agent Structure

Added:

```cpp
struct Agent
{
    float x;
    float y;

    float vx;
    float vy;
};
```

The first simulation entity is represented as a simple data structure containing:

- Position
- Velocity

This is intentionally simple.

The purpose is to familiarize ourselves with simulation logic before introducing Entity Component Systems.

---

## Agent Storage

Added:

```cpp
std::vector<Agent> m_agents;
```

to the Application class.

Agents are currently stored contiguously in memory.

Even though ECS has not yet been introduced, this choice already gives us some of the benefits of data-oriented design.

---

## Spawn Logic

Application initialization now creates the first agent.

Example:

```cpp
Agent agent;

agent.x = 100.0f;
agent.y = 100.0f;

agent.vx = 50.0f;
agent.vy = 250.0f;

m_agents.push_back(agent);
```

This allows the simulation to update visible objects each frame.

---

## Update Loop

Added:

```cpp
void Application::Update(float dt)
```

Responsibilities:

- Move agents
- Apply velocity
- Handle screen collisions

Current update logic:

```cpp
agent.x += agent.vx * dt;
agent.y += agent.vy * dt;
```

Velocity is measured in units per second.

Movement is scaled by frame time.

---

## Render Loop

Added:

```cpp
void Application::Render()
```

Responsibilities:

- Clear the screen
- Draw simulation objects
- Present the frame

Current flow:

```cpp
BeginFrame();

Draw agents;

EndFrame();
```

This establishes the separation between:

```text
Simulation
```

and

```text
Rendering
```

which will become increasingly important as the engine grows.

---

## Renderer Class

Added:

```text
Engine/
└── Rendering/
    ├── Renderer.h
    └── Renderer.cpp
```

The renderer currently wraps SDL rendering functionality.

Responsibilities:

- Create SDL renderer
- Clear screen
- Draw rectangles
- Present completed frame

This is the first rendering abstraction in the project.

---

# New SDL Functions Introduced

## SDL_CreateRenderer

Creates an SDL renderer associated with a window.

Example:

```cpp
SDL_CreateRenderer(...)
```

Purpose:

```text
Window
    +
Renderer
    =
Rendering capability
```

---

## SDL_SetRenderDrawColor

Sets the active drawing color.

Examples:

```cpp
SDL_SetRenderDrawColor(
    renderer,
    0,
    0,
    0,
    255);
```

Black:

```text
Background
```

and:

```cpp
SDL_SetRenderDrawColor(
    renderer,
    255,
    255,
    255,
    255);
```

White:

```text
Agent rectangle
```

---

## SDL_RenderClear

Clears the screen using the current draw color.

Example:

```cpp
SDL_RenderClear(renderer);
```

Current result:

```text
Black background
```

---

## SDL_RenderFillRect

Draws a filled rectangle.

Example:

```cpp
SDL_RenderFillRect(
    renderer,
    &rect);
```

This is how the first visible simulation object is rendered.

---

## SDL_RenderPresent

Displays the completed frame.

Example:

```cpp
SDL_RenderPresent(renderer);
```

Without this call:

```text
Nothing appears onscreen.
```

---

# New Standard Library Features Introduced

## std::vector

Header:

```cpp
#include <vector>
```

Purpose:

Dynamic contiguous array.

Current usage:

```cpp
std::vector<Agent>
```

Benefits:

- Automatic memory management
- Dynamic resizing
- Cache-friendly storage

This container will remain important throughout the ECS implementation.

---

## std::chrono

Header:

```cpp
#include <chrono>
```

Purpose:

Time measurement.

Current usage:

```cpp
std::chrono::steady_clock
```

Used to calculate delta time.

---

## std::random

Header:

```cpp
#include <random>
```

Introduced during experimentation for future agent spawning.

Will be used more heavily when generating large crowds with randomized behavior.

---

# New Concepts Introduced

## Delta Time

Current update logic uses:

```cpp
velocity * dt
```

instead of:

```cpp
velocity
```

alone.

Benefits:

```text
Movement becomes independent of frame rate.
```

Without delta time:

```text
60 FPS
    !=
144 FPS
```

simulation behavior.

With delta time:

```text
Movement is based on elapsed time.
```

---

## Simulation vs Rendering

This phase introduced an important architectural separation.

Simulation:

```cpp
Update()
```

Rendering:

```cpp
Render()
```

A common beginner approach is:

```cpp
agent.Update();
agent.Render();
```

inside every object.

We are intentionally avoiding that pattern.

This separation will naturally evolve into ECS systems later.

---

## Ownership Through Composition

Application now owns:

```cpp
Window
Renderer
std::vector<Agent>
```

This is another example of composition.

```text
Application
    has-a
        Renderer
```

rather than:

```text
Application
    inherits-from
        Renderer
```

---

# New Gotchas Encountered

## Forgetting To Call Update and Render

The application successfully opened a window but displayed nothing.

Cause:

```cpp
Update()
```

and

```cpp
Render()
```

were never called from:

```cpp
Application::Run()
```

The event loop was functioning correctly, but simulation and rendering never executed.

Lesson:

Opening a window is not enough.

The game loop must actively:

```text
Process Events
Update
Render
```

every frame.

---

## Struct Initialization Error

Initial rectangle code:

```cpp
SDL_FRect rect;

{
    x, y, width, height;
}
```

appeared valid but did not initialize the rectangle.

Result:

```text
Garbage rectangle values
```

Correct version:

```cpp
SDL_FRect rect
{
    x,
    y,
    width,
    height
};
```

Lesson:

Modern C++ initialization syntax is important and mistakes can be easy to miss visually.

---

## Position Does Not Equal Size

Initial collision logic used:

```cpp
if (agent.x > 1280)
```

which treats the agent as a point.

However the rendered rectangle has dimensions:

```cpp
50 x 50
```

so part of the rectangle moved off-screen before bouncing.

Correct logic:

```cpp
if (agent.x > WindowWidth - AgentSize)
```

Lesson:

Rendering dimensions must be considered when performing collision detection.

---

## Header Includes and Compilation Units

Question encountered:

> If SDL.h is included in multiple source files, is it copied multiple times?

Answer:

Yes.

Each source file becomes its own translation unit.

Example:

```text
Application.cpp
    +
SDL.h

Renderer.cpp
    +
SDL.h
```

SDL is processed once per translation unit.

This is why:

```cpp
struct SDL_Window;
```

forward declarations are preferred in header files whenever possible.

Reducing header dependencies is an important C++ optimization technique.

---

# Lessons Learned

This phase introduced:

- First rendering
- First simulation object
- Delta time
- SDL renderer
- std::vector
- std::chrono
- Update loops
- Render loops
- Collision handling
- Translation units
- Header dependency management

---

# Current Milestone

The application now:

✅ Opens a window

✅ Creates an SDL renderer

✅ Updates simulation state

✅ Renders a visible object

✅ Moves continuously

✅ Bounces within window boundaries

✅ Uses frame-rate independent movement

This is the first complete simulation in the project.

---

# Next Phase

## Phase 4: Growing the Crowd

Goals:

- Spawn multiple agents
- Generate random positions
- Generate random velocities
- Stress-test current design
- Begin identifying limitations of the current data model

Expected result:

```text
Dozens or hundreds of moving agents sharing the same update and render logic.
```

This phase prepares us for the eventual transition to a full Entity Component System.