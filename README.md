# Machine Language Simulator

This C++ project is a **Machine Language Simulator** designed to emulate the behavior of basic machine language instructions. It simulates a simplified computer architecture with a limited instruction set, registers, memory, and a Program Counter (PC).

## Features:
- **Memory Simulation**: Provides a simulated main memory where machine instructions and data are loaded and executed.
- **Instruction Set**: Supports basic operations like data movement, arithmetic, and control flow.
- **Registers**: Includes a set of registers (R0-RF) to hold intermediate values during computation.
- **Program Counter (PC)**: Tracks the current instruction being executed in memory.
- **Step and Run Execution**: Allows step-by-step execution for debugging or continuous running of instructions.
- **Memory Visualization**: Displays the current state of memory, CPU registers, and Program Counter in real time.
- **Reset and Clear**: Options to clear the memory or reset the entire system to its initial state.

## Usage:
- **Load Instructions**: Users can load machine language instructions into memory using a simple interface.
- **Step-by-Step Execution**: Execute instructions one by one to observe changes in registers and memory.
- **Run Mode**: Execute all loaded instructions in sequence until a halt condition is reached.

## Example of Supported Instructions:
- `MOV`: Move data between registers or memory.
- `ADD`: Perform arithmetic addition on registers.
- `JMP`: Jump to a specific memory address to control program flow.

## Future Improvements:
- Adding more complex instruction sets.
- Expanding the visualization of memory and registers.
- Optimizing the performance for large-scale memory simulations.

---

This simulator is a great tool for learning how low-level machine language works and can serve as an educational resource for understanding CPU and memory interactions in a simulated environment.
![Machine Language Simulator](https://github.com/saeedmhmoud100/Machine-Language-Simulator/blob/main/screens/Screenshot%202023-11-15%20102623.png)
![Machine Language Simulator](https://github.com/saeedmhmoud100/Machine-Language-Simulator/blob/main/screens/Screenshot%202023-11-15%20102816.png)
![Machine Language Simulator](https://github.com/saeedmhmoud100/Machine-Language-Simulator/blob/main/screens/Screenshot%202023-11-15%20102647.png)

