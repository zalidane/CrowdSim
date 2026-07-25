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

---

# Learning Roadmap

The project is being built incrementally.

## Phase 1
Project Setup and Architecture

- Visual Studio solution configuration
- Engine/Game separation
- Application lifecycle
- Project organization

## Phase 2
SDL Window and Game Loop

- Window creation
- Event processing
- Main update loop
- Introduction to RAII

## Phase 3
First Crowd Simulation

- Agent data structures
- Update loops
- Rendering hundreds of moving entities
- Learning the limitations of object-oriented data layouts

## Phase 4
Entity Component System

- Entity identifiers
- Component storage
- Sparse sets
- ECS world management
- Systems architecture

## Phase 5
Data-Oriented Simulation

- Structure of Arrays (SoA)
- Cache locality
- Entity spawning and destruction
- Large entity counts

## Phase 6
Asset Management

- Texture loading
- Resource caching
- Asset handles
- Lifetime management

## Phase 7
Serialization

- Save and load simulation state
- Component serialization
- JSON-based persistence

## Phase 8
Memory Management

- Object pools
- Custom allocators
- Memory fragmentation
- Allocation performance

## Phase 9
Job System

- Thread pools
- Work queues
- Parallel ECS updates
- Synchronization considerations

## Phase 10
Simulation Sandbox

- Interactive controls
- Large-scale crowd simulation
- Performance testing
- Engine polish

---

# Project Structure

```text
CrowdSim/
│
├── Assets/
├── Build/
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
└── Documentation/
```

### Engine

Contains reusable infrastructure:

- ECS
- Rendering
- Memory management
- Serialization
- Asset systems
- Job systems

### Game

Contains simulation-specific code:

- Components
- Systems
- Behaviors
- Scenarios

---

# Technology Choices

Current tools:

- Visual Studio Community 2026
- C++20

Planned libraries:

- SDL3 (windowing and rendering)
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
- C++ features introduced
- Common pitfalls
- Future work

The intent is to create a chronological record of learning and engine development.

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

Building the systems from scratch makes the tradeoffs visible and easier to understand.

---

# Current Status

✅ Phase 1 Complete

Current capabilities:

- Project structure established
- Engine/Game separation created
- Application lifecycle implemented
- Successful build and execution

Next milestone:

**Create an SDL3 window and implement the first application loop.**

---

# License

This project is licensed under the MIT License.
