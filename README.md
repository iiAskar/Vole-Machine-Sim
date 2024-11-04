classDiagram
    class Register {
        -registers: string[16]
        -size: int
        +Register()
        +getRegister(int) : string
        +setRegister(int, string)
        +displayRegisters()
    }

    class Memory {
        -memory: string[256]
        -size: int
        +Memory()
        +getCellAddress(int) : string
        +setCellAddress(int, string)
        +displayMemory()
        +getSize() : int
    }

    class Cpu {
        -memory: Memory&
        -registers: Register
        -programCounter: int
        -halted: bool
        -instructionRegister: string
        +Cpu(Memory&)
        +setProgramCounter(int)
        +reset()
        +isHalted() : bool
        +executeInstruction()
        +displayState()
        +getRegisters() : Register&
        +getProgramCounter() : int
        -hexToInt(string) : int
        -intToHex(int) : string
    }

    class Machine {
        -memory: Memory
        -cpu: Cpu
        +Machine()
        +run()
        -displayMenu()
        -resetSystem()
        -loadProgramFromFile(string) : vector~string~
        -parseInstructions(string) : vector~string~
        -displayFullState()
    }
