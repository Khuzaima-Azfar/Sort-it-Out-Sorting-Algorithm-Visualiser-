# SFML Algorithm Visualizer

This project is an algorithm visualizer built using the Simple and Fast Multimedia Library (SFML). It provides a graphical representation of various sorting algorithms, allowing users to observe how these algorithms work in real-time.

## Project Structure

```
sfml-algo-visualizer
├── src
│   ├── main.cpp                # Entry point of the application
│   ├── Visualizer.cpp          # Implementation of the Visualizer class
│   ├── renderer.cpp            # Implementation of the Renderer class
│   ├── algorithms              # Directory containing sorting algorithms
│   │   ├── insertion_sort.cpp  # Insertion sort visualization
│   │   ├── bubble_sort.cpp     # Bubble sort visualization
│   │   └── selection_sort.cpp   # Selection sort visualization
│   └── utils.cpp               # Utility functions
├── include
│   ├── Visualizer.hpp          # Header for the Visualizer class
│   ├── renderer.hpp            # Header for the Renderer class
│   └── algorithms              # Directory for sorting algorithm interfaces
│       └── sorting.hpp         # Interface for sorting algorithms
├── assets
│   └── fonts                   # Directory for font files
├── CMakeLists.txt             # CMake configuration file
├── .gitignore                  # Git ignore file
└── README.md                   # Project documentation
```

## Setup Instructions

1. **Clone the repository:**
   ```
   git clone <repository-url>
   cd sfml-algo-visualizer
   ```

2. **Install dependencies:**
   Ensure you have SFML installed on your system. Follow the installation instructions for your platform from the [SFML website](https://www.sfml-dev.org/download.php).

3. **Build the project:**
   ```
   mkdir build
   cd build
   cmake ..
   make
   ```

4. **Run the visualizer:**
   After building, you can run the visualizer executable located in the `build` directory.

## Usage

Upon running the application, you will see a window displaying the visualizations of various sorting algorithms. You can select different algorithms to visualize their sorting process.

## Algorithms Visualized

- **Insertion Sort:** A simple sorting algorithm that builds a sorted array one element at a time.
- **Bubble Sort:** A straightforward sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
- **Selection Sort:** An in-place comparison sorting algorithm that divides the input list into two parts: a sorted and an unsorted region.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.