# CrowdSim

A learning project focused on modern C++20, data-oriented design, and game engine architecture.

The goal of CrowdSim is to build a small but complete Entity Component System (ECS) engine from scratch while developing a crowd simulation capable of supporting thousands of moving entities.

Rather than learning C++ through isolated examples, this project uses a practical engine-building approach. Each feature is introduced when there is a real need for it, mirroring how production software evolves.

---

# Objectives

This project is designed to teach:

- Modern C++20
- Data-oriented design
- Entity Component Systems (ECS)
- Asset loading and management
- Serialization
- Memory pools and custom allocation
- Job systems and multithreading
- Basic 2D rendering
- Cache-friendly data structures
- Engine architecture

The emphasis is on understanding *why* these systems exist, not merely how they are implemented.

---

# Planned End Result

The final application will be a real-time crowd simulation where thousands of entities:

- Spawn and despawn dynamically
- Move toward goals
- Avoid obstacles
- Load visual assets
- Save and load simulation state
- Update in parallel using a custom job system

The simulation serves as a vehicle for exploring engine architecture rather than as a completed game.

Potential future simulation features:

- Individual moods
- Social interactions
- Crowd behavior variations
- Agent needs and motivations
- Emergent group behavior

---

# Learning Roadmap

The project is being built incrementally.

## ✅ Phase 1 - Completed
### Project Setup and Architecture

Implemented:

- Visual Studio solution configuration
- Repository setup
- Source tree organization
- Engine/Game separation
- Application lifecycle
- Build output organization
- Project documentation workflow

Key lessons:

- Visual Studio filters vs physical folders
- Project organization
- Header/source separation
- Modern C++ project structure

---

## ✅ Phase 2 - Completed
### SDL Window and Game Loop

Implemented:

- SDL3 integration
- Window creation
- SDL initialization and shutdown
- Event processing
- Main application loop
- Window abstraction
- First use of RAII concepts

Key lessons:

- Constructors and destructors
- Resource ownership
- Event-driven applications
- Forward declarations
- Composition vs pointers

---

## ✅ Phase 3 - Completed
### First Simulation and Rendering

Implemented:

- Agent data structure
- Agent storage using `std::vector`
- Delta time calculation
- Simulation update loop
- SDL renderer abstraction
- Rectangle rendering
- Screen boundary collision
- First visible moving entity

Key lessons:

- Frame-rate independent movement
- Update vs Render separation
- `std::vector`
- `std::chrono`
- Translation units
- Header dependency management
- Collision boundaries vs render dimensions

---

## Phase 4
### Growing the Crowd

Planned:

- Randomized agent spawning
- Multiple agents
- Randomized velocities
- Scalable update loops
- Hundreds of simultaneous agents
- Observing weaknesses in the current architecture

Goals:

- Understand what becomes difficult as complexity grows
- Identify opportunities for data-oriented design
- Establish motivation for ECS

---

## Phase 5
### Entity Component System

Planned:

- Entity identifiers
- Component storage
- Sparse sets
- ECS world management
- Systems architecture
- Component queries

Goals:

- Separate data from behavior
- Improve scalability
- Learn modern ECS concepts

---

## Phase 6
### Data-Oriented Simulation

Planned:

- Structure of Arrays (SoA)
- Cache locality
- Efficient iteration
- Entity spawning and destruction
- Large entity counts

Goals:

- Understand why ECS improves performance
- Learn data-oriented thinking

---

## Phase 7
### Asset Management

Planned:

- Texture loading
- Resource caching
- Asset handles
- Lifetime management
- Asset ownership

Goals:

- Understand resource management in engine architecture

---

## Phase 8
### Serialization

Planned:

- Save simulation state
- Load simulation state
- Component serialization
- JSON persistence

Goals:

- Learn persistence and data-driven design

---

## Phase 9
### Memory Management

Planned:

- Memory pools
- Free lists
- Custom allocators
- Allocation profiling
- Fragmentation awareness

Goals:

- Understand memory ownership and performance

---

## Phase 10
### Job System

Planned:

- Thread pools
- Work queues
- Parallel update systems
- Synchronization
- Work distribution

Goals:

- Learn multithreaded engine architecture

---

## Phase 11
### Simulation Sandbox

Planned:

- Interactive controls
- Large-scale crowd simulation
- Performance testing
- Diagnostics
- Engine polish

Goals:

- Integrate all previous systems into a single simulation

---

# Project Structure

```text
CrowdSim/
│
├── Assets/
├── Build/
├── Documentation/
├── External/
│
├── Source/
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
│       └── Systems/
│
├── .gitignore
├── LICENSE.txt
├── README.md
└── CrowdSim.slnx
```

---

# Current Architecture

Current runtime flow:

```text
main()
    ↓
Application
    ↓
Window
    ↓
Renderer
    ↓
Agent Simulation
```

Current rendering flow:

```text
SDL Window
    ↓
SDL Renderer
    ↓
Rectangle Rendering
```

Current simulation flow:

```text
Spawn Agent
    ↓
Update Position
    ↓
Boundary Collision
    ↓
Render Agent
```

---

# Engine

Contains reusable infrastructure:

- ECS
- Rendering
- Memory management
- Serialization
- Asset systems
- Job systems

The long-term goal is for the engine layer to become reusable independently of the crowd simulation.

---

# Game

Contains simulation-specific code:

- Components
- Systems
- Behaviors
- Simulation rules
- Crowd logic

The Game layer should consume Engine functionality rather than implementing low-level infrastructure directly.

---

# Technology Choices

Current tools and libraries:

- Visual Studio Community 2026
- C++20
- SDL3

Planned libraries:

- nlohmann/json (serialization)

Most engine systems will be implemented manually as learning exercises.

---

# Repository Documentation

The project maintains phase-specific documentation as the engine evolves.

Examples:

```text
Documentation/
├── README-Phase-01.md
├── README-Phase-02.md
├── README-Phase-03.md
└── ...
```

Each phase documents:

- Architecture decisions
- Concepts learned
- Bugs encountered
- C++ features introduced
- Common pitfalls
- Future work

The intent is to create a chronological engineering journal documenting not only what was built, but why each design decision was made.

---

# Why Build Yet Another ECS?

The purpose is educational.

Many ECS frameworks already exist and are significantly more capable than what will be built here.

The objective is not to compete with established engines, but to gain a practical understanding of:

- Data-oriented design
- Cache efficiency
- Engine architecture
- Modern C++
- Multithreaded simulation

Building these systems from scratch makes the tradeoffs visible and easier to understand.

---

# Future Ideas

## Mood System

Potential future feature:

Each spawned person may receive a randomized mood when created.

Possible moods:

- Happy
- Neutral
- Curious
- Angry
- Scared

Potential future systems:

- MoodSystem
- SocialSystem
- CrowdBehaviorSystem

Potential future components:

- Mood
- Energy
- SocialNeed

This feature is intentionally deferred until after the ECS implementation.

---

# Current Status

✅ Phase 1 Complete

✅ Phase 2 Complete

✅ Phase 3 Complete

Current capabilities:

- Project structure established
- Engine/Game separation created
- SDL3 integrated
- Application lifecycle implemented
- Native window creation
- SDL event processing
- Renderer abstraction
- Delta time calculation
- Agent simulation
- Rectangle rendering
- Screen boundary collision

Current simulation:

- One moving agent
- Frame-rate independent movement
- Continuous rendering
- Boundary bounce behavior

Current milestone achieved:

```text
A visible simulation object moves around the window and responds to collision constraints.
```

Next milestone:

**Grow the simulation from a single agent to many agents and begin identifying the architectural limitations that will eventually drive the transition to ECS.**

---

# License

This project is licensed under the MIT License.