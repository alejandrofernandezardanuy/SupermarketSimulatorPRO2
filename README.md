# Supermarket Management System

## Overview

This is a university project that simulates and manages a supermarket (Megathlon) checkout system. The application optimizes customer flow through different store sections and minimizes wait times at checkout counters. It provides an efficient way to manage store layout, customer routing, and cashier queue management.

## Project Description

The Supermarket Management System is designed to help a supermarket improve its operations by:

- **Optimizing Customer Routes**: Guiding customers through the most efficient path to collect their desired products
- **Managing Store Sections**: Organizing store layout into different rooms/sections where products are located
- **Reducing Wait Times**: Monitoring and minimizing checkout queue times across multiple cashiers
- **Tracking Customer Flow**: Recording customer shopping patterns and checkout times to improve service quality

This project demonstrates practical applications of data structures and algorithms in real-world scenarios, helping the supermarket provide better customer satisfaction and increase profitability.

## Features

- **Customer Management** (`Cliente` class): 
  - Track customer shopping lists and products to purchase
  - Calculate optimal room/section visits
  - Record customer data for analysis

- **Store Room Management** (`Tienda` class):
  - Organize store layout using binary tree structure
  - Generate optimal navigation instructions for customers
  - Manage product locations across different sections

- **Cashier Queue System** (`Caja` class):
  - Manage checkout lines for multiple cashiers
  - Track customer checkout times using time objects (`Hora`)
  - Minimize customer wait times

- **Collection Management**:
  - `ConjClientes`: Manage multiple customers
  - `ConjCajas`: Handle multiple checkout counters
  - Support for batch operations on customer and cashier data

## Project Structure

```
LAPRACTICA/
├── README.md                 # Project documentation
├── Makefile                  # Build configuration
├── program.cc                # Main program entry point
├── program.exe               # Compiled executable
│
├── Cliente.cc / Cliente.hh          # Customer class implementation
├── Caja.cc / Caja.hh                # Cashier/Checkout class implementation
├── Tienda.cc / Tienda.hh            # Store management class implementation
├── Hora.cc / Hora.hh                # Time utility class
├── ConjClientes.cc / ConjClientes.hh # Customer collection class
├── ConjCajas.cc / ConjCajas.hh      # Cashier collection class
├── BinTree.hh                       # Binary tree template implementation
│
├── Doxyfile                  # Doxygen documentation configuration
├── DOC/                      # Generated documentation files
└── test files               # Test input/output files
    ├── test1.inp
    ├── test1.cor
    └── ...
```

## Technical Details

### Data Structures Used

- **Binary Trees**: Store organization and room hierarchy
- **Sets**: Product lists and room tracking
- **Lists**: Cashier queues
- **Vectors**: Collection management
- **Pairs**: Customer ID and time associations

### Classes

| Class | Purpose |
|-------|---------|
| `Cliente` | Represents a customer with shopping list and room visits |
| `Caja` | Represents a cashier with queue management |
| `Tienda` | Manages store layout, rooms, and customer routing |
| `Hora` | Time representation for checkout tracking |
| `ConjClientes` | Collection of multiple customers |
| `ConjCajas` | Collection of multiple cashiers |

### Key Algorithms

- Customer route optimization using binary tree traversal
- Queue management for cashier lines
- Wait time calculation and analysis
- Optimal room navigation instructions

## Building and Running

### Prerequisites

- C++ compiler (supporting C++11 or later)
- Make (for building)
- Standard C++ libraries

### Compilation

```bash
make
```

This will compile all source files and generate the executable `program.exe`.

### Execution

```bash
./program.exe
```

The program will:
1. Load store room configuration
2. Display current store layout
3. Prompt for number of available cashiers
4. Accept commands for customer management (see Commands section)

### Clean Build

```bash
make clean
```

Removes compiled object files and executable.

## Commands

The program accepts the following commands:

- `nuevo_cliente` - Add a new customer to the system
- `fin` - End the program

When adding a new customer, you'll be prompted to:
1. Enter the list of products they want to purchase
2. The system will calculate which rooms they need to visit
3. The system will assign them to a cashier queue

## Documentation

This project uses Doxygen for code documentation. The documentation configuration file is `Doxyfile`.

To generate HTML documentation:

```bash
doxygen Doxyfile
```

Generated documentation will be available in the `DOC/` directory.

## Testing

Test cases are provided in the following format:

- **Input files** (`.inp`): Commands and customer data
- **Output files** (`.cor`): Expected program output for verification

Run tests by redirecting input:

```bash
./program.exe < test1.inp
```

## Academic Context

This is a university programming project focused on:

- Object-oriented programming principles
- Data structure implementation and usage
- Algorithm optimization
- Software design patterns
- Real-world application modeling

## Course Information

- **Institution**: University project (Engineering Program)
- **Subject**: Data Structures and Algorithms
- **Project Type**: Object-Oriented Programming in C++

## Authors

- Alex (Primary Developer)

## License

This project is provided as-is for educational purposes. Modify and use as needed for your studies.

## Future Enhancements

Potential improvements for future versions:

- Graphical user interface (GUI) for store layout visualization
- Advanced analytics and reporting
- Machine learning for optimal queue prediction
- Real-time simulation capabilities
- Multi-threaded customer processing
- Integration with real inventory systems
- Customer satisfaction metrics

## Notes

- The system uses efficient data structures to minimize computational complexity
- Time tracking provides insights for operational improvements
- Binary tree structure allows flexible store layout management
- Modular design enables easy extension and modification

## Support

For questions or issues regarding this project, please refer to the generated Doxygen documentation or review the inline code comments.

---

**Last Updated**: 2026

**Version**: 1.0
