```mermaid
classDiagram
    class Machine {
        -memory: Memory
        -cpu: CPU
        +Machine()
        +run() void
        -displayMenu() void
        -resetSystem() void
        -loadProgramFromFile(filename string) vector~string~
        -parseInstructions(input string) vector~string~
        -displayFullState() void
    }

    class CPU {
        -memory: Memory&
        -registers: Register
        -programCounter: int
        -halted: bool
        -instructionRegister: string
        +CPU(mem Memory&)
        +setProgramCounter(address int) void
        +reset() void
        +isHalted() bool
        +executeInstruction() void
        +displayState() void
        +getRegisters() Register&
        +getProgramCounter() int
        -hexToInt(hex string) int
        -intToHex(value int) string
    }

    class Memory {
        -memory: string[256]
        -size: int
        +Memory()
        +getCellAddress(address int) string
        +setCellAddress(address int, value string) void
        +displayMemory() void
        +getSize() int
    }

    class Register {
        -registers: string[16]
        +Register()
        +getRegister(index int) string
        +setRegister(index int, value string) void
        +displayRegisters() void
    }

    Machine *-- Memory
    Machine *-- CPU
    CPU o-- Memory
    CPU *-- Register