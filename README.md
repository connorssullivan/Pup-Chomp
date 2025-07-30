# Pup Patrol - 🐍 Snake Game - C++ SFML Implementation

![pupChomp](https://github.com/user-attachments/assets/1c52dee4-92d4-4dff-9416-8be97f5e338c)

A modern, feature-rich Snake game built with C++ and SFML, demonstrating object-oriented design, state management, and game development principles.

![Snake Game](https://img.shields.io/badge/C++-20-blue?style=for-the-badge&logo=cplusplus)
![SFML](https://img.shields.io/badge/SFML-3.0.1-green?style=for-the-badge)
![CMake](https://img.shields.io/badge/CMake-3.28-orange?style=for-the-badge&logo=cmake)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

## 🎮 Features

- **Classic Snake Gameplay**: Navigate, collect food, and grow your snake
- **State Management System**: Clean separation between menu, gameplay, pause, and game over states
- **Asset Management**: Centralized resource loading and management
- **Modern C++**: Utilizes C++20 features including smart pointers and modern STL containers
- **Cross-Platform**: Built with CMake for easy compilation on Windows, macOS, and Linux
- **Audio Integration**: Background music and sound effects
- **Responsive Controls**: Smooth keyboard input handling

## 🏗️ Architecture

### Core Components

- **Game Engine**: Main game loop with 60 FPS frame rate
- **State Machine**: Manages different game states (Menu, Play, Pause, Game Over)
- **Asset Manager**: Handles texture, font, and audio loading
- **Snake Class**: Implements snake movement, growth, and collision detection
- **Input System**: Keyboard event handling and input processing

### Design Patterns

- **State Pattern**: Clean separation of game states
- **Resource Manager Pattern**: Centralized asset management
- **Component-Based Design**: Modular, reusable game objects
- **RAII**: Proper resource management with smart pointers

## 🛠️ Technical Stack

- **Language**: C++20
- **Graphics Library**: SFML 3.0.1
- **Build System**: CMake 3.28
- **Audio**: SFML Audio module
- **Platform**: Cross-platform (Windows, macOS, Linux)

## 🚀 Getting Started

### Prerequisites

- C++20 compatible compiler (GCC 10+, Clang 12+, MSVC 2019+)
- CMake 3.28 or higher
- Git

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/connorssullivan/Pup-Chomp.git
   cd Pup-Chomp
   ```

2. **Build the project**
   ```bash
   cmake -B build
   cmake --build build
   ```

3. **Run the game**
   ```bash
   ./build/bin/main
   ```

### Development Setup

For different IDEs:

- **VS Code**: Install CMake extension and open the project
- **Visual Studio**: Open CMakeLists.txt as a CMake project
- **CLion**: Open the project directory
- **Qt Creator**: Open CMakeLists.txt

## 📁 Project Structure

```
Snake/
├── assets/                 # Game resources
│   ├── audio/             # Sound effects and music
│   ├── fonts/             # Custom fonts
│   └── textures/          # Game sprites and images
├── include/               # Header files
│   ├── Game.h            # Main game class
│   ├── StateMan.h        # State management
│   ├── AssetMan.h        # Asset management
│   ├── Snake.h           # Snake game object
│   └── ...               # Other game components
├── src/                   # Source files
│   ├── main.cpp          # Entry point
│   ├── Game.cpp          # Game implementation
│   ├── Snake.cpp         # Snake logic
│   └── ...               # Other implementations
└── CMakeLists.txt        # Build configuration
```

## 🎯 Key Implementation Details

### State Management
The game uses a state machine pattern to manage different game phases:
- **MainMenu**: Title screen with navigation
- **GamePlay**: Active gameplay with snake movement and collision detection
- **PauseGame**: Paused state with resume/quit options
- **GameOver**: End game screen with score display

### Snake Implementation
- Uses `std::list` for efficient body segment management
- Implements collision detection with walls and self
- Growth mechanism with proper segment addition
- Smooth movement with direction-based controls

### Asset Management
- Centralized resource loading and caching
- Texture and audio management with RAII principles
- Memory-efficient resource handling

## 🔧 Development Practices

- **Modern C++**: Utilizes C++20 features and best practices
- **Memory Safety**: Smart pointers and RAII for resource management
- **Clean Architecture**: Separation of concerns and modular design
- **Cross-Platform**: CMake-based build system for portability
- **Version Control**: Proper Git workflow and commit history

## 🎨 Customization

### Adding New Features
1. Create new state classes inheriting from `State`
2. Add assets to the `AssetID` enum
3. Implement game logic in appropriate classes
4. Update CMakeLists.txt for new source files

### Modifying Gameplay
- Adjust snake speed in `Game.cpp`
- Modify collision detection in `Snake.cpp`
- Add new game mechanics in `GamePlay.cpp`

## 📊 Performance Considerations

- 60 FPS target frame rate
- Efficient collision detection algorithms
- Memory-efficient asset management
- Optimized rendering pipeline

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## 🙏 Acknowledgments

- SFML team for the excellent graphics library
- CMake community for the build system
- Open source contributors for inspiration

---

**Built with ❤️ using C++ and SFML**

*This project demonstrates strong C++ programming skills, game development principles, and software engineering best practices suitable for software engineering positions.*
